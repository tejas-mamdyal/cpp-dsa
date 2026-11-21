/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

A queue layer contains courses whose prerequisites finished in earlier
semesters.

0 and 1 share semester 1;2 follows in semester 2.

The earliest semester of a course is one beyond its latest prerequisite; layer
processing attains that bound.

O(V+E) time/storage.

Newly unlocked courses must wait for the next queue layer.
*/
#include <iostream>
#include <cassert>
#include <vector>
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

int semesters(const Graph& g) {
    std::vector<int> degree(g.size());
    for (auto& row : g) {
        for (int v : row) {
            ++degree[v];
        }
    }
    std::queue<int> q;
    for (int i = 0; i < static_cast<int>(g.size()); ++i) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }
    int done = 0;
    int rounds = 0;
    while (!q.empty()) {
        int layer = static_cast<int>(q.size());
        ++rounds;
        while (layer--) {
            int u = q.front();
            q.pop();
            ++done;
            for (int v : g[u]) {
                if (--degree[v] == 0) {
                    q.push(v);
                }
            }
        }
    }
    return done == static_cast<int>(g.size()) ? rounds : -1;
}

int main() {
    assert(semesters(graph(3, {{0, 2}, {1, 2}}, true)) == 2);
    assert(semesters(graph(2, {{0, 1}, {1, 0}}, true)) == -1);
    assert(semesters(graph(0, {}, true)) == 0);
    std::cout << "checks passed\n";
    return 0;
}
