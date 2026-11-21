/*
POINTER TO CONST VERSUS CONST POINTER
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Compare const int*, int* const and const int* const. Each const applies to a different object.
Trace: readOnly may be redirected; fixed may modify its int but cannot be redirected.
Why it works: The declarator separates whether the pointer value and/or pointed-to int can change.
Cost: O(1) time and space.
Common mistake: Constness through a pointer does not make the original mutable int globally immutable.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int main() {
    int first = 3;
    int second = 5;
    const int* readOnly = &first;
    readOnly = &second;
    assert(*readOnly == 5);
    int* const fixed = &first;
    *fixed = 7;
    assert(first == 7);
    const int* const both = &second;
    assert(*both == 5);
    std::cout << "checks passed\n";
}
