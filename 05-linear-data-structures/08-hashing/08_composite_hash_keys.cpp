/*
EQUALITY AND HASHING MUST AGREE PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Grid-cell key contains row and column; hash map stores a value per cell. IDEA AND
STATE: Define equality using both fields and combine their size_t hash values. TRACE: (1,2)
and(2,1) are different cells even if hashes collide. CORRECTNESS: Equal keys produce equal
hashes; bucket collisions are resolved by key equality. COST: Expected O(1) operations for
bounded keys,O(n) worst; O(n) storage. PITFALL: A hash is not a unique ID, and this example is
not a cryptographic hash. PRACTICE: Change the example, predict each state update and add an
empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <unordered_map>
#include <functional>
#include <cstddef>

struct Cell {
    int row;
    int column;

    bool operator==(const Cell& other) const {
        return row == other.row && column == other.column;
    }
};

struct CellHash {
    std::size_t operator()(const Cell& cell) const {
        return std::hash<int>{}(cell.row) ^ (std::hash<int>{}(cell.column) << 1);
    }
};

int main() {
    std::unordered_map<Cell, int, CellHash> grid;
    grid[{1, 2}] = 7;
    grid[{2, 1}] = 9;
    assert(grid.size() == 2);
    assert((grid.at(Cell{1, 2}) == 7));
    assert(CellHash{}(Cell{1, 2}) == CellHash{}(Cell{1, 2}));
    std::cout << "checks passed\n";
    return 0;
}
