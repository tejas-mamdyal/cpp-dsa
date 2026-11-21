/*
 Square directed matrix, n 0..12; nonnegative costs,-1 absent arc; empty/singleton
tour costs 0.

dp[mask][u] is minimum cost of a route starting 0, visiting exactly mask,
and ending u; close the full subset with one arc back to 0.

Three cities cost 10+20+15=45 in either tour orientation.

Every route extends a unique smaller-mask predecessor and last city; all subsets
are processed before their supersets.

O(n^2*2^n) time, O(n*2^n) tables.

The last-to-start arc is required for a cycle; do not confuse a Hamiltonian path with
a tour.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <utility>
#include <limits>
#include <cstddef>

std::optional<std::pair<long long, std::vector<int>>>
tour(const std::vector<std::vector<int>>& cost) {
    int n = static_cast<int>(cost.size());
    assert(n <= 12);
    if (n == 0) {
        return std::pair<long long, std::vector<int>>{0, {}};
    }
    if (n == 1) {
        return std::pair<long long, std::vector<int>>{0, {0}};
    }
    const long long inf = std::numeric_limits<long long>::max() / 4;
    unsigned int size = 1U << n;
    std::vector<std::vector<long long>> dp(
        size, std::vector<long long>(static_cast<std::size_t>(n), inf));
    std::vector<std::vector<int>> parent(size, std::vector<int>(static_cast<std::size_t>(n), -1));
    dp[1][0] = 0;
    for (unsigned int mask = 1; mask < size; ++mask) {
        for (int u = 0; u < n; ++u) {
            if (dp[mask][u] == inf) {
                continue;
            }
            for (int v = 0; v < n; ++v) {
                if ((mask & (1U << v)) || cost[u][v] < 0) {
                    continue;
                }
                unsigned int next = mask | (1U << v);
                long long candidate = dp[mask][u] + cost[u][v];
                if (candidate < dp[next][v]) {
                    dp[next][v] = candidate;
                    parent[next][v] = u;
                }
            }
        }
    }
    long long best = inf;
    int last = -1;
    for (int u = 1; u < n; ++u) {
        if (dp[size - 1][u] != inf && cost[u][0] >= 0 && dp[size - 1][u] + cost[u][0] < best) {
            best = dp[size - 1][u] + cost[u][0];
            last = u;
        }
    }
    if (last == -1) {
        return std::nullopt;
    }
    std::vector<int> path;
    unsigned int mask = size - 1;
    int u = last;
    while (u != -1) {
        path.push_back(u);
        int previous = parent[mask][u];
        mask ^= 1U << u;
        u = previous;
    }
    std::reverse(path.begin(), path.end());
    path.push_back(0);
    return std::pair<long long, std::vector<int>>{best, path};
}

int main() {
    assert(tour({{0, 10, 15}, {10, 0, 20}, {15, 20, 0}})->first == 45);
    assert(!tour({{0, 1}, {-1, 0}}));
    assert(tour({})->first == 0);
    std::cout << "checks passed\n";
    return 0;
}
