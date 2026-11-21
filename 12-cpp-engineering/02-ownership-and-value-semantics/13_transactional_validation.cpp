/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

Current remains valid until the proposed vector has been checked and
copied.

[3,-1] is rejected with original[1,2] intact.

All potentially failing work precedes the nonthrowing vector swap.

O(n) time and temporary storage.

A strong guarantee may need extra memory; document that cost.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

bool replace(std::vector<int>& current, const std::vector<int>& proposed) {
    if (std::any_of(proposed.begin(), proposed.end(), [](int x) {
            return x < 0;
        })) {
        return false;
    }
    auto prepared = proposed;
    current.swap(prepared);
    return true;
}

int main() {
    std::vector<int> a{1, 2};
    assert(!replace(a, {3, -1}) && (a == std::vector<int>{1, 2}));
    assert(replace(a, {4, 5}) && (a == std::vector<int>{4, 5}));
    std::cout << "checks passed\n";
    return 0;
}
