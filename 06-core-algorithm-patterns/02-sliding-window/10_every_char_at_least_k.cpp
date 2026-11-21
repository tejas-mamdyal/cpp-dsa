/*
 Lowercase text; return longest substring where every present character occurs at
least k times.

IDEA AND STATE: For each target distinct count 1..26, maintain distinct and qualified
counts; shrink only when distinct exceeds that target.

TRACE: aaabb, k 3 ->3; ababbc, k 2 ->5.

On aaabb with k3,the target-one-distinct pass qualifies aaa;adding b forces shrinking,so
length3 wins.

Every valid answer has some target number of distinct letters; that pass tests all
feasible right endpoints.

O(26*n) time, O(26) space.

Simple shrinking on a low-frequency character is not monotone without the fixed
distinct-count pass.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <array>
#include <algorithm>

int atLeastK(const std::string& text, int k) {
    if (k <= 1) {
        return static_cast<int>(text.size());
    }
    int best = 0;
    for (int target = 1; target <= 26; ++target) {
        std::array<int, 26> count{};
        int distinct = 0;
        int qualified = 0;
        int left = 0;
        for (int right = 0; right < static_cast<int>(text.size()); ++right) {
            int index = text[right] - 'a';
            if (count[index] == 0) {
                ++distinct;
            }
            ++count[index];
            if (count[index] == k) {
                ++qualified;
            }
            while (distinct > target) {
                int old = text[left] - 'a';
                ++left;
                if (count[old] == k) {
                    --qualified;
                }
                --count[old];
                if (count[old] == 0) {
                    --distinct;
                }
            }
            if (distinct == target && qualified == distinct) {
                best = std::max(best, right - left + 1);
            }
        }
    }
    return best;
}

int main() {
    assert(atLeastK("aaabb", 3) == 3);
    assert(atLeastK("ababbc", 2) == 5);
    assert(atLeastK("", 2) == 0);
    assert(atLeastK("abc", 1) == 3);
    assert(atLeastK("abc", 4) == 0);
    std::cout << "checks passed\n";
    return 0;
}
