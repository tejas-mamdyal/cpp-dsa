/*
 Text length at most12; return all positional subsequences, including the empty one
and equal-looking results. No input is required. Keep assertions enabled; a successful run
prints checks passed. Tiny bounds are intentional because output grows exponentially or
factorially.

i tracks the next text position; path is the retained ordered prefix.
Unlike substrings, chosen positions need not be contiguous.

For aa, excluding the first a gives "" and "a"; including it gives another "a" and
"aa". There are four positional answers but three distinct strings.

Every increasing sequence of chosen positions has one decision vector, and
decisions are consumed in input order.

O((n+1)*2^n) time and output storage; O(n) auxiliary path and frames.

Do not deduplicate outputs unless the problem explicitly asks for distinct values;
that changes the counting contract.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

void visit(const std::string& text,
           std::size_t i,
           std::string& path,
           std::vector<std::string>& out) {
    if (i == text.size()) {
        out.push_back(path);
        return;
    }
    visit(text, i + 1, path, out); // Skip this position, not every equal character.
    path.push_back(text[i]);
    visit(text, i + 1, path, out);
    path.pop_back(); // The next branch must not inherit this character.
}

std::vector<std::string> subsequences(const std::string& text) {
    assert(text.size() <= 12);
    std::string path;
    std::vector<std::string> out;
    visit(text, 0, path, out);
    return out;
}

int main() {
    assert((subsequences("aa") == std::vector<std::string>{"", "a", "a", "aa"}));
    auto out = subsequences("abc");
    assert(out.size() == 8);
    assert(std::find(out.begin(), out.end(), "ac") != out.end());
    assert((subsequences("") == std::vector<std::string>{""}));
    std::cout << "checks passed\n";
    return 0;
}
