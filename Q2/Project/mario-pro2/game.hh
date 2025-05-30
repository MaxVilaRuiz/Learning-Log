#pragma once

#include <vector>
#include <list>
#include <set>
#include <vector>
#include "main_char.hh"
#include "platform.hh"
#include "coin.hh"
#include "window.hh"
#include "utils.hh"
#include "finder.hh"

class Game {
    static constexpr int sky_blue = 0x5c94fc; // Background color
    
    MainChar mario_;          // Main player
    MainChar luigi_;         // Second player
    std::list<Platform> platforms_;        // All platforms
    std::list<Coin> coins_;                // All coins
    Finder<Platform> platform_finder_;     // Platform finder
    Finder<Coin> coin_finder_;             // Coin finder
    std::set<const Coin*> coin_actualObj_;         // Coins in view
    std::set<const Platform*> platform_actualObj_; // Platforms in view

    bool finished_;     // Game over flag
    bool paused_;       // Pause flag
    int num_coins_;     // Collected coins
    bool following_cam_ = false; // Vertical camera tracking state

    void process_keys(pro2::Window& window);     // Handle input
    void update_objects(pro2::Window& window);   // Update game logic
    void update_camera(pro2::Window& window);    // Adjust camera

 public:
    Game(int width, int height); // Constructor

    void update(pro2::Window& window); // Per-frame update

    void paint(pro2::Window& window);  // Draw game

    bool is_finished() const { return finished_; }
};