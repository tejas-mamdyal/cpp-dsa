/*
EXACTLY K EQUALS AT-MOST K MINUS AT-MOST K-1

 Count nonempty subarrays; k<=0 returns 0.

IDEA AND STATE: For each endpoint, all starts inside an at-most window are valid.

TRACE: 1,2,1,2,3 with k 2 ->7.

There are12 ranges with at most2 distinct and5 with at most1 distinct;their difference is7.

The two at-most sets differ exactly in subarrays with k distinct values.

Expected O(n) time, O(k+1) space; use long long count.

Subtract counts, not longest lengths; the difference-of-lengths rule is false.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

long long atMost(const std::vector<int>& a, int k) {
    if (k < 0) {
        return 0;
    }
    std::unordered_map<int, int> count;
    int left = 0;
    long long result = 0;
    for (int right = 0; right < static_cast<int>(a.size()); ++right) {
        ++count[a[right]];
        while (static_cast<int>(count.size()) > k) {
            int value = a[left];
            ++left;
            --count[value];
            if (count[value] == 0) {
                count.erase(value);
            }
        }
        result += right - left + 1;
    }
    return result;
}

long long exactly(const std::vector<int>& a, int k) {
    if (k <= 0) {
        return 0;
    }
    return atMost(a, k) - atMost(a, k - 1);
}

int main() {
    assert(exactly({1, 2, 1, 2, 3}, 2) == 7);
    assert(exactly({1, 1}, 1) == 3);
    assert(exactly({}, 1) == 0);
    assert(exactly({1}, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
