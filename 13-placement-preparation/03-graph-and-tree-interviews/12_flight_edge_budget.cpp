/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

Layer k stores routes using at most k edges.

Direct flight costs 9; two flights via 1 cost 4.

A bounded route either was already feasible or appends one flight to an
earlier-layer route.

O(budget*(V+E)) time, O(V) work.

In-place updates can consume several flights within the same layer.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <utility>

struct Flight {
    int from;
    int to;
    int cost;
};

std::optional<int>
cheapest(int n, const std::vector<Flight>& flights, int source, int target, int edges) {
    std::vector<int> best(n, 1000000000);
    best[source] = 0;
    for (int k = 0; k < edges; ++k) {
        auto next = best;
        for (auto e : flights) {
            if (best[e.from] != 1000000000) {
                next[e.to] = std::min(next[e.to], best[e.from] + e.cost);
            }
        }
        best = std::move(next);
    }
    return best[target] == 1000000000 ? std::nullopt : std::optional<int>{best[target]};
}

int main() {
    std::vector<Flight> f{{0, 1, 2}, {1, 2, 2}, {0, 2, 9}};
    assert(cheapest(3, f, 0, 2, 1) == 9);
    assert(cheapest(3, f, 0, 2, 2) == 4);
    std::cout << "checks passed\n";
    return 0;
}
