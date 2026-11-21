/*
 At most 30 lowercase words, length<=30; adding exactly one character preserves
previous order.

dp[word] is maximum chain ending in that word; every predecessor is
obtained by deleting one character and is shorter.

a->ba->bda->bdca forms four words.

Sorting by length finalizes all possible one-deletion predecessor states before
the word is processed.

O(n*L^2*log(n+1)) conservative time including string keys; O(total word characters)
storage.

Equal-length words cannot extend each other by this rule.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstddef>

int chain(std::vector<std::string> words) {
    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        return a.size() < b.size();
    });
    std::map<std::string, int> dp;
    int best = 0;
    for (const auto& word : words) {
        int length = 1;
        for (std::size_t i = 0; i < word.size(); ++i) {
            std::string previous = word.substr(0, i) + word.substr(i + 1);
            auto found = dp.find(previous);
            if (found != dp.end()) {
                length = std::max(length, found->second + 1);
            }
        }
        dp[word] = std::max(dp[word], length);
        best = std::max(best, length);
    }
    return best;
}

int main() {
    assert(chain({"a", "b", "ba", "bca", "bda", "bdca"}) == 4);
    assert(chain({}) == 0);
    assert(chain({"a", "a"}) == 1);
    std::cout << "checks passed\n";
    return 0;
}
