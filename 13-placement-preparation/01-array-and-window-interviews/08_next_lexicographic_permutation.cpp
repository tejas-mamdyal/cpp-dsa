/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

The suffix is maximal descending; the pivot is the latest position that
can increase.

1,2,2 swaps pivot 1 with the final 2 then reverses suffix.

The rightmost greater suffix value is the smallest valid increase; ascending
suffix minimizes the remainder.

O(n) time, O(1) work.

Return false resets to minimum order, including empty input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>

bool next(std::vector<int>& a) {
    int i = static_cast<int>(a.size()) - 2;
    while (i >= 0 && a[i] >= a[i + 1]) {
        --i;
    }
    if (i < 0) {
        std::reverse(a.begin(), a.end());
        return false;
    }
    int j = static_cast<int>(a.size()) - 1;
    while (a[j] <= a[i]) {
        --j;
    }
    std::swap(a[i], a[j]);
    std::reverse(a.begin() + i + 1, a.end());
    return true;
}

int main() {
    std::vector<int> a{1, 2, 2};
    assert(next(a) && (a == std::vector<int>{2, 1, 2}));
    a = {3, 2, 1};
    assert(!next(a) && (a == std::vector<int>{1, 2, 3}));
    std::cout << "checks passed\n";
    return 0;
}
