/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

range[left, right) equals prefix(right)-prefix(left), including empty
intervals.

Array 1,2,3,4 gives sum[1,4)=2+3+4=9.

The earlier prefix cancels all values strictly before left.

O(log(n+1)) query/update, O(n) storage.

This subtraction depends on an invertible aggregate; min prefixes cannot be
subtracted.
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
    Fenwick f(4);
    for (std::size_t i = 0; i < 4; ++i) {
        f.add(i, static_cast<long long>(i + 1));
    }
    assert(f.range(1, 4) == 9);
    assert(f.range(2, 2) == 0);
    f.add(1, -2);
    assert(f.range(0, 3) == 4);
    std::cout << "checks passed\n";
    return 0;
}
