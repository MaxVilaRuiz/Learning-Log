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
#include "mushroom.hh"
#include "star.hh"

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
    int num_coins_ = 0;                             // Collected coins

    // Spikes
    std::list<Spike> spikes_;                       // All Spike
    Finder<Spike> spike_finder_;                    // Spike finder
    std::set<const Spike*> spike_actualObj_;        // Spike in view

    // Mushrooms
    std::list<Mushroom> mushrooms_;                 // All Mushrooms
    Finder<Mushroom> mushroom_finder_;              // Mushroom finder
    std::set<const Mushroom*> mushroom_actualObj_;  // Mushroom in view

    // Goombas
    std::list<Goomba> goombas_;                     // All Goombas
    Finder<Goomba> goombas_finder_;                 // Goombas finder
    std::set<const Goomba*> goombas_actualObj_;     // Goombas in view

    // Stars
    std::list<Star> stars_;                         // All Stars
    Finder<Star> star_finder_;                      // Star finder
    std::set<const Star*> star_actualObj_;          // Star in view

    bool finished_ = false;                         // Game over flag
    bool paused_ = true;                            // Pause flag
    bool pregame_ = true;                            // Pre-game state
    bool following_cam_ = false;                    // Vertical camera tracking state

    // Pre-game screen
    std::list<std::string> options_;
    std::list<std::string>::iterator options_it_ = options_.begin();
    static const std::vector<std::vector<int>> option_pointer_sprite_;

    bool day_time_ = true;                          // Background status
    int frame_counter_ = 0;
    static const int day_night_interval_ = 900;     // 15s at 60fps

    const int immunity_interval_ = 60;              // 1s at 60fps
    int immunity_mario_until_ = 0;
    int immunity_luigi_until_ = 0;
    bool immune_mario_ = false;    
    bool immune_luigi_ = false;
    bool single_player_ = false;

    void process_keys(pro2::Window& window);        // Handle input
    void update_objects(pro2::Window& window);      // Update game logic
    void update_camera(pro2::Window& window);       // Adjust camera

 public:
    Game(int width, int height);                    // Constructor

    void update(pro2::Window& window);              // Per-frame update

    void paint(pro2::Window& window);               // Draw game

    bool is_finished() const { return finished_; }
};