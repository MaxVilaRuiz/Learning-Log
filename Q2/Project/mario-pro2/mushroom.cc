#include "mushroom.hh"
using namespace std;


// Color codes
const int _ = -1;
const int g = pro2::gray;
const int b = pro2::black;
const int l = pro2::light_gray;

// clang-format off
// Spike sprites
const vector<vector<int>> Mushroom::mushroom_sprite_ = {
    {_, _, _, _, b, _, _, _, _, _, _, _},
    {_, _, _, b, l, b, _, _, _, _, _, _},
    {_, _, _, b, l, b, _, _, _, _, _, _},
    {_, _, _, _, b, _, _, _, _, _, _, _},
    {_, _, _, b, l, b, _, _, _, _, _, _},
    {_, _, _, b, l, b, _, _, _, _, _, _},
    {_, _, b, l, l, l, b, _, _, _, _, _},
    {_, _, b, g, l, l, b, _, _, _, _, _},
    {_, b, g, g, g, l, l, b, _, _, _, _},
    {_, b, g, g, g, l, l, b, _, _, _, _},
    {b, g, g, g, g, g, l, l, b, _, _, _},
    {b, g, g, g, g, g, l, l, b, _, _, _},
};
// clang-format on


void Mushroom::paint(pro2::Window& window) const {
    paint_sprite(window, {pos_.x, pos_.y}, mushroom_sprite_, false);
}


void Mushroom::update() {
    int phase = (frame_ / animation_speed_) % 10;
    
    if (phase == 3 || phase == 4 || phase == 5) pos_.y += 1;
    else if (phase == 6 || phase == 7 || phase == 8) pos_.y -= 1;

    frame_++;
}


pro2::Rect Mushroom::get_rect() const {
    return {pos_.x - 10, pos_.y - 10, pos_.x + 10, pos_.y + 10};
}