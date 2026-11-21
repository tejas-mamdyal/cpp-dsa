/*
 n 0..12; return integer Gray codes beginning with 0. Unless narrowed, at most 100
nodes/elements with values in [-1000,1000]. Recursive examples assume valid acyclic owned
structures; exponential searches use the smaller bounds stated here. No input; keep assertions
enabled. Success prints checks passed.

For each bit, append reversed previous codes with that new bit set. Binary
counting is a baseline but may change several bits at once.

n 2 grows 0,1 into 0,1,3,2; consecutive XOR values are 1,2,1.

Both halves inherit adjacency; the join changes only the new bit because
reflection shares the old endpoint.

O(2^n) time/output; O(1) auxiliary beyond output.

Shift only within the bounded unsigned bit width.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

std::vector<unsigned int> gray(int n) {
    assert(n >= 0 && n <= 12);
    std::vector<unsigned int> out{0U};
    for (int bit = 0; bit < n; ++bit) {
        std::size_t oldSize = out.size();
        for (std::size_t i = oldSize; i > 0; --i) {
            out.push_back(out[i - 1] | (1U << bit));
        }
    }
    return out;
}

int main() {
    assert((gray(2) == std::vector<unsigned int>{0, 1, 3, 2}));
    for (int n = 0; n <= 10; ++n) {
        auto a = gray(n);
        assert(a.size() == (1U << n));
        for (std::size_t i = 1; i < a.size(); ++i) {
            unsigned int x = a[i] ^ a[i - 1];
            assert(x != 0 && (x & (x - 1)) == 0);
        }
    }
    std::cout << "checks passed\n";
    return 0;
}
