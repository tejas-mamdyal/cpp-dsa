/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

Predicate is a deduced callable type; the interface requires
bool-convertible results.

Even predicate rejects 1, accepts 2, rejects 3, accepts 4.

Output preserves exactly the accepted elements in input order.

O(n*predicate cost), O(k) output.

Captures by reference require the referenced object to remain alive.
*/
#include <iostream>
#include <cassert>
#include <vector>

template <typename Predicate> std::vector<int> select(const std::vector<int>& a, Predicate keep) {
    std::vector<int> out;
    for (int x : a) {
        if (keep(x)) {
            out.push_back(x);
        }
    }
    return out;
}

int main() {
    assert((select({1, 2, 3, 4},
                   [](int x) {
                       return x % 2 == 0;
                   })
            == std::vector<int>{2, 4}));
    std::cout << "checks passed\n";
    return 0;
}
