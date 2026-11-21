/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

Closed segments intersect at a boundary point or when endpoints strictly
straddle both supporting lines.

Two crossing diagonals have opposite orientation signs on both lines.

After excluding collinear endpoint cases, opposite-side tests are necessary and
sufficient for an interior crossing.

O(1) time/storage.

Multiply orientation signs only if bounds guarantee safety; direct sign comparisons
avoid that extra product.
*/
#include <iostream>
#include <cassert>
#include <algorithm>
#include <tuple>

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

bool intersects(Point a, Point b, Point c, Point d) {
    auto x = cross(a, b, c);
    auto y = cross(a, b, d);
    auto z = cross(c, d, a);
    auto w = cross(c, d, b);
    if (x == 0 && onSegment(a, b, c)) {
        return true;
    }
    if (y == 0 && onSegment(a, b, d)) {
        return true;
    }
    if (z == 0 && onSegment(c, d, a)) {
        return true;
    }
    if (w == 0 && onSegment(c, d, b)) {
        return true;
    }
    return ((x < 0 && y > 0) || (x > 0 && y < 0)) && ((z < 0 && w > 0) || (z > 0 && w < 0));
}

int main() {
    assert(intersects({0, 0}, {2, 2}, {0, 2}, {2, 0}));
    assert(intersects({0, 0}, {2, 0}, {2, 0}, {3, 0}));
    assert(!intersects({0, 0}, {1, 0}, {2, 0}, {3, 0}));
    assert(intersects({1, 1}, {1, 1}, {0, 0}, {2, 2}));
    std::cout << "checks passed\n";
    return 0;
}
