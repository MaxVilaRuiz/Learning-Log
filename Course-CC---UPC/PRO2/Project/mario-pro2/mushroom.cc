#include "mushroom.hh"
using namespace std;


// Color codes
const int _ = -1;
const int r = pro2::red;
const int b = pro2::black;
const int w = pro2::white;

// clang-format off
// Spike sprites
const vector<vector<int>> Mushroom::mushroom_sprite_ = {
    {_, _, _, _, b, b, b, b, _, _, _, _},
    {_, _, _, b, r, r, w, w, b, _, _, _},
    {_, _, b, w, r, r, w, w, w, b, _, _},
    {_, b, w, w, r, r, r, r, r, r, b, _},
    {_, b, w, r, r, w, w, r, r, w, b, _},
    {b, w, r, r, w, w, w, w, r, w, w, b},
    {b, w, w, r, r, r, r, r, r, w, w, b},
    {b, w, r, b, b, b, b, b, b, r, w, b},
    {_, b, b, w, b, w, w, b, w, b, b, _},
    {_, b, w, w, b, w, w, b, w, w, b, _},
    {_, _, b, w, w, w, w, w, w, b, _, _},
    {_, _, _, b, b, b, b, b, b, _, _, _}
};
// clang-format on


void Mushroom::paint(pro2::Window& window) const {
    paint_sprite(window, {pos_.x, pos_.y}, mushroom_sprite_, false);
}


void Mushroom::update() {
    int phase = (frame_ / animation_speed_) % 12;
    
    if (phase == 10) pos_.y -= 1;
    else if (phase == 11) pos_.y += 1;

    frame_++;
}


pro2::Rect Mushroom::get_rect() const {
    return {pos_.x - 5, pos_.y - 5, pos_.x + 12, pos_.y + 10};
}