/*
 n 0..15 posts, k 0..5 colors; empty fence has one assignment. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

same counts endings whose last two colors match; different counts endings
whose last two differ. No three consecutive equal colors are permitted.

For two colors, n 2 has same 2, different 2; n 3 has same 2, different 4, total 6.

Matching the last color is legal only after different; choosing any of k-1
alternatives is legal after either state.

O(n) time, O(1) auxiliary.

An impossible zero-color nonempty input must not create negative counts through k-1.
*/
#include <iostream>
#include <cassert>

long long fence(int n, int k) {
    assert(n >= 0 && n <= 15 && k >= 0 && k <= 5);
    if (n == 0) {
        return 1;
    }
    if (k == 0) {
        return 0;
    }
    long long same = 0;
    long long different = k;
    for (int i = 2; i <= n; ++i) {
        long long nextSame = different;
        long long nextDifferent = (same + different) * (k - 1);
        same = nextSame;
        different = nextDifferent;
    }
    return same + different;
}

int main() {
    assert(fence(3, 2) == 6);
    assert(fence(0, 0) == 1);
    assert(fence(3, 1) == 0);
    assert(fence(2, 1) == 1);
    std::cout << "checks passed\n";
    return 0;
}
