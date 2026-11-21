/*
ARRAY DECAY AND ONE-PAST POINTERS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Walk a fixed array using pointers from its first element up to but excluding one-past.
Trace: 2,4,6 sum to 12; end-begin=3.
Why it works: Every dereferenced pointer refers to an element of the same array.
Cost: O(n) time and O(1) space.
Common mistake: One-past may be formed and compared, never dereferenced. Subtraction/order must stay within the same array.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int main() {
    int values[3] = {2, 4, 6};
    int* begin = values;
    int* end = values + 3;
    int sum = 0;
    for (int* current = begin; current != end; ++current) {
        sum += *current;
    }
    assert(sum == 12);
    assert(end - begin == 3);
    assert(*(begin + 1) == 4);
    std::cout << "checks passed\n";
}
