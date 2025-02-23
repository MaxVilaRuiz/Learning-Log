#ifndef COLOR_PRINTER_HH
#define COLOR_PRINTER_HH

#include <iostream>

enum Color {
    black = 30,
    red = 31,
    green = 32,
    yellow = 33,
    blue = 34,
    magenta = 35,
    cyan = 36,
    white = 37,
};

class ColorPrinter {
   private:
    Color curr_color_;

   public:
    ColorPrinter() : curr_color_(Color::white) {}

    void set_color(Color c) {
        curr_color_ = c;
    }

    Color get_current_color() const {
        return curr_color_;
    }

    template <typename T>
    const ColorPrinter& operator<<(const T& t) const {
        std::cout << "\033[1;" << int(curr_color_) << "m" << t << "\033[0m";
        return *this;
    }

    // Special case to allow manipulators like std::endl, std::flush, etc.
    const ColorPrinter& operator<<(std::ostream& (*pf)(std::ostream& o)) const {
        std::cout << pf;
        return *this;
    }
};

#endif
