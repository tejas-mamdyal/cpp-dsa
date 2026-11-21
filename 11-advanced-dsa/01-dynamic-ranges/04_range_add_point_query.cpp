/*
 Initially zero array, length<=30; valid half-open updates and point indices. Unless
a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

Difference[left]+=v and difference[right]-=v represent a half-open range
update; prefix integrates to a point value.

Add 3 to[1,4), then-1 to[2,5) yields 0,3,2,2,-1.

Update contributions start at left and cancel exactly at right, so their prefix
sum is the net active value.

O(log(n+1)) update/point query, O(n) storage.

Allocate a sentinel position for right==n.
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

class RangeAdd {
    Fenwick difference;

public:
    explicit RangeAdd(std::size_t n)
        : difference(n + 1) {
    }

    void add(std::size_t left, std::size_t right, long long value) {
        assert(left <= right);
        difference.add(left, value);
        difference.add(right, -value);
    }

    long long at(std::size_t index) const {
        return difference.prefix(index + 1);
    }
};

int main() {
    RangeAdd a(5);
    a.add(1, 4, 3);
    a.add(2, 5, -1);
    assert(a.at(0) == 0 && a.at(1) == 3 && a.at(2) == 2 && a.at(4) == -1);
    std::cout << "checks passed\n";
    return 0;
}
