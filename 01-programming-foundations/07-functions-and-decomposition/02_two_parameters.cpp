/*
ARGUMENTS BIND TO PARAMETERS IN ORDER
Route: Core | Prerequisites: Units 01–06: decisions, loops and repeated input.

The caller supplies two arguments; the callee uses descriptive parameter names to
express the rectangle formula.

O(1) time/space.

Parameter order is part of the interface, even when both have the same type.
*/
#include <iostream>

int perimeter(int width, int height) {
    return 2 * (width + height);
}

int main() {
    int w = 0;
    int h = 0;
    if (!(std::cin >> w >> h) || !(w >= 0 && w <= 1000 && h >= 0 && h <= 1000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    std::cout << perimeter(w, h) << "\n";
}
