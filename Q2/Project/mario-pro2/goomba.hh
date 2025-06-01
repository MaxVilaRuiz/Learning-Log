#pragma once

#include <vector>
#include "platform.hh"
#include "utils.hh"

class Goomba {
 private:
    static const std::vector<std::vector<int>> goomba_sprite_normal_;
    static const std::vector<std::vector<int>> goomba_sprite_walk1_;
    static const std::vector<std::vector<int>> goomba_sprite_walk2_;

    pro2::Pt pos_;
    int actual_pos_ = pos_.x;
    int frame_ = 0;

    const int travel_ = 50;
    const int speed_ = 5; // Positions moved in each frame

    bool to_right_ = true;


 public:   
    Goomba(pro2::Pt pos) : pos_(pos) {}

    /**
     * @brief Renders Goomba.
     * @param window Target window.
     */
    void paint(pro2::Window& window);

    void move();

    pro2::Rect get_rect() const;
};