/*
EXPLICIT CONVERSION BEFORE DIVISION
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: static_cast<double> converts before division; a cast after integer division cannot recover the fraction.
Trace: 5/2=2; double(5)/2=2.5; 3.9 to int truncates to 3.
Why it works: Each statement computes its result from the current values before the next statement.
Cost: O(1) arithmetic operations and auxiliary storage.
Common mistake: An out-of-range floating-to-integer conversion is invalid. C-style and functional casts exist; prefer named casts for clarity.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    std::cout << 5 / 2 << ' ' << static_cast<double>(5) / 2 << ' ' << static_cast<int>(3.9) << '\n';
}
