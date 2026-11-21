/*
 Positive k; maximum nonempty sum with length at least k; invalid k absent.

IDEA AND STATE: At endpoint end, retain the minimum prefix among indices 0 through end-k.

TRACE: -4,2,3,-1 with k 2 ->5.

At endpoint2,the eligible minimum prefix is -4,so range[1,3) later yields5 when endpoint3
arrives.

Subtracting the smallest eligible prefix maximizes this endpoint sum; every legal
start becomes eligible once.

O(n) time, O(n) prefix storage.

The minimum prefix must not include a start that makes length less than k.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <limits>

std::vector<long long> prefix(const std::vector<int>& a) {
    std::vector<long long> p(a.size() + 1, 0);
    for (std::size_t i = 0; i < a.size(); ++i) {
        p[i + 1] = p[i] + a[i];
    }
    return p;
}

std::optional<long long> atLeast(const std::vector<int>& a, int k) {
    if (k < 1 || k > static_cast<int>(a.size())) {
        return std::nullopt;
    }
    auto p = prefix(a);
    long long low = p[0];
    long long best = std::numeric_limits<long long>::lowest();
    for (int end = k; end <= static_cast<int>(a.size()); ++end) {
        low = std::min(low, p[end - k]);
        best = std::max(best, p[end] - low);
    }
    return best;
}

int main() {
    assert(atLeast({-4, 2, 3, -1}, 2) == 5);
    assert(atLeast({-3, -1}, 2) == -4);
    assert(!atLeast({}, 1));
    std::cout << "checks passed\n";
    return 0;
}
