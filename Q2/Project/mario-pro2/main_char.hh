#pragma once

#include <iostream>
#include <vector>
#include <set>
#include "platform.hh"
#include "window.hh"
#include "spike.hh"

class MainChar {
 private:
    // Physics
    pro2::Pt pos_, last_pos_, last_grounded_pos_;
    pro2::Pt speed_ = {0, 0};
    pro2::Pt accel_ = {0, 0};
    int accel_time_ = 0;

    // Walking animation
    int animation_counter_ = 0;
    int animation_speed_ = 7;

    int lives_ = 5;

    // Mushroom effect
    int growth_counter_ = 0;
    int decrease_counter_ = 0;
    bool big_ = false;

    // Star effect
    int star_counter_ = 0;
    bool star_mode_ = false;

    // Mario sprites
    static const std::vector<std::vector<int>> mario_sprite_normal_;
    static const std::vector<std::vector<int>> mario_sprite_normal_walk1_;
    static const std::vector<std::vector<int>> mario_sprite_normal_walk2_;
    static const std::vector<std::vector<int>> mario_sprite_normal_walk3_;
    static const std::vector<std::vector<int>> mario_sprite_medium_;
    static const std::vector<std::vector<int>> mario_sprite_big_;
    static const std::vector<std::vector<int>> mario_sprite_big_walk1_;
    static const std::vector<std::vector<int>> mario_sprite_big_walk2_;
    static const std::vector<std::vector<int>> mario_sprite_big_walk3_;

    // Luigi sprites
    static const std::vector<std::vector<int>> luigi_sprite_normal_;
    static const std::vector<std::vector<int>> luigi_sprite_normal_walk1_;
    static const std::vector<std::vector<int>> luigi_sprite_normal_walk2_;
    static const std::vector<std::vector<int>> luigi_sprite_normal_walk3_;
    static const std::vector<std::vector<int>> luigi_sprite_medium_;
    static const std::vector<std::vector<int>> luigi_sprite_big_;
    static const std::vector<std::vector<int>> luigi_sprite_big_walk1_;
    static const std::vector<std::vector<int>> luigi_sprite_big_walk2_;
    static const std::vector<std::vector<int>> luigi_sprite_big_walk3_;

    // Star mode
    static const std::vector<std::vector<int>> starmode_sprite_normal_;
    static const std::vector<std::vector<int>> starmode_sprite_normal_walk1_;
    static const std::vector<std::vector<int>> starmode_sprite_normal_walk2_;
    static const std::vector<std::vector<int>> starmode_sprite_normal_walk3_;
    static const std::vector<std::vector<int>> starmode_sprite_medium_;
    static const std::vector<std::vector<int>> starmode_sprite_big_;
    static const std::vector<std::vector<int>> starmode_sprite_big_walk1_;
    static const std::vector<std::vector<int>> starmode_sprite_big_walk2_;
    static const std::vector<std::vector<int>> starmode_sprite_big_walk3_;

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
    pro2::Pt pos() const { return pos_; }

    // Sets vertical position directly
    void set_y(int y) { pos_.y = y; }

    // True if MainChar is on ground
    bool is_grounded() const { return grounded_; }

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
    void reset_lives() { lives_ = 5; }

    /**
     * @brief Handles the effect of picking up a mushroom.  
     *        If the character is not already big, sets the big state to true and
     *        initializes the growth animation counter.
     */    
    void handle_mushroom();

    /**
     * @brief Resets the character's position to a new location.
     * @param new_pos The new position to set for the character.
     * @post The character is moved to the specified position.
     */
    void reset_position(pro2::Pt new_pos);

    /**
     * @brief Checks whether the character is in "big" state.
     * @return true if the character is big, false otherwise.
     */
    bool is_big() { return big_; }

    /**
     * @brief Returns the last position where the character was grounded.
     * @return A point representing the last grounded position.
     */
    pro2::Pt last_grounded_pos() { return last_grounded_pos_; }

    /**
     * @brief Activates star mode for the character.
     * @post star_mode_ is set to true and star_counter_ is reset to its starting value.
     */
    void handle_star();

    /**
     * @brief Checks if the character is currently in star mode.
     * @return true if the character is in star mode, false otherwise.
     */
    bool is_in_starmode() { return star_mode_; }

    /**
     * @brief Gets the remaining duration of star mode.
     * @return The number of frames remaining in star mode.
     */
    int star_countdown() { return star_counter_; }

    /// @brief Disables star mode for the character.
    void remove_starmode();

    /// @brief  Disables the big state
    void remove_big() { big_ = false; }
};