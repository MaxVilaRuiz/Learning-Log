#include "main_char.hh"
#include "utils.hh"
using namespace std;
using namespace pro2;


// Color codes
const int _ = -1;
const int r = pro2::red;
const int s = pro2::beige;
const int b = pro2::blue;
const int y = pro2::yellow;
const int h = pro2::black;
const int g = pro2::gray;
const int w = pro2::brown;
const int e = pro2::green;
const int i = pro2::white;
const int o = pro2::orange;
const int p = pro2::purple;

// clang-format off
// Mario sprites
const vector<vector<int>> MainChar::mario_sprite_normal_ = {
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, r, b, r, r, r, _, _, _, _},
    {_, r, r, r, b, r, r, b, r, r, r, _},
    {r, r, r, r, b, b, b, b, r, r, r, r},
    {g, g, r, b, y, b, b, y, b, r, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {w, w, w, w, _, _, _, _, w, w, w, w},
};
const vector<vector<int>> MainChar::mario_sprite_medium_ = {
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, r, b, r, r, r, _, _, _, _},
    {_, r, r, r, b, r, r, b, r, r, r, _},
    {r, r, r, r, b, b, b, b, r, r, r, r},
    {r, r, r, b, y, b, b, y, b, r, r, r},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {w, w, w, w, _, _, _, _, w, w, w, w},
};
const vector<vector<int>> MainChar::mario_sprite_big_ = {
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, r, b, r, r, r, _, _, _, _},
    {_, r, r, r, b, r, r, b, r, r, r, _},
    {r, r, r, r, b, b, b, b, r, r, r, r},
    {r, r, r, b, b, b, b, b, b, r, r, r},
    {r, r, b, b, y, b, b, y, b, b, r, r},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {w, w, w, w, _, _, _, _, w, w, w, w},
};
const vector<vector<int>> MainChar::mario_sprite_normal_walk1_ = {
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, r, b, r, r, r, _, _, _, _},
    {_, r, r, r, b, r, r, b, r, r, r, _},
    {r, r, r, r, b, b, b, b, r, r, r, r},
    {g, g, r, b, y, b, b, y, b, r, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {_, w, w, w, w, _, _, _, w, w, w, w},
};
const vector<vector<int>> MainChar::mario_sprite_normal_walk2_ = {
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, _, r, b, r, r, r, r, _, _, _},
    {_, _, r, r, b, r, r, b, r, r, _, _},
    {_, _, r, r, b, b, b, b, r, r, _, _},
    {_, _, g, g, b, b, b, y, b, r, _, _},
    {_, _, g, g, g, b, b, b, b, g, _, _},
    {_, _, g, g, b, b, b, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, w, w, w, _, _, w, w, w, _, _},
    {_, _, w, w, w, w, _, w, w, w, w, _},
};
const vector<vector<int>> MainChar::mario_sprite_normal_walk3_ = {
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, _, b, b, r, r, b, b, _, _, _},
    {_, _, _, b, b, r, r, b, b, _, _, _},
    {_, _, _, b, b, r, r, b, b, _, _, _},
    {_, _, _, b, b, g, g, b, b, _, _, _},
    {_, _, b, b, b, g, g, g, b, b, _, _},
    {_, _, b, b, b, g, g, b, b, b, _, _},
    {_, _, _, _, b, b, b, b, _, _, _, _},
    {_, _, _, _, w, w, w, w, _, _, _, _},
    {_, _, _, _, w, w, w, w, w, _, _, _},
};
const vector<vector<int>> MainChar::mario_sprite_big_walk1_ = {
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, r, b, r, r, r, _, _, _, _},
    {_, r, r, r, b, r, r, b, r, r, r, _},
    {r, r, r, r, b, b, b, b, r, r, r, r},
    {r, r, r, b, b, b, b, b, b, r, r, r},
    {r, r, b, b, y, b, b, y, b, b, r, r},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {_, w, w, w, w, _, _, _, w, w, w, w},
};
const vector<vector<int>> MainChar::mario_sprite_big_walk2_ = {
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, _, r, b, r, r, r, r, _, _, _},
    {_, _, r, r, b, r, r, b, r, r, _, _},
    {_, _, r, r, b, r, r, b, r, r, _, _},
    {_, _, r, r, b, b, b, b, r, r, _, _},
    {_, _, b, b, b, b, b, y, b, r, _, _},
    {_, _, g, g, b, b, b, b, b, r, _, _},
    {_, _, g, g, g, b, b, b, b, g, _, _},
    {_, _, g, g, b, b, b, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, w, w, w, _, _, w, w, w, _, _},
    {_, _, w, w, w, w, _, w, w, w, w, _},
};
const vector<vector<int>> MainChar::mario_sprite_big_walk3_ = {
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, _, b, b, r, r, b, b, _, _, _},
    {_, _, _, b, b, r, r, b, b, _, _, _},
    {_, _, _, b, b, r, r, b, b, _, _, _},
    {_, _, _, b, b, r, r, b, b, _, _, _},
    {_, _, _, b, b, g, g, b, b, _, _, _},
    {_, _, b, b, b, g, g, g, b, b, _, _},
    {_, _, b, b, b, g, g, b, b, b, _, _},
    {_, _, b, b, b, g, g, b, b, b, _, _},
    {_, _, _, _, b, b, b, b, _, _, _, _},
    {_, _, _, _, b, b, b, b, _, _, _, _},
    {_, _, _, _, b, b, b, b, _, _, _, _},
    {_, _, _, _, w, w, w, w, _, _, _, _},
    {_, _, _, _, w, w, w, w, w, _, _, _},
};

