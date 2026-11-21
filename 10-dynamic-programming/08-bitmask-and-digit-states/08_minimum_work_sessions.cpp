/*
 n<=16 positive task lengths, each<=positive capacity<=1000; tasks may be reordered.

dp[mask] is lexicographically best pair(number sessions, current
last-session load) for processed tasks; smaller load dominates equal session counts.

Tasks 1,2 fit one capacity 3 session; task 3 needs a second, so answer 2.

Any session arrangement can be ordered task by task; for equal session count, a
lower last load leaves at least as much room for every future task.

O(n*2^n) time, O(2^n) states.

The internal empty-mask pair 1,0 is a convenience; the public empty-task answer is 0.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>

int sessions(const std::vector<int>& tasks, int capacity) {
    if (tasks.empty()) {
        return 0;
    }
    int n = static_cast<int>(tasks.size());
    assert(n <= 16 && capacity > 0);
    std::pair<int, int> impossible{n + 1, 0};
    std::vector<std::pair<int, int>> dp(1U << n, impossible);
    dp[0] = {1, 0};
    for (unsigned int mask = 0; mask < dp.size(); ++mask) {
        if (dp[mask].first > n) {
            continue;
        }
        for (int i = 0; i < n; ++i) {
            assert(tasks[i] > 0 && tasks[i] <= capacity);
            if (mask & (1U << i)) {
                continue;
            }
            auto candidate = dp[mask];
            if (candidate.second + tasks[i] <= capacity) {
                candidate.second += tasks[i];
            } else {
                ++candidate.first;
                candidate.second = tasks[i];
            }
            auto next = mask | (1U << i);
            dp[next] = std::min(dp[next], candidate);
        }
    }
    return dp.back().first;
}

int main() {
    assert(sessions({1, 2, 3}, 3) == 2);
    assert(sessions({3, 1, 3, 1, 1}, 8) == 2);
    assert(sessions({}, 4) == 0);
    std::cout << "checks passed\n";
    return 0;
}
