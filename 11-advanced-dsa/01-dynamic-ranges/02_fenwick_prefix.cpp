/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

bit[i] stores the sum of the 1-based block(i-lowbit(i), i]; updates visit
enclosing blocks, prefix query removes disjoint ending blocks.

Adding at zero-based 2 updates internal 3 then 4; prefix 3 combines block 3 and
block 2.

Every updated index belongs to exactly the visited enclosing blocks; query blocks
partition the requested prefix without overlap.

O(log(n+1)) point add/prefix query, O(n) storage.

Public indices are 0-based, internal indices 1-based; unsigned lowbit avoids
signed-representation assumptions.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

class Fenwick {
    std::vector<long long> bit;

    static std::size_t lowbit(std::size_t i) {
        return i & (~i + std::size_t{1});
    }

public:
    explicit Fenwick(std::size_t n)
        : bit(n + 1, 0) {
    }

    void add(std::size_t index, long long delta) {
        assert(index + 1 < bit.size());
        for (std::size_t i = index + 1; i < bit.size(); i += lowbit(i)) {
            bit[i] += delta;
        }
    }

    long long prefix(std::size_t end) const {
        assert(end < bit.size());
        long long sum = 0;
        for (std::size_t i = end; i > 0; i -= lowbit(i)) {
            sum += bit[i];
        }
        return sum;
    }

    long long range(std::size_t left, std::size_t right) const {
        assert(left <= right);
        return prefix(right) - prefix(left);
    }
};

int main() {
    Fenwick f(5);
    f.add(0, 3);
    f.add(2, -1);
    f.add(4, 7);
    assert(f.prefix(0) == 0 && f.prefix(3) == 2 && f.prefix(5) == 9);
    f.add(2, 4);
    assert(f.prefix(3) == 6);
    Fenwick empty(0);
    assert(empty.prefix(0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
