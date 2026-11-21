/*
 n<=1000; values[-1000,1000]; exact sum over all nonempty ranges.

IDEA AND STATE: Reuse minimum counting on negated bounded values to obtain maximum sums.

TRACE: 1,2,3 ->4.

Singleton ranges contribute0;[1,2] and[2,3] contribute1 each;[1,2,3] contributes2,total4.

For each interval range=max-min; linearity permits independent contribution
totals.

O(n) time, O(n) space.

Negation is safe only under the stated bounded value contract.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

long long minima(const std::vector<int>& a) {
    int n = static_cast<int>(a.size());
    std::vector<int> left(a.size());
    std::vector<int> right(a.size());
    std::vector<int> stack;
    for (int i = 0; i < n; ++i) {
        while (!stack.empty() && a[stack.back()] >= a[i]) {
            stack.pop_back();
        }
        left[i] = stack.empty() ? -1 : stack.back();
        stack.push_back(i);
    }
    stack.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!stack.empty() && a[stack.back()] > a[i]) {
            stack.pop_back();
        }
        right[i] = stack.empty() ? n : stack.back();
        stack.push_back(i);
    }
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += 1LL * a[i] * (i - left[i]) * (right[i] - i);
    }
    return sum;
}

long long ranges(const std::vector<int>& a) {
    std::vector<int> negative;
    for (int x : a) {
        negative.push_back(-x);
    }
    return -minima(negative) - minima(a);
}

long long slowRanges(const std::vector<int>& a) {
    long long out = 0;
    for (std::size_t l = 0; l < a.size(); ++l) {
        int low = a[l];
        int high = a[l];
        for (std::size_t r = l; r < a.size(); ++r) {
            low = std::min(low, a[r]);
            high = std::max(high, a[r]);
            out += high - low;
        }
    }
    return out;
}

int main() {
    assert(ranges({1, 2, 3}) == 4);
    for (int n = 0; n <= 5; ++n) {
        int cases = 1;
        for (int i = 0; i < n; ++i) {
            cases *= 3;
        }
        for (int code = 0; code < cases; ++code) {
            int v = code;
            std::vector<int> a(static_cast<std::size_t>(n));
            for (int& x : a) {
                x = v % 3 - 1;
                v /= 3;
            }
            assert(ranges(a) == slowRanges(a));
        }
    }
    std::cout << "checks passed\n";
    return 0;
}
