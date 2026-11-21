/*
 At most 30 distinct stone coordinates; remove a stone only when another remaining
stone shares its row or column.

Rows and columns are disjoint vertex domains; each stone joins its row to
its column. Count connected stone groups.

Three stones sharing row/column links form one group; isolated 2,2 forms another;
four minus two gives 2 removals.

Within each connected group all but one stone can be removed by following a
spanning dependency tree; the last cannot be removed.

O(N log(N+1)+N*alpha(N)) time, O(N) storage.

Row 0 and column 0 must have different DSU IDs.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <map>
#include <set>
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

int removable(const std::vector<std::pair<int, int>>& stones) {
    std::map<int, int> row;
    std::map<int, int> col;
    for (auto [r, c] : stones) {
        row.emplace(r, 0);
        col.emplace(c, 0);
    }
    int next = 0;
    for (auto& item : row) {
        item.second = next;
        ++next;
    }
    for (auto& item : col) {
        item.second = next;
        ++next;
    }
    DSU dsu(next);
    for (auto [r, c] : stones) {
        dsu.unite(row.at(r), col.at(c));
    }
    std::set<int> components;
    for (auto [r, c] : stones) {
        (void)c;
        components.insert(dsu.find(row.at(r)));
    }
    return static_cast<int>(stones.size()) - static_cast<int>(components.size());
}

int main() {
    assert(removable({{0, 0}, {0, 1}, {1, 0}, {2, 2}}) == 2);
    assert(removable({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
