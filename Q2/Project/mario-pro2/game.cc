#include "game.hh"
using namespace pro2;

Game::Game(int width, int height)
    : mario_({width / 2, 150}, Keys::Space, Keys::Left, Keys::Right),
      mario2_({(width / 2) - 30, 150}, Keys::W, Keys::A, Keys::D),
      platforms_{
        Platform(100, 300, 200, 211),
        Platform(0, 200, 250, 261),
        Platform(250, 400, 150, 161),
      },
      coins_ {
        Coin({20, 232}),
        Coin({320, 132}),
      },
      paused_ (false),
      finished_(false),
      num_coins_(0) {
    for (int i = 1; i < 20; i++) {
        platforms_.push_back(Platform(250 + i * 200, 400 + i * 200, 150, 161));
        if (i % 2 != 0) platforms_.push_back(Platform(320 + i * 200, 370 + i * 200, 100, 111));
    }
    for (int i = 1; i < 20; i++) {
        if (i % 2 == 0) coins_.push_back(Coin({320 + i * 200, 132}));
        else coins_.push_back(Coin({410 + i * 200, 20}));
    }
}

void Game::process_keys(pro2::Window& window) {
    if (window.is_key_down(Keys::Escape)) {
        finished_ = true;
        return;
    }
    else if (window.was_key_pressed(80)) paused_ = !paused_;
}

void Game::update_objects(pro2::Window& window) {
    mario_.update(window, platforms_);
    mario2_.update(window, platforms_);
    
    if (!coins_.empty()) {
        for (auto it = coins_.begin(); it != coins_.end(); it++) {
            if (objs_collision(mario_.rect(), it->rect()) || objs_collision(mario2_.rect(), it->rect())) {
                num_coins_++;
                it = coins_.erase(it);
            }
            else it->update();
        }
    }
}
void Game::update_camera(pro2::Window& window) {
    const Pt pos = mario_.pos();
    const Pt cam = window.camera_center();

    int dx = 0, dy = 0;
    if (pos.x != cam.x) dx = pos.x - cam.x;

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

    for (const Platform& p : platforms_) {
        p.paint(window);
    }

    for (const Coin& c : coins_) {
        c.paint(window);
    }
    const pro2::Rect cam_rect = window.camera_rect();
    Pt top_left = {cam_rect.left + 5, cam_rect.top + 5}; 
    Pt top_left2 = {cam_rect.left + 22, cam_rect.top + 8};
    paint_sprite(window, top_left, Coin::coin_sprite_front, false);
    window.draw_num(top_left2, std::to_string(num_coins_), pro2::black);

    mario_.paint(window);
    mario2_.paint(window);
}