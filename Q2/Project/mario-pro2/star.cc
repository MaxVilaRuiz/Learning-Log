#include "star.hh"
using namespace std;
using namespace pro2;


const int _ = -1;
const int b = pro2::black;
const int r = pro2::red;
const int o = pro2::orange;
const int y = pro2::yellow; 
const int g = pro2::green;
const int u = pro2::blue;
const int p = pro2::purple;

// clang-format off
const vector<vector<int>> Star::star_sprite_front = {
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, b, r, b, _, _, _, _, _},
    {_, _, _, _, _, b, r, b, _, _, _, _, _},
    {_, _, _, _, b, r, r, o, b, _, _, _, _},
    {_, _, _, _, b, r, o, o, b, _, _, _, _},
    {b, b, b, b, r, o, o, y, y, b, b, b, b},
    {b, r, r, r, o, b, y, b, g, g, u, p, b},
    {_, b, r, o, o, b, y, b, g, u, p, b, _},
    {_, _, b, o, y, y, g, g, u, u, b, _, _},
    {_, _, b, y, y, g, g, u, u, p, b, _, _},
    {_, b, y, y, g, g, b, u, p, p, p, b, _},
    {_, b, y, g, b, b, _, b, b, p, p, b, _},
    {b, y, g, b, _, _, _, _, _, b, p, p, b},
    {b, b, b, _, _, _, _, _, _, _, b, b, b},    
};
const vector<vector<int>> Star::star_sprite_animation1_ = {
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, b, r, b, _, _, _, _, _},
    {_, _, _, _, _, b, r, b, _, _, _, _, _},
    {_, _, _, _, b, r, r, o, b, _, _, _, _},
    {_, _, _, _, b, r, r, o, b, _, _, _, _},
    {_, b, b, b, b, r, o, o, b, b, b, b, _},
    {_, b, r, r, r, o, o, y, y, g, u, b, _},
    {_, _, b, r, o, o, y, y, g, u, b, _, _},
    {_, _, _, b, o, y, y, g, u, b, _, _, _},
    {_, _, _, b, y, y, g, u, u, b, _, _, _},
    {_, _, b, y, y, g, b, u, u, p, b, _, _},
    {_, _, b, y, g, b, _, b, p, p, b, _, _},
    {_, b, y, g, b, _, _, _, b, p, p, b, _},
    {_, b, b, b, _, _, _, _, _, b, b, b, _}, 
};
const vector<vector<int>> Star::star_sprite_animation2_ = {
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, b, r, b, _, _, _, _, _},
    {_, _, _, _, _, b, r, b, _, _, _, _, _},
    {_, _, _, _, _, b, o, b, _, _, _, _, _},
    {_, _, _, _, b, r, o, y, b, _, _, _, _},
    {_, _, b, b, b, o, y, g, b, b, b, _, _},
    {_, _, b, r, r, o, y, g, u, u, b, _, _},
    {_, _, _, b, r, o, y, g, u, b, _, _, _},
    {_, _, _, _, b, o, y, g, b, _, _, _, _},
    {_, _, _, _, b, o, g, u, b, _, _, _, _},
    {_, _, _, b, o, y, b, p, p, b, _, _, _},
    {_, _, _, b, y, b, _, b, p, b, _, _, _},
    {_, _, b, y, y, b, _, b, p, p, b, _, _},
    {_, _, b, b, b, _, _, _, b, b, b, _, _}, 
};
const vector<vector<int>> Star::star_sprite_animation3_ = {
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, b, r, b, _, _, _, _, _},
    {_, _, _, _, _, b, r, b, _, _, _, _, _},
    {_, _, _, _, _, b, o, b, _, _, _, _, _},
    {_, _, _, b, b, r, o, y, b, b, _, _, _},
    {_, _, _, b, r, r, o, y, g, b, _, _, _},
    {_, _, _, _, b, o, o, y, b, _, _, _, _},
    {_, _, _, _, b, o, y, g, b, _, _, _, _},
    {_, _, _, _, b, y, g, u, b, _, _, _, _},
    {_, _, _, _, b, g, b, u, b, _, _, _, _},
    {_, _, _, b, y, b, _, b, p, b, _, _, _},
    {_, _, _, b, g, b, _, b, p, b, _, _, _},
    {_, _, _, b, b, _, _, _, b, b, _, _, _}, 
};
const vector<vector<int>> Star::star_sprite_animation4_ = {
    {_, _, _, _, _, _, _, _, _, _, _, _, _},
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, _, _, _, _, _, _, _, _},
};
// clang-format on


void Star::paint(pro2::Window& window) const {
    const std::vector<std::vector<int>>* sprite;
    const int phase = (frame_ / animation_speed_) % 12;
    int pos_y = pos_.y;

    if (phase == 0) sprite = &star_sprite_front;
    else if (phase == 1) {
        sprite = &star_sprite_animation1_;
        pos_y -= 1;
    }
    else if (phase == 2) {
        sprite = &star_sprite_animation2_;
        pos_y -= 2;
    }
    else if (phase == 3) {
        sprite = &star_sprite_animation3_;
        pos_y -= 3;
    }
    else if (phase == 4) {
        sprite = &star_sprite_animation2_;
        pos_y -= 4;
    }
    else if (phase == 5) {
        sprite = &star_sprite_animation1_;
        pos_y -= 5;
    }
    else if (phase == 6) {
        sprite = &star_sprite_front;
        pos_y -= 5;
    }
    else if (phase == 7) {
        sprite = &star_sprite_animation1_;
        pos_y -= 4;
    }
    else if (phase == 8) {
        sprite = &star_sprite_animation2_;
        pos_y -= 3;
    }
    else if (phase == 9) {
        sprite = &star_sprite_animation3_;
        pos_y -= 2;
    }
    else if (phase == 10) {
        sprite = &star_sprite_animation2_;
        pos_y -= 1;
    }
    else sprite = &star_sprite_animation1_;

    paint_sprite(window, {pos_.x, pos_y}, *sprite, false);
}


void Star::update() {
    frame_++;
}


pro2::Rect Star::get_rect() const {
    int left = pos_.x;
    int top = pos_.y - 5;
    int right = pos_.x + 15;
    int bottom = pos_.y + 20;
    return {left, top, right, bottom};    
}