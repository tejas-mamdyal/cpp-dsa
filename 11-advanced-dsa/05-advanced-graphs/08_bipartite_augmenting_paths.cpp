/*
 Bipartite graph represented by L left adjacency rows into right IDs 0..R-1, L,
R<=30.

owner[v] stores the left vertex matched to right v; each new left root
seeks an alternating augmenting route using a fresh left-visited array.

Left 0 initially takes right 0; left 1 needs right 0, so left 0 is rerouted to
right 1.

An augmenting path increases cardinality by one while preserving unique
endpoints; absence of an augmenting path characterizes maximal cardinality.

O(L*E) time, O(L+R) auxiliary.

Reset seen for each new root; permanently marking left vertices would prohibit later
rematching.
*/
#include <iostream>
#include <cassert>
#include <vector>
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

int main() {
    auto owner = matching({{0, 1}, {0}}, 2);
    assert(owner[0] == 1 && owner[1] == 0);
    assert(matching({{}, {}}, 0).empty());
    std::cout << "checks passed\n";
    return 0;
}
