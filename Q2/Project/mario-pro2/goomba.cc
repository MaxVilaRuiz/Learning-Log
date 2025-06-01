#include "goomba.hh"
using namespace std;


// Color codes
const int _ = -1;
const int s = pro2::beige;
const int b = pro2::black;
const int w = pro2::brown;

// clang-format off
// Goomba sprites
// Normal sprites
const vector<vector<int>> Goomba::goomba_sprite_normal1_ = {
    {_, _, _, _, w, w, w, w, _, _, _, _},
    {_, _, _, w, w, w, w, w, w, _, _, _},
    {_, _, w, b, b, w, w, b, b, w, _, _},
    {_, w, w, s, b, b, b, b, s, w, w, _},
    {w, w, w, s, b, w, w, b, s, w, w, w},
    {w, w, w, s, s, w, w, s, s, w, w, w},
    {w, w, w, w, w, w, w, w, w, w, w, w},
    {_, w, w, w, s, s, s, s, w, w, w, _},
    {_, _, _, s, s, s, s, s, s, _, _, _},
    {_, _, b, b, s, s, s, s, b, b, b, _},
    {_, b, b, b, b, _, _, b, b, b, b, b},
    {_, _, b, b, b, _, _, b, b, b, b, _},
};

const vector<vector<int>> Goomba::goomba_sprite_normal2_ = {
    {_, _, _, _, w, w, w, w, _, _, _, _},
    {_, _, _, w, w, w, w, w, w, _, _, _},
    {_, _, w, b, b, w, w, b, b, w, _, _},
    {_, w, w, s, b, b, b, b, s, w, w, _},
    {w, w, w, s, b, w, w, b, s, w, w, w},
    {w, w, w, s, s, w, w, s, s, w, w, w},
    {w, w, w, w, w, w, w, w, w, w, w, w},
    {_, w, w, w, s, s, s, s, w, w, w, _},
    {_, _, _, s, s, s, s, s, s, _, _, _},
    {_, b, b, b, s, s, s, s, b, b, _, _},
    {b, b, b, b, b, _, _, b, b, b, b, _},
    {_, b, b, b, b, _, _, b, b, b, _, _},
};

// Squashed sprites
const vector<vector<int>> Goomba::goomba_sprite_squashed1_ = {
    {_, _, _, _, w, w, w, w, _, _, _, _},
    {_, _, w, w, w, w, w, w, w, w, _, _},
    {w, w, b, b, b, w, w, b, b, b, w, w},
    {w, w, s, s, s, b, b, s, s, s, w, w},
    {w, w, w, w, w, w, w, w, w, w, w, w},
    {_, s, s, s, s, s, s, s, s, s, s, _},
    {_, _, _, s, s, _, _, s, s, _, _, _},
    {_, b, b, b, b, _, _, b, b, b, b, b},
};

const vector<vector<int>> Goomba::goomba_sprite_squashed2_ = {
    {_, _, _, _, w, w, w, w, _, _, _, _},
    {_, _, w, w, w, w, w, w, w, w, _, _},
    {w, w, b, b, b, w, w, b, b, b, w, w},
    {w, w, s, s, s, b, b, s, s, s, w, w},
    {w, w, w, w, w, w, w, w, w, w, w, w},
    {_, s, s, s, s, s, s, s, s, s, s, _},
    {_, _, _, s, s, _, _, s, s, _, _, _},
    {b, b, b, b, b, _, _, b, b, b, b, _},
};
// clang-format on


void Goomba::update() {
    if (immune_ && immune_until_ <= frame_) {
        immune_ = false;
    }

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

    frame_++;
}


void Goomba::paint(pro2::Window& window) const {
    const std::vector<std::vector<int>>* sprite;
    const int phase = (frame_ / animation_speed_) % 2;

    if (hit_count_ == 1) {
        sprite = (phase == 0) ? &goomba_sprite_squashed1_ : &goomba_sprite_squashed2_;
    }
    else {
        sprite = (phase == 0) ? &goomba_sprite_normal1_ : &goomba_sprite_normal2_;
    }

    paint_sprite(window, {actual_pos_, pos_.y}, *sprite, false);
}


pro2::Rect Goomba::get_rect() const {
    int left = actual_pos_ - 10;
    int top = pos_.y - 10;
    int right = actual_pos_ + 10;
    int bottom = pos_.y + 10;
    return {left, top, right, bottom};
}

void Goomba::hit_from_above() {
    hit_count_++;
    pos_.y += 4;
}

bool Goomba::is_squashed() const {
    return hit_count_ >= 2;
}

void Goomba::start_immunity(int current_frame, int duration) {
    immune_ = true;
    immune_until_ = current_frame + duration;
}

bool Goomba::is_immune(int current_frame) const {
    return immune_ && current_frame < immune_until_;
}