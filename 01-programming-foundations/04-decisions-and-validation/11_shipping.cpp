/*
NESTED DECISIONS AND A THRESHOLD
Route: Reinforcement | Prerequisites: Units 01–03: values, expressions and bool.

Membership decides the first branch; only nonmembers need the bill threshold check.

O(1) time and O(1) auxiliary space.

A flag should have a documented domain rather than accepting arbitrary integers.
*/
#include <iostream>

int main() {
    int total = 0;
    int member = 0;
    if (!(std::cin >> total >> member)
        || !(total >= 0 && total <= 10000 && (member == 0 || member == 1))) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    int shipping = 0;
    if (member == 0) {
        if (total < 500) {
            shipping = 50;
        }
    }
    std::cout << shipping << '\n';
}
