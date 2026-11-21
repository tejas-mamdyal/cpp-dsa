/*
A FUNCTION CAN ANSWER A YES/NO QUESTION
Route: Core | Prerequisites: Units 01–06: decisions, loops and repeated input.

A predicate returns bool; its name can make the if condition read like the problem
statement.

O(1) time/space.

Return the comparison itself rather than printing inside a reusable predicate.
*/
#include <iostream>

bool isEven(int n) {
    return n % 2 == 0;
}

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= -1000 && n <= 1000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    if (isEven(n)) {
        std::cout << "even\n";
    } else {
        std::cout << "odd\n";
    }
}
