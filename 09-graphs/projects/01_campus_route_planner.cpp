/*
 Read n,m,source,target then m directed arcs(from,to,weight). n1..30,
m0..100,weights[-1000000,1000000];reject incomplete/extra/invalid input as ERROR.
Print the selected algorithm,then UNREACHABLE,UNBOUNDED,or DISTANCE and PATH.
Roads are directed;two-way roads require two arcs. Parallel arcs and loops are
allowed. Distance means minimum total weight of a walk. Empty source-target
walk costs0 unless a reachable negative cycle can also reach the target.

SELECTION: All weights1 ->BFS;otherwise all0/1 ->01BFS;otherwise all
nonnegative ->DIJKSTRA;otherwise ->BELLMAN-FORD. The empty-edge graph chooses
BFS. The entire graph is inspected before selection;do not infer its domain
from the source's first adjacency row.

STATE: distance is the best known value,INF means unreachable,parent remembers
strictly improving route steps. BFS marks at enqueue;heap/deque variants skip
stale snapshots. Bellman-Ford checks extra improvements and propagates affected
destinations before any finite route is reconstructed.

Library0->Lab1 cost2,Library0->Cafe2 cost1,Cafe2->Lab1 cost0
selects DIJKSTRA and returns distance1,path0,2,1. A negative cycle unreachable
from source does not invalidate the route. A reachable cycle unable to reach
the requested target does not make that target unbounded either.

Selection establishes the assumptions of the chosen lesson proof.
Every relaxation records a real route. A target is unbounded exactly when
reachable from a source-reachable negative cycle. Otherwise finite predecessor
links reconstruct a shortest witness. All allocations are standard containers.

O(V+E) for BFS/0-1 BFS,O((V+E)log(E+1)) for Dijkstra,O(V*E)
for Bellman-Ford;O(V+E) storage plus output. Bounds keep finite arithmetic safe.

Road cost,edge count and maximum edge effort are different objectives.
Do not display arbitrary numeric distances for negative-cycle-affected targets.
FOLLOW-UP: Add named buildings,waypoint routes and independently validated input
files before introducing geographic heuristics or live traffic assumptions.
*/
#include <algorithm>
#include <cassert>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <utility>
#include <vector>

struct Edge {
    int from;
    int to;
    int weight;
};

constexpr long long INF = std::numeric_limits<long long>::max() / 4;

struct Route {
    std::string algorithm;
    std::string status;
    long long distance = 0;
    std::vector<int> path;
};

Route plan(int n, const std::vector<Edge>& edges, int source, int target) {
    std::vector<std::vector<std::pair<int, int>>> g(static_cast<std::size_t>(n));
    bool unit = true;
    bool binary = true;
    bool nonnegative = true;
    for (auto e : edges) {
        g[e.from].emplace_back(e.to, e.weight);
        unit = unit && e.weight == 1;
        binary = binary && (e.weight == 0 || e.weight == 1);
        nonnegative = nonnegative && e.weight >= 0;
    }
    Route answer;
    if (unit) {
        answer.algorithm = "BFS";
    } else if (binary) {
        answer.algorithm = "01BFS";
    } else if (nonnegative) {
        answer.algorithm = "DIJKSTRA";
    } else {
        answer.algorithm = "BELLMAN-FORD";
    }
    std::vector<long long> d(static_cast<std::size_t>(n), INF);
    std::vector<int> parent(static_cast<std::size_t>(n), -1);
    d[source] = 0;
    if (unit) {
        std::queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto [v, w] : g[u]) {
                (void)w;
                if (d[v] != INF) {
                    continue;
                }
                d[v] = d[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    } else if (binary) {
        std::deque<std::pair<long long, int>> q;
        q.emplace_front(0, source);
        while (!q.empty()) {
            auto [snapshot, u] = q.front();
            q.pop_front();
            if (snapshot != d[u]) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d[u] + w >= d[v]) {
                    continue;
                }
                d[v] = d[u] + w;
                parent[v] = u;
                if (w == 0) {
                    q.emplace_front(d[v], v);
                } else {
                    q.emplace_back(d[v], v);
                }
            }
        }
    } else if (nonnegative) {
        using Item = std::pair<long long, int>;
        std::priority_queue<Item, std::vector<Item>, std::greater<Item>> q;
        q.emplace(0, source);
        while (!q.empty()) {
            auto [snapshot, u] = q.top();
            q.pop();
            if (snapshot != d[u]) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    parent[v] = u;
                    q.emplace(d[v], v);
                }
            }
        }
    } else {
        for (int pass = 0; pass < n - 1; ++pass) {
            bool changed = false;
            for (auto e : edges) {
                if (d[e.from] != INF && d[e.from] + e.weight < d[e.to]) {
                    d[e.to] = d[e.from] + e.weight;
                    parent[e.to] = e.from;
                    changed = true;
                }
            }
            if (!changed) {
                break;
            }
        }
        std::vector<bool> affected(static_cast<std::size_t>(n), false);
        std::queue<int> q;
        for (auto e : edges) {
            if (d[e.from] != INF && d[e.from] + e.weight < d[e.to] && !affected[e.to]) {
                affected[e.to] = true;
                q.push(e.to);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto [v, w] : g[u]) {
                (void)w;
                if (!affected[v]) {
                    affected[v] = true;
                    q.push(v);
                }
            }
        }
        if (affected[target]) {
            answer.status = "UNBOUNDED";
            return answer;
        }
    }
    if (d[target] == INF) {
        answer.status = "UNREACHABLE";
        return answer;
    }
    answer.status = "FINITE";
    answer.distance = d[target];
    for (int v = target; v != -1; v = parent[v]) {
        answer.path.push_back(v);
        assert(answer.path.size() <= static_cast<std::size_t>(n));
    }
    std::reverse(answer.path.begin(), answer.path.end());
    return answer;
}

int main() {
    int n = 0;
    int m = 0;
    int source = 0;
    int target = 0;
    if (!(std::cin >> n >> m >> source >> target) || n < 1 || n > 30 || m < 0 || m > 100
        || source < 0 || source >= n || target < 0 || target >= n) {
        std::cout << "ERROR\n";
        return 0;
    }
    std::vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        Edge e{};
        if (!(std::cin >> e.from >> e.to >> e.weight) || e.from < 0 || e.from >= n || e.to < 0
            || e.to >= n || e.weight < -1000000 || e.weight > 1000000) {
            std::cout << "ERROR\n";
            return 0;
        }
        edges.push_back(e);
    }
    std::cin >> std::ws;
    if (!std::cin.eof()) {
        std::cout << "ERROR\n";
        return 0;
    }
    auto answer = plan(n, edges, source, target);
    std::cout << "ALGORITHM " << answer.algorithm << '\n';
    if (answer.status != "FINITE") {
        std::cout << answer.status << '\n';
        return 0;
    }
    std::cout << "DISTANCE " << answer.distance << "\nPATH";
    for (int vertex : answer.path) {
        std::cout << ' ' << vertex;
    }
    std::cout << '\n';
    return 0;
}
