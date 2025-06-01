#pragma once

#include <vector>
#include "platform.hh"
#include "utils.hh"

class Goomba {
 private:
    static const std::vector<std::vector<int>> goomba_sprite_normal1_;
    static const std::vector<std::vector<int>> goomba_sprite_normal2_;
    static const std::vector<std::vector<int>> goomba_sprite_squashed_;

    pro2::Pt pos_;
    int actual_pos_ = pos_.x;
    int frame_ = 0;

    const int travel_ = 50;
    const int speed_ = 1; // Positions moved in each frame
    const int animation_speed_ = 10;

    bool to_right_ = true;

    bool squashed_ = false;
    int deadtime_ = -1;


 public:   
    Goomba(pro2::Pt pos) : pos_(pos) {}

    /**
     * @brief Renders Goomba.
     * @param window Target window.
     */
    void paint(pro2::Window& window) const;

    void update();

    pro2::Rect get_rect() const;

    void hit_from_above(int global_frame);

    bool is_squashed() { return squashed_; };

    int get_deadtime() const { return deadtime_; }
};