/*
PARTITION GROUPING VERSUS STABLE ORDER
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: stable_partition retains relative order within true/false groups; stable_sort retains equivalent-key order.
Trace: 3,2,1,4 grouped evens ->2,4,3,1.
Why it works: Stability preserves encounter order among elements whose grouping/key is equivalent.
Cost: stable_partition O(n) predicate calls and up to O(n log n) moves without a buffer; stable_sort O(n log n) comparisons with buffer, up to O(n log^2 n) otherwise; up to O(n) extra memory.
Common mistake: Ordinary partition and sort do not promise that stability.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
    std::vector<int> values = {3, 2, 1, 4};
    auto boundary = std::stable_partition(values.begin(), values.end(), [](int x) {
        return x % 2 == 0;
    });
    assert(boundary - values.begin() == 2);
    assert((values == std::vector<int>{2, 4, 3, 1}));
    std::vector<std::pair<int, int>> records = {{2, 0}, {1, 1}, {2, 2}};
    std::stable_sort(records.begin(), records.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });
    assert(records[1].second == 0 && records[2].second == 2);
    std::cout << "checks passed\n";
}
