/*
 Undirected loop-free matrix<=8 vertices; seek a route starting at vertex 0; empty graph
has empty route. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000].
Recursive examples assume valid acyclic owned structures; exponential searches use the smaller
bounds stated here. No input; keep assertions enabled. Success prints checks passed.

path stores chosen vertices, used prevents repeats. Unlike a cycle, no final
edge back to 0 is required.

A chain 0-1-2 returns 0,1,2; two disconnected vertices have no route.

Every full permutation beginning 0 is considered except prefixes violating edges
or uniqueness.

O(n*n!) upper-bound time, O(n) auxiliary and witness.

A Hamiltonian path visits vertices once; an Euler path concerns edges and is a later
topic.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>

bool extend(const std::vector<std::vector<int>>& edges,
            std::vector<bool>& used,
            std::vector<int>& path) {
    if (path.size() == edges.size()) {
        return true;
    }
    int last = path.back();
    for (int v = 0; v < static_cast<int>(edges.size()); ++v) {
        if (used[v] || !edges[last][v]) {
            continue;
        }
        used[v] = true;
        path.push_back(v); // Choose this route element before exploring its completions.
        if (extend(edges, used, path)) {
            return true;
        }
        path.pop_back(); // Undo so the next sibling sees the same entry prefix.
        used[v] = false;
    }
    return false;
}

std::optional<std::vector<int>> hamilton(const std::vector<std::vector<int>>& edges) {
    if (edges.empty()) {
        return std::vector<int>{};
    }
    std::vector<bool> used(edges.size(), false);
    std::vector<int> path{0};
    used[0] = true;
    if (extend(edges, used, path)) {
        return path;
    }
    return std::nullopt;
}

int main() {
    assert((hamilton({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}})
            == std::optional<std::vector<int>>{{0, 1, 2}}));
    assert(!hamilton({{0, 0}, {0, 0}}));
    assert(hamilton({})->empty());
    std::cout << "checks passed\n";
    return 0;
}
