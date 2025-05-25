#include <vector>
#include "game.hh"
#include "window.hh"

using namespace std;

const int WIDTH = 480, HEIGHT = 320;
const int ZOOM = 2;
const int FPS = 48;

/**
 * @brief Main loop of the game.
 */
int main() {
    // Create and configure the game window
    pro2::Window window("Mario Pro 2", WIDTH, HEIGHT, ZOOM);
    window.set_fps(FPS);

    // Initialize game state
    Game game(WIDTH, HEIGHT);

    // Main game loop
    while (window.next_frame() && !game.is_finished()) {
        game.update(window);  // Update game logic
        game.paint(window);   // Render game
    }
}