/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Parse n, m and exactly m endpoint pairs into temporary storage; construct
only after complete validation.

2 1 0 2 rejects endpoint 2 because valid indices are 0,1.

Construction is reached only when every required field and endpoint is valid and
no trailing field remains.

O(V+E) time/storage within explicit bounds.

Never index adjacency using an unvalidated external endpoint.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <optional>
#include <utility>
#include <sstream>
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

std::optional<Graph> parse(const std::string& line) {
    std::istringstream in(line);
    int n = 0;
    int m = 0;
    if (!(in >> n >> m) || n < 0 || n > 30 || m < 0 || m > 100) {
        return std::nullopt;
    }
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u = 0;
        int v = 0;
        if (!(in >> u >> v) || u < 0 || v < 0 || u >= n || v >= n) {
            return std::nullopt;
        }
        edges.emplace_back(u, v);
    }
    in >> std::ws;
    if (!in.eof()) {
        return std::nullopt;
    }
    return graph(n, edges);
}

int main() {
    assert(parse("3 2 0 1 1 2"));
    assert(!parse("2 1 0 2"));
    assert(!parse("3 2 0 1"));
    assert(!parse("0 0 extra"));
    assert(parse("0 0")->empty());
    std::cout << "checks passed\n";
    return 0;
}
