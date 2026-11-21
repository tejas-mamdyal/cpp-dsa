/*
 Closed intervals with start<=end.

Output holds sorted disjoint merged intervals; only the last can overlap
the next input.

[1,3] and[3,5] share 3 and merge to[1,5].

Sorted starts ensure any overlap occurs with the current final merged component.

O(n log n) time, O(n) output/copy.

Half-open adjacency could have a different desired merge policy.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>

std::vector<std::pair<int, int>> merge(std::vector<std::pair<int, int>> a) {
    std::sort(a.begin(), a.end());
    std::vector<std::pair<int, int>> out;
    for (auto interval : a) {
        if (out.empty() || out.back().second < interval.first) {
            out.push_back(interval);
        } else {
            out.back().second = std::max(out.back().second, interval.second);
        }
    }
    return out;
}

int main() {
    assert((merge({{1, 3}, {3, 5}, {8, 9}}) == std::vector<std::pair<int, int>>{{1, 5}, {8, 9}}));
    assert(merge({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
