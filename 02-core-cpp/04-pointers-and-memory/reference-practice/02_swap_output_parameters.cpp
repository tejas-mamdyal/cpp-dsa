/*
SWAP THROUGH REFERENCES AND RETURN MULTIPLE RESULTS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use reference parameters to return quotient and remainder after a nonzero divisor check.
Trace: 17 divided by 5 gives quotient 3 and remainder 2.
Why it works: The temporary preserves the first value; output references write directly to caller variables.
Cost: O(1) time and space.
Common mistake: The division helper assumes small ints and distinct output variables; INT_MIN/-1 must also be excluded for general int division.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

void exchange(int& a, int& b) {
    int saved = a;
    a = b;
    b = saved;
}

bool divide(int value, int divisor, int& quotient, int& remainder) {
    if (divisor == 0) {
        return false;
    }
    quotient = value / divisor;
    remainder = value % divisor;
    return true;
}

int main() {
    int a = 4;
    int b = 9;
    exchange(a, b);
    assert(a == 9 && b == 4);
    int q = 0;
    int r = 0;
    assert(divide(17, 5, q, r));
    assert(q == 3 && r == 2);
    assert(!divide(17, 0, q, r));
    std::cout << "checks passed\n";
}
