#pragma once

#include <vector>
#include "platform.hh"
#include "utils.hh"


class Spike {
 private:
    // Sprite for the Spike
    static const std::vector<std::vector<int>> spike_sprite_;

    pro2::Pt pos_;

 public:
    /// @brief Default constructor for data structures
    Spike() {}

    /**
     * @brief Constructs a Spike at the given position.
     * @param pos Initial position of the Spike.
     */
    Spike(pro2::Pt pos) : pos_(pos) {}

    /**
     * @brief Renders the Spike on the screen.
     * @param window Window to draw to.
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Gets the bounding rectangle of the Spike for collision.
     * @return The rectangle covering the Spike's position and size.
     */
    pro2::Rect get_rect() const;

    /**
     * @brief Checks if the movement from plast to pcurr crosses the top of the spike.
     * @param plast Previous position.
     * @param pcurr Current position.
     * @return True if the path intersects the spike from above, false otherwise.
     * @pre plast and pcurr must be valid world coordinates.
     * @post Returns whether the spike was hit from above.
     */
    bool above_spike(pro2::Pt plast, pro2::Pt pcurr) const;
};