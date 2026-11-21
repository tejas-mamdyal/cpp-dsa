/*
FUNCTION POINTERS AND CALL SYNTAX
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Store the address of a function with matching signature and call it.
Trace: add(2,3)=5; redirected pointer multiply(2,3)=6.
Why it works: Both functions have the exact two-int-to-int signature.
Cost: O(1) time and space.
Common mistake: Do not call a null function pointer or cast an incompatible function signature.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int (*operation)(int, int) = &add;
    assert(operation(2, 3) == 5);
    operation = &multiply;
    assert((*operation)(2, 3) == 6);
    std::cout << "checks passed\n";
}
