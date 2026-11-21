/*
 Undirected edge list and a batch of distinct valid edge IDs to remove; return
initial count followed by the count after each deletion.

Build the graph after all deletions, then add removed edge IDs backward;
record component counts and reverse the answers.

Deleting two edges of a three-node chain gives counts 1,2,3 including the initial
graph.

The reversed state before readding deletion i is exactly the forward graph after
deletion i.

O(V+(E+Q)*alpha(V)) time, O(V+E+Q) storage.

This is offline; standard DSU cannot remove an edge from a live component.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
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

std::vector<int> afterDeletions(int n,
                                const std::vector<std::pair<int, int>>& edges,
                                const std::vector<int>& deleted) {
    std::vector<bool> absent(edges.size(), false);
    for (int id : deleted) {
        assert(!absent[id]);
        absent[id] = true;
    }
    DSU dsu(n);
    int components = n;
    for (std::size_t i = 0; i < edges.size(); ++i) {
        if (!absent[i] && dsu.unite(edges[i].first, edges[i].second)) {
            --components;
        }
    }
    std::vector<int> out{components};
    for (std::size_t i = deleted.size(); i > 0; --i) {
        auto e = edges[deleted[i - 1]];
        if (dsu.unite(e.first, e.second)) {
            --components;
        }
        out.push_back(components);
    }
    std::reverse(out.begin(), out.end());
    return out;
}

int main() {
    assert((afterDeletions(3, {{0, 1}, {1, 2}}, {0, 1}) == std::vector<int>{1, 2, 3}));
    assert((afterDeletions(2, {{0, 1}, {0, 1}}, {0}) == std::vector<int>{1, 1}));
    std::cout << "checks passed\n";
    return 0;
}
