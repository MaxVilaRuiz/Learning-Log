#include "coin.hh"
using namespace std;
using namespace pro2;


const int _ = -1;
const int y = pro2::yellow; 
const int b = pro2::black;
const int w = pro2::white;
const int o = pro2::brown;
const int g = pro2::golden;

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
const vector<vector<int>> Coin::coin_sprite_animation1_ = {
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
const vector<vector<int>> Coin::coin_sprite_animation2_ = {
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
const vector<vector<int>> Coin::coin_sprite_animation3_ = {
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
const vector<vector<int>> Coin::coin_sprite_animation4_ = {
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, b, g, g, _, _, _, _, _},
    {_, _, _, _, b, g, g, _, _, _, _, _},
    {_, _, _, b, g, g, g, g, _, _, _, _},
    {_, _, _, b, g, g, g, g, _, _, _, _},
    {_, _, _, b, g, g, g, g, _, _, _, _},
    {_, _, _, b, g, g, g, g, _, _, _, _},
    {_, _, _, b, g, g, g, g, _, _, _, _},
    {_, _, _, b, g, g, g, g, _, _, _, _},
    {_, _, _, b, g, g, g, g, _, _, _, _},
    {_, _, _, _, b, g, g, _, _, _, _, _},
    {_, _, _, _, b, g, g, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
};
const vector<vector<int>> Coin::coin_sprite_animation5_ = {
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, b, g, g, _, _, _, _, _},
    {_, _, _, b, g, g, g, g, _, _, _, _},
    {_, _, b, g, g, g, g, g, g, _, _, _},
    {_, _, b, g, g, g, g, g, g, _, _, _},
    {_, b, g, g, g, g, g, g, g, g, _, _},
    {_, b, g, g, g, g, g, g, g, g, _, _},
    {_, b, g, g, g, g, g, g, g, g, _, _},
    {_, _, b, g, g, g, g, g, g, _, _, _},
    {_, _, b, g, g, g, g, g, g, _, _, _},
    {_, _, _, b, g, g, g, g, _, _, _, _},
    {_, _, _, _, b, g, g, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
};
const vector<vector<int>> Coin::coin_sprite_back_ = {
    {_, _, _, _, b, b, b, b, _, _, _, _},
    {_, _, _, b, g, g, g, g, b, _, _, _},
    {_, _, b, g, g, g, g, g, g, b, _, _},
    {_, b, g, g, g, g, g, g, g, g, b, _},
    {_, b, g, g, g, y, b, g, g, g, b, _},
    {b, g, g, g, g, y, b, g, g, g, g, b},
    {b, g, g, g, g, y, b, g, g, g, g, b},
    {b, g, g, g, g, y, b, g, g, g, g, b},
    {_, b, g, g, g, b, b, g, g, g, b, _},
    {_, b, g, g, g, g, g, g, g, g, b, _},
    {_, _, b, g, g, g, g, g, g, b, _, _},
    {_, _, _, b, g, g, g, g, b, _, _, _},
    {_, _, _, _, b, b, b, b, _, _, _, _},
};
const vector<vector<int>> Coin::coin_sprite_animation6_ = {
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, g, g, b, _, _, _, _, _},
    {_, _, _, g, g, g, g, b, _, _, _, _},
    {_, _, g, g, g, g, g, g, b, _, _, _},
    {_, _, g, g, g, g, g, g, b, _, _, _},
    {_, g, g, g, g, g, g, g, g, b, _, _},
    {_, g, g, g, g, g, g, g, g, b, _, _},
    {_, g, g, g, g, g, g, g, g, b, _, _},
    {_, _, g, g, g, g, g, g, b, _, _, _},
    {_, _, g, g, g, g, g, g, b, _, _, _},
    {_, _, _, g, g, g, g, b, _, _, _, _},
    {_, _, _, _, g, g, b, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
};
const vector<vector<int>> Coin::coin_sprite_animation7_ = {
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, g, g, b, _, _, _, _, _},
    {_, _, _, _, g, g, b, _, _, _, _, _},
    {_, _, _, g, g, g, g, b, _, _, _, _},
    {_, _, _, g, g, g, g, b, _, _, _, _},
    {_, _, _, g, g, g, g, b, _, _, _, _},
    {_, _, _, g, g, g, g, b, _, _, _, _},
    {_, _, _, g, g, g, g, b, _, _, _, _},
    {_, _, _, g, g, g, g, b, _, _, _, _},
    {_, _, _, g, g, g, g, b, _, _, _, _},
    {_, _, _, _, g, g, b, _, _, _, _, _},
    {_, _, _, _, g, g, b, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
};
const vector<vector<int>> Coin::coin_sprite_animation8_ = {
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, b, y, y, _, _, _, _, _},
    {_, _, _, _, b, y, y, _, _, _, _, _},
    {_, _, _, b, y, y, y, y, _, _, _, _},
    {_, _, _, b, y, y, y, y, _, _, _, _},
    {_, _, _, b, y, y, y, y, _, _, _, _},
    {_, _, _, b, y, y, y, y, _, _, _, _},
    {_, _, _, b, y, y, y, y, _, _, _, _},
    {_, _, _, b, y, y, y, y, _, _, _, _},
    {_, _, _, b, y, y, y, y, _, _, _, _},
    {_, _, _, _, b, y, y, _, _, _, _, _},
    {_, _, _, _, b, y, y, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
};
const vector<vector<int>> Coin::coin_sprite_animation9_ = {
    {_, _, _, _, _, b, _, _, _, _, _, _},
    {_, _, _, _, b, y, y, _, _, _, _, _},
    {_, _, _, b, y, y, y, y, _, _, _, _},
    {_, _, b, y, y, y, y, y, y, _, _, _},
    {_, _, b, y, y, y, y, y, y, _, _, _},
    {_, b, y, y, y, y, y, y, y, y, _, _},
    {_, b, y, y, y, y, y, y, y, y, _, _},
    {_, b, y, y, y, y, y, y, y, y, _, _},
    {_, _, b, y, y, y, y, y, y, _, _, _},
    {_, _, b, y, y, y, y, y, y, _, _, _},
    {_, _, _, b, y, y, y, y, _, _, _, _},
    {_, _, _, _, b, y, y, _, _, _, _, _},
    {_, _, _, _, _, b, _, _, _, _, _, _},
};
// clang-format on


void Coin::paint(pro2::Window& window) const {
    int frame = (frame_ / animation_speed_) % 12;
    switch (frame) { 
        case 0:
            paint_sprite(window, {pos_.x, pos_.y}, coin_sprite_front, false);
            break;

        case 1:
            paint_sprite(window, {pos_.x, pos_.y + 1}, coin_sprite_animation1_, false);
            break;

        case 2:
            paint_sprite(window, {pos_.x, pos_.y + 2}, coin_sprite_animation2_, false);
            break;

        case 3:
            paint_sprite(window, {pos_.x, pos_.y + 3}, coin_sprite_animation3_, false);
            break;
            
        case 4:
            paint_sprite(window, {pos_.x, pos_.y + 4}, coin_sprite_animation4_, false);
            break;

        case 5:
            paint_sprite(window, {pos_.x, pos_.y + 5}, coin_sprite_animation5_, false);
            break;
        
        case 6:
            paint_sprite(window, {pos_.x, pos_.y + 5}, coin_sprite_back_, false);
            break;

        case 7:
            paint_sprite(window, {pos_.x, pos_.y + 4}, coin_sprite_animation6_, false);
            break;
        
        case 8:
            paint_sprite(window, {pos_.x, pos_.y + 3}, coin_sprite_animation7_, false);
            break;

        case 9:
            paint_sprite(window, {pos_.x, pos_.y + 2}, coin_sprite_animation3_, false);
            break;
        
        case 10:
            paint_sprite(window, {pos_.x, pos_.y + 1}, coin_sprite_animation8_, false);
            break;
        
        case 11:
            paint_sprite(window, {pos_.x, pos_.y + 0}, coin_sprite_animation9_, false);
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