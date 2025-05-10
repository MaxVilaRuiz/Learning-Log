#pragma once

// #include <iostream>
#include <vector>
#include "platform.hh"

class Coin { 
  private:
    pro2::Pt pos_;
    int frame_ = 0;

    static const std::vector<std::vector<int>> coin_sprite_oval_;
    static const std::vector<std::vector<int>> coin_sprite_side_;

  public:
    static const std::vector<std::vector<int>> coin_sprite_front; 

    Coin(pro2::Pt pos) : pos_(pos) {}

    void paint(pro2::Window& window) const;

    void update();

    /**
     * @brief Retorna el rectangle que conté a l'objecte que rep per paràmetre implícit.
     */
    pro2::Rect rect() const;
};