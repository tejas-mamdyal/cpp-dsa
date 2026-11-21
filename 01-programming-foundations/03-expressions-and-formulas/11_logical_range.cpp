/*
COMBINE A LOWER AND UPPER BOUND
Route: Reinforcement | Prerequisites: Units 01–02: streams, types and conversions.

Both comparisons must hold: x>=10 && x<=20. ! negates a truth value.

O(1) time and O(1) auxiliary space for bounded scalar input.

C++ chained comparisons such as 10<=x<=20 do not express a mathematical interval.
*/
#include <iostream>

int main() {
    int x = 0;
    std::cin >> x;
    bool inside = (x >= 10 && x <= 20);
    std::cout << inside << '\n';
}
