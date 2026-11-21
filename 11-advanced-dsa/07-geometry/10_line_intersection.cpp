/*
 Two nondegenerate integer-endpoint lines; coordinate magnitudes<=1000; returned
double values checked within 1e-9.

a+t*(b-a) lies on line cd when its cross product with d-c vanishes; solve
for t.

Two diagonals give t=1/2 and intersection(1,1).

Solving the two linear equations by determinants gives the unique intersection
when determinant is nonzero.

O(1) time/storage.

Absent means no unique line intersection, including coincident lines; this is not a
segment-range test.
*/
#include <iostream>
#include <cassert>
#include <optional>
#include <tuple>
#include <cstdlib>

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

struct RealPoint {
    double x;
    double y;
};

std::optional<RealPoint> intersection(Point a, Point b, Point c, Point d) {
    long long denominator = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);
    if (denominator == 0) {
        return std::nullopt;
    }
    long long numerator = (c.x - a.x) * (d.y - c.y) - (c.y - a.y) * (d.x - c.x);
    double t = static_cast<double>(numerator) / static_cast<double>(denominator);
    return RealPoint{a.x + t * (b.x - a.x), a.y + t * (b.y - a.y)};
}

int main() {
    auto p = intersection({0, 0}, {2, 2}, {0, 2}, {2, 0});
    assert(p && std::abs(p->x - 1.0) < 1e-9 && std::abs(p->y - 1.0) < 1e-9);
    assert(!intersection({0, 0}, {1, 0}, {0, 1}, {1, 1}));
    std::cout << "checks passed\n";
    return 0;
}
