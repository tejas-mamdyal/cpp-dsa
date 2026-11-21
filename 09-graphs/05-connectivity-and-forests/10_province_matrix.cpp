/*
 Square symmetric 0/1 adjacency matrix, V<=30.

A symmetric matrix specifies undirected adjacency; scan each off-diagonal
pair once.

First two cities are connected and the third is isolated, so two provinces.

Union of every listed undirected adjacency yields exactly its transitive
connected components.

O(V^2*alpha(V)) time, O(V) auxiliary beyond matrix.

Diagonal ones do not create extra provinces or useful merges.
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

int provinces(const std::vector<std::vector<int>>& a) {
    DSU dsu(static_cast<int>(a.size()));
    int count = static_cast<int>(a.size());
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        for (int j = i + 1; j < static_cast<int>(a.size()); ++j) {
            if (a[i][j] && dsu.unite(i, j)) {
                --count;
            }
        }
    }
    return count;
}

int main() {
    assert(provinces({{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) == 2);
    assert(provinces({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
