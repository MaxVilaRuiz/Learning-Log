#include "coin.hh"
#include "utils.hh"
using namespace std;
using namespace pro2;


const int _ = -1;
const int y = pro2::yellow; 
const int b = pro2::black;
const int w = pro2::white;

// clang-format off
const vector<vector<int>> Coin::coin_sprite_front = {
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
const vector<vector<int>> Coin::coin_sprite_oval_ = {
    {_, _, _, _, _, b, b, _, _, _, _, _},
    {_, _, _, _, b, y, y, b, _, _, _, _},
    {_, _, _, b, y, y, y, y, b, _, _, _},
    {_, _, b, y, y, y, y, y, y, b, _, _},
    {_, _, b, y, y, y, y, y, y, b, _, _},
    {_, b, y, y, y, y, y, y, y, y, b, _},
    {_, b, y, y, y, y, y, y, y, y, b, _},
    {_, b, y, y, y, y, y, y, y, y, b, _},
    {_, _, b, y, y, y, y, y, y, b, _, _},
    {_, _, b, y, y, y, y, y, y, b, _, _},
    {_, _, _, b, y, y, y, y, b, _, _, _},
    {_, _, _, _, b, y, y, b, _, _, _, _},
    {_, _, _, _, _, b, b, _, _, _, _, _},
};
const vector<vector<int>> Coin::coin_sprite_side_ = {
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, b, y, b, _, _, _, _, _},
    {_, _, _, b, y, y, y, b, _, _, _, _},
    {_, _, b, y, y, y, y, y, b, _, _, _},
    {_, _, b, y, y, y, y, y, b, _, _, _},
    {_, b, y, y, y, y, y, y, y, b, _, _},
    {_, b, y, y, y, y, y, y, y, b, _, _},
    {_, b, y, y, y, y, y, y, y, b, _, _},
    {_, _, b, y, y, y, y, y, b, _, _, _},
    {_, _, b, y, y, y, y, y, b, _, _, _},
    {_, _, _, b, y, y, y, b, _, _, _, _},
    {_, _, _, _, b, y, b, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
};
// clang-format on


void Coin::paint(pro2::Window& window) const {
    int frame = (frame_ / 13) % 4;
    switch (frame) { 
        case 0:
            paint_sprite(window, {pos_.x, pos_.y}, coin_sprite_front, false);
            break;

        case 1:
        case 3:
            paint_sprite(window, {pos_.x, pos_.y + 2}, coin_sprite_oval_, false);
            break;
            
        case 2:
            paint_sprite(window, {pos_.x, pos_.y + 4}, coin_sprite_side_, false);
            break;
    }
}


void Coin::update() {
    frame_++;
}


pro2::Rect Coin::get_rect() const {
    int left = pos_.x;
    int top = pos_.y + 2;
    int right = pos_.x + 12;
    int bottom = pos_.y + 20;
    return {left, top, right, bottom};    
}