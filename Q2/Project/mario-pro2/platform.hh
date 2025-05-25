#pragma once

#include <vector>
#include "window.hh"

class Platform {
 private:
    int left_, right_, top_, bottom_;

    // 2D texture used for rendering the platform
	static const std::vector<std::vector<int>> platform_texture_;

 public:
    // Default constructor (empty platform)
    Platform() : left_(0), right_(0), top_(0), bottom_(0) {}

    // Copy constructor
    Platform(const Platform& other)
        : left_(other.left_), right_(other.right_), top_(other.top_), bottom_(other.bottom_) {}

    // Parameterized constructor to define platform bounds
    Platform(int left, int right, int top, int bottom)
        : left_(left), right_(right), top_(top), bottom_(bottom) {}

    /**
     * @brief Renders the platform to the window.
     * @param window Window to render on.
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Checks if point moved from above to below the platform.
     * @param plast Previous position.
     * @param pcurr Current position.
     * @return True if a downward cross occurred.
     */
    bool has_crossed_floor_downwards(pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Checks if a point lies within the platform bounds.
     * @param pt The point to check.
     * @return True if inside.
     */
    bool is_pt_inside(pro2::Pt pt) const;

    // Returns top edge of the platform
    int top() const {
        return top_;
    }

    /**
     * @brief Gets platform bounds as a rectangle.
     * @return Bounding box of the platform.
     */
    pro2::Rect get_rect() const {
        return {left_, top_, right_, bottom_};
    }
};