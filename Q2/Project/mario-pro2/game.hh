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
#include "goomba.hh"
#include "spike.hh"

class Game {
    static constexpr int sky_blue = 0x5c94fc;       // Main background color
    static constexpr int sky_dark = 0x0C134F;       // Secondary background color
    
    // Players
    MainChar mario_;                                // Main player
    MainChar luigi_;                                // Second player

    // Platforms
    std::list<Platform> platforms_;                 // All platforms
    Finder<Platform> platform_finder_;              // Platform finder
    std::set<const Platform*> platform_actualObj_;  // Platforms in view

    // Coins
    std::list<Coin> coins_;                         // All coins
    Finder<Coin> coin_finder_;                      // Coin finder
    std::set<const Coin*> coin_actualObj_;          // Coins in view
    int num_coins_;                                 // Collected coins

    // Spikes
    std::list<Spike> spikes_;                       // All Spike
    Finder<Spike> spike_finder_;                    // Spike finder
    std::set<const Spike*> spike_actualObj_;        // Spike in view

    // Goombas
    std::list<Goomba> goombas_;                     // All Goombas
    Finder<Goomba> goombas_finder_;                 // Goombas finder
    std::set<const Goomba*> goombas_actualObj_;     // Goombas in view

    bool finished_;                                 // Game over flag
    bool paused_;                                   // Pause flag
    bool following_cam_ = false;                    // Vertical camera tracking state

    bool day_time_ = true;                          // Background status
    int frame_counter_ = 0;
    static const int day_night_interval_ = 900;     // 15s at 60fps

    const int immunity_interval_ = 60;              // 1s at 60fps
    int immunity_mario_until_ = 0;
    int immunity_luigi_until_ = 0;
    bool immune_mario_ = false;    
    bool immune_luigi_ = false;

    void process_keys(pro2::Window& window);        // Handle input
    void update_objects(pro2::Window& window);      // Update game logic
    void update_camera(pro2::Window& window);       // Adjust camera

 public:
    Game(int width, int height);                    // Constructor

    void update(pro2::Window& window);              // Per-frame update

    void paint(pro2::Window& window);               // Draw game

    bool is_finished() const { return finished_; }
};