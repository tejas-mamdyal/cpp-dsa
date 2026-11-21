/*
 Text length<=16; dictionary contains nonempty strings; return segmentations as word
lists. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Try each end after start and recurse only when that substring is in the
set.

catsanddog chooses cat, sand, dog and cats, and, dog.

Every full segmentation has unique boundaries; checking membership filters exactly
legal pieces.

Conservative O((n+1)^3*2^n) time with substring/set comparisons; O(n^2) active strings
plus output.

An empty dictionary word must not create a nonadvancing recursive branch.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <cstddef>

void visit(const std::string& s,
           std::size_t start,
           const std::set<std::string>& dictionary,
           std::vector<std::string>& path,
           std::vector<std::vector<std::string>>& out) {
    if (start == s.size()) {
        out.push_back(path);
        return;
    }
    for (std::size_t end = start + 1; end <= s.size(); ++end) {
        std::string word = s.substr(start, end - start);
        if (dictionary.count(word) == 0) {
            continue;
        }
        path.push_back(word); // Choose this route element before exploring its completions.
        visit(s, end, dictionary, path, out);
        path.pop_back(); // Undo so the next sibling sees the same entry prefix.
    }
}

int main() {
    std::vector<std::string> path;
    std::vector<std::vector<std::string>> out;
    visit("catsanddog", 0, {"cat", "cats", "and", "sand", "dog"}, path, out);
    assert(
        (out
         == std::vector<std::vector<std::string>>{{"cat", "sand", "dog"}, {"cats", "and", "dog"}}));
    assert(path.empty());
    std::cout << "checks passed\n";
    return 0;
}
