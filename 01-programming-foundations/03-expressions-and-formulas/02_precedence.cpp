/*
PARENTHESES CHANGE THE CALCULATION
Route: Core | Prerequisites: Units 01–02: streams, types and conversions.

Multiplication binds first unless parentheses require addition first.

O(1) time and O(1) auxiliary space for bounded scalar input.

Read expressions by grouping, not simply left to right.
*/
#include <iostream>

int main() {
    std::cout << 2 + 3 * 4 << '\n';
    std::cout << (2 + 3) * 4 << '\n';
}
