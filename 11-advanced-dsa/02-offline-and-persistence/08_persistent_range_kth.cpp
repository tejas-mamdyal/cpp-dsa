/*
 Static bounded array; valid position ranges, k 1-based; invalid rank returns
absence.

Version i counts values in positions[0, i); subtract version left from
version right to get the query interval histogram.

Range[1,5) values 1,4,1,3 sorts to 1,1,3,4; second is 1.

Prefix count subtraction gives exact frequencies; at each rank split, left count
determines whether the requested order statistic lies left or right.

O(n log(n+1)) build/storage, O(log(n+1)) kth query.

The tree domain is compressed values, not original positions; query versions still
refer to positions.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <cstddef>

class Histogram {
    struct Node {
        int left = 0;
        int right = 0;
        int count = 0;
    };

    std::vector<Node> pool{{}};
    std::vector<int> roots{0};
    std::vector<int> values;

    int add(int old, int l, int r, int index) {
        int p = static_cast<int>(pool.size());
        Node copy = pool[old];
        pool.push_back(copy);
        ++pool[p].count;
        if (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (index < mid) {
                pool[p].left = add(pool[old].left, l, mid, index);
            } else {
                pool[p].right = add(pool[old].right, mid, r, index);
            }
        }
        return p;
    }

public:
    explicit Histogram(const std::vector<int>& a)
        : values(a) {
        std::sort(values.begin(), values.end());
        values.erase(std::unique(values.begin(), values.end()), values.end());
        for (int x : a) {
            int rank = static_cast<int>(std::lower_bound(values.begin(), values.end(), x)
                                        - values.begin());
            roots.push_back(add(roots.back(), 0, static_cast<int>(values.size()), rank));
        }
    }

    std::optional<int> kth(int left, int right, int k) const {
        if (k < 1 || k > right - left) {
            return std::nullopt;
        }
        int a = roots.at(static_cast<std::size_t>(left));
        int b = roots.at(static_cast<std::size_t>(right));
        int l = 0;
        int r = static_cast<int>(values.size());
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            int count = pool[pool[b].left].count - pool[pool[a].left].count;
            if (k <= count) {
                a = pool[a].left;
                b = pool[b].left;
                r = mid;
            } else {
                k -= count;
                a = pool[a].right;
                b = pool[b].right;
                l = mid;
            }
        }
        return values[l];
    }
};

int main() {
    Histogram h({5, 1, 4, 1, 3});
    assert(h.kth(1, 5, 2) == 1);
    assert(h.kth(0, 3, 2) == 4);
    assert(!h.kth(2, 2, 1));
    assert(!Histogram({}).kth(0, 0, 1));
    std::cout << "checks passed\n";
    return 0;
}
