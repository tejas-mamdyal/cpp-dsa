/*
 At most12 bounded integers. Return subsets in exclude-before-include order; equal
values at different positions remain separate choices. No input is required. Keep assertions
enabled; a successful run prints checks passed. Tiny bounds are intentional because output
grows exponentially or factorially.

i is the first undecided input position; path contains included values
among earlier positions. This expands the inherited subset lesson and retains its
exclude/include algorithm.

For [1,2], excluding1 gives [] then [2]; including1 gives [1] then [1,2]. Each
include push has one matching pop.

Every index-subset has one exclude/include decision vector. The two branches are
disjoint by position, so all index-subsets appear once.

O((n+1)*2^n) time including copies, O(n) auxiliary path and stack, O((n+1)*2^n) output
storage.

For [1,1], the two singleton results have equal values but represent different index
choices. Unique-value subsets require the later duplicate-handling unit.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

void explore(const std::vector<int>& a,
             std::size_t i,
             std::vector<int>& path,
             std::vector<std::vector<int>>& out) {
    if (i == a.size()) {
        out.push_back(path);
        return;
    }
    explore(a, i + 1, path, out); // Exclude this position; path is unchanged.
    path.push_back(a[i]);         // Choose to include this position.
    explore(a, i + 1, path, out); // Explore the remaining undecided positions.
    path.pop_back();              // Undo inclusion so the caller retains its entry path.
}

std::vector<std::vector<int>> subsets(const std::vector<int>& a) {
    assert(a.size() <= 12);
    std::vector<int> path;
    std::vector<std::vector<int>> out;
    explore(a, 0, path, out);
    assert(path.empty());
    return out;
}

int main() {
    assert((subsets({1, 2}) == std::vector<std::vector<int>>{{}, {2}, {1}, {1, 2}}));
    assert((subsets({}) == std::vector<std::vector<int>>{{}}));
    assert((subsets({1, 1}) == std::vector<std::vector<int>>{{}, {1}, {1}, {1, 1}}));
    std::cout << "checks passed\n";
    return 0;
}
