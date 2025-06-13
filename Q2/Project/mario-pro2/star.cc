#include "star.hh"
using namespace std;
using namespace pro2;


const int _ = -1;
const int y = pro2::yellow; 
const int b = pro2::black;
const int w = pro2::white;
const int o = pro2::brown;
const int g = pro2::golden;

// clang-format off
const vector<vector<int>> Star::star_sprite_front_ = {
    {_, _, _, _, b, b, b, b, _, _, _, _},
    {_, _, _, b, y, y, y, y, b, _, _, _},
    {_, _, b, y, y, y, y, y, y, b, _, _},
    {_, b, y, y, y, y, y, y, y, y, b, _},
    {_, b, y, y, y, w, b, y, y, y, b, _},
    {b, y, y, y, y, w, b, y, y, y, y, b},
    {b, y, y, y, y, w, b, y, y, y, y, b},
    {b, y, y, y, y, w, b, y, y, y, y, b},
    {_, b, y, y, y, b, b, y, y, y, b, _},
    {_, b, y, y, y, y, y, y, y, y, b, _},
    {_, _, b, y, y, y, y, y, y, b, _, _},
    {_, _, _, b, y, y, y, y, b, _, _, _},
    {_, _, _, _, b, b, b, b, _, _, _, _},
};
const vector<vector<int>> Star::star_sprite_animation1_ = {
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, y, y, b, _, _, _, _, _},
    {_, _, _, y, y, y, y, b, _, _, _, _},
    {_, _, y, y, y, y, y, y, b, _, _, _},
    {_, _, y, y, y, y, y, y, b, _, _, _},
    {_, y, y, y, y, y, y, y, y, b, _, _},
    {_, y, y, y, y, y, y, y, y, b, _, _},
    {_, y, y, y, y, y, y, y, y, b, _, _},
    {_, _, y, y, y, y, y, y, b, _, _, _},
    {_, _, y, y, y, y, y, y, b, _, _, _},
    {_, _, _, y, y, y, y, b, _, _, _, _},
    {_, _, _, _, y, y, b, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
};
const vector<vector<int>> Star::star_sprite_animation2_ = {
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, y, y, b, _, _, _, _, _},
    {_, _, _, _, y, y, b, _, _, _, _, _},
    {_, _, _, y, y, y, y, b, _, _, _, _},
    {_, _, _, y, y, y, y, b, _, _, _, _},
    {_, _, _, y, y, y, y, b, _, _, _, _},
    {_, _, _, y, y, y, y, b, _, _, _, _},
    {_, _, _, y, y, y, y, b, _, _, _, _},
    {_, _, _, y, y, y, y, b, _, _, _, _},
    {_, _, _, y, y, y, y, b, _, _, _, _},
    {_, _, _, _, y, y, b, _, _, _, _, _},
    {_, _, _, _, y, y, b, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
};
const vector<vector<int>> Star::star_sprite_animation3_ = {
    {_, _, _, _, _, _, _, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, _, _, _, _, _, _, _, _},
};
// clang-format on


void Star::paint(pro2::Window& window) const {
    const std::vector<std::vector<int>>* sprite;
    const int phase = (frame_ / animation_speed_) % 12;
    int pos_y = pos_.y;

    if (phase == 0) sprite = &star_sprite_front_;
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
        sprite = &star_sprite_front_;
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
    int top = pos_.y + 2;
    int right = pos_.x + 12;
    int bottom = pos_.y + 20;
    return {left, top, right, bottom};    
}