#pragma once

#include <vector>
#include "platform.hh"
#include "utils.hh"

class Goomba {
 private:
    static const std::vector<std::vector<int>> goomba_sprite_normal_;
    static const std::vector<std::vector<int>> goomba_sprite_walk1_;
    static const std::vector<std::vector<int>> goomba_sprite_walk2_;
    static const std::vector<std::vector<int>> goomba_sprite_squashed_;

    pro2::Pt pos_;
    int actual_pos_ = pos_.x;
    int frame_ = 0;
    int hit_count_ = 0;

    const int travel_ = 50;
    const int speed_ = 1; // Positions moved in each frame
    const int animation_speed_ = 10;

    bool to_right_ = true;

    bool immune_ = false;
    int immune_until_ = 0;


 public:   
    Goomba(pro2::Pt pos) : pos_(pos) {}

    /**
     * @brief Renders Goomba.
     * @param window Target window.
     */
    void paint(pro2::Window& window) const;

    void update();

    pro2::Rect get_rect() const;

    void hit_from_above();

    bool is_squashed() const;

    void start_immunity(int current_frame, int duration);
    
    bool is_immune(int current_frame) const;
};