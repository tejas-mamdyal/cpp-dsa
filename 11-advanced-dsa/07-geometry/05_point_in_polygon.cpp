/*
 Simple polygon<=30 vertices; integer query; returns an explicit boundary category.

Boundary is checked first; inside toggles when an edge crosses a ray to
the right, with exactly one endpoint strictly above p.

Ray from(2,2) crosses the square right edge once; ray from(5,2) crosses none.

Every transverse boundary crossing toggles membership; half-open y-tests avoid
counting a vertex twice.

O(n) time, O(1) space.

A horizontal edge does not satisfy the crossing test; boundary detection still
handles it.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <tuple>
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

bool onSegment(Point a, Point b, Point p) {
    return cross(a, b, p) == 0 && std::min(a.x, b.x) <= p.x && p.x <= std::max(a.x, b.x)
           && std::min(a.y, b.y) <= p.y && p.y <= std::max(a.y, b.y);
}
enum class Location {
    outside,
    boundary,
    inside
};

Location locate(const std::vector<Point>& polygon, Point p) {
    bool inside = false;
    for (std::size_t i = 0; i < polygon.size(); ++i) {
        Point a = polygon[i];
        Point b = polygon[(i + 1) % polygon.size()];
        if (onSegment(a, b, p)) {
            return Location::boundary;
        }
        if ((a.y > p.y) != (b.y > p.y)) {
            long long turn = cross(a, b, p);
            if ((b.y > a.y && turn > 0) || (b.y < a.y && turn < 0)) {
                inside = !inside;
            }
        }
    }
    return inside ? Location::inside : Location::outside;
}

int main() {
    std::vector<Point> p{{0, 0}, {4, 0}, {4, 4}, {0, 4}};
    assert(locate(p, {2, 2}) == Location::inside);
    assert(locate(p, {4, 2}) == Location::boundary);
    assert(locate(p, {5, 2}) == Location::outside);
    assert(locate({}, {0, 0}) == Location::outside);
    std::cout << "checks passed\n";
    return 0;
}
