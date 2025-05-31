#include "game.hh"
using namespace pro2;


// const std::vector<std::vector<int>> sun_sprite_ {
    
// };

// const std::vector<std::vector<int>> sun_sprite_ {

// };


Game::Game(int width, int height)
    : mario_({width / 2, 150}, Keys::Up, Keys::Down, Keys::Left, Keys::Right, "mario"),
      luigi_({(width / 2) - 30, 150}, Keys::W, Keys::S, Keys::A, Keys::D, "luigi"),
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
    else if (window.was_key_pressed(Keys::P)) paused_ = !paused_; // 'P' key to pause/unpause
}


void Game::update_objects(pro2::Window& window) {
    mario_.update(window, platform_actualObj_);
    luigi_.update(window, platform_actualObj_);

    // Subtract lives from characters if they are out of bounds
    const int bottom_limit = window.camera_rect().bottom + 320;
    if (mario_.pos().y > bottom_limit) {
        mario_.lose_life();
        window.set_camera_topleft({window.camera_rect().left, window.camera_rect().top - 185});
        mario_.reset_position({window.camera_center().x - 80, window.camera_center().y - 20});
    }
    if (luigi_.pos().y > bottom_limit) {
        luigi_.lose_life();
        luigi_.reset_position({window.camera_center().x - 60, window.camera_center().y - 20});
    }

    // Finish game if a character have run out of lives
    if (mario_.lives() == 0 || luigi_.lives() == 0) {
        finished_ = true;
    }

    // Query visible objects
    pro2::Rect cam_rec = window.camera_rect();
    // Increase the query rectangle to preload the objects at the bottom and top of the screen
    pro2::Rect query_rec = {cam_rec.left, cam_rec.top - 160, cam_rec.right, cam_rec.bottom + 160};
    platform_actualObj_ = platform_finder_.query(query_rec);
    coin_actualObj_ = coin_finder_.query(query_rec);
    
    // Check collisions and update coins
    if (!coins_.empty()) {
        for (auto it = coins_.begin(); it != coins_.end(); it++) {
            if (objs_collision(mario_.rect(), it->get_rect()) || 
                objs_collision(luigi_.rect(), it->get_rect())) {
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
    const int limit_y = 140;

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
    // Paint the background and its objects
    const pro2::Rect cam_rect = window.camera_rect();
    if ((cam_rect.right / 1500) % 2 == 0) {
        window.clear(sky_blue);
    }
    else {
        window.clear(sky_dark);
    }

    // Draw platforms
    for (const Platform* p : platform_actualObj_) {
        p->paint(window);
    }

    // Draw coins
    for (const Coin* c : coin_actualObj_) {
        c->paint(window);
    }

    // Draw the counter
    Pt top_left = {cam_rect.left + 5, cam_rect.top + 35}; 
    paint_sprite(window, top_left, Coin::coin_sprite_front, false);
    pro2::Color text_color = ((cam_rect.right / 1500) % 2 == 0) ? pro2::black : pro2::white;
    window.draw_num({top_left.x + 17, top_left.y + 3}, std::to_string(num_coins_), text_color);

    // Draw characters
    mario_.paint(window);
    luigi_.paint(window);

    // Draw characters' lives
    mario_.paint_lives(window, "mario");
    luigi_.paint_lives(window, "luigi");
}