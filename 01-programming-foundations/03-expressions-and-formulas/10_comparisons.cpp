/*
COMPARISONS PRODUCE TRUTH VALUES
Route: Reinforcement | Prerequisites: Units 01–02: streams, types and conversions.

A comparison produces bool and does not change either operand.

O(1) time and O(1) auxiliary space for bounded scalar input.

Equality uses two equals signs; = would assign.
*/
#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    std::cout << (a < b) << ' ' << (a == b) << ' ' << (a != b) << '\n';
}
