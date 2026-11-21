/*
CHOOSE BETWEEN TWO OUTCOMES
Route: Core | Prerequisites: Units 01–03: values, expressions and bool.

An integer is even precisely when its remainder modulo 2 is zero; all other integers are
odd.

O(1) time and O(1) auxiliary space.

Do not test n%2==1 for all signed odd numbers.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= -1000000 && n <= 1000000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    if (n % 2 == 0) {
        std::cout << "even\n";
    } else {
        std::cout << "odd\n";
    }
}
