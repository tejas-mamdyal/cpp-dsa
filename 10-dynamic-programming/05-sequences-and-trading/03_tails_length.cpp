/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

tails[len-1] is minimum possible last value of a strictly increasing
subsequence of length len in the processed prefix.

Values 2,6,3,4,1,5 produce tails 1,3,4,5; length 4 is valid but those final tails
are not one positional witness.

A smaller tail is never worse for future extension; lower_bound finds the longest
extendable shorter length and preserves sorted tails.

O(n log(n+1)) time, O(n) auxiliary.

Do not present the final tails vector as a guaranteed actual subsequence.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int lis(const std::vector<int>& a) {
    std::vector<int> tails;
    for (int x : a) {
        auto it = std::lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) {
            tails.push_back(x);
        } else {
            *it = x;
        }
    }
    return static_cast<int>(tails.size());
}

int main() {
    assert(lis({10, 9, 2, 5, 3, 7, 101, 18}) == 4);
    assert(lis({2, 2, 2}) == 1);
    assert(lis({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
