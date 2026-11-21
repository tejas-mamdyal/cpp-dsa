/*
 <=30 axis-aligned rectangles with x 1<x 2, y 1<y 2; coordinates magnitude<=1000.

Endpoint compression partitions the plane into cells with constant
coverage; sum covered y gaps for each x strip.

Two 2x 2 squares overlap in 1 unit of area, so union is 4+4-1=7.

Rectangle boundaries coincide with cell boundaries; each covered cell contributes
its physical area exactly once.

O(n^3) time, O(n) coordinates; an explicit small-input sweep baseline. Follow-up:
maintain y coverage with a segment tree for O(n log n).

Coordinate ranks do not measure length; subtract original coordinates.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

struct Rectangle {
    int x1;
    int y1;
    int x2;
    int y2;
};

long long unionArea(const std::vector<Rectangle>& rectangles) {
    std::vector<int> xs;
    std::vector<int> ys;
    for (auto r : rectangles) {
        xs.push_back(r.x1);
        xs.push_back(r.x2);
        ys.push_back(r.y1);
        ys.push_back(r.y2);
    }
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    std::sort(ys.begin(), ys.end());
    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());
    long long area = 0;
    for (std::size_t i = 1; i < xs.size(); ++i) {
        long long covered = 0;
        for (std::size_t j = 1; j < ys.size(); ++j) {
            bool present = false;
            for (auto r : rectangles) {
                if (r.x1 <= xs[i - 1] && xs[i] <= r.x2 && r.y1 <= ys[j - 1] && ys[j] <= r.y2) {
                    present = true;
                    break;
                }
            }
            if (present) {
                covered += ys[j] - ys[j - 1];
            }
        }
        area += static_cast<long long>(xs[i] - xs[i - 1]) * covered;
    }
    return area;
}

int main() {
    assert(unionArea({{0, 0, 2, 2}, {1, 1, 3, 3}}) == 7);
    assert(unionArea({{0, 0, 1, 1}, {1, 0, 2, 1}}) == 2);
    assert(unionArea({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
