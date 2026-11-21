/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

Sortedness plus multiplicity conservation characterize the sorted result;
sorting is idempotent.

Enumerate all 3^4 arrays over{-1,0,1}.

The checks jointly reject unsorted outputs and dropped/duplicated values in this
finite domain.

O(3^n*n log n) test work, O(n) temporary storage; here n=4.

Checking only sortedness would accept an incorrectly emptied output.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <type_traits>

void check(std::vector<int> a) {
    auto before = a;
    std::sort(a.begin(), a.end());
    assert(std::is_sorted(a.begin(), a.end()));
    for (int value = -1; value <= 1; ++value) {
        assert(std::count(a.begin(), a.end(), value)
               == std::count(before.begin(), before.end(), value));
    }
    auto again = a;
    std::sort(again.begin(), again.end());
    assert(again == a);
}

int main() {
    for (int mask = 0; mask < 81; ++mask) {
        int digits = mask;
        std::vector<int> a(4);
        for (int& x : a) {
            x = digits % 3 - 1;
            digits /= 3;
        }
        check(a);
    }
    check({});
    std::cout << "checks passed\n";
    return 0;
}
