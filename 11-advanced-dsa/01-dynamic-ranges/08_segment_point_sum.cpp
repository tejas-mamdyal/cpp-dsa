/*
 Array length<=30; valid point assignments and half-open sum queries, including
empty.

Leaves hold values at a power-of-two base; each parent sums its two
children; query consumes disjoint boundary blocks.

Range[1,4) takes leaf 2 and the block 3+4, producing 9.

The iterative boundary decomposition covers the requested interval exactly once;
updates repair every ancestor containing the changed leaf.

O(n) build/storage, O(log(n+1)) point assignment/query.

Point assignment replaces a value; it is not an additive Fenwick update.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

class Segment {
    std::size_t base = 1;
    std::vector<long long> tree;

public:
    explicit Segment(const std::vector<int>& a) {
        while (base < a.size()) {
            base *= 2;
        }
        tree.assign(2 * base, 0);
        for (std::size_t i = 0; i < a.size(); ++i) {
            tree[base + i] = a[i];
        }
        for (std::size_t i = base; i > 1; --i) {
            std::size_t p = i - 1;
            tree[p] = tree[2 * p] + tree[2 * p + 1];
        }
    }

    void set(std::size_t index, long long value) {
        std::size_t p = base + index;
        tree[p] = value;
        while (p > 1) {
            p /= 2;
            tree[p] = tree[2 * p] + tree[2 * p + 1];
        }
    }

    long long query(std::size_t left, std::size_t right) const {
        long long sum = 0;
        for (left += base, right += base; left < right; left /= 2, right /= 2) {
            if (left % 2 == 1) {
                sum += tree[left];
                ++left;
            }
            if (right % 2 == 1) {
                --right;
                sum += tree[right];
            }
        }
        return sum;
    }
};

int main() {
    Segment t({1, 2, 3, 4});
    assert(t.query(1, 4) == 9);
    t.set(2, -3);
    assert(t.query(0, 4) == 4);
    assert(t.query(2, 2) == 0);
    assert(Segment({}).query(0, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
