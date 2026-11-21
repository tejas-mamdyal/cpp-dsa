/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

frequency counts earlier prefix sums, including the empty prefix.

Prefixes 0,1,0,1 produce three differences equal 1.

A subarray sums to target exactly when its earlier prefix equals current-target.

O(n log n) time, O(n) storage.

Negative values invalidate the usual positive-sum sliding-window exclusion.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

long long countSums(const std::vector<int>& a, int target) {
    std::map<long long, int> frequency{{0, 1}};
    long long prefix = 0;
    long long result = 0;
    for (int x : a) {
        prefix += x;
        result += frequency[prefix - target];
        ++frequency[prefix];
    }
    return result;
}

int main() {
    assert(countSums({1, -1, 1}, 1) == 3);
    assert(countSums({0, 0}, 0) == 3);
    assert(countSums({}, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
