/*
 n<=12; positional subsets retain duplicate-looking values. Unless narrowed, at most
100 nodes/elements with values in [-1000,1000]. Recursive examples assume valid acyclic owned
structures; exponential searches use the smaller bounds stated here. No input; keep assertions
enabled. Success prints checks passed.

Begin with the empty subset; extend only the old collection size during
each step.

After 1:[[],[1]]; after 2 append[2],[1,2].

Each subset either omits the new value and already exists, or includes it by
extending one old subset.

O((n+1)*2^n) time/output; O(n) temporary copied path beyond collection.

Do not loop to a growing out.size(); that would repeatedly extend newly appended
entries.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

std::vector<std::vector<int>> subsets(const std::vector<int>& a) {
    std::vector<std::vector<int>> out{{}};
    for (int x : a) {
        std::size_t oldSize = out.size();
        for (std::size_t i = 0; i < oldSize; ++i) {
            auto path = out[i];
            path.push_back(x); // Choose this route element before exploring its completions.
            out.push_back(path);
        }
    }
    return out;
}

int main() {
    assert((subsets({1, 2}) == std::vector<std::vector<int>>{{}, {1}, {2}, {1, 2}}));
    assert(subsets({}).size() == 1);
    assert(subsets({1, 1}).size() == 4);
    std::cout << "checks passed\n";
    return 0;
}
