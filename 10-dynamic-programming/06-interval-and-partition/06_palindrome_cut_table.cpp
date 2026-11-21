/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

pal[l][r] states whether that substring is a palindrome; pieces[i] is
minimum palindrome-piece count covering the first i characters.

For aab, pieces 2=1 from aa; appending b gives pieces 3=2 and one cut.

Every partition has one final palindromic segment; try all its starting positions
after palindromicity is known.

O(n^2) time/storage, improving the earlier exponential enumeration.

Cuts equal pieces-1 only for nonempty text; empty text needs explicit 0.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <cstddef>

int cuts(const std::string& s) {
    int n = static_cast<int>(s.size());
    if (n == 0) {
        return 0;
    }
    std::vector<std::vector<bool>> pal(s.size(), std::vector<bool>(s.size(), false));
    for (int l = n - 1; l >= 0; --l) {
        for (int r = l; r < n; ++r) {
            pal[l][r] = s[l] == s[r] && (r - l < 2 || pal[l + 1][r - 1]);
        }
    }
    std::vector<int> pieces(static_cast<std::size_t>(n + 1), n + 1);
    pieces[0] = 0;
    for (int end = 1; end <= n; ++end) {
        for (int start = 0; start < end; ++start) {
            if (pal[start][end - 1]) {
                pieces[end] = std::min(pieces[end], pieces[start] + 1);
            }
        }
    }
    return pieces[n] - 1;
}

int main() {
    assert(cuts("aab") == 1);
    assert(cuts("abba") == 0);
    assert(cuts("") == 0);
    std::cout << "checks passed\n";
    return 0;
}
