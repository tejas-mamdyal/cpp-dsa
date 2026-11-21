/*
 Bounded signed array; valid existing versions and point indices; half-open sums; old
versions remain readable.

Each version stores a root index into an owning immutable node pool;
updates clone ancestors but share unchanged child subtrees.

Changing index 1 in version 0 creates version 1 with sum 13; branching another
update from version 0 leaves both older roots unchanged.

No existing node is mutated; each new root points to copied changed ancestors and
original unchanged children.

O(n) initial build, O(log(n+1)) time/new nodes per update/query; O(n+versions*log(n+1))
storage.

Do not keep references into a vector pool across recursive push_back; indices remain
stable while addresses may change.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

class Persistent {
    struct Node {
        int left;
        int right;
        long long sum;
    };

    int n;
    std::vector<Node> pool{{0, 0, 0}};
    std::vector<int> roots;

    int build(const std::vector<int>& a, int l, int r) {
        if (l == r) {
            return 0;
        }
        int p = static_cast<int>(pool.size());
        pool.push_back({0, 0, 0});
        if (r - l == 1) {
            pool[p].sum = a[l];
            return p;
        }
        int mid = l + (r - l) / 2;
        pool[p].left = build(a, l, mid);
        pool[p].right = build(a, mid, r);
        pool[p].sum = pool[pool[p].left].sum + pool[pool[p].right].sum;
        return p;
    }

    int set(int old, int l, int r, int index, long long value) {
        int p = static_cast<int>(pool.size());
        Node copy = pool[old];
        pool.push_back(copy);
        if (r - l == 1) {
            pool[p].sum = value;
            return p;
        }
        int mid = l + (r - l) / 2;
        if (index < mid) {
            pool[p].left = set(pool[old].left, l, mid, index, value);
        } else {
            pool[p].right = set(pool[old].right, mid, r, index, value);
        }
        pool[p].sum = pool[pool[p].left].sum + pool[pool[p].right].sum;
        return p;
    }

    long long sum(int p, int l, int r, int ql, int qr) const {
        if (qr <= l || r <= ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return pool[p].sum;
        }
        int mid = l + (r - l) / 2;
        return sum(pool[p].left, l, mid, ql, qr) + sum(pool[p].right, mid, r, ql, qr);
    }

public:
    explicit Persistent(const std::vector<int>& a)
        : n(static_cast<int>(a.size())) {
        roots.push_back(build(a, 0, n));
    }

    int change(int version, int index, long long value) {
        assert(index >= 0 && index < n);
        roots.push_back(set(roots.at(static_cast<std::size_t>(version)), 0, n, index, value));
        return static_cast<int>(roots.size()) - 1;
    }

    long long query(int version, int l, int r) const {
        assert(l >= 0 && l <= r && r <= n);
        return l == r ? 0 : sum(roots.at(static_cast<std::size_t>(version)), 0, n, l, r);
    }
};

int main() {
    Persistent p({1, 2, 3});
    int a = p.change(0, 1, 9);
    int b = p.change(0, 0, -1);
    assert(p.query(0, 0, 3) == 6);
    assert(p.query(a, 0, 3) == 13);
    assert(p.query(b, 0, 3) == 4);
    assert(Persistent({}).query(0, 0, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
