/*
THROW A SPECIFIC EXCEPTION AND CATCH BY CONST REFERENCE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Reject a negative square side using invalid_argument.
Trace: side3 ->9; side-1 -> catch.
Why it works: Invalid input is rejected before multiplication.
Cost: O(1) normal path; exceptional runtime overhead is implementation-dependent.
Common mistake: Catch derived exception types before their base classes; catching by value can slice exception information.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <stdexcept>

int squareArea(int side) {
    if (side < 0 || side > 1000) {
        throw std::invalid_argument("side outside 0..1000");
    }
    return side * side;
}

int main() {
    assert(squareArea(3) == 9);
    bool caught = false;
    try {
        (void)squareArea(-1);
    } catch (const std::invalid_argument&) {
        caught = true;
    }
    assert(caught);
    std::cout << "checks passed\n";
}
