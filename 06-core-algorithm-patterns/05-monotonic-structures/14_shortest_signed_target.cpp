/*
 Positive target; signed values; shortest nonempty sum>=target, or absence.

IDEA AND STATE: Increasing prefix deque: resolve valid fronts, then discard dominated larger
previous prefixes.

TRACE: 1,-1,5 target 5 ->1.

Prefixes0,1,0,5 discard the dominated earlier prefixes;at5,the latest zero-prefix yields
length1.

A later smaller prefix gives every future endpoint a no-worse sum and shorter
length; resolved fronts cannot improve later.

O(n) time, O(n) space.

This is not the nonnegative sum-shrinking rule; prefix ordering supplies the missing
monotonicity.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <deque>
#include <algorithm>
#include <optional>

std::vector<long long> prefix(const std::vector<int>& a) {
    std::vector<long long> p(a.size() + 1, 0);
    for (std::size_t i = 0; i < a.size(); ++i) {
        p[i + 1] = p[i] + a[i];
    }
    return p;
}

std::optional<int> shortest(const std::vector<int>& a, long long target) {
    assert(target > 0);
    auto p = prefix(a);
    std::deque<int> q;
    int best = static_cast<int>(a.size()) + 1;
    for (int end = 0; end < static_cast<int>(p.size()); ++end) {
        while (!q.empty() && p[end] - p[q.front()] >= target) {
            best = std::min(best, end - q.front());
            q.pop_front();
        }
        while (!q.empty() && p[q.back()] >= p[end]) {
            q.pop_back();
        }
        q.push_back(end);
    }
    if (best > static_cast<int>(a.size())) {
        return std::nullopt;
    }
    return best;
}

int main() {
    assert(shortest({1, -1, 5}, 5) == 1);
    assert(shortest({2, -1, 2}, 3) == 3);
    assert(!shortest({-2, -1}, 1));
    assert(!shortest({}, 1));
    std::cout << "checks passed\n";
    return 0;
}
