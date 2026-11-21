/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

A point on the supporting line belongs to the segment exactly when inside
its bounding box.

(3,3) is collinear with(0,0),(2,2), but exceeds the endpoint bounds.

On a collinear line, coordinate bounds restrict the interpolation parameter
to[0,1].

O(1) time/storage.

Collinearity alone tests an infinite line, not a finite segment.
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

int main() {
    assert(onSegment({0, 0}, {2, 2}, {1, 1}));
    assert(!onSegment({0, 0}, {2, 2}, {3, 3}));
    assert(onSegment({1, 1}, {1, 1}, {1, 1}));
    std::cout << "checks passed\n";
    return 0;
}
