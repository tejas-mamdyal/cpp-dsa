/*
 Loop-free undirected matrix<=8 vertices; k 0..4 labeled colors. Unless narrowed, at
most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume valid acyclic
owned structures; exponential searches use the smaller bounds stated here. No input; keep
assertions enabled. Success prints checks passed.

Explore every legal color per vertex and add complete assignment counts; no
early success return.

A triangle with 3 colors has 6 assignments, not 1, because renaming colors changes a
labeled answer.

Each complete assignment corresponds to exactly one sequence of vertex color
choices.

O(n*k^n) time, O(n) work.

Do not symmetry-divide unless the specification identifies color renamings.
*/
#include <iostream>
#include <cassert>
#include <vector>

long long
count(const std::vector<std::vector<int>>& edges, int v, int k, std::vector<int>& colors) {
    if (v == static_cast<int>(edges.size())) {
        return 1;
    }
    long long total = 0;
    for (int color = 1; color <= k; ++color) {
        bool ok = true;
        for (int j = 0; j < v; ++j) {
            if (edges[v][j] && colors[j] == color) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        colors[v] = color;
        total += count(edges, v + 1, k, colors);
        colors[v] = 0;
    }
    return total;
}

int main() {
    std::vector<int> colors(3);
    assert(count({{0, 1, 1}, {1, 0, 1}, {1, 1, 0}}, 0, 3, colors) == 6);
    assert((colors == std::vector<int>{0, 0, 0}));
    colors.clear();
    assert(count({}, 0, 0, colors) == 1);
    std::cout << "checks passed\n";
    return 0;
}
