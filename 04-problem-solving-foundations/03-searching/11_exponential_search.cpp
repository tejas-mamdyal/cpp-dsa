/*
FIND A SMALL SEARCH WINDOW BY DOUBLING PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Sorted vector; find a key with doubling bounds then ordinary lower_bound in that
window. IDEA AND STATE: Grow a bound until its value reaches key or the vector ends. TRACE:
1,3,5,7,9 target7:bounds1,2,4 then search indices2..4. CORRECTNESS: Earlier rejected positions
are smaller than key; the bracket contains any possible first match. COST: O(log(p+1))
comparisons near insertion position p; O(1) space. PITFALL: Guard size arithmetic instead of
allowing bound*=2 to wrap. PRACTICE: Change the example, predict each state update and add an
empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

int exponential(const std::vector<int>& a, int key) {
    if (a.empty()) {
        return -1;
    }
    std::size_t bound = 1;
    while (bound < a.size() && a[bound] < key) {
        if (bound > a.size() / 2) {
            bound = a.size();
            break;
        }
        bound *= 2;
    }
    std::size_t start = bound / 2;
    std::size_t stop = a.size();
    if (bound < a.size()) {
        stop = bound + 1;
    }
    auto it = std::lower_bound(a.begin() + static_cast<std::ptrdiff_t>(start),
                               a.begin() + static_cast<std::ptrdiff_t>(stop),
                               key);
    if (it == a.begin() + static_cast<std::ptrdiff_t>(stop) || *it != key) {
        return -1;
    }
    return static_cast<int>(it - a.begin());
}

int main() {
    std::vector<int> a = {1, 3, 5, 7, 9};
    for (int key = -1; key <= 11; ++key) {
        assert((exponential(a, key) != -1) == std::binary_search(a.begin(), a.end(), key));
    }
    assert(exponential({}, 0) == -1);
    assert(exponential({2}, 2) == 0);
    std::cout << "checks passed\n";
    return 0;
}
