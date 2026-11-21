/*
 Static array; queries are half-open with IDs 0..Q-1. Unless a different bound is
stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

After processing prefix[0, end), only each value final occurrence holds a
1 marker; queries are sorted by right endpoint.

Processing the second 1 removes marker 0 and adds marker 2; range[1,3) still
counts 1 and 2 exactly once.

A value appears in[left, right) exactly when its last occurrence before right
lies at or after left.

O((n+Q)log(n+Q+1)) time, O(n+Q) storage.

Do not leave old markers active or repeated values get counted more than once.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
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

struct Query {
    int left;
    int right;
    int id;
};

std::vector<long long> distinctQueries(const std::vector<int>& a, std::vector<Query> queries) {
    std::sort(queries.begin(), queries.end(), [](const Query& x, const Query& y) {
        return x.right < y.right;
    });
    Fenwick bit(a.size());
    std::map<int, int> last;
    int end = 0;
    std::vector<long long> out(queries.size());
    for (auto q : queries) {
        while (end < q.right) {
            auto found = last.find(a[end]);
            if (found != last.end()) {
                bit.add(static_cast<std::size_t>(found->second), -1);
            }
            bit.add(static_cast<std::size_t>(end), 1);
            last[a[end]] = end;
            ++end;
        }
        out[q.id] = bit.range(static_cast<std::size_t>(q.left), static_cast<std::size_t>(q.right));
    }
    return out;
}

int main() {
    assert((distinctQueries({1, 2, 1, 3}, {{0, 3, 0}, {1, 4, 1}, {2, 2, 2}})
            == std::vector<long long>{2, 3, 0}));
    std::cout << "checks passed\n";
    return 0;
}
