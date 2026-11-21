/*
 Length n is in [0,12]; return every binary string of that length, with 0 branches
before 1. Length zero has one empty string. No input is required. Keep assertions enabled; a
successful run prints checks passed. Tiny bounds are intentional because output grows
exponentially or factorially.

The simple baseline writes n nested loops, but its source changes with n.
Recursion represents one loop level per position. A path is passed by value, so every call
owns a separate string.

For n=2, root "" visits 0 then 00 and 01; after returning it visits 1 then 10 and
11. Only length-two leaves are saved.

At each position the two disjoint choices cover exactly 0 and 1; reaching n
positions records exactly one complete assignment.

O((n+1)*2^n) time including path copies; O(n^2) worst-case active copied-string storage
and O(n) call frames; output O((n+1)*2^n).

Recording every internal node would mix lengths; reaching zero decisions still has
one complete empty assignment.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

void visit(int n, std::string path, std::vector<std::string>& out) {
    if (static_cast<int>(path.size()) == n) {
        out.push_back(path); // Save only a complete assignment.
        return;
    }
    visit(n, path + "0", out); // A child owns its extended copy.
    visit(n, path + "1", out); // The sibling starts from the unchanged parent copy.
}

std::vector<std::string> binaryStrings(int n) {
    assert(n >= 0 && n <= 12);
    std::vector<std::string> out;
    visit(n, "", out);
    return out;
}

int main() {
    assert((binaryStrings(2) == std::vector<std::string>{"00", "01", "10", "11"}));
    assert((binaryStrings(0) == std::vector<std::string>{""}));
    assert(binaryStrings(5).size() == 32);
    std::cout << "checks passed\n";
    return 0;
}
