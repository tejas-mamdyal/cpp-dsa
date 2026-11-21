/*
 Nonnegative ints; goal may be negative, which returns 0.

IDEA AND STATE: At each endpoint, all starts within an at-most-sum window contribute; subtract
thresholds goal and goal-1.

TRACE: 0,0 with goal 0 ->3 nonempty subarrays.

For two zeros,the at-most-zero windows contribute1 then2 starts;at-most-minus-one
contributes0,total3.

Integer sums partition into <=goal and <=goal-1, leaving exactly
goal; nonnegativity makes at-most windows monotone.

O(n) time, O(1) space.

Zeros create multiple valid starts; counting only one window per endpoint is
insufficient.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

long long sumsAtMost(const std::vector<int>& a, long long goal) {
    if (goal < 0) {
        return 0;
    }
    long long sum = 0;
    long long answer = 0;
    int left = 0;
    for (int right = 0; right < static_cast<int>(a.size()); ++right) {
        sum += a[right];
        while (sum > goal) {
            sum -= a[left];
            ++left;
        }
        answer += right - left + 1;
    }
    return answer;
}

long long exactSum(const std::vector<int>& a, long long goal) {
    if (goal < 0) {
        return 0;
    }
    return sumsAtMost(a, goal) - sumsAtMost(a, goal - 1);
}

int main() {
    assert(exactSum({0, 0}, 0) == 3);
    assert(exactSum({1, 0, 1, 0, 1}, 2) == 4);
    assert(exactSum({}, 0) == 0);
    assert(exactSum({1}, -1) == 0);
    std::cout << "checks passed\n";
    return 0;
}
