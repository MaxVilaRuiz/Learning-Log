#include <vector>
#include <iostream>
#include "window.hh"

using pro2::ModKey, pro2::Colors;
using std::vector;

const int WIDTH = 320, HEIGHT = 200;
const int ZOOM = 3;

void paint_line(pro2::Window& window, int j, int color) {
    for (int i = 0; i < HEIGHT; i++) {
        window.set_pixel({j, i}, color);
    }
}

int bar_position(int time) {
    int f = time % (HEIGHT * 2);
    return (f >= HEIGHT ? (2 * HEIGHT - 1) - f : f);
}

int main() {
    pro2::Window window("Window Animation", WIDTH, HEIGHT, ZOOM);
    pro2::Pt last_mouse = window.mouse_pos();  // Última posición conocida
    bool inside_window = true;

    while (window.next_frame()) {
        if (window.is_key_pressed(27)) {
            break;
        }

        window.clear(Colors::black);

        pro2::Pt mouse = window.mouse_pos();

        // Si la posición del ratón no cambia entre frames, asumimos que está fuera
        if (mouse.x == last_mouse.x && mouse.y == last_mouse.y) {
            inside_window = false;
        } else if (mouse.x >= 0 && mouse.x < WIDTH && mouse.y >= 0 && mouse.y < HEIGHT) {
            inside_window = true;
        }

        last_mouse = mouse;  // Guardamos la posición para el próximo frame

        if (inside_window) {
            int j = bar_position(window.frame_count());
            paint_line(window, j, Colors::yellow);
        }

        if (window.is_key_pressed(32)) {
            paint_line(window, mouse.y, Colors::red);
        }
    }
}
