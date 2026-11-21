/*
 At most16 integers in [-100,100]; return the number of positional subsets summing to
target, including the empty subset when target=0. No input is required. Keep assertions
enabled; a successful run prints checks passed. Tiny bounds are intentional because output
grows exponentially or factorially.

i is undecided position and sum is passed by value. The direct baseline
enumerates masks;recursive counting avoids storing all subsets but still explores their
decisions.

For [5,-4], target1, the include5 branch currently exceeds target but later
include -4 reaches1. Cutting that branch would lose the answer.

At the leaf all positions are decided, so sum==target exactly characterizes a
valid subset. Disjoint include/exclude branches let counts be added.

O(2^n) time, O(n) auxiliary frames, O(1) result storage. Counts fit long long under the
size bound.

A sum>target cutoff requires suitable nonnegative assumptions; even then zero values
affect early counting. Here inspect equality only at full leaves.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

long long count(const std::vector<int>& a, std::size_t i, long long sum, long long target) {
    if (i == a.size()) {
        return sum == target ? 1 : 0;
    }
    long long without = count(a, i + 1, sum, target);
    long long with =
        count(a, i + 1, sum + a[i], target); // A negative later value can undo an excess.
    return without + with;
}

int main() {
    assert(count({5, -4}, 0, 0, 1) == 1);
    assert(count({0, 0}, 0, 0, 0) == 4);
    assert(count({}, 0, 0, 0) == 1);
    assert(count({}, 0, 0, 2) == 0);
    assert(count({1, 2}, 0, 0, 9) == 0);
    std::cout << "checks passed\n";
    return 0;
}
