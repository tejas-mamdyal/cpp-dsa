/*
 Arbitrary byte string, length<=1000; return prefix-function lengths. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

pi[i] is the length of the longest proper prefix also a suffix of
pattern[0..i]; a mismatch at candidate length j falls back to pi[j-1].

abab has borders of lengths 0,0,1,2; after an unsuitable length 2 candidate, its
own shorter border supplies the next candidate.

Every possible shorter border must also be a border of the current matched
prefix; the fallback chain enumerates exactly those candidates.

O(n) time, O(n) prefix table; total fallback decreases are bounded by previous
matched-length increases.

A proper border is shorter than the full prefix; do not compare the prefix to itself.
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

int main() {
    assert((prefix("abab") == std::vector<int>{0, 0, 1, 2}));
    assert((prefix("aaaa") == std::vector<int>{0, 1, 2, 3}));
    assert(prefix("").empty());
    std::cout << "checks passed\n";
    return 0;
}
