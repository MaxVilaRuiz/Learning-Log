#pragma once

#include <vector>
#include "platform.hh"
#include "utils.hh"

class Coin { 
  private:
    pro2::Pt pos_;  // Position of the coin
    int frame_ = 0; // Animation frame counter
    int animation_speed_ = 7;

    // Internal sprites for animation
    static const std::vector<std::vector<int>> coin_sprite_animation1_;
    static const std::vector<std::vector<int>> coin_sprite_animation2_;
    static const std::vector<std::vector<int>> coin_sprite_animation3_;
    static const std::vector<std::vector<int>> coin_sprite_animation4_;
    static const std::vector<std::vector<int>> coin_sprite_animation5_;
    static const std::vector<std::vector<int>> coin_sprite_animation6_;
    static const std::vector<std::vector<int>> coin_sprite_animation7_;
    static const std::vector<std::vector<int>> coin_sprite_animation8_;
    static const std::vector<std::vector<int>> coin_sprite_animation9_;
    static const std::vector<std::vector<int>> coin_sprite_back_;

  public:
    static const std::vector<std::vector<int>> coin_sprite_front; // Public facing sprite

    /// @brief Default constructor for data structures
    Coin() {}

    /// @brief Constructs a Coin at a given position
    Coin(pro2::Pt pos) : pos_(pos) {}

    /**
     * @brief Draws the coin on the screen
     * @param window Window to render the coin on
     * @pre window must be valid
     * @post Coin is painted to the window
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Updates animation frame of the coin
     * @post frame_ is incremented or cycled for animation
     */
    void update();

    /**
     * @brief Returns the bounding rectangle of the coin
     * @return A rectangle representing the coin's area
     * @post The returned Rect encloses the coin's position
     */
    pro2::Rect get_rect() const;
};