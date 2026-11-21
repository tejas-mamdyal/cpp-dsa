/*
 k 0..9; target 0..45; values 1..9 chosen once. Unless narrowed, at most 100
nodes/elements with values in [-1000,1000]. Recursive examples assume valid acyclic owned
structures; exponential searches use the smaller bounds stated here. No input; keep assertions
enabled. Success prints checks passed.

Both need and remaining sum constrain the search; increasing next value
prevents reorderings.

k 3, target 7 chooses 1,2,4; other triples exceed or miss 7.

At need 0 record exactly when remaining 0; all increasing choices cover valid sets
once.

O(2^9*9) time including copies; O(9) auxiliary plus output.

A zero target before need 0 is not automatically a complete answer.
*/
#include <iostream>
#include <cassert>
#include <vector>

void visit(
    int start, int need, int target, std::vector<int>& path, std::vector<std::vector<int>>& out) {
    if (need == 0) {
        if (target == 0) {
            out.push_back(path);
        }
        return;
    }
    for (int x = start; x <= 9; ++x) {
        if (x > target) {
            break;
        }
        path.push_back(x); // Choose this route element before exploring its completions.
        visit(x + 1, need - 1, target - x, path, out);
        path.pop_back(); // Undo so the next sibling sees the same entry prefix.
    }
}

std::vector<std::vector<int>> digitSums(int k, int target) {
    std::vector<int> path;
    std::vector<std::vector<int>> out;
    visit(1, k, target, path, out);
    return out;
}

int main() {
    assert((digitSums(3, 7) == std::vector<std::vector<int>>{{1, 2, 4}}));
    assert(digitSums(0, 0).size() == 1);
    assert(digitSums(4, 1).empty());
    std::cout << "checks passed\n";
    return 0;
}
