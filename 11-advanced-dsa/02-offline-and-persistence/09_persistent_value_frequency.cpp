/*
 Static bounded array; valid positional ranges and inclusive numeric low/high;
low>high returns 0.

Use two prefix-version roots and count value ranks below two boundary
ranks; high uses upper_bound for inclusive value semantics.

Positions[1,5) contain three values between 1 and 3:1,1,3.

Both positional and value prefix differences cancel excluded parts without
double-counting equal values.

O(log(n+1)) query, O(n log(n+1)) version storage.

Position ranges are half-open but the requested numeric value band here is inclusive.
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

    int below(int a, int b, int l, int r, int bound) const {
        if (bound <= l) {
            return 0;
        }
        if (r <= bound) {
            return pool[b].count - pool[a].count;
        }
        int mid = l + (r - l) / 2;
        return below(pool[a].left, pool[b].left, l, mid, bound)
               + below(pool[a].right, pool[b].right, mid, r, bound);
    }

    int count(int left, int right, int low, int high) const {
        if (low > high || values.empty()) {
            return 0;
        }
        int lo =
            static_cast<int>(std::lower_bound(values.begin(), values.end(), low) - values.begin());
        int hi =
            static_cast<int>(std::upper_bound(values.begin(), values.end(), high) - values.begin());
        int a = roots.at(static_cast<std::size_t>(left));
        int b = roots.at(static_cast<std::size_t>(right));
        return below(a, b, 0, static_cast<int>(values.size()), hi)
               - below(a, b, 0, static_cast<int>(values.size()), lo);
    }
};

int main() {
    Histogram h({5, 1, 4, 1, 3});
    assert(h.count(1, 5, 1, 3) == 3);
    assert(h.count(0, 5, 2, 2) == 0);
    assert(h.count(0, 5, 5, 1) == 0);
    assert(Histogram({}).count(0, 0, 0, 9) == 0);
    std::cout << "checks passed\n";
    return 0;
}
