#pragma once

#include <unordered_map>
#include <set>
#include <algorithm>
#include "geometry.hh"

template <class T>
class Finder {
 private:
    // Grid 480 x 640 (sued by game.cc) - max 52 cols, 39 rows
    inline static const int CELL_WIDTH = 480;
    inline static const int CELL_HEIGHT = 640;
    inline static const int MAX_X = 25000;
    inline static const int MAX_Y = 25000;
    inline static const int MAX_COL = MAX_X / CELL_WIDTH;
    inline static const int MAX_ROW = MAX_Y / CELL_HEIGHT;

    // Cell Grid
    std::unordered_map<int, std::unordered_map<int, std::set<const T*>>> objects_;

    /**
     * @brief Adds or removes object `t` from the spatial grid based on the `add` parameter.
     * @pre
     * - `t` != nullptr
     * - `pro2::Rect r = t->get_rect()`:
     *   - `0 <= r.left <= r.right <= MAX_COL * CELL_WIDTH`
     *   - `0 <= r.top <= r.bottom <= MAX_ROW * CELL_HEIGHT`
     * @post
     * - If `add` is `true`, `t` is inserted into all grid cells that intersect with its rectangle.
     * - Otherwise, `t` is removed from all grid cells that intersect with its rectangle.
     * @param t Pointer to an object of type T that implements `get_rect() const`.
     * @param add Indicates whether to add (`true`) or remove (`false`) the object `t` from the grid.
    */
    void apply_action(const T *t, bool add) {
        pro2::Rect t_r = t->get_rect();
        int left_cell = std::max(0, t_r.left / CELL_WIDTH);
        int right_cell = std::min(MAX_COL, t_r.right / CELL_WIDTH);
        int top_cell = std::max(0, t_r.top / CELL_HEIGHT);
        int bottom_cell = std::min(MAX_ROW, t_r.bottom / CELL_HEIGHT);

        for (int i = left_cell; i <= right_cell; i++) {
            for (int j = top_cell; j <= bottom_cell; j++) {
                if (add) objects_[i][j].insert(t);
                else objects_[i][j].erase(t);
            }
        }
    }

 public:
    Finder() {}

    /**
     * @brief Adds an object to the spatial grid.
     * @param t Pointer to the object to be added.
     * @pre t != nullptr
     * @post Object t is registered in all grid cells overlapping its bounding box.
     */
    void add(const T* t) {
        apply_action(t, true);
    }

    /**
     * @brief Removes an object from the spatial grid.
     * @param t Pointer to the object to be removed.
     * @pre t != nullptr
     * @post Object t is removed from all grid cells it was registered in.
     */
    void remove(const T* t) {
        apply_action(t, false);
    }

    /**
     * @brief Updates the position of an object in the spatial grid.
     * @param t Pointer to the object to be updated.
     * @pre t != nullptr
     * @post Object t is reinserted in grid cells based on its new position.
     */
    void update(const T* t) {
        remove(t);
        add(t);
    }

    /**
     * @brief Queries all objects currently overlapping a given rectangle.
     * @param qrect The query rectangle.
     * @return Set of pointers to objects that intersect qrect.
     * @pre qrect is within the bounds of the grid.
     * @post Returns all objects whose bounding boxes overlap qrect.
     */
    std::set<const T*> query(pro2::Rect qrect) const {
        std::set<const T*> aux;
        int left_cell = std::max(0, qrect.left / CELL_WIDTH);
        int right_cell = std::min(MAX_COL, qrect.right / CELL_WIDTH);
        int top_cell = std::max(0, qrect.top / CELL_HEIGHT);
        int bottom_cell = std::min(MAX_ROW, qrect.bottom / CELL_HEIGHT);

        // Gather objects from overlapping cells
        for (int i = left_cell; i <= right_cell; i++) {
            for (int j = top_cell; j <= bottom_cell; j++) {
                if (objects_.count(i) && objects_.at(i).count(j)) {
                    for (const T* obj : objects_.at(i).at(j)) aux.insert(obj);
                }
            }
        }

        // Filter objects that truly intersect the query rectangle
        std::set<const T*> res;
        for (const T* obj : aux) {
            pro2::Rect obj_r = obj->get_rect();
            if (obj_r.right >= qrect.left && obj_r.left <= qrect.right &&
                obj_r.bottom >= qrect.top && obj_r.top <= qrect.bottom) {
                res.insert(obj);
            }
        }

        return res;
    }

    /**
     * @brief Clears all objects from the spatial grid.
     * @post All internal grid cells are emptied.
     */
    void clear() { objects_.clear(); }
};