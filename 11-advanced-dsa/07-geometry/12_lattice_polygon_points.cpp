/*
 Simple nondegenerate integer polygon,3..30 vertices, coordinates magnitude<=1000, no
holes.

An edge contributes gcd(abs(dx), abs(dy)) lattice intervals; Pick gives
2*interior=2*area-boundary+2.

A 2x 2 square has doubled area 8, boundary 8, interior(8-8+2)/2=1.

Primitive lattice triangles satisfy Pick; triangulation and cancellation of
shared edges preserve it. The edge gcd counts equally spaced integer steps without
double-counting endpoints.

O(n log(C+1)) time for gcds, O(1) auxiliary storage.

Pick requires a nondegenerate simple lattice polygon without holes; do not apply it
to self-crossing or empty inputs.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <tuple>
#include <cstdlib>
#include <cstddef>
#include <numeric>

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

std::pair<long long, long long> lattice(const std::vector<Point>& polygon) {
    long long boundary = 0;
    for (std::size_t i = 0; i < polygon.size(); ++i) {
        auto a = polygon[i];
        auto b = polygon[(i + 1) % polygon.size()];
        boundary += std::gcd(std::abs(a.x - b.x), std::abs(a.y - b.y));
    }
    long long interior = (twiceArea(polygon) - boundary + 2) / 2;
    return {interior, boundary};
}

int main() {
    auto [inside, boundary] = lattice({{0, 0}, {2, 0}, {2, 2}, {0, 2}});
    assert(inside == 1 && boundary == 8);
    auto triangle = lattice({{0, 0}, {1, 0}, {0, 1}});
    assert(triangle.first == 0 && triangle.second == 3);
    std::cout << "checks passed\n";
    return 0;
}
