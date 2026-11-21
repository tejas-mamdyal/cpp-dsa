/*
 Grid dimensions 1..30; additions are valid coordinates, possibly repeated. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

Inactive DSU slots do not count as land; each new active cell adds one
component, then successful neighbor unions subtract one.

Two diagonal cells give two islands; adding 0,1 bridges both; adding it again
changes nothing.

All and only active orthogonal edges are joined when their later endpoint
activates.

O(R*C+Q*alpha(R*C)) time, O(R*C+Q) storage.

Duplicate activation must not increase island count.
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

std::vector<int>
islandCounts(int rows, int cols, const std::vector<std::pair<int, int>>& additions) {
    DSU dsu(rows * cols);
    std::vector<bool> active(static_cast<std::size_t>(rows * cols), false);
    std::vector<int> out;
    int count = 0;
    const int dr[4]{1, -1, 0, 0};
    const int dc[4]{0, 0, 1, -1};
    for (auto [r, c] : additions) {
        int id = r * cols + c;
        if (!active[id]) {
            active[id] = true;
            ++count;
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && active[nr * cols + nc]
                    && dsu.unite(id, nr * cols + nc)) {
                    --count;
                }
            }
        }
        out.push_back(count);
    }
    return out;
}

int main() {
    assert((islandCounts(2, 2, {{0, 0}, {1, 1}, {0, 1}, {0, 1}}) == std::vector<int>{1, 2, 1, 1}));
    std::cout << "checks passed\n";
    return 0;
}
