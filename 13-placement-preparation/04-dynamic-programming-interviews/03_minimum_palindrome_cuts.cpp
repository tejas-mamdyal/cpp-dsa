/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

pal[l][r] tests a substring; pieces[k] minimizes palindrome pieces
covering prefix k.

aab uses aa|b, so 2 pieces and 1 cut.

Every partition has one final palindromic segment, whose earlier prefix is
already solved.

O(n^2) time/storage.

Cuts equal pieces-1 only for nonempty text.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

int cuts(const std::string& s) {
    int n = static_cast<int>(s.size());
    if (n == 0) {
        return 0;
    }
    std::vector<std::vector<bool>> pal(n, std::vector<bool>(n));
    std::vector<int> pieces(n + 1, n + 1);
    pieces[0] = 0;
    for (int end = 0; end < n; ++end) {
        for (int begin = end; begin >= 0; --begin) {
            pal[begin][end] = s[begin] == s[end] && (end - begin < 2 || pal[begin + 1][end - 1]);
            if (pal[begin][end]) {
                pieces[end + 1] = std::min(pieces[end + 1], pieces[begin] + 1);
            }
        }
    }
    return pieces[n] - 1;
}

int main() {
    assert(cuts("aab") == 1 && cuts("abba") == 0 && cuts("") == 0);
    std::cout << "checks passed\n";
    return 0;
}
