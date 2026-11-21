/*
 Initially zero array, n 0..30; half-open signed range additions and sums. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

sum[p] already includes all updates covering its interval; lazy[p] is
pending additive work for its children.

Five 2 values total 10; adding 3 to three interior values adds 9, total 19.

A uniform addition changes an interval sum by length*delta; distributing
accumulated tags before partial access preserves child summaries.

O(log(n+1)) update/query, O(n) storage.

Push before descending and recompute a partially updated parent afterward.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

class LazyAdd {
    int n;
    std::vector<long long> sum;
    std::vector<long long> lazy;

    void apply(int p, int l, int r, long long value) {
        sum[p] += (r - l) * value;
        lazy[p] += value;
    }

    void push(int p, int l, int r) {
        if (r - l > 1 && lazy[p] != 0) {
            int mid = l + (r - l) / 2;
            apply(2 * p, l, mid, lazy[p]);
            apply(2 * p + 1, mid, r, lazy[p]);
            lazy[p] = 0;
        }
    }

    void add(int p, int l, int r, int ql, int qr, long long value) {
        if (qr <= l || r <= ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            apply(p, l, r, value);
            return;
        }
        push(p, l, r);
        int mid = l + (r - l) / 2;
        add(2 * p, l, mid, ql, qr, value);
        add(2 * p + 1, mid, r, ql, qr, value);
        sum[p] = sum[2 * p] + sum[2 * p + 1];
    }

    long long query(int p, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return sum[p];
        }
        push(p, l, r);
        int mid = l + (r - l) / 2;
        return query(2 * p, l, mid, ql, qr) + query(2 * p + 1, mid, r, ql, qr);
    }

public:
    explicit LazyAdd(int size)
        : n(size),
          sum(static_cast<std::size_t>(std::max(1, 4 * size)), 0),
          lazy(sum.size(), 0) {
    }

    // Preserve the nonzero-array build example using the already taught point range update.
    // This simple constructor takes O(n log(n+1));a bottom-up build can reduce it to O(n).
    explicit LazyAdd(const std::vector<int>& initial)
        : LazyAdd(static_cast<int>(initial.size())) {
        for (int i = 0; i < static_cast<int>(initial.size()); ++i) {
            add(i, i + 1, initial[i]);
        }
    }

    void add(int l, int r, long long value) {
        assert(l >= 0 && l <= r && r <= n);
        if (n > 0) {
            add(1, 0, n, l, r, value);
        }
    }

    long long query(int l, int r) {
        assert(l >= 0 && l <= r && r <= n);
        return n == 0 ? 0 : query(1, 0, n, l, r);
    }
};

int main() {
    LazyAdd initial(std::vector<int>{1, 2, 3, 4});
    initial.add(0, 4, 2);
    initial.add(1, 3, 5);
    assert(initial.query(0, 4) == 28 && initial.query(1, 2) == 9);
    LazyAdd t(5);
    t.add(0, 5, 2);
    t.add(1, 4, 3);
    assert(t.query(0, 5) == 19);
    assert(t.query(2, 3) == 5);
    t.add(2, 3, -5);
    assert(t.query(2, 3) == 0);
    assert(LazyAdd(0).query(0, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
