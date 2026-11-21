/*
 Same bounded TSP domain; return cost and one valid optimum vertex route. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

parent[mask][u] records the previous city attaining the saved cost; mask
without u identifies its previous state.

For one optimum, full-mask last 1 points to 2, then 0; reverse and append 0 to
close the cycle.

Each parent was saved from an improving valid transition; clearing one bit
strictly reduces unresolved route history.

O(n^2*2^n) time, O(n*2^n) table plus route.

Reverse the backward path before appending the closing source.
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
    auto answer = tour({{0, 10, 15}, {10, 0, 20}, {15, 20, 0}});
    assert(answer && answer->first == 45 && answer->second.size() == 4
           && answer->second.front() == 0 && answer->second.back() == 0);
    assert(tour({{0}})->second == std::vector<int>{0});
    std::cout << "checks passed\n";
    return 0;
}