// Luigi sprites
const vector<vector<int>> MainChar::luigi_sprite_normal_ = {
    {_, _, _, e, e, e, e, e, _, _, _, _},
    {_, _, e, e, e, e, e, e, e, e, e, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, e, e, b, e, e, e, _, _, _, _},
    {_, e, e, e, b, e, e, b, e, e, e, _},
    {e, e, e, e, b, b, b, b, e, e, e, e},
    {g, g, e, b, y, b, b, y, b, e, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {w, w, w, w, _, _, _, _, w, w, w, w},
};
const vector<vector<int>> MainChar::luigi_sprite_medium_ = {
    {_, _, _, e, e, e, e, e, _, _, _, _},
    {_, _, e, e, e, e, e, e, e, e, e, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, e, e, b, e, e, e, _, _, _, _},
    {_, e, e, e, b, e, e, b, e, e, e, _},
    {e, e, e, e, b, b, b, b, e, e, e, e},
    {e, e, e, b, y, b, b, y, b, e, e, e},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {w, w, w, w, _, _, _, _, w, w, w, w},
};
const vector<vector<int>> MainChar::luigi_sprite_big_ = {
    {_, _, _, e, e, e, e, e, _, _, _, _},
    {_, _, e, e, e, e, e, e, e, e, e, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, e, e, b, e, e, e, _, _, _, _},
    {_, e, e, e, b, e, e, b, e, e, e, _},
    {e, e, e, e, b, b, b, b, e, e, e, e},
    {e, e, e, b, b, b, b, b, b, e, e, e},
    {e, e, b, b, y, b, b, y, b, b, e, e},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {w, w, w, w, _, _, _, _, w, w, w, w},
};
const vector<vector<int>> MainChar::luigi_sprite_normal_walk1_ = {
    {_, _, _, e, e, e, e, e, _, _, _, _},
    {_, _, e, e, e, e, e, e, e, e, e, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, e, e, b, e, e, e, _, _, _, _},
    {_, e, e, e, b, e, e, b, e, e, e, _},
    {e, e, e, e, b, b, b, b, e, e, e, e},
    {g, g, e, b, y, b, b, y, b, e, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {_, w, w, w, w, _, _, _, w, w, w, w},
};
const vector<vector<int>> MainChar::luigi_sprite_normal_walk2_ = {
    {_, _, _, e, e, e, e, e, _, _, _, _},
    {_, _, e, e, e, e, e, e, e, e, e, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, _, e, b, e, e, e, e, _, _, _},
    {_, _, e, e, b, e, e, b, e, e, _, _},
    {_, _, e, e, b, b, b, b, e, e, _, _},
    {_, _, g, g, b, b, b, y, b, e, _, _},
    {_, _, g, g, g, b, b, b, b, g, _, _},
    {_, _, g, g, b, b, b, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, w, w, w, _, _, w, w, w, _, _},
    {_, _, w, w, w, w, _, w, w, w, w, _},
};
const vector<vector<int>> MainChar::luigi_sprite_normal_walk3_ = {
    {_, _, _, e, e, e, e, e, _, _, _, _},
    {_, _, e, e, e, e, e, e, e, e, e, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, _, b, b, e, e, b, b, _, _, _},
    {_, _, _, b, b, e, e, b, b, _, _, _},
    {_, _, _, b, b, e, e, b, b, _, _, _},
    {_, _, _, b, b, g, g, b, b, _, _, _},
    {_, _, b, b, b, g, g, g, b, b, _, _},
    {_, _, b, b, b, g, g, b, b, b, _, _},
    {_, _, _, _, b, b, b, b, _, _, _, _},
    {_, _, _, _, w, w, w, w, _, _, _, _},
    {_, _, _, _, w, w, w, w, w, _, _, _},
};
const vector<vector<int>> MainChar::luigi_sprite_big_walk1_ = {
    {_, _, _, e, e, e, e, e, _, _, _, _},
    {_, _, e, e, e, e, e, e, e, e, e, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, e, e, b, e, e, e, _, _, _, _},
    {_, e, e, e, b, e, e, b, e, e, e, _},
    {e, e, e, e, b, b, b, b, e, e, e, e},
    {e, e, e, b, b, b, b, b, b, e, e, e},
    {e, e, b, b, y, b, b, y, b, b, e, e},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {_, w, w, w, w, _, _, _, w, w, w, w},
};
const vector<vector<int>> MainChar::luigi_sprite_big_walk2_ = {
    {_, _, _, e, e, e, e, e, _, _, _, _},
    {_, _, e, e, e, e, e, e, e, e, e, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, _, e, b, e, e, e, e, _, _, _},
    {_, _, e, e, b, e, e, b, e, e, _, _},
    {_, _, e, e, b, e, e, b, e, e, _, _},
    {_, _, e, e, b, b, b, b, e, e, _, _},
    {_, _, b, b, b, b, b, y, b, e, _, _},
    {_, _, g, g, b, b, b, b, b, e, _, _},
    {_, _, g, g, g, b, b, b, b, g, _, _},
    {_, _, g, g, b, b, b, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, w, w, w, _, _, w, w, w, _, _},
    {_, _, w, w, w, w, _, w, w, w, w, _},
};
const vector<vector<int>> MainChar::luigi_sprite_big_walk3_ = {
    {_, _, _, e, e, e, e, e, _, _, _, _},
    {_, _, e, e, e, e, e, e, e, e, e, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, _, b, b, e, e, b, b, _, _, _},
    {_, _, _, b, b, e, e, b, b, _, _, _},
    {_, _, _, b, b, e, e, b, b, _, _, _},
    {_, _, _, b, b, e, e, b, b, _, _, _},
    {_, _, _, b, b, g, g, b, b, _, _, _},
    {_, _, b, b, b, g, g, g, b, b, _, _},
    {_, _, b, b, b, g, g, b, b, b, _, _},
    {_, _, b, b, b, g, g, b, b, b, _, _},
    {_, _, _, _, b, b, b, b, _, _, _, _},
    {_, _, _, _, b, b, b, b, _, _, _, _},
    {_, _, _, _, b, b, b, b, _, _, _, _},
    {_, _, _, _, w, w, w, w, _, _, _, _},
    {_, _, _, _, w, w, w, w, w, _, _, _},
};

// Star mode
const vector<vector<int>> MainChar::starmode_sprite_normal_ = {
    {_, _, _, r, o, o, y, e, _, _, _, _},
    {_, _, r, r, o, y, y, e, e, p, p, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, o, b, e, e, e, _, _, _, _},
    {_, r, o, y, b, e, e, b, e, p, p, _},
    {r, r, o, y, b, b, b, b, p, p, p, p},
    {g, g, y, b, y, b, b, y, b, p, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {w, w, w, w, _, _, _, _, w, w, w, w},
};
const vector<vector<int>> MainChar::starmode_sprite_medium_ = {
    {_, _, _, r, r, o, y, y, _, _, _, _},
    {_, _, r, r, o, o, y, e, e, p, p, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, o, b, y, y, e, _, _, _, _},
    {_, r, r, o, b, y, e, b, e, e, p, _},
    {r, r, o, o, b, b, b, b, e, p, p, p},
    {r, o, o, b, y, b, b, y, b, p, p, p},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {w, w, w, w, _, _, _, _, w, w, w, w},
};
const vector<vector<int>> MainChar::starmode_sprite_big_ = {
    {_, _, _, r, r, o, y, y, _, _, _, _},
    {_, _, r, r, o, o, y, e, e, p, p, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, o, b, y, y, e, _, _, _, _},
    {_, r, r, o, b, y, e, b, e, e, p, _},
    {r, r, o, o, b, b, b, b, e, e, p, p},
    {r, o, o, b, b, b, b, b, b, p, p, p},
    {o, o, b, b, y, b, b, y, b, b, p, p},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {w, w, w, w, _, _, _, _, w, w, w, w},
};
const vector<vector<int>> MainChar::starmode_sprite_normal_walk1_ = {
    {_, _, _, o, o, y, y, e, _, _, _, _},
    {_, _, o, o, y, y, e, p, p, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, o, y, b, e, e, p, _, _, _, _},
    {_, o, o, y, b, e, e, b, p, p, r, _},
    {o, y, y, y, b, b, b, b, p, r, r, r},
    {g, g, y, b, y, b, b, y, b, r, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {_, w, w, w, w, _, _, _, w, w, w, w},
};
const vector<vector<int>> MainChar::starmode_sprite_normal_walk2_ = {
    {_, _, _, y, y, e, e, p, _, _, _, _},
    {_, _, y, y, e, e, p, p, r, r, o, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, _, y, b, e, p, p, r, _, _, _},
    {_, _, y, e, b, e, p, b, r, o, _, _},
    {_, _, y, e, b, b, b, b, r, o, _, _},
    {_, _, g, g, b, b, b, y, b, o, _, _},
    {_, _, g, g, g, b, b, b, b, g, _, _},
    {_, _, g, g, b, b, b, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, w, w, w, _, _, w, w, w, _, _},
    {_, _, w, w, w, w, _, w, w, w, w, _},
};
const vector<vector<int>> MainChar::starmode_sprite_normal_walk3_ = {
    {_, _, _, e, e, p, r, r, _, _, _, _},
    {_, _, e, e, p, p, r, o, o, y, y, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, _, b, b, e, p, b, b, _, _, _},
    {_, _, _, b, b, r, o, b, b, _, _, _},
    {_, _, _, b, b, y, p, b, b, _, _, _},
    {_, _, _, b, b, g, g, b, b, _, _, _},
    {_, _, b, b, b, g, g, g, b, b, _, _},
    {_, _, b, b, b, g, g, b, b, b, _, _},
    {_, _, _, _, b, b, b, b, _, _, _, _},
    {_, _, _, _, w, w, w, w, _, _, _, _},
    {_, _, _, _, w, w, w, w, w, _, _, _},
};
const vector<vector<int>> MainChar::starmode_sprite_big_walk1_ = {
    {_, _, _, o, o, y, e, e, _, _, _, _},
    {_, _, o, o, y, y, e, p, p, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, o, y, b, e, e, e, _, _, _, _},
    {_, o, o, y, b, e, e, b, p, p, r, _},
    {o, o, y, y, b, b, b, b, p, p, r, r},
    {o, y, y, b, b, b, b, b, b, p, r, r},
    {y, y, b, b, y, b, b, y, b, b, r, r},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {_, w, w, w, w, _, _, _, w, w, w, w},
};
const vector<vector<int>> MainChar::starmode_sprite_big_walk2_ = {
    {_, _, _, y, y, e, p, p, _, _, _, _},
    {_, _, y, y, e, e, p, r, r, o, o, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, _, e, b, p, r, r, r, _, _, _},
    {_, _, y, e, b, p, r, b, r, o, _, _},
    {_, _, y, e, b, p, p, b, r, o, _, _},
    {_, _, y, e, b, b, b, b, o, o, _, _},
    {_, _, b, b, b, b, b, y, b, o, _, _},
    {_, _, g, g, b, b, b, b, b, o, _, _},
    {_, _, g, g, g, b, b, b, b, g, _, _},
    {_, _, g, g, b, b, b, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, _, w, w, w, _, _, w, w, w, _, _},
    {_, _, w, w, w, w, _, w, w, w, w, _},
};
const vector<vector<int>> MainChar::starmode_sprite_big_walk3_ = {
    {_, _, _, e, e, p, r, r, _, _, _, _},
    {_, _, e, e, p, p, r, o, o, y, y, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, _, b, b, e, p, b, b, _, _, _},
    {_, _, _, b, b, r, o, b, b, _, _, _},
    {_, _, _, b, b, y, e, b, b, _, _, _},
    {_, _, _, b, b, o, p, b, b, _, _, _},
    {_, _, _, b, b, g, g, b, b, _, _, _},
    {_, _, b, b, b, g, g, g, b, b, _, _},
    {_, _, b, b, b, g, g, b, b, b, _, _},
    {_, _, b, b, b, g, g, b, b, b, _, _},
    {_, _, _, _, b, b, b, b, _, _, _, _},
    {_, _, _, _, b, b, b, b, _, _, _, _},
    {_, _, _, _, b, b, b, b, _, _, _, _},
    {_, _, _, _, w, w, w, w, _, _, _, _},
    {_, _, _, _, w, w, w, w, w, _, _, _},
};

// Lives sprite
const vector<vector<int>> MainChar::mario_lives_sprite_ = {
    {_, _, _, _, _, _, _, _, _, _, _, _},
    {_, _, _, h, h, h, _, h, h, h, _, _},
    {_, _, h, r, r, r, h, r, r, r, h, _},
    {_, h, r, i, i, r, h, r, r, r, r, h},
    {_, h, r, i, r, r, r, r, r, r, r, h},
    {_, h, r, i, r, r, r, r, r, r, r, h},
    {_, h, r, r, r, r, r, r, r, r, r, h},
    {_, _, h, r, r, r, r, r, r, r, h, _},
    {_, _, _, h, r, r, r, r, r, h, _, _},
    {_, _, _, _, h, r, r, r, h, _, _, _},
    {_, _, _, _, _, h, r, h, _, _, _, _},
    {_, _, _, _, _, _, h, _, _, _, _, _},
    {_, _, _, _, _, _, _, _, _, _, _, _},    
};
const vector<vector<int>> MainChar::luigi_lives_sprite_ = {
    {_, _, _, _, _, _, _, _, _, _, _, _},
    {_, _, _, h, h, h, _, h, h, h, _, _},
    {_, _, h, e, e, e, h, e, e, e, h, _},
    {_, h, e, i, i, e, h, e, e, e, e, h},
    {_, h, e, i, e, e, e, e, e, e, e, h},
    {_, h, e, i, e, e, e, e, e, e, e, h},
    {_, h, e, e, e, e, e, e, e, e, e, h},
    {_, _, h, e, e, e, e, e, e, e, h, _},
    {_, _, _, h, e, e, e, e, e, h, _, _},
    {_, _, _, _, h, e, e, e, h, _, _, _},
    {_, _, _, _, _, h, e, h, _, _, _, _},
    {_, _, _, _, _, _, h, _, _, _, _, _},
    {_, _, _, _, _, _, _, _, _, _, _, _},    
};
// clang-format on


void MainChar::paint(pro2::Window& window, bool immune, int frame) const {
    Pt pos = {pos_.x - 6, pos_.y - 15};
    const vector<vector<int>>* sprite = nullptr;
    if (0 < star_counter_) {
        if (0 < growth_counter_) {
            pos.y -= 3;
            bool phase = 4 < (growth_counter_ % 10);
    
            if (30 < growth_counter_) sprite = phase ? &starmode_sprite_medium_ : &starmode_sprite_normal_;
            else sprite = phase ? &starmode_sprite_big_ : &starmode_sprite_medium_;

            paint_sprite(window, pos, *sprite, looking_left_);
        }
        else if (0 < decrease_counter_) {
            pos.y -= 3;
    
            if (!immune || (immune && (frame % 2 == 0))) {
                bool phase = 4 < (decrease_counter_ % 10);
    
                if (30 < decrease_counter_) sprite = phase ? &starmode_sprite_medium_ : &starmode_sprite_big_;
                else sprite = phase ? &starmode_sprite_normal_ : &starmode_sprite_medium_;
                
                paint_sprite(window, pos, *sprite, looking_left_);
            }
        }
        else {
            if (!immune || (immune && (frame % 2 == 0))) {
                if (big_) {
                    pos.y -= 4;
                    if (speed_.x != 0) {
                        int phase = (animation_counter_ / animation_speed_) % 3;
                        if (phase == 0) sprite = &starmode_sprite_big_walk1_;
                        else if (phase == 1) sprite = &starmode_sprite_big_walk2_;
                        else sprite = &starmode_sprite_big_walk3_;
                    }
                    else sprite = &starmode_sprite_big_;
                }
                else {
                    if (speed_.x != 0) {
                        int phase = (animation_counter_ / animation_speed_) % 3;
                        if (phase == 0) sprite = &starmode_sprite_normal_walk1_;
                        else if (phase == 1) sprite = &starmode_sprite_normal_walk2_;
                        else sprite = &starmode_sprite_normal_walk3_;
                    }
                    else sprite = &starmode_sprite_normal_;   
                }

                paint_sprite(window, pos, *sprite, looking_left_);
            }
        }
    }
    else {
        if (0 < growth_counter_) {
            pos.y -= 3;
            bool phase = 4 < (growth_counter_ % 10);
    
            if (character_ == "mario") {
                if (30 < growth_counter_) sprite = phase ? &mario_sprite_medium_ : &mario_sprite_normal_;
                else sprite = phase ? &mario_sprite_big_ : &mario_sprite_medium_;
            }
            else {
                if (30 < growth_counter_) sprite = phase ? &luigi_sprite_medium_ : &luigi_sprite_normal_;
                else sprite = phase ? &luigi_sprite_big_ : &luigi_sprite_medium_;
            }
            paint_sprite(window, pos, *sprite, looking_left_);
        }
        else if (0 < decrease_counter_) {
            pos.y -= 3;
    
            if (!immune || (immune && (frame % 2 == 0))) {
                bool phase = 4 < (decrease_counter_ % 10);
    
                if (character_ == "mario") {
                    if (30 < decrease_counter_) sprite = phase ? &mario_sprite_medium_ : &mario_sprite_big_;
                    else sprite = phase ? &mario_sprite_normal_ : &mario_sprite_medium_;
                }
                else {
                    if (30 < decrease_counter_) sprite = phase ? &luigi_sprite_medium_ : &luigi_sprite_big_;
                    else sprite = phase ? &luigi_sprite_normal_ : &luigi_sprite_medium_;
                }
                
                paint_sprite(window, pos, *sprite, looking_left_);
            }
        }
        else {
            if (!immune || (immune && (frame % 2 == 0))) {
                if (character_ == "mario") {
                    if (big_) {
                        pos.y -= 4;
                        if (speed_.x != 0) {
                            int phase = (animation_counter_ / animation_speed_) % 3;
                            if (phase == 0) sprite = &mario_sprite_big_walk1_;
                            else if (phase == 1) sprite = &mario_sprite_big_walk2_;
                            else sprite = &mario_sprite_big_walk3_;
                        }
                        else sprite = &mario_sprite_big_;
                    }
                    else {
                        if (speed_.x != 0) {
                            int phase = (animation_counter_ / animation_speed_) % 3;
                            if (phase == 0) sprite = &mario_sprite_normal_walk1_;
                            else if (phase == 1) sprite = &mario_sprite_normal_walk2_;
                            else sprite = &mario_sprite_normal_walk3_;
                        }
                        else sprite = &mario_sprite_normal_;   
                    }
                }
                else {
                    if (big_) {
                        pos.y -= 4;
                        if (speed_.x != 0) {
                            int phase = (animation_counter_ / animation_speed_) % 3;
                            if (phase == 0) sprite = &luigi_sprite_big_walk1_;
                            else if (phase == 1) sprite = &luigi_sprite_big_walk2_;
                            else sprite = &luigi_sprite_big_walk3_;
                        }
                        else sprite = &luigi_sprite_big_;
                    }
                    else {
                        if (speed_.x != 0) {
                            int phase = (animation_counter_ / animation_speed_) % 3;
                            if (phase == 0) sprite = &luigi_sprite_normal_walk1_;
                            else if (phase == 1) sprite = &luigi_sprite_normal_walk2_;
                            else sprite = &luigi_sprite_normal_walk3_;
                        }
                        else sprite = &luigi_sprite_normal_;
                    }
                }
                paint_sprite(window, pos, *sprite, looking_left_);
            }
        }
    }
}


void MainChar::paint_lives(pro2::Window& window, string character) const {
    if (character == "mario") {
        const pro2::Pt top_left = {window.camera_rect().left + 5, window.camera_rect().top + 5};

        for (int i = 0; i < lives_; i++) {
            paint_sprite(window, {top_left.x + 15*i, top_left.y}, mario_lives_sprite_, false);
        }
    }
    else {
        const pro2::Pt top_left = {window.camera_rect().left + 5, window.camera_rect().top + 20};

        for (int i = 0; i < lives_; i++) {
            paint_sprite(window, {top_left.x + 15*i, top_left.y}, luigi_lives_sprite_, false);
        }
    }
}


void MainChar::apply_physics_() {
    if (grounded_) {
        speed_.y = 0;
        accel_.y = 0;
        last_grounded_pos_ = pos_;
    }

    // Gravity pull
    const int gravity = 1;
    speed_.y += gravity;

    if (accel_time_ > 0) {
        speed_.y += accel_.y;
        accel_time_--;
    }

    pos_.x += speed_.x;
    pos_.y += speed_.y;
}


void MainChar::jump() {
    if (grounded_) {
        accel_.y = (star_mode_) ? -7 : -6;
        accel_time_ = 2;
        grounded_ = false;
    }
}


void MainChar::update(pro2::Window& window, std::set<const Platform*> platforms, std::set<const Spike*> spikes) {
    if (0 < growth_counter_) growth_counter_--;
    else if (0 < decrease_counter_) decrease_counter_--;
    else {
        if (0 < star_counter_) star_counter_--;
        else if (star_counter_ == 0) star_mode_ = false;

        last_pos_ = pos_;
    
        // Repositioning the character if out of bounds
        pro2::Rect char_rec = rect();
        pro2::Rect cam_rec = window.camera_rect();
        if (pos_.x < 5) pos_.x = 5;

        // Repositioning the secondary characters on the screen
        if (character_ != "mario") {
            // Horizontal position
            if (char_rec.right < cam_rec.left) pos_.x = cam_rec.left;
            else if (char_rec.left > cam_rec.right) pos_.x = cam_rec.right;
            else pos_.x = last_pos_.x;
        }
    
        if (window.is_key_down(jump_key_)) {
            jump();
        }
    
        // Horizontal speed
        speed_.x = 0;
        if (window.is_key_down(left_key_)) speed_.x = (star_mode_) ? -5 : -4;
        else if (window.is_key_down(right_key_)) speed_.x = (star_mode_) ? 5 : 4;
    
        if (speed_.x != 0) {
            looking_left_ = speed_.x < 0;
            animation_counter_++;
        }
        else animation_counter_ = 0;
    
        if (pos_.x == last_pos_.x && pos_.y == last_pos_.y) apply_physics_();
        set_grounded(false);
    
        // Check grounded on platforms 
        for (const Platform* platform : platforms) {
            if (!window.is_key_down(down_key_)) {
                if (platform->has_crossed_floor_downwards(last_pos_, pos_)) {
                    set_grounded(true);
                    set_y(platform->top());
                }
            }
        }
    
        // Check grounded on spikes
        for (const Spike* spike : spikes) {
            if (spike->above_spike(last_pos_, pos_)) {
                set_grounded(true);
                set_y(spike->get_rect().top);
            }
        }
    }
}


pro2::Rect MainChar::rect() const {
    return pro2::Rect({pos_.x - 6, pos_.y - 15, pos_.x + 6, pos_.y + 15});
}


int MainChar::lives() const {
    return lives_;
}


void MainChar::lose_life() {
    if (0 < lives_) {
        lives_--;
        remove_starmode();
        if (big_) {
            big_ = false;
            decrease_counter_ = 60; // 1s at 60fps
        }
    }
}


void MainChar::reset_position(pro2::Pt new_pos) {
    pos_ = new_pos;
    speed_ = {0, 0};
    accel_ = {0, 0};
    grounded_ = false;
}


void MainChar::handle_mushroom() {
    if (!big_) {
        big_ = true;
        growth_counter_ = 60; // 1s at 60fps
    }
}


void MainChar::handle_star() {
    star_counter_ = 600; // 10s at 60fps
    star_mode_ = true;
}


void MainChar::remove_starmode() {
    star_mode_ = false;
    star_counter_ = 0;
}