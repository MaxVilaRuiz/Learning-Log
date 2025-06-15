#pragma once

#include <vector>
#include "platform.hh"
#include "utils.hh"

class Star { 
  private:
    pro2::Pt pos_;  // Position of the star
    int frame_ = 0; // Animation frame counter
    int animation_speed_ = 7;

    // Internal sprites for animation
    static const std::vector<std::vector<int>> star_sprite_animation1_;
    static const std::vector<std::vector<int>> star_sprite_animation2_;
    static const std::vector<std::vector<int>> star_sprite_animation3_;
    static const std::vector<std::vector<int>> star_sprite_animation4_;

  public:
    static const std::vector<std::vector<int>> star_sprite_front;

    /// @brief Default constructor for data structures
    Star() {}

    /// @brief Constructs a Star at a given position
    Star(pro2::Pt pos) : pos_(pos) {}

    /**
     * @brief Draws the star on the screen
     * @param window Window to render the star on
     * @pre window must be valid
     * @post Star is painted to the window
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Updates animation frame of the star
     * @post frame_ is incremented or cycled for animation
     */
    void update();

    /**
     * @brief Returns the bounding rectangle of the star
     * @return A rectangle representing the star's area
     * @post The returned Rect encloses the star's position
     */
    pro2::Rect get_rect() const;
};