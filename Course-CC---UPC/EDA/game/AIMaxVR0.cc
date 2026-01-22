#include "Player.hh"

#include <vector>
#include <queue>
#include <algorithm>
#include <array>

#define PLAYER_NAME MaxVR1

using namespace std;

struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }



  // Player attributes

  bool initialized;
  vector<vector<int>> box_solutions; // cache of solutions for each box

  PLAYER_NAME() : initialized(false) {}



  // Helpers

  const vector<Dir> dirs = {Down, Right, Up, Left};

  /**
   * @brief The board has 60 rows and cols (from the row / col 0 to the 59)
   * @post Returns whether a cell is in the board or not.
   */
  bool pos_ok(const Pos& p) const {
    return p.i >= 0 && p.i < board_rows()
        && p.j >= 0 && p.j < board_cols();
  }

  /**
   * @brief A cell is a box door if it has a box it and does not contain gold.
   * @post Returns whether a cell is a box door or not
   */
  bool is_box_door(const Cell& c) const {
    return c.box != -1 && !c.gold;
  }

  /**
   * @brief A cell is walkable if it is not a wall, a box door, or an own unit and is not outside the boundaries of the board
   * @post Returns whether a cell is walkable or not
   */
  bool is_walkable(const Cell& c, int my_player) const {
    if (c.type == Wall) return false;
    if (is_box_door(c)) return false;
    if (c.id != -1) {
      Unit u = unit(c.id);
      if (u.player == my_player) return false;
    }
    return true;
  }

  /**
   * @post Returns whether a cell is an access cell to any box door or not
   */
  bool is_box_access_pos(const Pos& p) {
    if (!pos_ok(p)) return false;
    Cell c = cell(p);
    if (c.type == Wall) return false;
    for (Dir d : dirs) {
      Pos q = p + d;
      if (!pos_ok(q)) continue;
      Cell cd = cell(q);
      if (is_box_door(cd)) return true;
    }
    return false;
  }

  static bool is_money(const Cell& c, const Pos&) { 
    return c.money > 0; 
  }

  static bool is_health_kit(const Cell& c, const Pos&) { 
    return c.health_kit; 
  }

  static bool is_poison_kit(const Cell& c, const Pos&) { 
    return c.poison_kit; 
  }

  /**
   * @brief Choose n disjoint triplets that cover all indices (Backtracking)
   */
  bool dfs(int used_count, vector<bool>& used, vector<array<int,3>>& chosen, const vector<array<int,3>>& triples, const vector<vector<int>>& triples_indexes, int m) {
    if (used_count == m) return true;

    int i = 0;
    while (i < m && used[i]) i++;
    if (i == m) return false;

    for (int tid : triples_indexes[i]) {
      auto tri = triples[tid];
      int a = tri[0], b = tri[1], c = tri[2];
      if (used[a] || used[b] || used[c]) continue;

      used[a] = used[b] = used[c] = true;
      chosen.push_back(tri);

      if (dfs(used_count + 3, used, chosen, triples, triples_indexes, m)) return true;

      chosen.pop_back();
      used[a] = used[b] = used[c] = false;
    }
    return false;
  }



  // BFS

  template <typename Predicate>

  /**
   * @brief Calculates the first steep of the bfs algorithm
   */
  bool bfs(Pos start, int my_player, Predicate is_target, Dir& out_dir) {
    int R = board_rows();
    int C = board_cols();

    if (!pos_ok(start)) return false;

    vector<vector<int>> dist(R, vector<int>(C, -1));
    vector<vector<Pos>> parent(R, vector<Pos>(C, Pos(-1, -1)));
    vector<vector<int>> parent_dir(R, vector<int>(C, -1));

    queue<Pos> q;
    dist[start.i][start.j] = 0;
    q.push(start);

    bool found = false;
    Pos target(-1, -1);

    while (!q.empty() && !found) {
      Pos p = q.front();
      q.pop();

      for (int k = 0; k < 4; ++k) {
        Dir d = dirs[k];
        Pos np = p + d;
        if (!pos_ok(np)) continue;
        if (dist[np.i][np.j] != -1) continue;

        Cell c = cell(np);

        // If it is not walkably, it could be an enemy
        if (!is_walkable(c, my_player)) {
          if (is_target(c, np)) {
            found = true;
            target = np;
            parent[np.i][np.j] = p;
            parent_dir[np.i][np.j] = k;
          }
          continue;
        }

        dist[np.i][np.j] = dist[p.i][p.j] + 1;
        parent[np.i][np.j] = p;
        parent_dir[np.i][np.j] = k;

        if (is_target(c, np)) {
          found = true;
          target = np;
          break;
        }

        q.push(np);
      }
    }

    if (!found) return false;

    // Rebuild the first step from start to target
    Pos cur = target;
    while (!(cur == start) && parent[cur.i][cur.j] != Pos(-1, -1) && dist[cur.i][cur.j] > 1) {
      cur = parent[cur.i][cur.j];
    }

    int dir_index = parent_dir[cur.i][cur.j];
    if (dir_index < 0 || dir_index >= 4) return false;
    out_dir = dirs[dir_index];
    return true;
  }



  // Fight functions

  /**
   * @brief Soldier: attack if we have poison
   */
  bool attack(const Unit& u, int my_player) {
    if (u.type != Soldier) return false;
    if (u.poison <= 0) return false;

    for (Dir d : dirs) {
      Pos np = u.pos + d;
      if (!pos_ok(np)) continue;
      Cell c = cell(np);
      if (c.id == -1) continue;
      Unit v = unit(c.id);
      if (v.player == my_player) continue;
      move(u.id, d);
      return true;
    }
    return false;
  }

  /**
   * @brief Make a safe move if we can not do anything better
   */
  void random_move(const Unit& u, int my_player) {
    vector<int> perm = random_permutation(4);
    for (int idx : perm) {
      Dir d = dirs[idx];
      Pos np = u.pos + d;
      if (!pos_ok(np)) continue;
      Cell c = cell(np);
      if (!is_walkable(c, my_player)) continue;
      move(u.id, d);
      return;
    }
  }



  // Professor escape

  /**
   * @post Returns whether an enemy soldier is near
   */
  bool enemy_soldier_near(const Pos& p, int my_player) {
    for (Dir d : dirs) {
      Pos np = p + d;
      if (!pos_ok(np)) continue;
      Cell c = cell(np);
      if (c.id == -1) continue;
      Unit u = unit(c.id);
      if (u.player != my_player && u.type == Soldier) return true;
    }
    return false;
  }

  /**
   * @brief The more enemy soldiers are nearby, the higher the danger level is
   * @post Returns the level of danger that is around the position of the parameter `p`
   */
  int danger_level(const Pos& p, int my_player) {
    int danger = 0;
    for (Dir d : dirs) {
      Pos np = p + d;
      if (!pos_ok(np)) continue;
      Cell c = cell(np);
      if (c.id == -1) continue;
      Unit u = unit(c.id);
      if (u.player != my_player && u.type == Soldier) danger++;
    }
    return danger;
  }


  /**
   * @post Professor: Return whether to run away or not 
   */
  bool professor_escape(const Unit& prof, int my_player) {
    if (!enemy_soldier_near(prof.pos, my_player)) return false;

    int best_danger = 1000000;
    Dir best_dir = Down;
    bool found = false;

    for (Dir d : dirs) {
      Pos np = prof.pos + d;
      if (!pos_ok(np)) continue;
      Cell c = cell(np);
      if (!is_walkable(c, my_player)) continue;
      int danger = danger_level(np, my_player);
      if (danger < best_danger) {
        best_danger = danger;
        best_dir = d;
        found = true;
      }
    }

    if (found && best_danger < danger_level(prof.pos, my_player)) {
      move(prof.id, best_dir);
      return true;
    }
    return false;
  }



  // Solve the keys to the boxes

  /**
   * @brief A triplet is valid if one element is the sum of the other two
   * @post Returns whether three values can form a valid triplet
   */
  bool valid_triplet(int a, int b, int c) const {
    return (a + b == c) || (a + c == b) || (b + c == a);
  }

  /**
   * @brief Solve the key to a box based on its clues 
   */
  vector<int> solve_box(int id_box) {
    vector<int> h = safety_box_hints(id_box);
    int m = h.size();
    int n = m / 3;

    // Calculate all valid triplets
    vector<array<int,3>> triples;
    vector<vector<int>> triples_indexes(m);

    for (int i = 0; i < m; ++i) {
      for (int j = i + 1; j < m; ++j) {
        for (int k = j + 1; k < m; ++k) {
          if (valid_triplet(h[i], h[j], h[k])) {
            int idx = (int)triples.size();
            triples.push_back({i, j, k});
            triples_indexes[i].push_back(idx);
            triples_indexes[j].push_back(idx);
            triples_indexes[k].push_back(idx);
          }
        }
      }
    }

    vector<bool> used(m, false);
    vector<array<int,3>> chosen;
    chosen.reserve(n);

    dfs(0, used, chosen, triples, triples_indexes, m);

    vector<int> sol(m, 0);
    for (int t = 0; t < chosen.size(); t++) {
        auto tri = chosen[t];
        sol[tri[0]] = sol[tri[1]] = sol[tri[2]] = t;
    }
    return sol;
  }

  void init() {
    if (!initialized) {
      int nb = num_safety_boxes();
      box_solutions = vector<vector<int>>(nb, vector<int>());
      initialized = true;
    }
  }

  const vector<int>& get_box_solution(int id_box) {
    if (id_box < 0) {
      static vector<int> empty;
      return empty;
    }
    if (box_solutions[id_box].empty()) {
      box_solutions[id_box] = solve_box(id_box);
    }
    return box_solutions[id_box];
  }

  /**
   * @brief Professor: Try to open a box if is in the right position
   */
  bool try_open_box(const Unit& prof, int my_player) {
    Pos p = prof.pos;
    bool opened = false;
    for (Dir d : dirs) {
      Pos q = p + d;
      if (!pos_ok(q)) continue;
      Cell door = cell(q);
      if (!is_box_door(door)) continue;
      int id_box = door.box;
      if (id_box < 0) continue;
      const vector<int>& sol = get_box_solution(id_box);
      if (sol.empty()) continue;
      open(prof.id, sol, d);
      opened = true;
      break;
    }
    return opened;
  }



  /**
   * @brief Professor logic
   */
  void play_professor(int prof_id, int my_player) {
    if (prof_id == -1) return;
    Unit p = unit(prof_id);
    if (!p.is_alive()) return;

    int max_h = professor_max_health();
    int my_health = p.health;
    int pot_health = available_health(my_player);

    // Escape if there is enemy soldiers near
    if (professor_escape(p, my_player)) return;

    // Heal if it is very damaged and there is health in the pot
    if (my_health > 0 && my_health < max_h / 2 && pot_health > 0) {
      heal(p.id);
      return;
    }

    // Try to open a box if it is in an access cell access to a box
    if (is_box_access_pos(p.pos)) {
      if (try_open_box(p, my_player)) return;
    }

    Dir dir;
    bool found = false;

    // Find the closest access cell to any box
    found = bfs(p.pos, my_player,
        [this](const Cell& c, const Pos& pos) {
          return is_box_access_pos(pos);
        },
        dir
    );
    if (found) {
      move(p.id, dir);
      return;
    }

    // Find coins
    found = bfs(p.pos, my_player, is_money, dir);
    if (found) {
      move(p.id, dir);
      return;
    }

    // Find health kids 
    found = bfs(p.pos, my_player, is_health_kit, dir);
    if (found) {
      move(p.id, dir);
      return;
    }

    // Find poison kits
    found = bfs(p.pos, my_player, is_poison_kit, dir);
    if (found) {
      move(p.id, dir);
      return;
    }

    // Else
    random_move(p, my_player);
  }



  /**
   * @brief Soldiers logic
   */
  void play_soldier(int sid, int my_player) {
    Unit s = unit(sid);
    if (!s.is_alive()) return;

    int max_poison = soldier_max_poisons();
    int pot_poison = available_poison(my_player);

    // Attack nearby enemies if we have poison 
    if (attack(s, my_player)) return;

    // Load poison if we do not have it and there is in the jar
    if (s.poison <= 0 && pot_poison > 0) {
      charge(s.id);
      return;
    }

    Dir dir;
    bool found = false;

    // Try to find enemy professors if we have poison
    if (s.poison > 0) {
      found = bfs(
          s.pos, my_player,
          [this, my_player](const Cell& c, const Pos&) {
            if (c.id == -1) return false;
            Unit v = unit(c.id);
            if (v.player == my_player) return false;
            return v.type == Professor;
          },
          dir
      );
      if (found) {
        move(s.id, dir);
        return;
      }
    }

    // Find any enemy if we have poison
    if (s.poison > 0) {
      found = bfs(
          s.pos, my_player,
          [this, my_player](const Cell& c, const Pos&) {
            if (c.id == -1) return false;
            Unit v = unit(c.id);
            return v.player != my_player;
          },
          dir
      );
      if (found) {
        move(s.id, dir);
        return;
      }
    }

    // Find poison kits if we have less that the maximum of the poison capacity
    if (s.poison < max_poison) {
      found = bfs(s.pos, my_player, is_poison_kit, dir);
      if (found) {
        move(s.id, dir);
        return;
      }
    }

    // Find coins
    found = bfs(s.pos, my_player, is_money, dir);
    if (found) {
      move(s.id, dir);
      return;
    }

    // Else
    random_move(s, my_player);
  }


  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
    init();
    int my_player = me();

    // Professor
    int pid = professor(my_player);
    play_professor(pid, my_player);

    // Soldier
    vector<int> sols = soldiers(my_player);
    for (int sid : sols) {
      play_soldier(sid, my_player);
    }
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);