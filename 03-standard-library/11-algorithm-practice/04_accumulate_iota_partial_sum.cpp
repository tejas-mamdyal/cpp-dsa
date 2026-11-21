/*
NUMERIC ALGORITHMS AND ACCUMULATOR TYPES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Generate1..4 with iota; use long long accumulation and partial_sum for prefix totals.
Trace: 1,2,3,4 ->sum10;prefix1,3,6,10.
Why it works: Each prefix adds the next element to the accumulated total.
Cost: O(n) range work and O(n) output storage; gcd/lcm add logarithmic arithmetic work.
Common mistake: The initial value controls accumulate arithmetic type; 0LL avoids int summation for a long long result. lcm requires representability.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> values(4);
    std::iota(values.begin(), values.end(), 1);
    long long sum = std::accumulate(values.begin(), values.end(), 0LL);
    assert(sum == 10);
    std::vector<int> prefix(4);
    std::partial_sum(values.begin(), values.end(), prefix.begin());
    assert((prefix == std::vector<int>{1, 3, 6, 10}));
    assert(std::gcd(12, 18) == 6);
    assert(std::lcm(12, 18) == 36);
    std::cout << "checks passed\n";
}
