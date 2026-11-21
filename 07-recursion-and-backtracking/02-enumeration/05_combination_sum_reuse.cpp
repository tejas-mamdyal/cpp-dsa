/*
 At most 8 positive candidates; target 0..20; unlimited reuse, unique combinations. Unless
narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume
valid acyclic owned structures; exponential searches use the smaller bounds stated here. No
input; keep assertions enabled. Success prints checks passed.

Carry remaining target; choosing index i recurses from i again. A brute
sequence generator wastes work on order duplicates.

Candidates 2,3,6,7 at 7 produce 2,2,3 and 7; choosing 2 lowers remaining 7 to 5 to 3.

Positive choices strictly reduce remaining; nondecreasing indices identify each
multiset once.

Conservative O((T+1)*(m+1)^(T+1)) time; O(T+m) auxiliary plus output.

Zero or negative candidates can destroy termination and invalidate the sorted cutoff.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

void visit(const std::vector<int>& a,
           std::size_t start,
           int remaining,
           bool reuse,
           std::vector<int>& path,
           std::vector<std::vector<int>>& out) {
    if (remaining == 0) {
        out.push_back(path);
        return;
    }
    for (std::size_t i = start; i < a.size(); ++i) {
        if (i > start && a[i] == a[i - 1]) {
            continue;
        }
        if (a[i] > remaining) {
            break;
        }
        path.push_back(a[i]); // Choose this route element before exploring its completions.
        visit(a, reuse ? i : i + 1, remaining - a[i], reuse, path, out);
        path.pop_back(); // Undo so the next sibling sees the same entry prefix.
    }
}

std::vector<std::vector<int>> sums(std::vector<int> a, int target, bool reuse) {
    assert(target >= 0 && target <= 20);
    for (int x : a) {
        assert(x > 0);
    }
    std::sort(a.begin(), a.end());
    std::vector<int> path;
    std::vector<std::vector<int>> out;
    visit(a, 0, target, reuse, path, out);
    return out;
}

int main() {
    assert((sums({2, 3, 6, 7}, 7, true) == std::vector<std::vector<int>>{{2, 2, 3}, {7}}));
    assert(sums({2}, 3, true).empty());
    assert(sums({}, 0, true).size() == 1);
    std::cout << "checks passed\n";
    return 0;
}
