/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

ZL, ZR are vertices reachable by unmatched left-to-right edges and matched
right-to-left edges; cover is(Left minus ZL) union ZR.

Two left vertices sharing right 0 have a size 1 cover containing only right 0.

Every uncovered-edge possibility contradicts alternating reachability; the
constructed cover selects exactly one endpoint per maximum-matching edge, so no smaller cover
exists.

O(L*E+V+E) time including matching, O(V+E) storage.

The equality between maximum matching and minimum vertex cover requires a bipartite
graph.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <queue>
#include <cstddef>

bool augment(const std::vector<std::vector<int>>& g,
             int u,
             std::vector<bool>& seen,
             std::vector<int>& owner) {
    if (seen[u]) {
        return false;
    }
    seen[u] = true;
    for (int v : g[u]) {
        if (owner[v] == -1 || augment(g, owner[v], seen, owner)) {
            owner[v] = u;
            return true;
        }
    }
    return false;
}

std::vector<int> matching(const std::vector<std::vector<int>>& g, int rightCount) {
    std::vector<int> owner(static_cast<std::size_t>(rightCount), -1);
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        std::vector<bool> seen(g.size(), false);
        augment(g, u, seen, owner);
    }
    return owner;
}

std::pair<std::vector<int>, std::vector<int>> cover(const std::vector<std::vector<int>>& g,
                                                    int rightCount) {
    auto owner = matching(g, rightCount);
    std::vector<int> mate(g.size(), -1);
    for (int v = 0; v < rightCount; ++v) {
        if (owner[v] != -1) {
            mate[owner[v]] = v;
        }
    }
    std::vector<bool> left(g.size(), false);
    std::vector<bool> right(static_cast<std::size_t>(rightCount), false);
    std::queue<int> q;
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        if (mate[u] == -1) {
            left[u] = true;
            q.push(u);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (mate[u] == v || right[v]) {
                continue;
            }
            right[v] = true;
            if (owner[v] != -1 && !left[owner[v]]) {
                left[owner[v]] = true;
                q.push(owner[v]);
            }
        }
    }
    std::vector<int> a;
    std::vector<int> b;
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        if (!left[u]) {
            a.push_back(u);
        }
    }
    for (int v = 0; v < rightCount; ++v) {
        if (right[v]) {
            b.push_back(v);
        }
    }
    return {a, b};
}

int main() {
    auto result = cover({{0, 1}, {0}}, 2);
    assert(result.first.size() + result.second.size() == 2);
    auto small = cover({{0}, {0}}, 1);
    assert(small.first.empty() && small.second == std::vector<int>{0});
    std::cout << "checks passed\n";
    return 0;
}
