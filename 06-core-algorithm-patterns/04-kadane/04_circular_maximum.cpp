/*
 Nonempty circular subarray uses each index at most once; empty absent.

IDEA AND STATE: Compare normal Kadane with total minus minimum; handle all-negative separately.

TRACE: 5,-3,5 ->10; -3,-2 ->-2.

For5,-3,5,normal maximum is7,total7,minimum -3;excluding that middle yields10.

A proper wrapping interval is the complement of one nonempty middle; nonwrapping
intervals are ordinary Kadane.

O(n) time, O(1) space.

Removing the whole array would produce an illegal empty answer.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

std::optional<long long> maximum(const std::vector<int>& a) {
    if (a.empty()) {
        return std::nullopt;
    }
    long long ending = a[0];
    long long best = ending;
    for (std::size_t i = 1; i < a.size(); ++i) {
        ending = std::max(1LL * a[i], ending + a[i]);
        best = std::max(best, ending);
    }
    return best;
}

std::optional<long long> circular(const std::vector<int>& a) {
    auto best = maximum(a);
    if (!best || *best < 0) {
        return best;
    }
    long long total = a[0];
    long long ending = a[0];
    long long low = ending;
    for (std::size_t i = 1; i < a.size(); ++i) {
        total += a[i];
        ending = std::min(1LL * a[i], ending + a[i]);
        low = std::min(low, ending);
    }
    return std::max(*best, total - low);
}

int main() {
    assert(circular({5, -3, 5}) == 10);
    assert(circular({-3, -2}) == -2);
    assert(circular({0}) == 0);
    assert(!circular({}));
    std::cout << "checks passed\n";
    return 0;
}
