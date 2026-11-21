/*
 Strictly increasing positive travel days; nonnegative pass prices. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

best[i] is minimum cost covering travel days from i onward.

A 7-day pass beginning at day 4 covers 4,6,7,8.

The first uncovered day must be covered by one of the three passes; moving its
start to that day never hurts.

O(n^2) reference time, O(n) storage; binary-search pass endpoints for O(n log n).

A duration 7 pass covers start through start+6, not start+7.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <array>

int tickets(const std::vector<int>& days, const std::array<int, 3>& prices) {
    std::vector<int> best(days.size() + 1);
    std::array<int, 3> durations{1, 7, 30};
    for (int i = static_cast<int>(days.size()) - 1; i >= 0; --i) {
        best[i] = 1000000000;
        for (int p = 0; p < 3; ++p) {
            int next = i;
            while (next < static_cast<int>(days.size()) && days[next] < days[i] + durations[p]) {
                ++next;
            }
            best[i] = std::min(best[i], prices[p] + best[next]);
        }
    }
    return best[0];
}

int main() {
    assert(tickets({1, 4, 6, 7, 8, 20}, {2, 7, 15}) == 11);
    assert(tickets({}, {2, 7, 15}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
