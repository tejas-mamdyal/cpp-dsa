/*
COMPARATORS REQUIRE STRICT WEAK ORDERING
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Order records by descending mark, then ascending ID; equal records compare false in both directions.
Trace: marks90 IDs1,2 precede mark80 ID3.
Why it works: Lexicographic tie-breaking defines consistent strict comparisons.
Cost: O(n log n) comparisons; sort implementation uses O(log n) typical stack space.
Common mistake: Never use <= in a sort comparator; irreflexivity and transitivity are required.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

struct Record {
    int id;
    int mark;
};

bool before(const Record& left, const Record& right) {
    if (left.mark != right.mark) {
        return left.mark > right.mark;
    }
    return left.id < right.id;
}

int main() {
    std::vector<Record> records = {{3, 80}, {2, 90}, {1, 90}};
    std::sort(records.begin(), records.end(), before);
    assert(records[0].id == 1 && records[1].id == 2 && records[2].id == 3);
    assert(!before(records[0], records[0]));
    std::cout << "checks passed\n";
}
