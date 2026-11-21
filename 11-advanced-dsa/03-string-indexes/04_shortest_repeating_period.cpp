/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

The final longest border suggests candidate n-pi[n-1]; it is a full
repeating unit only if it divides n.

ababab has candidate 2 and three full copies; ababa has weak period 2 but cannot
be full copies, so answer 5.

The border equality supplies repeated offsets; divisibility ensures the last copy
is complete.

O(n) time/storage.

Do not confuse a period allowing a partial final copy with a whole-word repetition
unit.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>

std::vector<int> prefix(const std::string& p) {
    std::vector<int> pi(p.size());
    for (int i = 1; i < static_cast<int>(p.size()); ++i) {
        int j = pi[i - 1];
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}

int period(const std::string& s) {
    if (s.empty()) {
        return 0;
    }
    auto pi = prefix(s);
    int n = static_cast<int>(s.size());
    int candidate = n - pi.back();
    return n % candidate == 0 ? candidate : n;
}

int main() {
    assert(period("ababab") == 2);
    assert(period("ababa") == 5);
    assert(period("") == 0);
    std::cout << "checks passed\n";
    return 0;
}
