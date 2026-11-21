/*
 At most 8 words, length<=10; return a shortest common superstring with deterministic
lexical ties.

dp[mask][last] stores a shortest superstring covering mask and ending with
last word; ties choose lexicographically smaller text.

abc overlaps bcd bybc and bcd overlaps cde bycd, formingabcde.

After contained words are removed, an optimum can be ordered by word endpoints
and built from suffix-prefix overlaps; the subset recurrence tests every such order.

O(2^n*n^2*S+n^2*L^2) conservative time with string copying, S total characters;
O(2^n*n*S) character storage.

Contained words and duplicates must not force unnecessary appended copies.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <optional>
#include <cstddef>

std::string superstring(const std::vector<std::string>& input) {
    std::vector<std::string> words;
    for (std::size_t i = 0; i < input.size(); ++i) {
        bool redundant = false;
        for (std::size_t j = 0; j < input.size(); ++j) {
            if (i != j && input[j].find(input[i]) != std::string::npos
                && (input[i].size() < input[j].size() || i > j)) {
                redundant = true;
                break;
            }
        }
        if (!redundant) {
            words.push_back(input[i]);
        }
    }
    int n = static_cast<int>(words.size());
    if (n == 0) {
        return "";
    }
    std::vector<std::vector<int>> overlap(words.size(), std::vector<int>(words.size(), 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (std::size_t len = 1; len <= std::min(words[i].size(), words[j].size()); ++len) {
                if (words[i].compare(words[i].size() - len, len, words[j], 0, len) == 0) {
                    overlap[i][j] = static_cast<int>(len);
                }
            }
        }
    }
    using Text = std::optional<std::string>;
    std::vector<std::vector<Text>> dp(1U << n, std::vector<Text>(words.size()));
    for (int i = 0; i < n; ++i) {
        dp[1U << i][i] = words[i];
    }
    for (unsigned int mask = 1; mask < dp.size(); ++mask) {
        for (int last = 0; last < n; ++last) {
            if (!dp[mask][last]) {
                continue;
            }
            for (int next = 0; next < n; ++next) {
                if (mask & (1U << next)) {
                    continue;
                }
                std::string candidate =
                    *dp[mask][last]
                    + words[next].substr(static_cast<std::size_t>(overlap[last][next]));
                auto& slot = dp[mask | (1U << next)][next];
                if (!slot || candidate.size() < slot->size()
                    || (candidate.size() == slot->size() && candidate < *slot)) {
                    slot = candidate;
                }
            }
        }
    }
    Text best;
    for (const auto& value : dp.back()) {
        if (value
            && (!best || value->size() < best->size()
                || (value->size() == best->size() && *value < *best))) {
            best = value;
        }
    }
    return *best;
}

int main() {
    assert(superstring({"abc", "bcd", "cde"}) == "abcde");
    assert(superstring({"abc", "bc", "abc"}) == "abc");
    assert(superstring({"", ""}) == "");
    assert(superstring({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
