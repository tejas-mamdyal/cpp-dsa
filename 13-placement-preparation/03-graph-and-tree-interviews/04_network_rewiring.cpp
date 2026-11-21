/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

Successful unions count component reductions; cycle links are reusable.

A triangle leaves one spare link for an isolated fourth vertex.

C components require C-1 joins, and E>=V-1 supplies enough surplus after internal
forests.

O(E*alpha(V)) amortized time, O(V) storage.

Assume a cable may be relocated to arbitrary endpoints.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <cstddef>
#include <numeric>

class DSU {
    std::vector<int> parent;
    std::vector<int> size;

public:
    explicit DSU(int n)
        : parent(static_cast<std::size_t>(n)),
          size(static_cast<std::size_t>(n), 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (size[a] < size[b]) {
            std::swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    int count(int u) {
        return size[find(u)];
    }
};

int rewires(int n, const std::vector<std::pair<int, int>>& links) {
    if (n == 0) {
        return 0;
    }
    if (static_cast<int>(links.size()) < n - 1) {
        return -1;
    }
    DSU d(n);
    int components = n;
    for (auto [u, v] : links) {
        if (d.unite(u, v)) {
            --components;
        }
    }
    return components - 1;
}

int main() {
    assert(rewires(4, {{0, 1}, {1, 2}, {0, 2}}) == 1);
    assert(rewires(4, {{0, 1}}) == -1);
    std::cout << "checks passed\n";
    return 0;
}
