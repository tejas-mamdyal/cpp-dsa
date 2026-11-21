/*
 Text length<=12; return every complete partition into nonempty palindromes. Unless
narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume
valid acyclic owned structures; exponential searches use the smaller bounds stated here. No
input; keep assertions enabled. Success prints checks passed.

start is the next uncovered position. Baseline tries all cut sets and
validates; here reject a nonpalindrome piece immediately.

aab first chooses a, a, b; then aa, b; ab is rejected.

Every valid partition has a unique increasing cut sequence; only invalid pieces
are removed.

O((n+1)^2*2^n) conservative time including checks/copies; O(n) work stack/path plus
output.

Do not permit an empty piece: it would fail to advance start.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstddef>

bool palindrome(const std::string& s, std::size_t left, std::size_t right) {
    while (left < right) {
        --right;
        if (s[left] != s[right]) {
            return false;
        }
        ++left;
    }
    return true;
}

void split(const std::string& s,
           std::size_t start,
           std::vector<std::string>& path,
           std::vector<std::vector<std::string>>& out) {
    if (start == s.size()) {
        out.push_back(path);
        return;
    }
    for (std::size_t end = start + 1; end <= s.size(); ++end) {
        if (!palindrome(s, start, end)) {
            continue;
        }
        path.push_back(s.substr(
            start, end - start)); // Choose this route element before exploring its completions.
        split(s, end, path, out);
        path.pop_back(); // Undo so the next sibling sees the same entry prefix.
    }
}

std::vector<std::vector<std::string>> partitions(const std::string& s) {
    std::vector<std::string> path;
    std::vector<std::vector<std::string>> out;
    split(s, 0, path, out);
    return out;
}

int main() {
    assert(
        (partitions("aab") == std::vector<std::vector<std::string>>{{"a", "a", "b"}, {"aa", "b"}}));
    assert(partitions("").size() == 1);
    std::cout << "checks passed\n";
    return 0;
}
