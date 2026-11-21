/*
 Static bounded array; valid half-open ranges; count values<=threshold including
duplicates.

Each segment node owns its sorted value multiset; query decomposes the
position range and upper_bounds each complete node list.

Range[1,5) has 1,4,1,3; three values are<=3.

Disjoint position blocks partition the query, and sorted-list upper_bound counts
all and only acceptable values within each block.

O(n log n) build/storage, O(log^2 n) query.

This structure is static; updating every ancestor sorted vector is not an O(log n)
operation.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstddef>

class MergeTree {
    int n;
    std::vector<std::vector<int>> tree;

    void build(int p, int l, int r, const std::vector<int>& a) {
        if (r - l == 1) {
            tree[p] = {a[l]};
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * p, l, mid, a);
        build(2 * p + 1, mid, r, a);
        std::merge(tree[2 * p].begin(),
                   tree[2 * p].end(),
                   tree[2 * p + 1].begin(),
                   tree[2 * p + 1].end(),
                   std::back_inserter(tree[p]));
    }

    int count(int p, int l, int r, int ql, int qr, int value) const {
        if (qr <= l || r <= ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return static_cast<int>(std::upper_bound(tree[p].begin(), tree[p].end(), value)
                                    - tree[p].begin());
        }
        int mid = l + (r - l) / 2;
        return count(2 * p, l, mid, ql, qr, value) + count(2 * p + 1, mid, r, ql, qr, value);
    }

public:
    explicit MergeTree(const std::vector<int>& a)
        : n(static_cast<int>(a.size())),
          tree(static_cast<std::size_t>(std::max(1, 4 * n))) {
        if (n > 0) {
            build(1, 0, n, a);
        }
    }

    int countAtMost(int l, int r, int value) const {
        return n == 0 ? 0 : count(1, 0, n, l, r, value);
    }
};

int main() {
    MergeTree t({5, 1, 4, 1, 3});
    assert(t.countAtMost(1, 5, 3) == 3);
    assert(t.countAtMost(0, 3, 4) == 2);
    assert(t.countAtMost(2, 2, 100) == 0);
    std::cout << "checks passed\n";
    return 0;
}
