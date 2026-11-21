/*
COMPARE TWO CANDIDATES
Route: Core | Prerequisites: Units 01–03: values, expressions and bool.

If a>=b, a is a maximum; otherwise b is. Equal values need no special output.

O(1) time and O(1) auxiliary space.

Do not initialize a maximum to zero when inputs may be negative.
*/
#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    if (!(std::cin >> a >> b) || !(a >= -1000 && a <= 1000 && b >= -1000 && b <= 1000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    if (a >= b) {
        std::cout << a << '\n';
    } else {
        std::cout << b << '\n';
    }
}
