/*
 n<=8 distinct values; input restored on return. Unless narrowed, at most 100
nodes/elements with values in [-1000,1000]. Recursive examples assume valid acyclic owned
structures; exponential searches use the smaller bounds stated here. No input; keep assertions
enabled. Success prints checks passed.

Positions before fixed are final; swap every remaining candidate into
fixed, then swap back.

For 1,2, fix 1 to emit 1,2; undo, fix 2 to emit 2,1; undo restores 1,2.

Each next remaining position is selected once; the inverse swap restores the
sibling state.

O((n+1)*n!) time, O(n) stack plus output; no used array.

Duplicate values need canonical handling; this version assumes distinct input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <cstddef>

void visit(std::vector<int>& a, std::size_t fixed, std::vector<std::vector<int>>& out) {
    if (fixed == a.size()) {
        out.push_back(a);
        return;
    }
    for (std::size_t i = fixed; i < a.size(); ++i) {
        std::swap(a[fixed], a[i]);
        visit(a, fixed + 1, out);
        std::swap(a[fixed], a[i]);
    }
}

int main() {
    std::vector<int> a{1, 2, 3};
    auto original = a;
    std::vector<std::vector<int>> out;
    visit(a, 0, out);
    assert(a == original && out.size() == 6);
    std::vector<int> empty;
    out.clear();
    visit(empty, 0, out);
    assert(out.size() == 1);
    std::cout << "checks passed\n";
    return 0;
}
