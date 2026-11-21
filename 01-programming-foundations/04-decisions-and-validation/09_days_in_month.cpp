/*
DISCRETE CHOICES WITH SWITCH
Route: Reinforcement | Prerequisites: Units 01–03: values, expressions and bool.

Several case labels can share one body. February is separate; break stops execution from
continuing to another body.

O(1) time and O(1) auxiliary space.

This fixed common-year contract deliberately does not handle leap years.
*/
#include <iostream>

int main() {
    int month = 0;
    if (!(std::cin >> month) || !(month >= 1 && month <= 12)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    switch (month) {
        case 2:
            std::cout << 28 << '\n';
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            std::cout << 30 << '\n';
            break;
        default:
            std::cout << 31 << '\n';
            break;
    }
}
