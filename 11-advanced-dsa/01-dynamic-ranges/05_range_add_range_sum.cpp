/*
 Initially zero length<=30 array; half-open range adds and sum queries. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

A difference entry d[i] contributes(end-i)*d[i] to a length-end prefix, so
store both d[i] and i*d[i].

Updated values 0,3,2,2,-1 have total 6 and range[1,4) sum 7.

Expanding the prefix sum of integrated differences gives end*sum(d)-sum(i*d),
exactly the two-tree formula.

O(log(n+1)) update/range query, O(n) storage.

The coefficient uses 0-based difference positions consistently; mixing 1-based
formulas creates off-by-one errors.
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

class RangeSum {
    Fenwick first;
    Fenwick weighted;

public:
    explicit RangeSum(std::size_t n)
        : first(n + 1),
          weighted(n + 1) {
    }

    void add(std::size_t l, std::size_t r, long long value) {
        first.add(l, value);
        first.add(r, -value);
        weighted.add(l, value * static_cast<long long>(l));
        weighted.add(r, -value * static_cast<long long>(r));
    }

    long long prefix(std::size_t end) const {
        return static_cast<long long>(end) * first.prefix(end) - weighted.prefix(end);
    }

    long long query(std::size_t l, std::size_t r) const {
        return prefix(r) - prefix(l);
    }
};

int main() {
    RangeSum a(5);
    a.add(1, 4, 3);
    a.add(2, 5, -1);
    assert(a.query(0, 5) == 6);
    assert(a.query(1, 4) == 7);
    assert(a.query(3, 3) == 0);
    std::cout << "checks passed\n";
    return 0;
}
