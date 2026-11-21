/*
 Byte string, length<=1000; z[0]=0.

z[i] is the longest common prefix of the whole text and suffix i;[l, r) is
the farthest-right already known matching-prefix window.

For aaaa, the suffixes at 1,2,3 match prefix lengths 3,2,1.

Inside the window, mirrored prefix information is valid up to its boundary; only
extensions beyond it require new comparisons.

O(n) time, O(n) storage; successful extra comparisons advance the rightmost boundary.

This convention defines z 0=0; other resources may choose n.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> zFunction(const std::string& s) {
    int n = static_cast<int>(s.size());
    int l = 0;
    int r = 0;
    std::vector<int> z(n);
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = std::min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    assert((zFunction("aaaa") == std::vector<int>{0, 3, 2, 1}));
    assert((zFunction("abacaba") == std::vector<int>{0, 0, 1, 0, 3, 0, 1}));
    assert(zFunction("").empty());
    std::cout << "checks passed\n";
    return 0;
}
