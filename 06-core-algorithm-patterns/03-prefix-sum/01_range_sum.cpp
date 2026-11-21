/*
 Query[ left, right ) with 0<=left<=right<=n; empty ranges sum to 0.

IDEA AND STATE: prefix[i] stores the first i values; subtract two completed prefixes.

TRACE: 2,-1,4 range[1,3) ->prefix 3-prefix 1=3.

Prefixes are0,2,1,5;subtract prefix1=2 from prefix3=5 to obtain3.

The earlier prefix cancels exactly the elements before left.

O(n) preprocessing, O(1) query, O(n) stored prefix.

Do not mix inclusive and exclusive endpoint formulas.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<long long> prefix(const std::vector<int>& a) {
    std::vector<long long> p(a.size() + 1, 0);
    for (std::size_t i = 0; i < a.size(); ++i) {
        p[i + 1] = p[i] + a[i];
    }
    return p;
}

int main() {
    std::vector<int> a = {2, -1, 4};
    auto p = prefix(a);
    for (std::size_t l = 0; l <= a.size(); ++l) {
        for (std::size_t r = l; r <= a.size(); ++r) {
            long long sum = 0;
            for (std::size_t i = l; i < r; ++i) {
                sum += a[i];
            }
            assert(p[r] - p[l] == sum);
        }
    }
    assert(prefix({}) == std::vector<long long>{0});
    std::cout << "checks passed\n";
    return 0;
}
