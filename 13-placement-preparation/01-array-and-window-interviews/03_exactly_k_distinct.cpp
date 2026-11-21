/*
 k>=0; nonempty subarrays only; other common bounds apply. Unless a different bound
is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

Every ending position contributes all valid starting positions in its
at-most window.

Exactly 2=atMost 2-atMost 1 gives 7 for 1,2,1,2,3.

Distinct counts are monotone under left removal, and subtraction cancels every
smaller count.

O(n log n) time, O(n) frequency storage.

Exactly-k itself is not a simple monotone window predicate.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <cstddef>

long long atMost(const std::vector<int>& a, int k) {
    if (k < 0) {
        return 0;
    }
    std::map<int, int> count;
    std::size_t left = 0;
    long long result = 0;
    for (std::size_t right = 0; right < a.size(); ++right) {
        ++count[a[right]];
        while (static_cast<int>(count.size()) > k) {
            if (--count[a[left]] == 0) {
                count.erase(a[left]);
            }
            ++left;
        }
        result += static_cast<long long>(right + 1 - left);
    }
    return result;
}

long long exactly(const std::vector<int>& a, int k) {
    return atMost(a, k) - atMost(a, k - 1);
}

int main() {
    assert(exactly({1, 2, 1, 2, 3}, 2) == 7);
    assert(exactly({}, 0) == 0);
    assert(exactly({1, 1}, 1) == 3);
    std::cout << "checks passed\n";
    return 0;
}
