/*
COMBINE EXCEPTIONS IN A RULE
Route: Core | Prerequisites: Units 01–03: values, expressions and bool.

A multiple of 400 is leap; otherwise a multiple of 4 is leap only if not also a multiple
of 100.

O(1) time and O(1) auxiliary space.

Divisibility by 4 alone misses the century exception.
*/
#include <iostream>

int main() {
    int year = 0;
    if (!(std::cin >> year) || !(year >= 1 && year <= 9999)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    bool leap = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
    if (leap) {
        std::cout << "leap\n";
    } else {
        std::cout << "common\n";
    }
}
