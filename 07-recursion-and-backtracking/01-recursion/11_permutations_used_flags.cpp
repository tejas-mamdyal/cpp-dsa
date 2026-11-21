/*
 At most8 distinct integers;return every permutation in input-position choice order.
Empty input has one empty permutation. No input is required. Keep assertions enabled; a
successful run prints checks passed. Tiny bounds are intentional because output grows
exponentially or factorially.

Unlike subsets,each level can choose any unused position. used[i] means
a[i] is already in path. Both that flag and the path element must be undone.

For [1,2],mark1,then mark2 and save[1,2];undo2 and1;mark2,then mark1 and
save[2,1]. Every flag is false afterward.

At depth d,the path holds d distinct positions. Each unused next position is
explored once,so every full ordering has one unique route.

O((n+1)*n!) time including candidate scans and saved copies;O(n) auxiliary flags,path
and stack;O((n+1)*n!) output.

Distinct input is a precondition. Repeated values need later duplicate
skipping;forgetting to unmark a flag silently loses sibling solutions.
*/
#include <iostream>
#include <cassert>
#include <vector>

void arrange(const std::vector<int>& a,
             std::vector<bool>& used,
             std::vector<int>& path,
             std::vector<std::vector<int>>& out) {
    if (path.size() == a.size()) {
        out.push_back(path);
        return;
    }
    for (std::size_t i = 0; i < a.size(); ++i) {
        if (used[i]) {
            continue;
        }
        used[i] = true; // Reserve this position for the active route.
        path.push_back(a[i]);
        arrange(a, used, path, out);
        path.pop_back();
        used[i] = false; // Restore availability before trying a sibling.
    }
}

std::vector<std::vector<int>> permutations(const std::vector<int>& a) {
    assert(a.size() <= 8);
    std::vector<bool> used(a.size(), false);
    std::vector<int> path;
    std::vector<std::vector<int>> out;
    arrange(a, used, path, out);
    assert(path.empty());
    for (bool flag : used) {
        assert(!flag);
    }
    return out;
}

int main() {
    assert((permutations({1, 2}) == std::vector<std::vector<int>>{{1, 2}, {2, 1}}));
    assert(permutations({1, 2, 3}).size() == 6);
    assert((permutations({}) == std::vector<std::vector<int>>{{}}));
    std::cout << "checks passed\n";
    return 0;
}
