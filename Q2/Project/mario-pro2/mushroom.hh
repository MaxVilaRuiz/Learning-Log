#pragma once

#include <vector>
#include "platform.hh"
#include "utils.hh"


class Mushroom {
 private:
    // Sprites for the Mushroom
    static const std::vector<std::vector<int>> mushroom_sprite_;

    pro2::Pt pos_;  // Position of the mushroom
    int frame_ = 0; // Animation frame counter
    int animation_speed_ = 10;


 public:
    /// @brief Default constructor for data structures
    Mushroom() {}

    /**
     * @brief Constructs a Mushroom at a given position.
     * @param pos Initial position of the Mushroom.
     */
    Mushroom(pro2::Pt pos) : pos_(pos) {}

    /**
     * @brief Renders the Mushroom on the screen.
     * @param window Window to draw to.
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Updates animation frame of the mushroom
     * @post frame_ is incremented or cycled for animation
     */
    void update();

    /**
     * @brief Gets the bounding rectangle of the Mushroom for collision.
     * @return The rectangle covering the Mushroom's position and size.
     */
    pro2::Rect get_rect() const;
};