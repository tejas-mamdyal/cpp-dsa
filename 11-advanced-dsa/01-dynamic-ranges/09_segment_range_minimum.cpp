/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

Every node stores its interval minimum; unused padded leaves use an
identity larger than any candidate.

Range[2,4) combines 7 and 1 to return 1.

Minimum is associative on disjoint blocks and infinity does not change any
nonempty result.

O(n) build, O(log(n+1)) query, O(n) storage.

An empty range has no minimum; do not silently return the identity as a real answer.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <limits>
#include <cstddef>

class Minimum {
    std::size_t base = 1;
    std::vector<int> tree;

public:
    explicit Minimum(const std::vector<int>& a) {
        while (base < a.size()) {
            base *= 2;
        }
        tree.assign(2 * base, std::numeric_limits<int>::max());
        for (std::size_t i = 0; i < a.size(); ++i) {
            tree[base + i] = a[i];
        }
        for (std::size_t i = base; i > 1; --i) {
            std::size_t p = i - 1;
            tree[p] = std::min(tree[2 * p], tree[2 * p + 1]);
        }
    }

    std::optional<int> query(std::size_t l, std::size_t r) const {
        if (l == r) {
            return std::nullopt;
        }
        int best = std::numeric_limits<int>::max();
        for (l += base, r += base; l < r; l /= 2, r /= 2) {
            if (l % 2) {
                best = std::min(best, tree[l]);
                ++l;
            }
            if (r % 2) {
                --r;
                best = std::min(best, tree[r]);
            }
        }
        return best;
    }
};

int main() {
    Minimum t({5, -2, 7, 1});
    assert(t.query(0, 4) == -2);
    assert(t.query(2, 4) == 1);
    assert(!t.query(1, 1));
    std::cout << "checks passed\n";
    return 0;
}
