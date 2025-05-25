#pragma once

#include <iostream>
#include <vector>
#include <list>
#include "platform.hh"
#include "window.hh"

class Mario {
 private:
    pro2::Pt pos_, last_pos_;
    pro2::Pt speed_ = {0, 0};
    pro2::Pt accel_ = {0, 0};
    int      accel_time_ = 0;

    int jump_key_;
    int left_key_;
    int right_key_;

    bool grounded_ = false;
	bool looking_left_ = false;

    /**
     * @brief Handles movement physics.
     * @pre Speed and acceleration initialized.
     * @post Position and speed updated based on gravity and input.
     */
    void apply_physics_();
	
 public:
    /// @brief Constructs Mario at initial position with control keys.
    Mario(pro2::Pt pos, int jump_key, int left_key, int right_key) 
        : pos_(pos), last_pos_(pos), jump_key_(jump_key), left_key_(left_key), right_key_(right_key) {}

    /**
     * @brief Renders Mario.
     * @param window Target window.
     */
    void paint(pro2::Window& window) const;

    // Returns current position
    pro2::Pt pos() const {
        return pos_;
    }

    // Sets vertical position directly
    void set_y(int y) {
        pos_.y = y;
    }

    // True if Mario is on ground
    bool is_grounded() const {
        return grounded_;
    }

    // Sets grounded state and resets vertical speed if grounded
    void set_grounded(bool grounded) {
        grounded_ = grounded;
        if (grounded_) {
            speed_.y = 0;
        }
    }

    // Toggles grounded flag
    void toggle_grounded() {
        set_grounded(!grounded_);
    }

    /**
     * @brief Performs jump if grounded.
     * @pre Mario must be grounded.
     * @post Vertical acceleration applied.
     */
    void jump();

    /**
     * @brief Updates Mario each frame.
     * @param window Game window (for input).
     * @param platforms Platform list to check collisions.
     * @pre Inputs and platforms valid.
     * @post Updates position, speed, grounded state.
     */
    void update(pro2::Window& window, const std::list<Platform>& platforms);

    /**
     * @brief Returns Mario's bounding box.
     * @return Rect around Mario's position.
     */
    pro2::Rect rect() const;

 private:
    static const std::vector<std::vector<int>> mario_sprite_normal_;
};