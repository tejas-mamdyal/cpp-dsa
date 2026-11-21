/*
 Unit-time jobs, integer deadlines>=0; empty selection allowed. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

After processing deadline d, selected retains the best feasible unit-time
jobs under prefix deadlines.

Among deadlines 1,1,2,2, profits 40 and 30 fit two slots.

When one too many jobs compete for d slots, removing the smallest profit is a
safe exchange; later deadlines cannot repair that prefix overload.

O(n log n) time, O(n) heap.

This greedy argument requires unit durations, not arbitrary job lengths.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <functional>

int schedule(std::vector<std::pair<int, int>> jobs) {
    std::sort(jobs.begin(), jobs.end());
    std::priority_queue<int, std::vector<int>, std::greater<int>> selected;
    int sum = 0;
    for (auto [deadline, profit] : jobs) {
        if (profit <= 0) {
            continue;
        }
        selected.push(profit);
        sum += profit;
        if (static_cast<int>(selected.size()) > deadline) {
            sum -= selected.top();
            selected.pop();
        }
    }
    return sum;
}

int main() {
    assert(schedule({{1, 20}, {1, 10}, {2, 40}, {2, 30}}) == 70);
    assert(schedule({{0, 10}, {1, -2}}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
