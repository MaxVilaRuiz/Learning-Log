#include "utils.hh"
using namespace std;

namespace pro2 {

void paint_hline(Window& window, int xini, int xfin, int y, Color color) {
    for (int x = xini; x <= xfin; x++) {
        window.set_pixel({x, y}, color);
    }
}

void paint_vline(Window& window, int x, int yini, int yfin, Color color) {
    for (int y = yini; y <= yfin; y++) {
        window.set_pixel({x, y}, color);
    }
}

void paint_sprite(Window&              window,
                  Pt                   orig,
                  const vector<vector<int>>& sprite,
                  bool                       mirror) {
    for (int i = 0; i < sprite.size(); i++) {
        const vector<int>& line = sprite[i];
        for (int j = 0; j < line.size(); j++) {
            const int _j = mirror ? line.size() - j - 1 : j;
            if (line[_j] >= 0) {
                window.set_pixel({orig.x + j, orig.y + i}, line[_j]);
            }
        }
    }
}

void paint_rect(Window& window, Rect rectangle, Color color) {
    for (int x = rectangle.left; x < rectangle.right; x++) {
        for (int y = rectangle.bottom; y < rectangle.top; y++) {
            window.set_pixel({x,y}, color);
        }
    }
}

bool objs_collision(Rect obj1, Rect obj2) {
    bool left_coll = obj1.left < obj2.right && obj1.left > obj2.left;
    bool right_coll = obj1.right < obj2.right && obj1.right > obj2.left;
    bool top_coll = obj1.top > obj2.top && obj1.top < obj2.bottom;
    bool bottom_coll = obj1.bottom < obj2.bottom && obj1.bottom > obj2.top;
    return (left_coll && top_coll) || (left_coll && bottom_coll) || (right_coll && top_coll) || (right_coll && bottom_coll);
}

}