/*
 At most 16 positive weights and nonnegative values<=100; capacity 0..100; each item used
once. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

At each item compare skipping with including if weight fits. Fractional
density from Phase 4 cannot solve this contract.

Weights 10,20,30; values 60,100,120; capacity 50 chooses 20+30 for 220 rather than
fractional 240.

Every legal item subset lies in one disjoint include/exclude branch; take the
better value.

O(2^n) time, O(n) recursion; DP improvement belongs to Phase 7.

Do not reuse an item or silently take a fraction.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

int best(const std::vector<int>& weights,
         const std::vector<int>& values,
         std::size_t i,
         int capacity) {
    if (i == weights.size()) {
        return 0;
    }
    int answer = best(weights, values, i + 1, capacity);
    if (weights[i] <= capacity) {
        answer = std::max(answer, values[i] + best(weights, values, i + 1, capacity - weights[i]));
    }
    return answer;
}

int main() {
    assert(best({10, 20, 30}, {60, 100, 120}, 0, 50) == 220);
    assert(best({1}, {3}, 0, 0) == 0);
    assert(best({}, {}, 0, 10) == 0);
    std::cout << "checks passed\n";
    return 0;
}
