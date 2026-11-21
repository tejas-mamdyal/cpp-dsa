/*
 Static bounded integer array; only nonempty valid half-open queries. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

table[k][i] is minimum over length 2^k starting i; logs chooses two blocks
covering the query.

Length 3 query uses two length 2 blocks; their overlap does not change a minimum.

The blocks cover the full interval and minimum is idempotent, so duplicated
overlap values have no effect.

O(n log(n+1)) build/storage, O(1) static query.

This overlapping-block trick is wrong for ordinary sum because overlap would be
counted twice.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

class Sparse {
    std::vector<int> logs;
    std::vector<std::vector<int>> table;

public:
    explicit Sparse(const std::vector<int>& a)
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
                table[k][i] = std::min(table[k - 1][i], table[k - 1][i + length / 2]);
            }
        }
    }

    int query(std::size_t l, std::size_t r) const {
        assert(l < r && r < logs.size());
        int k = logs[r - l];
        return std::min(table[k][l], table[k][r - (std::size_t{1} << k)]);
    }
};

int main() {
    Sparse t({5, 2, 7, -1, 3});
    assert(t.query(0, 3) == 2);
    assert(t.query(1, 5) == -1);
    assert(t.query(2, 3) == 7);
    std::cout << "checks passed\n";
    return 0;
}
