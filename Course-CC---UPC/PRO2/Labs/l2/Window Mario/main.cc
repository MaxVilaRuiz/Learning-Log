#include <vector>
#include <iostream>
#include "window.hh"

using namespace std;
using pro2::Colors;

const int WIDTH = 256, HEIGHT = 240;
const int ZOOM = 2;

const int _ = -1;
const int r = Colors::red;
const int s = 0xecc49b;
const int b = 0x5e6ddc;
const int y = Colors::yellow;
const int h = Colors::black;
const int g = 0xaaaaaa;
const int w = 0x8d573c;

// Definir sprite de Mario
const vector<vector<int>> mario_sprite = {
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, r, b, r, r, r, _, _, _, _},
    {_, r, r, r, b, r, r, b, r, r, r, _},
    {r, r, r, r, b, b, b, b, r, r, r, r},
    {g, g, r, b, y, b, b, y, b, r, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {w, w, w, w, _, _, _, _, w, w, w, w},
};

// Constantes de teclas
const char arrow_up = 38;    // Flecha arriba
const char arrow_down = 40;  // Flecha abajo
const char arrow_left = 37;  // Flecha izquierda
const char arrow_right = 39; // Flecha derecha

// Función para dibujar el sprite en la ventana
void put_sprite(pro2::Window& window, pro2::Pt orig, const vector<vector<int>>& sprite) {
    for (int i = 0; i < sprite.size(); i++) {
        const vector<int>& line = sprite[i];
        for (int j = 0; j < line.size(); j++) {
            if (line[j] >= 0) {
                window.set_pixel({orig.x + j, orig.y + i}, line[j]);
            }
        }
    }
}

int main() {
    pro2::Window window("Mario Bros", WIDTH, HEIGHT, ZOOM);

    pro2::Pt mario = {WIDTH / 2 - 6, HEIGHT / 2 - 8}; // Posición inicial

    while (window.next_frame()) {
        // Limpiar la ventana antes de dibujar
        window.clear();

        // Movimiento en eje X
        if (window.is_key_pressed(arrow_right)) mario.x++;
        if (window.is_key_pressed(arrow_left)) mario.x--;

        // Movimiento en eje Y
        if (window.is_key_pressed(arrow_up)) mario.y--;
        if (window.is_key_pressed(arrow_down)) mario.y++;

        // Dibujar a Mario en la nueva posición
        put_sprite(window, mario, mario_sprite);
    }

    return 0;
}
