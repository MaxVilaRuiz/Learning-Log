#pragma once

#include <vector>
#include "platform.hh"
#include "utils.hh"

class Goomba {
 private:
    // Sprites for the Goomba
    static const std::vector<std::vector<int>> goomba_sprite_normal1_;
    static const std::vector<std::vector<int>> goomba_sprite_normal2_;
    static const std::vector<std::vector<int>> goomba_sprite_squashed_;

    pro2::Pt pos_;                     // Initial position
    int actual_pos_ = pos_.x;          // Current X position
    int frame_ = 0;                    // Frame counter

    int travel_ = 50;            // Max distance Goomba travels left/right from start
    int speed_ = 1;              // Speed in positions per update
    int animation_speed_ = 10;   // How often to change sprite frame

    bool to_right_ = true;             // Movement direction

    bool squashed_ = false;            // Whether Goomba has been squashed
    int deadtime_ = -1;                // Frame when Goomba was squashed (-1 = alive)


 public:   
    /// @brief Default constructor for data structures
    Goomba() {}

    /**
     * @brief Constructs a Goomba at a given position.
     * @param pos Initial position of the Goomba.
     */
    Goomba(pro2::Pt pos, int travel) : pos_(pos), travel_(travel) {}

    /**
     * @brief Renders the Goomba on the screen.
     * @param window Window to draw to.
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Updates Goomba's animation and position.
     * @pre Goomba must not be squashed unless used to track death time.
     * @post Position and animation frame are updated. If squashed, death timer increments.
     */
    void update();

    /**
     * @brief Gets the bounding rectangle of the Goomba for collision.
     * @return The rectangle covering the Goomba's position and size.
     */
    pro2::Rect get_rect() const;

    /**
     * @brief Handles a hit from above (e.g., by the player).
     * @param global_frame The current global frame to timestamp the death.
     * @pre Goomba must not already be squashed.
     * @post Goomba enters the squashed state and records the death time.
     */
    void hit_from_above(int global_frame);

    /**
     * @brief Checks if the Goomba is squashed.
     * @return True if squashed, false otherwise.
     */
    bool is_squashed() { return squashed_; }

    /**
     * @brief Gets the frame in which the Goomba was squashed.
     * @return The frame number, or -1 if not yet squashed.
     */
    int get_deadtime() const { return deadtime_; }
};