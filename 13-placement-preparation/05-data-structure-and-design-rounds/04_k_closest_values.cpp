/*
 0<=k<=n; duplicates retained.

Distance then numeric value defines selection order; returned selections
are sorted numerically.

At target 3, tie distance 2 chooses 1 before 5.

The first k entries under the total ranking are exactly the required multiset.

O(n log n) reference time, O(n) copy; bounded heap alternative O(n log(k+1)).

State whether ties prefer smaller values and whether duplicate occurrences count.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstddef>

std::vector<int> closest(std::vector<int> a, int target, int k) {
    std::sort(a.begin(), a.end(), [target](int x, int y) {
        return std::pair<int, int>{std::abs(x - target), x}
               < std::pair<int, int>{std::abs(y - target), y};
    });
    a.resize(static_cast<std::size_t>(k));
    std::sort(a.begin(), a.end());
    return a;
}

int main() {
    assert((closest({1, 2, 3, 4, 5}, 3, 4) == std::vector<int>{1, 2, 3, 4}));
    assert(closest({}, 0, 0).empty());
    std::cout << "checks passed\n";
    return 0;
}
