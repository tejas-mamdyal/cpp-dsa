/*
EXTRACT THE FINAL DECIMAL DIGIT
Route: Core | Prerequisites: Units 01–02: streams, types and conversions.

%10 gives the units digit; /10 removes it. This is the basis of later digit loops.

O(1) time and O(1) auxiliary space for bounded scalar input.

The stated nonnegative domain avoids sign questions for digit characters.
*/
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << n % 10 << ' ' << n / 10 << '\n';
}
