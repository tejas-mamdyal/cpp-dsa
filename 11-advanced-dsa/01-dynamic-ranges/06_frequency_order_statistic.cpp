/*
 Nonnegative count array<=30; rank 1-based; out-of-range rank returns absence. Unless
a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

index is the longest accepted prefix whose frequency sum is below rank;
try descending powers of two using stored Fenwick blocks.

Counts 0,2,0,1 place ranks 1 and 2 at index 1, rank 3 at index 3.

Nonnegative frequencies make prefix sums monotone; each accepted block stays
strictly before the requested rank and descending steps locate its first crossing.

O(n log(n+1)) construction, O(log(n+1)) kth query, O(n) storage.

Negative frequencies destroy the monotone-prefix assumption.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <cstddef>

class Frequencies {
    std::vector<long long> bit;

public:
    explicit Frequencies(const std::vector<int>& counts)
        : bit(counts.size() + 1, 0) {
        for (std::size_t i = 0; i < counts.size(); ++i) {
            assert(counts[i] >= 0);
            for (std::size_t j = i + 1; j < bit.size(); j += j & (~j + std::size_t{1})) {
                bit[j] += counts[i];
            }
        }
    }

    std::optional<std::size_t> kth(long long rank) const {
        if (rank < 1) {
            return std::nullopt;
        }
        std::size_t n = bit.size() - 1;
        std::size_t index = 0;
        long long sum = 0;
        std::size_t step = 1;
        while (step <= n / 2) {
            step *= 2;
        }
        for (; step > 0; step /= 2) {
            std::size_t next = index + step;
            if (next <= n && sum + bit[next] < rank) {
                sum += bit[next];
                index = next;
            }
        }
        if (index == n) {
            return std::nullopt;
        }
        return index;
    }
};

int main() {
    Frequencies f({0, 2, 0, 1});
    assert(f.kth(1) == 1 && f.kth(2) == 1 && f.kth(3) == 3);
    assert(!f.kth(0) && !f.kth(4));
    assert(!Frequencies({}).kth(1));
    std::cout << "checks passed\n";
    return 0;
}
