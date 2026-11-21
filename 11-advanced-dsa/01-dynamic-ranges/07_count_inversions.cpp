/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

Fenwick counts ranks strictly to the current position right; prefix(rank)
counts smaller values, excluding equals.

When processing 4 in 2,4,1,3,5, the inserted suffix contains smaller 1 and 3,
adding 2.

Each inversion is counted exactly once at its left endpoint against
already-inserted right endpoints.

O(n log(n+1)) time, O(n) compression/tree storage.

Querying prefix(rank+1) would incorrectly count equal pairs as strict inversions.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
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

long long inversions(const std::vector<int>& a) {
    auto sorted = a;
    std::sort(sorted.begin(), sorted.end());
    sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
    Fenwick bit(sorted.size());
    long long answer = 0;
    for (std::size_t i = a.size(); i > 0; --i) {
        std::size_t rank = static_cast<std::size_t>(
            std::lower_bound(sorted.begin(), sorted.end(), a[i - 1]) - sorted.begin());
        answer += bit.prefix(rank);
        bit.add(rank, 1);
    }
    return answer;
}

int main() {
    assert(inversions({2, 4, 1, 3, 5}) == 3);
    assert(inversions({2, 2}) == 0);
    assert(inversions({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
