#include "goomba.hh"
using namespace std;


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

// clang-format off
// Goomba sprites
const vector<vector<int>> Goomba::goomba_sprite_left_ = {
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
// clang-format on


void Goomba::paint(pro2::Window& window) const {
    const vector<vector<int>>* sprite = nullptr;
    const int phase = frame_ % 5;

    if (phase == 0) sprite = &goomba_sprite_left_; 
    else if (phase == 1) sprite = &goomba_sprite_left_;
    else if (phase == 2) sprite = &goomba_sprite_left_;
    else if (phase == 3) sprite = &goomba_sprite_left_;
    else &goomba_sprite_left_;
    
    paint_sprite(window, {actual_pos_, pos_.y}, *sprite, !to_right_);
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