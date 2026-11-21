/*
 Byte string<=1000; odd radius includes the center. Unless a different bound is
stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

radius[i] includes the center character, so its maximum odd palindrome
length is 2*radius[i]-1;[left, right] is the inclusive rightmost palindrome.

abacaba at center 3 expands four radius units for length 7.

Symmetry supplies the radius inside the known window; additional matching work
only extends the right boundary.

O(n) time, O(n) storage.

Character-centered and gap-centered radius formulas differ by one.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> oddRadii(const std::string& s) {
    int n = static_cast<int>(s.size());
    std::vector<int> radius(s.size());
    int left = 0;
    int right = -1;
    for (int center = 0; center < n; ++center) {
        int length =
            center > right ? 1 : std::min(radius[left + right - center], right - center + 1);
        while (center - length >= 0 && center + length < n
               && s[center - length] == s[center + length]) {
            ++length;
        }
        radius[center] = length;
        if (center + length - 1 > right) {
            left = center - length + 1;
            right = center + length - 1;
        }
    }
    return radius;
}

int main() {
    assert((oddRadii("aaaa") == std::vector<int>{1, 2, 2, 1}));
    assert(oddRadii("abacaba")[3] == 4);
    assert(oddRadii("").empty());
    std::cout << "checks passed\n";
    return 0;
}
