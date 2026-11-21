/*
 At most 1000 bounded integers; duplicates allowed; empty operations return explicit
absence. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

For zero-based index i, left is 2i+1, right 2i+2, parent(i-1)/2 for nonroot i.
Shape is complete independently of values.

Indices 0,1,2 represent root, left, right; index 4 has parent 1.

Breadth-first levels fill consecutive slots, so the arithmetic maps exactly their
two ordered children.

O(n) demonstration time, O(1) auxiliary beyond fixture.

Never compute an unsigned parent for index 0; there is no parent.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <cstddef>

std::optional<std::size_t> parent(std::size_t i) {
    if (i == 0) {
        return std::nullopt;
    }
    return (i - 1) / 2;
}

int main() {
    assert(parent(4) == 1);
    assert(!parent(0));
    std::vector<int> a{9, 7, 8, 1, 2};
    assert(a[2 * 0 + 1] == 7 && a[2 * 0 + 2] == 8);
    for (std::size_t i = 1; i < a.size(); ++i) {
        assert(*parent(i) < i);
    }
    std::cout << "checks passed\n";
    return 0;
}
