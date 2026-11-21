/*
USE A COMPARISON IN A CONDITION
Route: Core | Prerequisites: Units 01–07; functions and input validation.

x==0 checks without modifying x. x=0 would replace x and produce false.

O(1) time and O(1) auxiliary space.

Assignments inside conditions can compile; warnings help identify accidental ones.
*/
#include <iostream>

int main() {
    int x = 0;
    if (!(std::cin >> x) || !(x >= -10 && x <= 10)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    if (x == 0) {
        std::cout << "zero\n";
    } else {
        std::cout << "nonzero\n";
    }
}
