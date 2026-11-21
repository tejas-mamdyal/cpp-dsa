/*
 At most 30 days, three signed scores each; cannot repeat yesterday task. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

dp[t] is best score after all processed days when the last chosen task is
t; exactly one task per day is required.

Choose 70,50,90 for total 210; the highest task 80 on day 2 cannot follow previous
task 70 if both are task 2.

A current task may follow exactly either of the other two previous task states.

O(days*3) time, O(3) auxiliary.

Zero initialization may invent skipped days when points are negative; initialize the
first day explicitly.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <array>

long long training(const std::vector<std::array<int, 3>>& points) {
    std::array<long long, 3> dp{};
    bool first = true;
    for (auto day : points) {
        std::array<long long, 3> next{};
        for (int task = 0; task < 3; ++task) {
            if (first) {
                next[task] = day[task];
            } else {
                next[task] = day[task] + std::max(dp[(task + 1) % 3], dp[(task + 2) % 3]);
            }
        }
        dp = next;
        first = false;
    }
    return points.empty() ? 0 : *std::max_element(dp.begin(), dp.end());
}

int main() {
    assert(training({{10, 40, 70}, {20, 50, 80}, {30, 60, 90}}) == 210);
    assert(training({}) == 0);
    assert(training({{-1, -2, -3}}) == -1);
    std::cout << "checks passed\n";
    return 0;
}
