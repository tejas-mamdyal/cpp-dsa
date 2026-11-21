/*
 Simple polygon with<=30 vertices; empty/degenerate inputs return 0. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

Sum directed edge determinants, then take absolute value for unsigned
area.

Right triangle legs 3 and 1 has doubled area 3, actual area 1.5.

Signed triangle areas against the origin cancel interior directed edges and leave
the polygon area.

O(n) time, O(1) auxiliary storage.

The formula assumes a simple polygon for ordinary filled area; self-intersections
give algebraic area.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <tuple>
#include <cstdlib>
#include <cstddef>

struct Point {
    long long x;
    long long y;

    bool operator==(const Point& b) const {
        return x == b.x && y == b.y;
    }

    bool operator<(const Point& b) const {
        return std::tie(x, y) < std::tie(b.x, b.y);
    }
};

long long cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

long long squareDistance(Point a, Point b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}

long long twiceArea(const std::vector<Point>& polygon) {
    long long total = 0;
    for (std::size_t i = 0; i < polygon.size(); ++i) {
        auto a = polygon[i];
        auto b = polygon[(i + 1) % polygon.size()];
        total += a.x * b.y - a.y * b.x;
    }
    return std::abs(total);
}

int main() {
    assert(twiceArea({{0, 0}, {3, 0}, {0, 1}}) == 3);
    assert(twiceArea({{0, 0}, {0, 2}, {2, 2}, {2, 0}}) == 8);
    assert(twiceArea({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
