/*
 At most 12 elements, values[-3,3]; nonempty product; empty absent.

IDEA AND STATE: Keep both extreme products ending here before computing the next pair.

TRACE: -2,3,-4 ->24.

After -2 and3,ending extremes are -6 and3;multiplying by -4 creates candidates24 and -12,so
best becomes24.

A positive factor preserves order, a negative reverses it, and zero resets both
extremes.

O(n) time, O(1) space.

Updating low before high loses the previous state; bounded input prevents overflow.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

std::optional<long long> product(const std::vector<int>& a) {
    if (a.empty()) {
        return std::nullopt;
    }
    long long low = a[0];
    long long high = a[0];
    long long best = high;
    for (std::size_t i = 1; i < a.size(); ++i) {
        long long x = a[i];
        long long first = low * x;
        long long second = high * x;
        low = std::min({x, first, second});
        high = std::max({x, first, second});
        best = std::max(best, high);
    }
    return best;
}

int main() {
    assert(product({-2, 3, -4}) == 24);
    assert(product({-2, 0, -1}) == 0);
    assert(product({-3}) == -3);
    assert(!product({}));
    std::cout << "checks passed\n";
    return 0;
}
