/*
 Signed array; nonempty minimum sum, empty absent.

IDEA AND STATE: Keep the smaller of start-here and extend.

TRACE: 3,-4,2,-3 ->-5.

Ending minima on3,-4,2,-3 are3,-4,-2,-5;the smallest is -5.

Every ending interval starts here or extends an earlier ending interval; only its
minimum matters.

O(n) time, O(1) space.

Do not negate INT_MIN in int to reuse a maximum solver.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

std::optional<long long> minimum(const std::vector<int>& a) {
    if (a.empty()) {
        return std::nullopt;
    }
    long long ending = a[0];
    long long best = ending;
    for (std::size_t i = 1; i < a.size(); ++i) {
        ending = std::min(1LL * a[i], ending + a[i]);
        best = std::min(best, ending);
    }
    return best;
}

int main() {
    assert(minimum({3, -4, 2, -3}) == -5);
    assert(minimum({2, 5}) == 2);
    assert(!minimum({}));
    std::cout << "checks passed\n";
    return 0;
}
