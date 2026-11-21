/*
NEXT PERMUTATION AND SELECTING A KTH POSITION
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Starting sorted visits distinct permutations; nth_element selects a position without fully sorting.
Trace: 1,1,2 has3 distinct permutations; rank2 in9,1,5,3 is5.
Why it works: Lexicographic successor avoids repeated arrangements; nth_element establishes the selected rank partition.
Cost: Permutation enumeration O(p*n) for p permutations; nth_element expected O(n) comparisons. O(n) stored data.
Common mistake: nth_element does not sort either side; never select an index outside the range.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> permutation = {1, 1, 2};
    int count = 0;
    do {
        ++count;
    } while (std::next_permutation(permutation.begin(), permutation.end()));
    assert(count == 3);
    std::vector<int> values = {9, 1, 5, 3};
    std::nth_element(values.begin(), values.begin() + 2, values.end());
    assert(values[2] == 5);
    std::cout << "checks passed\n";
}
