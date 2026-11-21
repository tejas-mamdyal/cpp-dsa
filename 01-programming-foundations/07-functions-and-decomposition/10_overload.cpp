/*
OVERLOAD BY PARAMETER LIST
Route: Reinforcement | Prerequisites: Units 01–06: decisions, loops and repeated input.

The argument count selects which overload applies. Both overloads represent the same
operation on different numbers of operands.

O(1) time/space.

Return type alone cannot distinguish overloads with the same parameter list.
*/
#include <iostream>

int add(int a, int b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    int a = 0;
    int b = 0;
    if (!(std::cin >> a >> b) || !(a >= 0 && a <= 100 && b >= 0 && b <= 100)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    std::cout << add(a, b) << ' ' << add(a, b, 1) << "\n";
}
