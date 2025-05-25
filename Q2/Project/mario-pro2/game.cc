#include "game.hh"
using namespace pro2;


Game::Game(int width, int height)
    : mario_({width / 2, 150}, Keys::Space, Keys::Left, Keys::Right),
      mario2_({(width / 2) - 30, 150}, Keys::W, Keys::A, Keys::D),
      platforms_{
        Platform(0, 200, 250, 261),
        Platform(100, 300, 200, 211),
        Platform(250, 400, 150, 161),
      },
      coins_ {
        Coin({20, 232}),
        Coin({320, 132}),
      },
      paused_ (false),
      finished_(false),
      num_coins_(0) {
    
    // Generate platforms
    for (int i = 1; i < 98; i++) {
        platforms_.push_back(Platform(250 + i * 200, 400 + i * 200, 150, 161));
        platforms_.push_back(Platform(i * 200, 480 + i * 200, 400, 411));

        if (i % 2 != 0) {
            platforms_.push_back(Platform(320 + i * 200, 370 + i * 200, 100, 111));
        }

        if (i % 3 == 0) {
            platforms_.push_back(Platform(405 + i * 200, 445 + i * 200, 200, 211));
        }
    }

    // Add platforms to finder
    for (const auto& plataform : platforms_) {
        platform_finder_.add(&plataform);
    }

    // Generate coins
    for (int i = 1; i < 98; i++) {
        for (int j = 1; j < 5; j++) {
            coins_.push_back(Coin({50 * j + i * 200, 382}));
        }

        if (i % 2 == 0) coins_.push_back(Coin({320 + i * 200, 132}));
        else coins_.push_back(Coin({410 + i * 200, 20}));

        if (i % 3 == 0) coins_.push_back(Coin({420 + i * 200, 182}));
    }

    // Add coins to finder
    for (const auto& coin : coins_) {
        coin_finder_.add(&coin);
    }
}


void Game::process_keys(pro2::Window& window) {
    if (window.is_key_down(Keys::Escape)) {
        finished_ = true;
        return;
    }
    else if (window.was_key_pressed(80)) paused_ = !paused_; // 'P' key to pause/unpause
}


void Game::update_objects(pro2::Window& window) {
    mario_.update(window, platforms_);
    mario2_.update(window, platforms_);

    // Query visible objects
    platform_actualObj_ = platform_finder_.query(window.camera_rect());
    coin_actualObj_ = coin_finder_.query(window.camera_rect());
    
    // Check collisions and update coins
    if (!coins_.empty()) {
        for (auto it = coins_.begin(); it != coins_.end(); it++) {
            if (objs_collision(mario_.rect(), it->get_rect()) || objs_collision(mario2_.rect(), it->get_rect())) {
                coin_finder_.remove(&(*it)); 
                it = coins_.erase(it);
                num_coins_++;
            }
            else it->update();
        }
    }
}


void Game::update_camera(pro2::Window& window) {
    const Pt mario_pos = mario_.pos();
    const Pt cam = window.camera_center();

    int dx = 0, dy = 0;
    const int limit_y = 160;

    // Always follow Mario horizontally
    if (mario_pos.x != cam.x) dx = mario_pos.x - cam.x;

    // Follow vertically only if out of bounds
    if (mario_pos.y < cam.y - limit_y || mario_pos.y > cam.y + limit_y) {
        dy = mario_pos.y - cam.y;
        following_cam_ = true;
    }
    else if (following_cam_) following_cam_ = false;

    window.move_camera({dx, dy});
}


void Game::update(pro2::Window& window) {
    process_keys(window);

    if (!paused_) {
        update_objects(window);
        update_camera(window);
    }
}


void Game::paint(pro2::Window& window) {
    window.clear(sky_blue);

    // Draw platforms
    for (const Platform* p : platform_actualObj_) {
        p->paint(window);
    }

    // Draw coins
    for (const Coin* c : coin_actualObj_) {
        c->paint(window);
    }

    // Draw the counter
    const pro2::Rect cam_rect = window.camera_rect();
    Pt top_left = {cam_rect.left + 5, cam_rect.top + 5}; 
    Pt top_left2 = {cam_rect.left + 22, cam_rect.top + 8};
    paint_sprite(window, top_left, Coin::coin_sprite_front, false);
    window.draw_num(top_left2, std::to_string(num_coins_), pro2::black);

    // Draw characters
    mario_.paint(window);
    mario2_.paint(window);
}