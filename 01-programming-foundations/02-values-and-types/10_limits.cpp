/*
numeric_limits<T> reports properties of type T. For integers min() and max() are bounds; for floating types min() is the smallest positive normal value, while lowest() is the most negative finite value. A chosen sentinel must leave arithmetic headroom.
*/
/*
PORTABLE NUMERIC BOUNDS
Route: Reinforcement | Prerequisites: Unit 01: statements, variables and streams.

numeric_limits obtains properties from the implementation instead of guessing fixed
widths.

O(1) time and O(1) auxiliary space for these bounded examples.

Do not assume all C++ integer types have the same range.
*/
#include <iostream>
#include <limits>

int main() {
    std::cout << (std::numeric_limits<int>::min() < 0) << "\n";
    std::cout << (std::numeric_limits<int>::max() >= 32767) << "\n";
}
