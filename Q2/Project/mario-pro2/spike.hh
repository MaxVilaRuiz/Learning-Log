#pragma once

#include <vector>
#include "platform.hh"
#include "utils.hh"


class Spike {
 private:
    static const std::vector<std::vector<int>> spike_sprite_;

    pro2::Pt pos_;


 public:
    Spike(pro2::Pt pos) : pos_(pos) {}

    /**
     * @brief Renders Spike.
     * @param window Target window.
     */
    void paint(pro2::Window& window) const;

    pro2::Rect get_rect() const;
};