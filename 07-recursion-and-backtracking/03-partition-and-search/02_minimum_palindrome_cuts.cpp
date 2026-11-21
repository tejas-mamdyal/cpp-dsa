/*
 Text length<=12; empty text needs 0 cuts. Unless narrowed, at most 100 nodes/elements
with values in [-1000,1000]. Recursive examples assume valid acyclic owned structures;
exponential searches use the smaller bounds stated here. No input; keep assertions enabled.
Success prints checks passed.

Use the previous full partition reference and minimize number of pieces
minus 1. This is intentionally exponential; Phase 7 later removes repeated work.

aab has partitions of 3 and 2 pieces, so minimum cuts is 1.

Every legal cut partition is enumerated; the minimum piece count therefore gives
the optimum.

O((n+1)^2*2^n) time and exponential saved output; not an efficient large-input solver.

Do not advertise enumeration as polynomial; empty partition needs an explicit
zero-cuts rule.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
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

int cuts(const std::string& s) {
    if (s.empty()) {
        return 0;
    }
    int best = static_cast<int>(s.size()) - 1;
    for (const auto& p : partitions(s)) {
        best = std::min(best, static_cast<int>(p.size()) - 1);
    }
    return best;
}

int main() {
    assert(cuts("aab") == 1);
    assert(cuts("racecar") == 0);
    assert(cuts("") == 0);
    assert(cuts("abc") == 2);
    std::cout << "checks passed\n";
    return 0;
}
