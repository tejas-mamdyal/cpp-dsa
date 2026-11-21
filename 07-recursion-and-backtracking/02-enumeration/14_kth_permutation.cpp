/*
 n 0..9; rank is 1-based; out-of-range rank returns absence. Unless narrowed, at most 100
nodes/elements with values in [-1000,1000]. Recursive examples assume valid acyclic owned
structures; exponential searches use the smaller bounds stated here. No input; keep assertions
enabled. Success prints checks passed.

Sorted remaining values split into blocks of (remaining-1)! orderings.
Convert rank to zero-based and choose its block index.

n 3, rank 4: zero rank 3 chooses 2, then 3, then 1 ->2,3,1.

Every first-value block has equal factorial size; quotient selects its block and
remainder is the rank inside it.

O(n^2) time due to vector erase, O(n) storage; factorials fit bounds.

Rank 0 is invalid; empty input has one empty ordering, rank 1.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <cstddef>

std::optional<std::vector<int>> kth(int n, long long rank) {
    assert(n >= 0 && n <= 9);
    std::vector<long long> fact(static_cast<std::size_t>(n + 1), 1);
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i;
    }
    if (rank < 1 || rank > fact[n]) {
        return std::nullopt;
    }
    --rank;
    std::vector<int> available;
    for (int i = 1; i <= n; ++i) {
        available.push_back(i);
    }
    std::vector<int> out;
    for (int remaining = n; remaining > 0; --remaining) {
        long long block = fact[remaining - 1];
        std::size_t index = static_cast<std::size_t>(rank / block);
        out.push_back(available[index]);
        available.erase(available.begin() + static_cast<std::ptrdiff_t>(index));
        rank %= block;
    }
    return out;
}

int main() {
    assert((kth(3, 4) == std::optional<std::vector<int>>{{2, 3, 1}}));
    assert(kth(0, 1)->empty());
    assert(!kth(3, 0));
    assert(!kth(3, 7));
    std::cout << "checks passed\n";
    return 0;
}
