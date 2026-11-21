/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

auto[x, y] copies the pair value; auto& binds names to the original
subobjects.

Changing x leaves point unchanged; changing rx updates point.first.

Reference binding aliases existing storage while value binding owns an
independent decomposition.

O(1) for an int pair.

Structured bindings can copy large objects unless reference intent is explicit.
*/
#include <iostream>
#include <cassert>
#include <utility>

std::pair<int, int> coordinates() {
    return {2, 5};
}

int main() {
    auto point = coordinates();
    auto [x, y] = point;
    x = 9;
    assert(point.first == 2 && y == 5);
    auto& [rx, ry] = point;
    rx = 7;
    ry = 8;
    assert(point.first == 7 && point.second == 8 && x == 9);
    std::cout << "checks passed\n";
    return 0;
}
