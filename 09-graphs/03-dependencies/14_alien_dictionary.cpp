/*
 Words contain only first k lowercase letters, k 1..26; return any consistent full
alphabet order.

Compare adjacent sorted words; their first differing character imposes one
directed precedence arc.

baa before abcd gives b<a; abc before ab is invalid because a longer exact-prefix
word cannot precede its prefix.

Lexical comparison is decided at its first difference; adjacent comparisons
characterize consistency with the given sorted list.

O(total compared word lengths+alphabet+constraints) time/storage.

Do not add constraints from every differing position.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <optional>
#include <utility>
#include <queue>
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

std::optional<std::vector<int>> topological(const Graph& g) {
    std::vector<int> indegree(g.size(), 0);
    for (const auto& row : g) {
        for (int v : row) {
            ++indegree[v];
        }
    }
    std::queue<int> q;
    for (int u = 0; u < static_cast<int>(g.size()); ++u) {
        if (indegree[u] == 0) {
            q.push(u);
        }
    }
    std::vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            --indegree[v];
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    if (order.size() != g.size()) {
        return std::nullopt;
    }
    return order;
}

std::optional<std::vector<int>> alphabet(const std::vector<std::string>& words, int k) {
    Graph g(static_cast<std::size_t>(k));
    for (std::size_t i = 1; i < words.size(); ++i) {
        const auto& a = words[i - 1];
        const auto& b = words[i];
        std::size_t p = 0;
        while (p < a.size() && p < b.size() && a[p] == b[p]) {
            ++p;
        }
        if (p == b.size() && a.size() > b.size()) {
            return std::nullopt;
        }
        if (p < a.size() && p < b.size()) {
            g[a[p] - 'a'].push_back(b[p] - 'a');
        }
    }
    return topological(g);
}

int main() {
    auto order = alphabet({"baa", "abcd", "abca", "cab", "cad"}, 4);
    assert(order && order->size() == 4);
    assert(!alphabet({"abc", "ab"}, 3));
    assert(!alphabet({"a", "b", "a"}, 2));
    std::cout << "checks passed\n";
    return 0;
}
