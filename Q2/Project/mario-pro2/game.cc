#include "game.hh"
using namespace pro2;


Game::Game(int width, int height)
    : mario_({width / 2, 150}, Keys::Up, Keys::Down, Keys::Left, Keys::Right, "mario"),
      luigi_({(width / 2) - 30, 150}, Keys::W, Keys::S, Keys::A, Keys::D, "luigi"),

      // Unsorted objects
      platforms_{
        Platform(0, 300, 200, 450),        
        Platform(315, 385, 150, 161),
        Platform(400, 600, 200, 450),
        Platform(450, 550, 155, 166),

        Platform(625, 675, 170, 181),
        Platform(700, 750, 140, 151),
        Platform(775, 875, 110, 121),
        Platform(775, 800, 170, 181),
        Platform(900, 950, 140, 151),
        Platform(975, 1025, 170, 181),
        Platform(1050, 1100, 200, 211),

        Platform(1125, 1325, 200, 450),
        Platform(1175, 1275, 155, 166),

        Platform(1350, 1400, 230, 241),
        Platform(1425, 1475, 260, 271),
        Platform(1500, 1550, 290, 301),
        Platform(1585, 1635, 290, 301),
        Platform(1670, 1700, 290, 301),
        Platform(1670, 1700, 210, 221),
        Platform(1670, 1700, 130, 141),

        Platform(1350, 1400, 170, 181),
        Platform(1425, 1475, 140, 151),
        Platform(1500, 1550, 110, 121),
        Platform(1575, 1625, 80, 91),
        Platform(1650, 1720, 50, 61),
        Platform(1750, 1820, 50, 61),
        Platform(1850, 2051, 80, 91),
        Platform(2080, 2155, 110, 121),
        Platform(2105, 2130, 160, 171),
        Platform(2180, 2230, 140, 151),

        Platform(2260, 3000, 170, 420),
        Platform(2325, 2400, 130, 141),

        Platform(2500, 2520, 150, 170),
        Platform(2538, 2558, 130, 170),
        Platform(2576, 2596, 110, 170),
        Platform(2614, 2634, 90, 170),
        Platform(2652, 2672, 110, 170),        
        Platform(2690, 2710, 130, 170),
        Platform(2728, 2748, 150, 170),
      },

      coins_ {
        Coin({345, 130}),
        Coin({820, 90})
      },

      spikes_ {
        Spike({291, 192}),
        Spike({400, 192}),
      },

      goombas_ {
        Goomba({496, 189}, 60),
        Goomba({921, 129}, 20),
        Goomba({1071, 189}, 20),
        Goomba({2113, 99}, 35)
      },

      mushrooms_ {
        Mushroom({1220, 144}),
        Mushroom({2112, 149}),
      },

      stars_ {
        Star({781, 155}),
        Star({1678, 275}),
      }

    {
        
    // Sorted objects

    // Generate coins
    for (int i = 0; i < 3; i++) {
        coins_.push_back(Coin({475 + 20*i, 135}));
        coins_.push_back(Coin({1665 + 15*i, 30}));
        coins_.push_back(Coin({2342 + 15*i, 110}));
    }

    // Generate spikes
    for (int i = 0; i < 2; i++) {
        spikes_.push_back(Spike({991 + 9*i, 162}));
        spikes_.push_back(Spike({666 + 75*i, 162 - 30*i}));
        spikes_.push_back(Spike({2180 + 41*i, 132}));
        spikes_.push_back(Spike({2491 + 257*i, 162}));
    }
    for (int i = 0; i < 3; i++) {
        spikes_.push_back(Spike({1350 + 75*i, 222 + 30*i}));
        spikes_.push_back(Spike({1391 + 75*i, 222 + 30*i}));
        spikes_.push_back(Spike({1771 + 9*i, 42}));
        for (int j = 0; j < 3; j++) spikes_.push_back(Spike({1880 + 9*j + 57*i, 72}));
    }
    for (int i = 0; i < 4; i++) {
        spikes_.push_back(Spike({1391 + 75*i, 162 - 30*i}));
    }
    for (int i = 0; i < 6; i++) {
        spikes_.push_back(Spike({2520 + 38*i, 162}));
        spikes_.push_back(Spike({2529 + 38*i, 162}));
    }

    // Generate gooombas
    for (int i = 0; i < 2; i++) goombas_.push_back(Goomba({1171 + 100*i, 189}, 45));
    
        





    // // Generate platforms
    // for (int i = 1; i < 98; i++) {
    //     platforms_.push_back(Platform(250 + i * 200, 400 + i * 200, 150, 161));
    //     platforms_.push_back(Platform(i * 200, 480 + i * 200, 400, 411));

    //     if (i % 2 != 0) {
    //         platforms_.push_back(Platform(320 + i * 200, 370 + i * 200, 100, 111));
    //     }

    //     if (i % 3 == 0) {
    //         platforms_.push_back(Platform(405 + i * 200, 445 + i * 200, 200, 211));
    //     }
    // }

    // // Generate coins
    // for (int i = 1; i < 98; i++) {
    //     for (int j = 1; j < 5; j++) {
    //         coins_.push_back(Coin({50 * j + i * 200, 382}));
    //     }

    //     if (i % 2 == 0) coins_.push_back(Coin({320 + i * 200, 132}));
    //     else coins_.push_back(Coin({410 + i * 200, 20}));

    //     if (i % 3 == 0) coins_.push_back(Coin({420 + i * 200, 182}));
    // }

    // // Generate spikes
    // for (int i = 1; i < 50; i++) {
    //     for (int j = 1; j < 4; j++) {
    //         spikes_.push_back(Spike({280 + 200 * i + 10 * j, 142}));
    //     }
    // }

    // // Generate mushrooms
    // for (int i = 1; i < 50; i++) {
    //     mushrooms_.push_back(Mushroom({340 + 200 * i, 139}));
    // }

    // // Generate goombas
    // for (int i = 0; i < 98; i++) {
    //     if (i % 2 == 1) goombas_.push_back(Goomba({325 + i * 200, 139}));
    // }

    // // Generate stars
    // for (int i = 1; i < 50; i++) {
    //     stars_.push_back(Star({350 + 200 * i, 137}));
    // }


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

    // Add mushrooms to finder
    for (const auto& mushroom : mushrooms_) {
        mushroom_finder_.add(&mushroom);
    }

    // Add goombas to finder
    for (const auto& goomba : goombas_) {
        goombas_finder_.add(&goomba);
    }

    // Add stars to finder
    for (const auto& star : stars_) {
        star_finder_.add(&star);
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
        // mario_.lose_life();
        Pt mario_last_pos = mario_.last_grounded_pos();
        mario_.reset_position({mario_last_pos.x, mario_last_pos.y});
    }
    if (luigi_.pos().y > bottom_limit) {
        // luigi_.lose_life();
        Pt luigi_last_pos = luigi_.last_grounded_pos();
        luigi_.reset_position({luigi_last_pos.x, luigi_last_pos.y});
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
    mushroom_actualObj_ = mushroom_finder_.query(query_rec);
    goombas_actualObj_ = goombas_finder_.query(query_rec);
    star_actualObj_ = star_finder_.query(query_rec);
    
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

    // Check collisions and update mushrooms
    for (auto it = mushroom_actualObj_.begin(); it != mushroom_actualObj_.end();) {
        const Mushroom* m = *it;
        if (objs_collision(mario_.rect(), m->get_rect())) {
            mushroom_finder_.remove(m);    
            it = mushroom_actualObj_.erase(it);
            mario_.eat_mushroom();            
        }
        else if (objs_collision(luigi_.rect(), m->get_rect())) {
            mushroom_finder_.remove(m);    
            it = mushroom_actualObj_.erase(it);
            luigi_.eat_mushroom();            
        }
        else {
            Mushroom* non_const_coin = const_cast<Mushroom*>(m);
            non_const_coin->update();
            ++it;
        }
    }

    // Check collisions with spikes
    for (const Spike* s : spike_actualObj_) {
        if (!immune_mario_ && objs_collision(mario_.rect(), s->get_rect())) {
            immune_mario_ = true;
            immunity_mario_until_ = (mario_.is_big()) ? frame_counter_ + 1.5*immunity_interval_ 
                                    : frame_counter_ + immunity_interval_;
            // mario_.lose_life();
        }

        if (!immune_luigi_ && objs_collision(luigi_.rect(), s->get_rect())) {
            immune_luigi_ = true;
            immunity_luigi_until_ = (luigi_.is_big()) ? frame_counter_ + 1.5*immunity_interval_ 
                                    : frame_counter_ + immunity_interval_;
            // luigi_.lose_life();
        }
    }

    // Check collisions and update goombas
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
                immune_mario_ = true;
                immunity_mario_until_ = (mario_.is_big()) ? frame_counter_ + 1.5*immunity_interval_ 
                                        : frame_counter_ + immunity_interval_;
                // mario_.lose_life();
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
                immune_luigi_ = true;
                immunity_luigi_until_ = (luigi_.is_big()) ? frame_counter_ + 1.5*immunity_interval_ 
                                        : frame_counter_ + immunity_interval_;
                // luigi_.lose_life();
            }
        }
    
        goomba->update();
        it++;
    }

    // Check collisions and update stars
    for (auto it = star_actualObj_.begin(); it != star_actualObj_.end();) {
        const Star* s = *it;
        if (objs_collision(mario_.rect(), s->get_rect())) {
            star_finder_.remove(s);    
            it = star_actualObj_.erase(it);
            mario_.handle_star();           
        }
        else if (objs_collision(luigi_.rect(), s->get_rect())) {
            star_finder_.remove(s);    
            it = star_actualObj_.erase(it);
            luigi_.handle_star();          
        }
        else {
            Star* non_const_star = const_cast<Star*>(s);
            non_const_star->update();
            ++it;
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
    if ((mario_pos.y < cam.y - limit_y || mario_pos.y > cam.y + limit_y) && mario_.is_grounded()) {
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

    // Draw mushrooms
    for (const Mushroom* m : mushroom_actualObj_) {
        m->paint(window);
    }

    // Draw goombas
    for (const Goomba* g : goombas_actualObj_) {
        g->paint(window);
    }

    // Draw stars
    for (const Star* s : star_actualObj_) {
        s->paint(window);
    }

    // Draw the star mode logo
    const pro2::Rect cam_rect = window.camera_rect();
    if (mario_.is_in_starmode_() || luigi_.is_in_starmode_()) {
        Pt top_left = {cam_rect.left + 5, cam_rect.top + 51};

        if (mario_.star_countdown() < 180 && luigi_.star_countdown() < 180) {
            if ((frame_counter_ / 9) % 2 == 0) {
                paint_sprite(window, top_left, Star::star_sprite_front, false);
            }
        }
        else paint_sprite(window, top_left, Star::star_sprite_front, false);
    }

    // Draw the coin counter
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