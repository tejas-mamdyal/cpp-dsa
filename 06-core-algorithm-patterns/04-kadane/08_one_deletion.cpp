/*
 At most one deletion; remaining subarray must be nonempty; empty absent.

IDEA AND STATE: Compute best sums ending and starting at each index; join neighbors around an
interior deletion.

TRACE: 1,-2,0,3 ->4 after deleting -2.

For deletion index1,left-ending sum at0 is1 and right-starting sum at2 is3;joining them
yields4.

An optimum either deletes nothing or joins the best left-ending and
right-starting pieces around its deleted index.

O(n) time, O(n) auxiliary space.

At most one permits no deletion; singletons must retain their value.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

std::optional<long long> maximum(const std::vector<int>& a) {
    if (a.empty()) {
        return std::nullopt;
    }
    long long ending = a[0];
    long long best = ending;
    for (std::size_t i = 1; i < a.size(); ++i) {
        ending = std::max(1LL * a[i], ending + a[i]);
        best = std::max(best, ending);
    }
    return best;
}

std::optional<long long> deletion(const std::vector<int>& a) {
    if (a.empty()) {
        return std::nullopt;
    }
    std::vector<long long> left(a.size());
    std::vector<long long> right(a.size());
    left[0] = a[0];
    right.back() = a.back();
    for (std::size_t i = 1; i < a.size(); ++i) {
        left[i] = std::max(1LL * a[i], left[i - 1] + a[i]);
    }
    for (int i = static_cast<int>(a.size()) - 2; i >= 0; --i) {
        right[i] = std::max(1LL * a[i], right[i + 1] + a[i]);
    }
    long long best = *maximum(a);
    for (std::size_t i = 1; i + 1 < a.size(); ++i) {
        best = std::max(best, left[i - 1] + right[i + 1]);
    }
    return best;
}

int main() {
    assert(deletion({1, -2, 0, 3}) == 4);
    assert(deletion({-5, -2}) == -2);
    assert(deletion({7}) == 7);
    assert(!deletion({}));
    std::cout << "checks passed\n";
    return 0;
}
