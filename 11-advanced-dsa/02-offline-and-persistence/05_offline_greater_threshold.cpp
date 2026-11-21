/*
 Static bounded array; queries specify valid half-open positions and distinct output
IDs.

Fenwick marks exactly positions whose value is strictly above the current
descending threshold.

Threshold 3 activates two 5 positions but not the equal 3; threshold 5 activates
none.

All query ranges can share the same globally activated value set for their
threshold, then prefix differences count its positions.

O((n+Q)log(n+Q+1)) time, O(n+Q) storage.

Activate>threshold, not>=threshold, for a strict comparison.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
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

struct Threshold {
    int left;
    int right;
    int threshold;
    int id;
};

std::vector<long long> greaterThan(const std::vector<int>& a, std::vector<Threshold> queries) {
    std::vector<std::pair<int, int>> positions;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        positions.emplace_back(a[i], i);
    }
    std::sort(positions.begin(), positions.end(), std::greater<std::pair<int, int>>());
    std::sort(queries.begin(), queries.end(), [](const Threshold& x, const Threshold& y) {
        return x.threshold > y.threshold;
    });
    Fenwick bit(a.size());
    std::size_t used = 0;
    std::vector<long long> out(queries.size());
    for (auto q : queries) {
        while (used < positions.size() && positions[used].first > q.threshold) {
            bit.add(static_cast<std::size_t>(positions[used].second), 1);
            ++used;
        }
        out[q.id] = bit.range(static_cast<std::size_t>(q.left), static_cast<std::size_t>(q.right));
    }
    return out;
}

int main() {
    assert((greaterThan({5, 1, 5, 3}, {{0, 4, 3, 0}, {1, 4, 5, 1}, {0, 3, 1, 2}})
            == std::vector<long long>{2, 0, 2}));
    std::cout << "checks passed\n";
    return 0;
}
