/*
 n<=1000; values[-1000,1000]; exact long long sum, no modulo.

IDEA AND STATE: Previous strictly smaller and next smaller-or-equal assign ties to the
rightmost minimum.

TRACE: 2,2 ->6; three intervals each minimum 2.

For2,2,the left occurrence owns only its singleton;the right occurrence owns its singleton and
the full pair,total6.

Each interval has one rightmost minimum; independent left/right endpoint choices
give the product of distances.

O(n) time, O(n) space.

Using strict comparisons on both sides double-counts equal minima.
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

int main() {
    assert(minima({3, 1, 2, 4}) == 17);
    assert(minima({2, 2}) == 6);
    assert(minima({-1, -1}) == -3);
    assert(minima({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
