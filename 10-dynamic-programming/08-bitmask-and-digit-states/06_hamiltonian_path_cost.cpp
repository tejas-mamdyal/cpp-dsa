/*
 Square optional signed-cost matrix, n 1..12; specified valid endpoints; visit all
vertices exactly once.

dp[mask][u] is minimum source-starting route visiting exactly mask and
ending u; the required answer is full-mask, target without a return edge.

0->1 cost 2 then 1->2 cost-3 yields-1; negative edges are safe because no vertex
can repeat.

Subset growth is acyclic even with signed weights; each complete Hamiltonian
route has one smaller-mask predecessor.

O(n^2*2^n) time, O(n*2^n) storage.

Use an optional edge representation when negative costs are valid; numeric-1 cannot
mean both missing and cost-1.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <limits>
#include <cstddef>

std::optional<long long>
pathCost(const std::vector<std::vector<std::optional<int>>>& cost, int source, int target) {
    int n = static_cast<int>(cost.size());
    assert(n >= 1 && n <= 12);
    const long long inf = std::numeric_limits<long long>::max() / 4;
    std::vector<std::vector<long long>> dp(
        1U << n, std::vector<long long>(static_cast<std::size_t>(n), inf));
    dp[1U << source][source] = 0;
    for (unsigned int mask = 0; mask < dp.size(); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (dp[mask][u] == inf) {
                continue;
            }
            for (int v = 0; v < n; ++v) {
                if ((mask & (1U << v)) == 0U && cost[u][v]) {
                    unsigned int next = mask | (1U << v);
                    dp[next][v] = std::min(dp[next][v], dp[mask][u] + *cost[u][v]);
                }
            }
        }
    }
    long long answer = dp.back()[target];
    if (answer == inf) {
        return std::nullopt;
    }
    return answer;
}

int main() {
    assert(pathCost({{0, 2, 8}, {std::nullopt, 0, -3}, {std::nullopt, std::nullopt, 0}}, 0, 2)
           == -1);
    assert(!pathCost({{0, std::nullopt}, {std::nullopt, 0}}, 0, 1));
    std::cout << "checks passed\n";
    return 0;
}
