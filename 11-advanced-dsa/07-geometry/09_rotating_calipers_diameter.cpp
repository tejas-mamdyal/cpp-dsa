/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

For each hull edge, j maximizes its nonnegative oriented area; the support
point advances monotonically around the convex polygon.

A square edge reaches either opposite vertex; diagonal squared length is 8.

A farthest pair is antipodal on the convex hull; monotone support directions
enumerate such pairs, including tied opposite edges.

O(n log(n+1)) hull construction plus O(h) calipers, O(n) storage.

Area ties can represent two candidate support vertices; check both rather than
skipping a diagonal.
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

long long diameter(const std::vector<Point>& points) {
    auto h = hull(points);
    if (h.size() < 2) {
        return 0;
    }
    if (h.size() == 2) {
        return squareDistance(h[0], h[1]);
    }
    std::size_t j = 1;
    long long best = 0;
    for (std::size_t i = 0; i < h.size(); ++i) {
        std::size_t next = (i + 1) % h.size();
        while (cross(h[i], h[next], h[(j + 1) % h.size()]) > cross(h[i], h[next], h[j])) {
            j = (j + 1) % h.size();
        }
        best = std::max({best, squareDistance(h[i], h[j]), squareDistance(h[next], h[j])});
        if (cross(h[i], h[next], h[(j + 1) % h.size()]) == cross(h[i], h[next], h[j])) {
            best = std::max({best,
                             squareDistance(h[i], h[(j + 1) % h.size()]),
                             squareDistance(h[next], h[(j + 1) % h.size()])});
        }
    }
    return best;
}

int main() {
    assert(diameter({{0, 0}, {2, 0}, {2, 2}, {0, 2}, {1, 1}}) == 8);
    assert(diameter({{0, 0}, {3, 4}}) == 25);
    assert(diameter({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
