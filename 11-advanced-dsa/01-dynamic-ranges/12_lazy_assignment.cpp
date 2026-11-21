/*
 Initially zero array, n 0..30; valid half-open assignments and sum queries. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

An optional assignment tag overrides all earlier assignments for its
segment; engaged 0 means a real zero assignment, not no pending work.

5,5,5,5 becomes 5,0,0,5 after assigning 0 to[1,3).

Uniform assignment sets aggregate to length*value and replaces rather than adds
deferred child operations.

O(log(n+1)) range assignment/sum, O(n) storage.

Using numeric 0 as no-tag sentinel loses valid zero assignments.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <cstddef>

class Assign {
    int n;
    std::vector<long long> sum;
    std::vector<std::optional<long long>> tag;

    void apply(int p, int l, int r, long long value) {
        sum[p] = (r - l) * value;
        tag[p] = value;
    }

    void push(int p, int l, int r) {
        if (tag[p] && r - l > 1) {
            int mid = l + (r - l) / 2;
            apply(2 * p, l, mid, *tag[p]);
            apply(2 * p + 1, mid, r, *tag[p]);
            tag[p].reset();
        }
    }

    void set(int p, int l, int r, int ql, int qr, long long value) {
        if (qr <= l || r <= ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            apply(p, l, r, value);
            return;
        }
        push(p, l, r);
        int mid = l + (r - l) / 2;
        set(2 * p, l, mid, ql, qr, value);
        set(2 * p + 1, mid, r, ql, qr, value);
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
    explicit Assign(int size)
        : n(size),
          sum(static_cast<std::size_t>(std::max(1, 4 * size)), 0),
          tag(sum.size()) {
    }

    void set(int l, int r, long long value) {
        if (n > 0) {
            set(1, 0, n, l, r, value);
        }
    }

    long long query(int l, int r) {
        return n == 0 ? 0 : query(1, 0, n, l, r);
    }
};

int main() {
    Assign t(4);
    t.set(0, 4, 5);
    t.set(1, 3, 0);
    assert(t.query(0, 4) == 10);
    assert(t.query(1, 2) == 0);
    t.set(2, 4, -2);
    assert(t.query(0, 4) == 1);
    std::cout << "checks passed\n";
    return 0;
}
