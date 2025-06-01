#include "goomba.hh"
using namespace std;


// Color codes
const int _ = -1;
const int s = pro2::beige;
const int b = pro2::black;
const int w = pro2::brown;

// clang-format off
// Goomba sprites
const vector<vector<int>> Goomba::goomba_sprite_normal_ = {
    {_, _, _, w, w, w, w, _, _, _},
    {_, _, w, b, w, w, b, w, _, _},
    {_, w, s, w, b, b, w, s, w, _},
    {w, w, s, b, s, s, b, s, w, w},
    {w, w, s, b, s, s, b, s, w, w},
    {w, w, w, w, w, w, w, w, w, w},
    {_, w, w, w, s, s, w, w, w, _},
    {_, _, s, s, s, s, s, s, _, _},
    {_, b, b, b, s, s, b, b, b, _},
    {b, b, b, b, _, _, b, b, b, b},
};

const vector<vector<int>> Goomba::goomba_sprite_walk1_ = {
    {_, _, _, w, w, w, w, _, _, _},
    {_, _, w, b, w, w, b, w, _, _},
    {_, w, s, w, b, b, w, s, w, _},
    {w, w, s, b, s, s, b, s, w, w},
    {w, w, s, b, s, s, b, s, w, w},
    {w, w, w, w, w, w, w, w, w, w},
    {_, w, w, w, s, s, w, w, w, _},
    {_, _, s, s, s, s, s, s, _, _},
    {_, b, b, b, s, s, b, b, b, b},
    {_, b, b, b, _, _, b, b, b, b},
};

const vector<vector<int>> Goomba::goomba_sprite_walk2_ = {
    {_, _, _, w, w, w, w, _, _, _},
    {_, _, w, b, w, w, b, w, _, _},
    {_, w, s, w, b, b, w, s, w, _},
    {w, w, s, b, s, s, b, s, w, w},
    {w, w, s, b, s, s, b, s, w, w},
    {w, w, w, w, w, w, w, w, w, w},
    {_, w, w, w, s, s, w, w, w, _},
    {_, _, s, s, s, s, s, s, _, _},
    {b, b, b, b, s, s, b, b, b, _},
    {b, b, b, b, _, _, b, b, b, _},
};
// clang-format on


void Goomba::paint(pro2::Window& window) {
    const vector<vector<int>>* sprite = nullptr;
    const int phase = frame_ % 4;

    if (phase == 0) sprite = &goomba_sprite_normal_; 
    else if (phase == 1) sprite = &goomba_sprite_walk1_;
    else if (phase == 2) sprite = &goomba_sprite_normal_;
    else sprite = &goomba_sprite_walk2_;
    
    paint_sprite(window, {actual_pos_, pos_.y}, *sprite, false);
    frame_++;
}


void Goomba::move() {
    if (to_right_) {
        if (pos_.x + travel_ <= actual_pos_) {
            to_right_ = false;
            actual_pos_ -= speed_;
        }
        else actual_pos_ += speed_;
    }
    else {
        if (actual_pos_ <= pos_.x - travel_) {
            to_right_ = true;
            actual_pos_ += speed_;
        }
        else actual_pos_ -= speed_;
    }
}


pro2::Rect Goomba::get_rect() const {
    int left = actual_pos_ - 10;
    int top = pos_.y - 10;
    int right = actual_pos_ + 10;
    int bottom = pos_.y + 10;
    return {left, top, right, bottom};
}