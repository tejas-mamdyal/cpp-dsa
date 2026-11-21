/*
 Sorted inputs; nonempty combined array.

A merged reference exposes both middle order statistics; lesson 09
supplies the logarithmic alternative.

1,2,3,4 averages middle 2 and 3 into 2.5.

Sorted merge preserves every input element and the median definition selects the
middle positions.

O(n+m) time/storage; replace with two lesson 09 kth calls for logarithmic work.

Convert before addition if full-range int inputs are later allowed.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstddef>
#include <stdexcept>

double median(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> merged;
    std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(merged));
    if (merged.empty()) {
        throw std::invalid_argument("empty");
    }
    std::size_t n = merged.size();
    return (static_cast<double>(merged[(n - 1) / 2]) + merged[n / 2]) / 2.0;
}

int main() {
    assert(median({1, 3}, {2}) == 2.0);
    assert(median({1, 2}, {3, 4}) == 2.5);
    assert(median({}, {5}) == 5.0);
    std::cout << "checks passed\n";
    return 0;
}
