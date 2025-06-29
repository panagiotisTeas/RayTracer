#include "color.hpp"

void write_color(std::ofstream& out, const color3& pixel_color) {
    auto r = pixel_color.getX();
    auto g = pixel_color.getY();
    auto b = pixel_color.getZ();

    // Translate the [0,1] component values to the byte range [0,255].
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}