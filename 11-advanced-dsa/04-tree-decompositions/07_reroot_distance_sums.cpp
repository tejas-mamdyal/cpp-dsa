/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

First compute subtree sizes and root 0 distance sum; answer[u] then means
sum of distances from u to every vertex in the whole tree.

Moving from 0 to child 1 makes its subtree vertices one step closer and all others
one farther: answer 1=answer 0+V-2*size 1.

The edge partitions vertices into the child subtree and its complement; distance
changes are-1 and+1 respectively.

O(V) time/storage, improving repeated BFS O(V^2).

Use subtree size under the original rooting during every reroot transition.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <cstddef>

using Graph = std::vector<std::vector<int>>;

Graph graph(int n, const std::vector<std::pair<int, int>>& edges, bool directed = false) {
    assert(n >= 0);
    Graph g(static_cast<std::size_t>(n));
    for (auto [u, v] : edges) {
        assert(u >= 0 && v >= 0 && u < n && v < n);
        g[u].push_back(v);
        if (!directed) {
            g[v].push_back(u);
        }
    }
    return g;
}

void sizes(
    const Graph& g, int u, int parent, std::vector<int>& count, std::vector<long long>& answer) {
    count[u] = 1;
    for (int v : g[u]) {
        if (v == parent) {
            continue;
        }
        sizes(g, v, u, count, answer);
        count[u] += count[v];
        answer[u] += answer[v] + count[v];
    }
}

void moveRoot(const Graph& g,
              int u,
              int parent,
              const std::vector<int>& count,
              std::vector<long long>& answer) {
    for (int v : g[u]) {
        if (v == parent) {
            continue;
        }
        answer[v] = answer[u] + static_cast<long long>(g.size()) - 2LL * count[v];
        moveRoot(g, v, u, count, answer);
    }
}

std::vector<long long> sums(const Graph& g) {
    std::vector<int> count(g.size(), 0);
    std::vector<long long> answer(g.size(), 0);
    if (!g.empty()) {
        sizes(g, 0, -1, count, answer);
        moveRoot(g, 0, -1, count, answer);
    }
    return answer;
}

int main() {
    assert((sums(graph(3, {{0, 1}, {1, 2}})) == std::vector<long long>{3, 2, 3}));
    assert(sums({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
