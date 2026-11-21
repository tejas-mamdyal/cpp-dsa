/*
HANDLE A ZERO-ITERATION EDGE CASE
Route: Core | Prerequisites: Units 01–07; functions and input validation.

A do/while counts the first digit before testing whether more remain.

O(d) time for d digits; O(1) auxiliary space.

Zero is a valid one-digit number, not missing data.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 1000000000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    int count = 0;
    do {
        ++count;
        n /= 10;
    } while (n);
    std::cout << count << '\n';
}
