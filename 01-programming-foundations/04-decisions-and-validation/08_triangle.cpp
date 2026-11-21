/*
VALIDATE A GEOMETRIC CONDITION
Route: Core | Prerequisites: Units 01–03: values, expressions and bool.

Positive lengths form a nondegenerate triangle exactly when each pair sum exceeds the
third side.

O(1) time and O(1) auxiliary space.

Equality describes a degenerate straight line and is excluded.
*/
#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    if (!(std::cin >> a >> b >> c)
        || !(a >= 1 && a <= 1000 && b >= 1 && b <= 1000 && c >= 1 && c <= 1000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    if (a + b > c && a + c > b && b + c > a) {
        std::cout << "triangle\n";
    } else {
        std::cout << "not triangle\n";
    }
}
