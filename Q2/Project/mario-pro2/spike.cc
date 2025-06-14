#include "spike.hh"
using namespace std;


// Color codes
const int _ = -1;
const int g = pro2::gray;
const int b = pro2::black;
const int l = pro2::light_gray;

// clang-format off
// Spike sprites
const vector<vector<int>> Spike::spike_sprite_ = {
    {_, _, _, _, b, _, _, _, _},
    {_, _, _, b, l, b, _, _, _},
    {_, _, _, b, l, b, _, _, _},
    {_, _, b, l, l, l, b, _, _},
    {_, _, b, g, l, l, b, _, _},
    {_, b, g, g, g, l, l, b, _},
    {_, b, g, g, g, l, l, b, _},
    {b, g, g, g, g, g, l, l, b},
    {b, g, g, g, g, g, l, l, b},
};
// clang-format on


void Spike::paint(pro2::Window& window) const {
    paint_sprite(window, {pos_.x, pos_.y}, spike_sprite_, false);
}


pro2::Rect Spike::get_rect() const {
    return {pos_.x - 3, pos_.y + 5, pos_.x + 10, pos_.y + 25};
}


bool Spike::above_spike(pro2::Pt plast, pro2::Pt pcurr) const {
    pro2::Rect rect = get_rect();
    return (rect.left <= plast.x && plast.x <= rect.right) && (rect.left <= pcurr.x && pcurr.x <= rect.right) &&
           (plast.y <= rect.top && pcurr.y >= rect.top);
}