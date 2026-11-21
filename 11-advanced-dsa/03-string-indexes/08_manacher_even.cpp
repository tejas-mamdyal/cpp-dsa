/*
 Byte string<=1000; empty even palindrome has radius 0. Unless a different bound is
stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

radius[i] counts matching pairs around the gap before i; its palindrome
length is 2*radius[i].

abba has center gap before index 2 and radius 2, length 4.

The mirrored gap supplies valid pairs within the rightmost palindrome, then
explicit comparisons extend it.

O(n) time, O(n) storage.

Use left+right-center+1 for the mirrored gap, not the odd-center expression.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> evenRadii(const std::string& s) {
    int n = static_cast<int>(s.size());
    std::vector<int> radius(s.size());
    int left = 0;
    int right = -1;
    for (int center = 0; center < n; ++center) {
        int length =
            center > right ? 0 : std::min(radius[left + right - center + 1], right - center + 1);
        while (center - length - 1 >= 0 && center + length < n
               && s[center - length - 1] == s[center + length]) {
            ++length;
        }
        radius[center] = length;
        if (center + length - 1 > right) {
            left = center - length;
            right = center + length - 1;
        }
    }
    return radius;
}

int main() {
    assert((evenRadii("aaaa") == std::vector<int>{0, 1, 2, 1}));
    assert(evenRadii("abba")[2] == 2);
    assert(evenRadii("").empty());
    std::cout << "checks passed\n";
    return 0;
}
