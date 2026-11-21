/*
 Equal-length nonnegative gas/cost arrays; empty absent; unlimited tank.

IDEA AND STATE: Accumulate total net gas and candidate tank; after a negative tank, restart
after the failing station.

TRACE: gas 1,2,3,4,5; cost 3,4,5,1,2 ->start 3.

Net deficits at0,1,2 reset the candidate to3;total net0 permits that surviving candidate to
complete the cycle.

Earlier candidate prefixes had nonnegative balance, so any interior start has no
more gas at the failed end; total nonnegative guarantees the final surviving candidate wraps
successfully.

O(n) time, O(1) space.

A locally surviving suffix is insufficient unless total gas covers total cost.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>

std::optional<int> station(const std::vector<int>& gas, const std::vector<int>& cost) {
    assert(gas.size() == cost.size());
    if (gas.empty()) {
        return std::nullopt;
    }
    long long total = 0;
    long long tank = 0;
    int start = 0;
    for (int i = 0; i < static_cast<int>(gas.size()); ++i) {
        long long net = 1LL * gas[i] - cost[i];
        total += net;
        tank += net;
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    if (total < 0) {
        return std::nullopt;
    }
    return start;
}

bool completes(const std::vector<int>& gas, const std::vector<int>& cost, int start) {
    long long tank = 0;
    for (int step = 0; step < static_cast<int>(gas.size()); ++step) {
        int i = (start + step) % static_cast<int>(gas.size());
        tank += 1LL * gas[i] - cost[i];
        if (tank < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> g{1, 2, 3, 4, 5};
    std::vector<int> c{3, 4, 5, 1, 2};
    auto x = station(g, c);
    assert(x && *x == 3 && completes(g, c, *x));
    assert(!station({1}, {2}));
    assert(!station({}, {}));
    assert(station({0}, {0}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
