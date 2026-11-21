/*
 ASCII letters/digits only, length<=12; preserve nonletter digits. Unless narrowed, at
most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume valid acyclic
owned structures; exponential searches use the smaller bounds stated here. No input; keep
assertions enabled. Success prints checks passed.

Each letter has lowercase/uppercase alternatives; digits have one. Use
explicit ASCII ranges, not locale-sensitive assumptions.

a 1B ->a 1b, a 1B, A 1b, A 1B.

One branch per allowed character form yields exactly the Cartesian product of
case choices.

O((n+1)*2^n) upper-bound time/output; O(n) auxiliary.

A digit is not a second case choice.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstddef>

void visit(const std::string& s, std::size_t i, std::string& path, std::vector<std::string>& out) {
    if (i == s.size()) {
        out.push_back(path);
        return;
    }
    char ch = s[i];
    if (ch >= '0' && ch <= '9') {
        path.push_back(ch); // Choose this route element before exploring its completions.
        visit(s, i + 1, path, out);
        path.pop_back(); // Undo so the next sibling sees the same entry prefix.
        return;
    }
    char low = ch >= 'A' && ch <= 'Z' ? static_cast<char>(ch - 'A' + 'a') : ch;
    path.push_back(low); // Choose this route element before exploring its completions.
    visit(s, i + 1, path, out);
    path.back() = static_cast<char>(low - 'a' + 'A');
    visit(s, i + 1, path, out);
    path.pop_back(); // Undo so the next sibling sees the same entry prefix.
}

int main() {
    std::string path;
    std::vector<std::string> out;
    visit("a1B", 0, path, out);
    assert((out == std::vector<std::string>{"a1b", "a1B", "A1b", "A1B"}));
    assert(path.empty());
    std::cout << "checks passed\n";
    return 0;
}
