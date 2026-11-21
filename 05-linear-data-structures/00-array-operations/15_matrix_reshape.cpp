/*
RESHAPE WITHOUT CHANGING ROW-MAJOR ORDER PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Rectangular nonempty matrix,positive new dimensions,at most1000 cells; invalid
shapes return absence. IDEA AND STATE: Map each flat position to old and new row/column
coordinates. TRACE: [1,2,3;4,5,6] reshapes to[1,2;3,4;5,6]. CORRECTNESS: The same flat
position denotes the same value before and after reshaping. COST: O(cells) time and returned
storage,O(1) extra working state. PITFALL: Equal element counts are necessary; validate shapes
before division/indexing. PRACTICE: Change the example, predict each state update and add an
empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>

std::optional<std::vector<std::vector<int>>>
reshape(const std::vector<std::vector<int>>& a, std::size_t rows, std::size_t columns) {
    if (a.empty() || a[0].empty() || rows == 0 || columns == 0 || rows > 1000 || columns > 1000) {
        return std::nullopt;
    }
    for (const auto& row : a) {
        if (row.size() != a[0].size()) {
            return std::nullopt;
        }
    }
    std::size_t total = a.size() * a[0].size();
    if (total > 1000 || rows * columns != total) {
        return std::nullopt;
    }
    std::vector<std::vector<int>> out(rows, std::vector<int>(columns));
    for (std::size_t i = 0; i < total; ++i) {
        out[i / columns][i % columns] = a[i / a[0].size()][i % a[0].size()];
    }
    return out;
}

int main() {
    auto out = reshape({{1, 2, 3}, {4, 5, 6}}, 3, 2);
    assert(out);
    assert((*out == std::vector<std::vector<int>>{{1, 2}, {3, 4}, {5, 6}}));
    assert(!reshape({{1, 2, 3}}, 2, 2));
    assert(!reshape({}, 1, 1));
    assert(!reshape({{1}, {2, 3}}, 1, 3));
    std::cout << "checks passed\n";
    return 0;
}
