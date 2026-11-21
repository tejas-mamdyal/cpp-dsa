/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

best is the smallest squared distance among pairs already visited.

Distances from(0,0) to(3,4) and(1,0) are 25 and 1; minimum is 1.

Every unordered pair is visited once, so the minimum is complete.

O(n^2) time, O(1) auxiliary storage.

Fewer than two points has no pair; zero is a valid answer for duplicates.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
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

std::optional<long long> closest(const std::vector<Point>& p) {
    std::optional<long long> best;
    for (std::size_t i = 0; i < p.size(); ++i) {
        for (std::size_t j = i + 1; j < p.size(); ++j) {
            auto d = squareDistance(p[i], p[j]);
            if (!best || d < *best) {
                best = d;
            }
        }
    }
    return best;
}

int main() {
    assert(closest({{0, 0}, {3, 4}, {1, 0}}) == 1);
    assert(closest({{2, 2}, {2, 2}}) == 0);
    assert(!closest({{1, 1}}));
    std::cout << "checks passed\n";
    return 0;
}
