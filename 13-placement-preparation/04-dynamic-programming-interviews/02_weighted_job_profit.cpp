/*
 Half-open jobs, start<end; empty selection permitted. Unless a different bound is
stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

best[k] is optimum using the first k finish-sorted jobs.

Jobs[1,3),[3,5) are compatible and yield 90.

An optimum either excludes the final job or combines it with an optimum
compatible prefix.

O(n^2) time, O(n) storage; binary-search compatible finishes for O(n log n).

Earliest-finish greedy maximizes job count, not arbitrary profit.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

struct Job {
    int start;
    int end;
    int profit;
};

int profit(std::vector<Job> jobs) {
    std::sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
        return a.end < b.end;
    });
    std::vector<int> best(jobs.size() + 1);
    for (std::size_t i = 0; i < jobs.size(); ++i) {
        int prefix = 0;
        for (std::size_t j = 0; j < i; ++j) {
            if (jobs[j].end <= jobs[i].start) {
                prefix = static_cast<int>(j) + 1;
            }
        }
        best[i + 1] = std::max(best[i], best[prefix] + jobs[i].profit);
    }
    return best.back();
}

int main() {
    assert(profit({{1, 3, 50}, {2, 4, 10}, {3, 5, 40}}) == 90);
    assert(profit({{0, 1, -2}}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
