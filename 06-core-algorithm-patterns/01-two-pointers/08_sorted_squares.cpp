/*
 Nondecreasing input; return sorted long long squares.

IDEA AND STATE: The greatest absolute remaining value is at one of the endpoints.

TRACE: -4,-1,0,3,10 ->0,1,9,16,100.

Compare magnitudes4 and10:write100 last;then16,9,1,and0 fill the remaining slots backward.

Choosing the larger endpoint square fixes the greatest unfilled output position.

O(n) time, O(n) returned storage, O(1) working state.

Avoid abs(INT_MIN); the bounded inputs are widened before multiplication.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<long long> squares(const std::vector<int>& a) {
    std::vector<long long> out(a.size());
    int l = 0;
    int r = static_cast<int>(a.size()) - 1;
    for (std::size_t end = a.size(); end > 0; --end) {
        long long left = 1LL * a[l] * a[l];
        long long right = 1LL * a[r] * a[r];
        if (left > right) {
            out[end - 1] = left;
            ++l;
        } else {
            out[end - 1] = right;
            --r;
        }
    }
    return out;
}

int main() {
    assert((squares({-4, -1, 0, 3, 10}) == std::vector<long long>{0, 1, 9, 16, 100}));
    assert(squares({}).empty());
    assert((squares({-3, -2}) == std::vector<long long>{4, 9}));
    std::cout << "checks passed\n";
    return 0;
}
