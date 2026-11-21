/*
 At most 12 values in[-4,4]; return product of all other positions. Empty returns
empty; singleton gives 1.

IDEA AND STATE: Store left products in output, then multiply each by a running right product.

TRACE: 1,2,3,4 ->24,12,8,6; two zeros make all results 0.

Left products are1,1,2,6;reverse suffix factors24,12,4,1 give24,12,8,6.

Each output combines disjoint factors strictly left and right of its position.

O(n) time, O(n) returned output, O(1) other state.

Product bounds are explicit; long long is not arbitrary precision.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<long long> products(const std::vector<int>& a) {
    std::vector<long long> out(a.size(), 1);
    long long left = 1;
    for (std::size_t i = 0; i < a.size(); ++i) {
        out[i] = left;
        left *= a[i];
    }
    long long right = 1;
    for (std::size_t i = a.size(); i > 0; --i) {
        out[i - 1] *= right;
        right *= a[i - 1];
    }
    return out;
}

int main() {
    assert((products({1, 2, 3, 4}) == std::vector<long long>{24, 12, 8, 6}));
    assert((products({0, 2, 0}) == std::vector<long long>{0, 0, 0}));
    assert((products({3}) == std::vector<long long>{1}));
    assert(products({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
