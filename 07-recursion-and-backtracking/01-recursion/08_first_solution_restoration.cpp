/*
 At most16 integers in [-100,100]; find first target-sum subset in exclude-first
order. Return optional vector;empty vector is a valid target-zero witness. No input is
required. Keep assertions enabled; a successful run prints checks passed. Tiny bounds are
intentional because output grows exponentially or factorially.

path is borrowed mutable state;answer is a copied witness. A bool reports
success. The naive early-return version leaks its pushed value into the caller.

For [5,-4],target1,only both inclusions succeed. Copy [5,-4] at the leaf,then pop
-4 and5 while returning true;the working path ends empty.

Each branch restores path on both failure and success. Once a witness is
copied,it survives the undo independently of the work buffer.

Worst-case O(2^n+n) time, O(n) stack/path and O(n) saved witness;may terminate earlier.

Do not write return search(...) immediately after a push:that bypasses pop_back. No
witness and an empty witness are distinct.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>

bool search(const std::vector<int>& a,
            std::size_t i,
            long long sum,
            long long target,
            std::vector<int>& path,
            std::vector<int>& answer) {
    if (i == a.size()) {
        if (sum == target) {
            answer = path;
            return true;
        }
        return false;
    }
    if (search(a, i + 1, sum, target, path, answer)) {
        return true;
    } // Exclusion added no state.
    path.push_back(a[i]);
    bool found = search(a, i + 1, sum + a[i], target, path, answer);
    path.pop_back(); // Undo before inspecting success and returning early.
    return found;
}

std::optional<std::vector<int>> firstSubset(const std::vector<int>& a, long long target) {
    std::vector<int> path;
    std::vector<int> answer;
    bool found = search(a, 0, 0, target, path, answer);
    assert(path.empty());
    if (found) {
        return answer;
    }
    return std::nullopt;
}

int main() {
    assert((firstSubset({5, -4}, 1) == std::optional<std::vector<int>>{{5, -4}}));
    auto empty = firstSubset({1, 2}, 0);
    assert(empty && empty->empty());
    assert(!firstSubset({1, 2}, 9));
    assert(!firstSubset({}, 1));
    std::cout << "checks passed\n";
    return 0;
}
