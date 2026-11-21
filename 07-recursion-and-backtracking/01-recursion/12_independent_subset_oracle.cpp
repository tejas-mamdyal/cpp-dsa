/*
 Reference domain n<=10 with small signed values;positional subsets retain
equal-looking outputs. No input is required. Keep assertions enabled; a successful run prints
checks passed. Tiny bounds are intentional because output grows exponentially or factorially.

Use the same released subset helper,then generate a separate reference
using one bit per input position. Sort both collections only to compare multisets,not to
change lesson03 traversal order.

For n=2,masks00,01,10,11 encode [],[a0],[a1],[a0,a1]. Their ordering differs from
exclude-first recursion,but the multisets match.

Each bit mask uniquely specifies an index-subset independently of the recursive
control flow. Full multiset equality checks completeness and multiplicity,not only the result
count.

Each reference generation costs O((n+1)*2^n);sorting comparisons give conservative
O((n+1)^2*2^n) time. O((n+1)*2^n) saved reference/results plus O(n) active recursion.

Checking only size==2^n would miss repeated wrong answers. Finite-domain agreement
supports,but does not replace,the subset proof.
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

std::vector<std::vector<int>> masks(const std::vector<int>& a) {
    assert(a.size() <= 10);
    std::vector<std::vector<int>> out;
    unsigned int limit = 1U << a.size();
    for (unsigned int mask = 0; mask < limit; ++mask) {
        std::vector<int> path;
        for (std::size_t i = 0; i < a.size(); ++i) {
            if ((mask & (1U << i)) != 0U) {
                path.push_back(a[i]);
            }
        }
        out.push_back(path);
    }
    return out;
}

int main() {
    for (int n = 0; n <= 10; ++n) {
        std::vector<int> a;
        for (int i = 0; i < n; ++i) {
            a.push_back(i % 3 - 1);
        }
        auto actual = subsets(a);
        auto expected = masks(a);
        std::sort(actual.begin(), actual.end());
        std::sort(expected.begin(), expected.end());
        assert(actual == expected);
    }
    std::cout << "checks passed\n";
    return 0;
}
