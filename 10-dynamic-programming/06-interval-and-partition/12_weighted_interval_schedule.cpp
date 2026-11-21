/*
 At most 30 half-open nonempty jobs with distinct IDs; values signed; empty schedule
allowed.

dp[i] is maximum value from first i finish-sorted jobs; compatible[i]
counts earlier jobs finishing by current start.

Jobs[1,3) value 5 and[3,6) value 5 beat overlapping[2,5) value 6 with total 10.

An optimum skips current job or includes it and combines with an optimal
compatible earlier prefix; the two choices are exhaustive.

O(n log(n+1)) time, O(n) states/witness.

Earliest-finish greedy maximizes count, not total value; weighted scheduling needs
this state recurrence.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstddef>

struct Job {
    int start;
    int finish;
    int value;
    int id;
};

std::pair<long long, std::vector<int>> schedule(std::vector<Job> jobs) {
    std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.finish < b.finish;
    });
    std::vector<int> ends;
    for (auto j : jobs) {
        assert(j.start < j.finish);
        ends.push_back(j.finish);
    }
    std::vector<long long> dp(jobs.size() + 1, 0);
    std::vector<std::size_t> compatible(jobs.size() + 1, 0);
    for (std::size_t i = 1; i <= jobs.size(); ++i) {
        auto last = ends.begin() + static_cast<std::ptrdiff_t>(i - 1);
        compatible[i] = static_cast<std::size_t>(
            std::upper_bound(ends.begin(), last, jobs[i - 1].start) - ends.begin());
        dp[i] = std::max(dp[i - 1], jobs[i - 1].value + dp[compatible[i]]);
    }
    std::vector<int> selected;
    for (std::size_t i = jobs.size(); i > 0;) {
        if (dp[i] == dp[i - 1]) {
            --i;
        } else {
            selected.push_back(jobs[i - 1].id);
            i = compatible[i];
        }
    }
    std::reverse(selected.begin(), selected.end());
    return {dp.back(), selected};
}

int main() {
    auto answer = schedule({{1, 3, 5, 0}, {2, 5, 6, 1}, {3, 6, 5, 2}});
    assert(answer.first == 10 && (answer.second == std::vector<int>{0, 2}));
    assert(schedule({}).first == 0);
    assert(schedule({{0, 1, -5, 0}}).second.empty());
    std::cout << "checks passed\n";
    return 0;
}
