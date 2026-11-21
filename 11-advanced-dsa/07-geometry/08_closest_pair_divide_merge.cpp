/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

Each recursive slice initially has x-order and returns y-order plus its
minimum; capture split x before recursion.

The pair(50,1),(51,1) may straddle halves and is recovered from the strip.

Within-half minima are complete; any better crossing pair lies within sqrt(best)
of the split and each other vertically. Packing within each half bounds candidate neighbors by
a constant.

O(n log(n+1)) time, O(n) peak temporary storage plus O(log n) frames.

Reading p[mid].x after recursion is wrong because slices have already been reordered
by y.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <limits>
#include <tuple>
#include <iterator>
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

long long closestPart(std::vector<Point>& p, int left, int right) {
    constexpr long long infinity = std::numeric_limits<long long>::max() / 4;
    if (right - left <= 3) {
        long long best = infinity;
        for (int i = left; i < right; ++i) {
            for (int j = i + 1; j < right; ++j) {
                best = std::min(best, squareDistance(p[i], p[j]));
            }
        }
        std::sort(p.begin() + left, p.begin() + right, [](Point a, Point b) {
            return a.y < b.y;
        });
        return best;
    }
    int mid = (left + right) / 2;
    long long middleX = p[mid].x;
    long long best = std::min(closestPart(p, left, mid), closestPart(p, mid, right));
    std::vector<Point> merged;
    std::merge(p.begin() + left,
               p.begin() + mid,
               p.begin() + mid,
               p.begin() + right,
               std::back_inserter(merged),
               [](Point a, Point b) {
                   return a.y < b.y;
               });
    std::copy(merged.begin(), merged.end(), p.begin() + left);
    std::vector<Point> strip;
    for (int i = left; i < right; ++i) {
        long long dx = p[i].x - middleX;
        if (dx * dx < best) {
            for (std::size_t j = strip.size(); j > 0; --j) {
                long long dy = p[i].y - strip[j - 1].y;
                if (dy * dy >= best) {
                    break;
                }
                best = std::min(best, squareDistance(p[i], strip[j - 1]));
            }
            strip.push_back(p[i]);
        }
    }
    return best;
}

std::optional<long long> closest(std::vector<Point> p) {
    if (p.size() < 2) {
        return std::nullopt;
    }
    std::sort(p.begin(), p.end());
    return closestPart(p, 0, static_cast<int>(p.size()));
}

int main() {
    assert(closest({{0, 0}, {3, 4}, {1, 0}}) == 1);
    assert(closest({{2, 2}, {2, 2}}) == 0);
    assert(!closest({}));
    assert(closest({{0, 0}, {100, 0}, {50, 1}, {51, 1}}) == 1);
    std::cout << "checks passed\n";
    return 0;
}
