/*
DEFAULT ARGUMENTS AND UNAMBIGUOUS OVERLOADS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: A default argument supplies an omitted trailing value; it is not a second function. Small integers only.
Trace: power3 defaults exponent2 ->9; power3,0 ->1.
Why it works: Repeated multiplication starts with the multiplicative identity.
Cost: O(e) multiplications, O(1) space.
Common mistake: Put defaults in one declaration and only on trailing parameters; ambiguous overloads should be redesigned.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int power(int base, int exponent = 2) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    assert(power(3) == 9);
    assert(power(3, 0) == 1);
    assert(power(2, 3) == 8);
    std::cout << "checks passed\n";
}
