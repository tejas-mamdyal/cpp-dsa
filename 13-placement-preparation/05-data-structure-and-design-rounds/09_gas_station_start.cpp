/*
 Equal-length nonnegative gas/cost vectors; any valid start accepted. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

tank measures balance from the current candidate start, total measures the
entire cycle.

Start 3 accumulates enough surplus before the low-gas stations.

If the candidate fails at i, every intermediate start has no larger prefix
balance and also fails; nonnegative total makes the final surviving candidate feasible around
the cycle.

O(n) time, O(1) work.

A locally large gas value alone does not prove a valid complete cycle.
*/
#include <iostream>
#include <cassert>
#include <vector>

int station(const std::vector<int>& gas, const std::vector<int>& cost) {
    if (gas.empty()) {
        return -1;
    }
    int total = 0;
    int tank = 0;
    int start = 0;
    for (int i = 0; i < static_cast<int>(gas.size()); ++i) {
        int difference = gas[i] - cost[i];
        total += difference;
        tank += difference;
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    return total < 0 ? -1 : start;
}

int main() {
    assert(station({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}) == 3);
    assert(station({2, 3, 4}, {3, 4, 3}) == -1);
    std::cout << "checks passed\n";
    return 0;
}
