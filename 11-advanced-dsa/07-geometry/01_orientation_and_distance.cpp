/*
std::tie(a,b) creates a tuple of references to existing variables. Tuple comparison is lexicographic: compare a first, then b only when the first fields are equal. Here it expresses coordinate order without changing either point; references must not outlive their targets.
*/
/*
 Integer coordinate magnitudes<=1000 throughout this unit unless stated. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

cross is twice the oriented triangle area; its sign distinguishes left,
right and collinear.

Edge(0,0)->(2,0), point(1,1) gives 2, so it is a left turn.

The determinant measures signed parallelogram area and changes sign when
orientation reverses.

O(1) time/storage.

Cast or store coordinates wide before multiplying; assigning an overflowing int
product to long long is too late.
*/
#include <iostream>
#include <cassert>
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

int main() {
    assert(cross({0, 0}, {2, 0}, {1, 1}) > 0);
    assert(cross({0, 0}, {2, 0}, {1, -1}) < 0);
    assert(cross({0, 0}, {2, 0}, {3, 0}) == 0);
    assert(squareDistance({0, 0}, {3, 4}) == 25);
    std::cout << "checks passed\n";
    return 0;
}
