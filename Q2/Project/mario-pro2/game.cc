#include "game.hh"
using namespace pro2;


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

    // Generate coins
    for (int i = 1; i < 98; i++) {
        for (int j = 1; j < 5; j++) {
            coins_.push_back(Coin({50 * j + i * 200, 382}));
        }

        if (i % 2 == 0) coins_.push_back(Coin({320 + i * 200, 132}));
        else coins_.push_back(Coin({410 + i * 200, 20}));

        if (i % 3 == 0) coins_.push_back(Coin({420 + i * 200, 182}));
    }

    // Generate spikes
    for (int i = 1; i < 50; i++) {
        for (int j = 1; j < 4; j++) {
            spikes_.push_back(Spike({280 + 200 * i + 10 * j, 142}));
        }
    }

    // Generate goombas
    for (int i = 0; i < 98; i++) {
        if (i % 2 == 1) goombas_.push_back(Goomba({325 + i * 200, 139}));
    }

    // Add platforms to finder
    for (const auto& plataform : platforms_) {
        platform_finder_.add(&plataform);
    }

    // Add coins to finder
    for (const auto& coin : coins_) {
        coin_finder_.add(&coin);
    }

    // Add spikes to finder
    for (const auto& spike : spikes_) {
        spike_finder_.add(&spike);
    }

    // Add goombas to finder
    for (const auto& goomba : goombas_) {
        goombas_finder_.add(&goomba);
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
    // Update main characters
    mario_.update(window, platform_actualObj_, spike_actualObj_);
    luigi_.update(window, platform_actualObj_, spike_actualObj_);

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
    spike_actualObj_ = spike_finder_.query(query_rec);
    goombas_actualObj_ = goombas_finder_.query(query_rec);
    
    // Check collisions and update coins
    for (auto it = coin_actualObj_.begin(); it != coin_actualObj_.end();) {
        const Coin* c = *it;
        if (objs_collision(mario_.rect(), c->get_rect()) ||
            objs_collision(luigi_.rect(), c->get_rect())) {
            coin_finder_.remove(c);    
            it = coin_actualObj_.erase(it);
            num_coins_++;                   
        } else {
            Coin* non_const_coin = const_cast<Coin*>(c);
            non_const_coin->update();
            ++it;
        }
    }

    // Check collisions with spikes
    for (const Spike* s : spike_actualObj_) {
        if (!immune_mario_ && objs_collision(mario_.rect(), s->get_rect())) {
            mario_.lose_life();
            immune_mario_ = true;
            immunity_mario_until_ = frame_counter_ + immunity_interval_;
        }

        if (!immune_luigi_ && objs_collision(luigi_.rect(), s->get_rect())) {
            luigi_.lose_life();
            immune_luigi_ = true;
            immunity_luigi_until_ = frame_counter_ + immunity_interval_;
        }
    }

    // Update Goombas
    for (auto it = goombas_actualObj_.begin(); it != goombas_actualObj_.end();) {
        Goomba* goomba = const_cast<Goomba*>(*it);
        const pro2::Rect goomba_rect = goomba->get_rect();
        bool remove = false;

        if (goomba->is_squashed() && goomba->get_deadtime() <= frame_counter_) {
            goombas_finder_.remove(goomba);
            it = goombas_actualObj_.erase(it);
            continue;
        }
    
        // Mario' collision
        if (objs_collision(mario_.rect(), goomba_rect)) {
            if (mario_.rect().bottom <= goomba_rect.top + 5) {
                if (!goomba->is_squashed()) {
                    goomba->hit_from_above(frame_counter_);
                    mario_.set_grounded(true);
                }
            }
            else if (!immune_mario_ && !goomba->is_squashed()) {
                mario_.lose_life();
                immune_mario_ = true;
                immunity_mario_until_ = frame_counter_ + immunity_interval_;
            }
        }

        // Luigi' collision
        if (objs_collision(luigi_.rect(), goomba_rect)) {
            if (luigi_.rect().bottom <= goomba_rect.top + 5) {
                if (!goomba->is_squashed()) {
                    goomba->hit_from_above(frame_counter_);
                    luigi_.set_grounded(true);
                }
            } 
            else if (!immune_luigi_ && !goomba->is_squashed()) {
                luigi_.lose_life();
                immune_luigi_ = true;
                immunity_luigi_until_ = frame_counter_ + immunity_interval_;
            }
        }
    
        goomba->update();
        ++it;
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

    // To update the background status
    frame_counter_++;
    if (frame_counter_ % day_night_interval_ == 0) {
        day_time_ = !day_time_;
    }

    // To update the characters immunity
    if (immune_mario_ && immunity_mario_until_ <= frame_counter_) immune_mario_ = false;
    if (immune_luigi_ && immunity_luigi_until_ <= frame_counter_) immune_luigi_ = false;
}


void Game::paint(pro2::Window& window) {
    // Paint the background and its objects
    if (day_time_) window.clear(sky_blue);
    else window.clear(sky_dark);

    // Draw platforms
    for (const Platform* p : platform_actualObj_) {
        p->paint(window);
    }

    // Draw coins
    for (const Coin* c : coin_actualObj_) {
        c->paint(window);
    }

    // Draw spikes
    for (const Spike* s : spike_actualObj_) {
        s->paint(window);
    }

    // Draw goombas
    for (const Goomba* g : goombas_actualObj_) {
        g->paint(window);
    }

    // Draw the counter
    const pro2::Rect cam_rect = window.camera_rect();
    Pt top_left = {cam_rect.left + 5, cam_rect.top + 35}; 
    paint_sprite(window, top_left, Coin::coin_sprite_front, false);
    pro2::Color text_color = (day_time_) ? pro2::black : pro2::white;
    window.draw_num({top_left.x + 17, top_left.y + 3}, std::to_string(num_coins_), text_color);

    // Draw characters
    mario_.paint(window, immune_mario_, frame_counter_);
    luigi_.paint(window, immune_luigi_, frame_counter_);

    // Draw characters' lives
    mario_.paint_lives(window, "mario");
    luigi_.paint_lives(window, "luigi");
}