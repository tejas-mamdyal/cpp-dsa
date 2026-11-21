/*
 Same binary strings and order as lesson01, n in [0,12]. No input is required. Keep
assertions enabled; a successful run prints checks passed. Tiny bounds are intentional because
output grows exponentially or factorially.

The copied baseline is easy to reason about but duplicates active
prefixes. Now path is borrowed by reference; its entry value must be restored before every
return.

At prefix0 append0, save00, pop back to0; append1, save01, pop back to0. Returning
from the prefix0 call leaves its caller's path unchanged.

Induct on remaining positions: each recursive call restores its own entry state,
and each explicit pop reverses this frame's push. Thus siblings see the same parent prefix.

O((n+1)*2^n) time including result copies; O(n) auxiliary path plus frames; output
O((n+1)*2^n).

Without pop_back the next sibling inherits a decision it did not choose. Saving path
into out copies it; result elements do not alias path.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

void visit(int n, std::string& path, std::vector<std::string>& out) {
    if (static_cast<int>(path.size()) == n) {
        out.push_back(path);
        return;
    }
    path.push_back('0'); // Choose the first branch.
    visit(n, path, out); // Explore all completions of that branch.
    path.pop_back();     // Undo before starting its sibling.
    path.push_back('1');
    visit(n, path, out);
    path.pop_back(); // Restore exactly the state supplied by the caller.
}

int main() {
    std::string path;
    std::vector<std::string> out;
    visit(2, path, out);
    assert(path.empty());
    assert((out == std::vector<std::string>{"00", "01", "10", "11"}));
    out.clear();
    visit(0, path, out);
    assert((out == std::vector<std::string>{""}));
    assert(path.empty());
    std::cout << "checks passed\n";
    return 0;
}
