#pragma once

#include <vector>
#include <set>
#include <vector>
#include "main_char.hh"
#include "platform.hh"
#include "coin.hh"
#include "window.hh"
#include "utils.hh"
#include "finder.hh"
#include "goomba.hh"
#include "spike.hh"
#include "mushroom.hh"
#include "star.hh"
#include "list.hh"

class Game {
    static constexpr int sky_blue = 0x5c94fc;       // Main background color
    static constexpr int sky_dark = 0x0C134F;       // Secondary background color
    
    // Players
    MainChar mario_;                                // Main player
    MainChar luigi_;                                // Second player

    // Platforms
    List<Platform> platforms_;                      // All platforms
    Finder<Platform> platform_finder_;              // Platform finder
    std::set<const Platform*> platform_actualObj_;  // Platforms in view

    // Coins
    List<Coin> coins_;                              // All coins
    Finder<Coin> coin_finder_;                      // Coin finder
    std::set<const Coin*> coin_actualObj_;          // Coins in view
    int num_coins_ = 0;                             // Collected coins

    // Spikes
    List<Spike> spikes_;                            // All Spike
    Finder<Spike> spike_finder_;                    // Spike finder
    std::set<const Spike*> spike_actualObj_;        // Spike in view

    // Mushrooms
    List<Mushroom> mushrooms_;                      // All Mushrooms
    Finder<Mushroom> mushroom_finder_;              // Mushroom finder
    std::set<const Mushroom*> mushroom_actualObj_;  // Mushroom in view

    // Goombas
    List<Goomba> goombas_;                          // All Goombas
    Finder<Goomba> goombas_finder_;                 // Goombas finder
    std::set<const Goomba*> goombas_actualObj_;     // Goombas in view

    // Stars
    List<Star> stars_;                              // All Stars
    Finder<Star> star_finder_;                      // Star finder
    std::set<const Star*> star_actualObj_;          // Star in view

    // Utils
    static const std::vector<std::vector<int>> option_pointer_sprite_;
    static const std::vector<std::vector<int>> finish_flag_sprite_;
    std::vector<std::pair<std::string, std::vector<std::string>>> instructions_ = {
        {"UP", {"`", "W"}}, {"DOWN", {",", "S"}}, {"LEFT", {"<", "A"}}, {"RIGHT", {">", "D"}},
        {"(UN)PAUSE", {"P"}}, {"QUIT", {"ESC"}}, {"CONTINUE", {"RETURN"}}
    };

    // Pre-game screen
    std::vector<std::string> pregame_options_ = {"1 PLAYER GAME", "2 PLAYER GAME"};
    std::vector<std::string>::iterator pregame_options_it_ = pregame_options_.begin();
    std::vector<pro2::Color> color_vec_ = {pro2::red, pro2::green, pro2::yellow, pro2::blue};
    bool single_player_ = false;

    // End-game screen
    std::vector<std::string> endgame_options_ = {"TRY AGAIN", "MENU", "QUIT"};
    std::vector<std::string>::iterator endgame_options_it_ = endgame_options_.begin();
    bool win_ = false;

    // Characters' immunity
    const int immunity_interval_ = 60;              // 1s at 60fps
    int immunity_mario_until_ = 0;
    int immunity_luigi_until_ = 0;
    bool immune_mario_ = false;    
    bool immune_luigi_ = false;

    // General states
    bool finished_ = false;                         // Game over flag
    bool paused_ = true;                            // Pause flag
    bool pregame_ = true;                           // Pre-game state
    bool endgame_ = false;                          // End-game state
    bool following_cam_ = false;                    // Vertical camera tracking state
    bool restarting_game_ = false;
    bool day_time_ = true;                          // Background status
    int frame_counter_ = 0;
    static const int day_night_interval_ = 900;     // 15s at 60fps

    // Screen size
    int width_;
    int height_;

    void process_keys(pro2::Window& window);        // Handle input
    void update_objects(pro2::Window& window);      // Update game logic
    void update_camera(pro2::Window& window);       // Adjust camera

 public:
    Game(int width, int height);                    // Constructor

    void update(pro2::Window& window);              // Per-frame update

    void paint(pro2::Window& window);               // Draw game

    bool is_finished() const { return finished_; }
};