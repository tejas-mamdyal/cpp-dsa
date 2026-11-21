/*
MALFORMED INPUT MUST NOT BECOME A CALCULATION
Route: Reinforcement | Prerequisites: Units 01–07; functions and input validation.

Extraction failure returns before arithmetic, so an initializer is never mistaken for a
valid user value.

O(1) time and O(1) auxiliary space.

Invalid input is different from a legitimate zero.
*/
#include <iostream>

int main() {
    int age = 0;
    if (!(std::cin >> age) || !(age >= 0 && age <= 120)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    std::cout << age + 1 << '\n';
}
