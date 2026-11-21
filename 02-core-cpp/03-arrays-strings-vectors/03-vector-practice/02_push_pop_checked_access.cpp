/*
VECTOR INSERTION AT THE END AND CHECKED ACCESS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: push_back appends; pop_back removes without returning a value; at checks bounds.
Trace: empty -> 3,8 -> 3.
Why it works: Each operation updates only the last logical position except when growth reallocates.
Cost: Amortized O(1) push_back, O(1) pop_back, O(n) storage.
Common mistake: front/back/pop_back require a nonempty vector. at throws on invalid indices; [] does not check.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

int main() {
    std::vector<int> values;
    values.push_back(3);
    values.push_back(8);
    assert(values.at(1) == 8);
    int last = values.back();
    values.pop_back();
    assert(last == 8 && values.size() == 1);
    values.pop_back();
    assert(values.empty());
    std::cout << "checks passed\n";
}
