#pragma once

#include <iostream>
#include <vector>
#include <set>
#include "platform.hh"
#include "window.hh"
#include "spike.hh"

class MainChar {
 private:
    pro2::Pt pos_, last_pos_;
    pro2::Pt speed_ = {0, 0};
    pro2::Pt accel_ = {0, 0};
    int accel_time_ = 0;
    int animation_counter_ = 0;
    int animation_speed_ = 7;
    int lives_ = 5;

    // Mario sprites
    static const std::vector<std::vector<int>> mario_sprite_normal_;
    static const std::vector<std::vector<int>> mario_sprite_walk1_;
    static const std::vector<std::vector<int>> mario_sprite_walk2_;
    static const std::vector<std::vector<int>> mario_sprite_walk3_;

    // Mario sprites
    static const std::vector<std::vector<int>> luigi_sprite_normal_;
    static const std::vector<std::vector<int>> luigi_sprite_walk1_;
    static const std::vector<std::vector<int>> luigi_sprite_walk2_;
    static const std::vector<std::vector<int>> luigi_sprite_walk3_;

    // Lives sprite
    static const std::vector<std::vector<int>> mario_lives_sprite_;
    static const std::vector<std::vector<int>> luigi_lives_sprite_;

    // Constructor parameters
    int jump_key_;
    int down_key_;
    int left_key_;
    int right_key_;
    std::string character_;

    bool grounded_ = false;
	bool looking_left_ = false;

    /**
     * @brief Handles movement physics.
     * @pre Speed and acceleration initialized.
     * @post Position and speed updated based on gravity and input.
     */
    void apply_physics_();
	
 public:
    /// @brief Constructs MainChar at initial position with control keys.
    MainChar(pro2::Pt pos, int jump_key, int down_key, int left_key, int right_key, std::string character) 
        : pos_(pos), last_pos_(pos), jump_key_(jump_key), down_key_(down_key), left_key_(left_key), 
          right_key_(right_key), character_(character) {}

    /**
     * @brief Renders MainChar.
     * @param window Target window.
     */
    void paint(pro2::Window& window, bool immune, int frame) const;

    /**
     * @brief Renders MainChar lives.
     * @param window Target window.
     */
    void paint_lives(pro2::Window& window, std::string character) const;

    // Returns current position
    pro2::Pt pos() const {
        return pos_;
    }

    // Sets vertical position directly
    void set_y(int y) {
        pos_.y = y;
    }

    // True if MainChar is on ground
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
     * @pre MainChar must be grounded.
     * @post Vertical acceleration applied.
     */
    void jump();

    /**
     * @brief Updates MainChar each frame.
     * @param window Game window (for input).
     * @param platforms Platform set to check collisions.
     * @pre Inputs and platforms valid.
     * @post Updates position, speed, grounded state.
     */
    void update(pro2::Window& window, std::set<const Platform*> platforms, std::set<const Spike*> spikes);

    /**
     * @brief Returns MainChar's bounding box.
     * @return Rect around Mario's position.
     */
    pro2::Rect rect() const;
    
    /**
     * @brief Returns the number of remaining lives.
     * @return The current number of lives.
     */
    int lives() const;

    /**
     * @brief Decreases the number of lives by one.
     * @post lives_-- && 0 <= lives_
     */
    void lose_life();

    /**
     * @brief Refills the character's lives to the maximum allowed.
     * @pre The character must exist / be alive.
     * @post The character's life count is set to its maximum value.
     */
    void refill_lives();

    /**
     * @brief Resets the character's position to a new location.
     * @param new_pos The new position to set for the character.
     * @post The character is moved to the specified position.
     */
    void reset_position(pro2::Pt new_pos);
};