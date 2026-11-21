/*
 Nonempty queried half-open interval in a bounded signed array; empty query returns
absence.

A range summary stores total sum, best nonempty prefix, suffix, and
internal subarray; combining two ranges needs the crossing suffix+prefix option.

Left[-2,3] has suffix 3; right[-1,4,-5] has prefix 3; crossing sum 6 beats either
local best.

An optimum lies inside one side or crosses their boundary; prefix/suffix totals
characterize every crossing candidate.

O(n) construction/storage;cached-tree query and point assignment O(log(n+1)).
The convenience maximum wrapper constructs a fresh tree and therefore costs O(n).

A 0 empty identity would incorrectly beat all-negative nonempty answers; optional
summaries represent disjoint pieces.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

struct Summary {
    long long sum;
    long long prefix;
    long long suffix;
    long long best;
};

Summary join(const Summary& a, const Summary& b) {
    return {a.sum + b.sum,
            std::max(a.prefix, a.sum + b.prefix),
            std::max(b.suffix, b.sum + a.suffix),
            std::max({a.best, b.best, a.suffix + b.prefix})};
}

class MaximumTree {
    std::size_t base = 1;
    std::vector<std::optional<Summary>> tree;

    static std::optional<Summary> combine(const std::optional<Summary>& a,
                                          const std::optional<Summary>& b) {
        if (!a) {
            return b;
        }
        if (!b) {
            return a;
        }
        return join(*a, *b);
    }

public:
    explicit MaximumTree(const std::vector<int>& values) {
        while (base < values.size()) {
            base *= 2;
        }
        tree.resize(2 * base);
        for (std::size_t i = 0; i < values.size(); ++i) {
            long long x = values[i];
            tree[base + i] = Summary{x, x, x, x};
        }
        for (std::size_t i = base; i > 1; --i) {
            std::size_t p = i - 1;
            tree[p] = combine(tree[2 * p], tree[2 * p + 1]);
        }
    }

    void set(std::size_t index, long long value) {
        std::size_t p = base + index;
        tree[p] = Summary{value, value, value, value};
        while (p > 1) {
            p /= 2;
            tree[p] = combine(tree[2 * p], tree[2 * p + 1]);
        }
    }

    std::optional<long long> query(std::size_t left, std::size_t right) const {
        std::optional<Summary> before;
        std::optional<Summary> after;
        for (left += base, right += base; left < right; left /= 2, right /= 2) {
            if (left % 2) {
                before = combine(before, tree[left++]);
            }
            if (right % 2) {
                after = combine(tree[--right], after);
            }
        }
        auto result = combine(before, after);
        if (!result) {
            return std::nullopt;
        }
        return result->best;
    }
};

std::optional<long long> maximum(const std::vector<int>& a, int left, int right) {
    return MaximumTree(a).query(static_cast<std::size_t>(left), static_cast<std::size_t>(right));
}

int main() {
    assert(maximum({-2, 3, -1, 4, -5}, 0, 5) == 6);
    assert(maximum({-3, -1, -2}, 0, 3) == -1);
    assert(!maximum({}, 0, 0));
    MaximumTree tree({-2, 3, -1, 4, -5});
    assert(tree.query(0, 5) == 6);
    tree.set(2, 10);
    assert(tree.query(0, 5) == 17);
    assert(!tree.query(2, 2));
    std::cout << "checks passed\n";
    return 0;
}
