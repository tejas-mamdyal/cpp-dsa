/*
 n<=15, element magnitudes<=4; empty product is 1. Unless a different bound is
stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

Output first holds product strictly before i, then multiplies product
strictly after i.

For index 1 in 1,2,3,4, prefix 1 times suffix 12 gives 12.

The two disjoint sides contain every factor except the current one exactly once.

O(n) time, O(1) auxiliary excluding output.

Division fails on zeros; also bound the complete product to avoid overflow.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

std::vector<long long> products(const std::vector<int>& a) {
    std::vector<long long> out(a.size(), 1);
    long long prefix = 1;
    for (std::size_t i = 0; i < a.size(); ++i) {
        out[i] = prefix;
        prefix *= a[i];
    }
    long long suffix = 1;
    for (std::size_t i = a.size(); i > 0; --i) {
        out[i - 1] *= suffix;
        suffix *= a[i - 1];
    }
    return out;
}

int main() {
    assert((products({1, 2, 3, 4}) == std::vector<long long>{24, 12, 8, 6}));
    assert((products({0, 2, 0}) == std::vector<long long>{0, 0, 0}));
    assert((products({7}) == std::vector<long long>{1}));
    std::cout << "checks passed\n";
    return 0;
}
