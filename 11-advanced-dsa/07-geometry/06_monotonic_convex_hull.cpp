/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

Sorted points form lower and upper chains with strictly left turns;
interior collinear points are discarded.

Point(1,1) lies inside the square and is popped from both outer chains.

A non-left turn places the middle point on or inside the hull edge joining its
neighbors, so removing it preserves the convex enclosure.

O(n log(n+1)) time, O(n) output/work storage.

Choose whether boundary collinear points are retained; this implementation keeps only
extreme endpoints.
*/
#include <iostream>
#include <cassert>
#include <vector>
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

std::vector<Point> hull(std::vector<Point> p) {
    std::sort(p.begin(), p.end());
    p.erase(std::unique(p.begin(), p.end()), p.end());
    if (p.size() < 2) {
        return p;
    }
    std::vector<Point> lower;
    std::vector<Point> upper;
    for (auto v : p) {
        while (lower.size() >= 2 && cross(lower[lower.size() - 2], lower.back(), v) <= 0) {
            lower.pop_back();
        }
        lower.push_back(v);
    }
    for (auto it = p.rbegin(); it != p.rend(); ++it) {
        while (upper.size() >= 2 && cross(upper[upper.size() - 2], upper.back(), *it) <= 0) {
            upper.pop_back();
        }
        upper.push_back(*it);
    }
    lower.pop_back();
    upper.pop_back();
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

int main() {
    auto h = hull({{0, 0}, {2, 0}, {2, 2}, {0, 2}, {1, 1}, {0, 0}});
    assert(h.size() == 4);
    assert(hull({{0, 0}, {1, 0}, {2, 0}}).size() == 2);
    assert(hull({}).empty());
    assert(hull({{1, 1}}).size() == 1);
    std::cout << "checks passed\n";
    return 0;
}
