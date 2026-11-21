/*
 Return a first-ending nonempty zero-sum half-open interval, or absence.

IDEA AND STATE: Remember earliest positions of prefix sums; the first repeated prefix closes an
answer.

TRACE: 4,2,-2,1 ->[1,3).

Prefixes are0,4,6,4;the repeated4 closes the nonempty interval from1 to3.

Equal prefixes enclose exactly zero; querying before insertion prevents an empty
self-match.

Expected O(n) time, O(n) space.

The answer is an interval of indices, not the repeated prefix value.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <optional>
#include <utility>

std::optional<std::pair<int, int>> zeroRange(const std::vector<int>& a) {
    std::unordered_map<long long, int> first;
    first.emplace(0, 0);
    long long sum = 0;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        sum += a[i];
        auto found = first.find(sum);
        if (found != first.end()) {
            return std::pair<int, int>{found->second, i + 1};
        }
        first.emplace(sum, i + 1);
    }
    return std::nullopt;
}

int main() {
    assert((zeroRange({4, 2, -2, 1}) == std::optional<std::pair<int, int>>{{1, 3}}));
    assert((zeroRange({0}) == std::optional<std::pair<int, int>>{{0, 1}}));
    assert(!zeroRange({1, 2}));
    assert(!zeroRange({}));
    std::cout << "checks passed\n";
    return 0;
}
