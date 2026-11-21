/*
 Static nonnegative integer array<=30; nonempty valid half-open queries. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

table[k][i] stores gcd of its power-of-two block; overlap is safe because
gcd(x, x)=x.

gcd 12,18,24 equals 6, whether the overlapping 18 appears once or twice.

Associativity combines the blocks, and idempotence removes duplicate influence
from overlap.

O(n log n) gcd operations to build, O(1) gcd operations per query; each integer gcd has
its own logarithmic arithmetic cost.

Distinguish constant aggregate-operation count from bit complexity of the aggregate
itself.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>
#include <numeric>

class GcdTable {
    std::vector<int> logs;
    std::vector<std::vector<int>> table;

public:
    explicit GcdTable(const std::vector<int>& a)
        : logs(a.size() + 1, 0) {
        for (std::size_t i = 2; i < logs.size(); ++i) {
            logs[i] = logs[i / 2] + 1;
        }
        if (a.empty()) {
            return;
        }
        table.assign(static_cast<std::size_t>(logs[a.size()] + 1), std::vector<int>(a.size()));
        table[0] = a;
        for (std::size_t k = 1; k < table.size(); ++k) {
            std::size_t length = std::size_t{1} << k;
            for (std::size_t i = 0; i + length <= a.size(); ++i) {
                table[k][i] = std::gcd(table[k - 1][i], table[k - 1][i + length / 2]);
            }
        }
    }

    int query(std::size_t l, std::size_t r) const {
        assert(l < r && r < logs.size());
        int k = logs[r - l];
        return std::gcd(table[k][l], table[k][r - (std::size_t{1} << k)]);
    }
};

int main() {
    GcdTable t({12, 18, 24, 30});
    assert(t.query(0, 3) == 6);
    assert(t.query(1, 4) == 6);
    assert(t.query(2, 3) == 24);
    std::cout << "checks passed\n";
    return 0;
}
