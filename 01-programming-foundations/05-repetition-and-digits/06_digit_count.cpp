/*
ZERO HAS ONE DIGIT
Route: Core | Prerequisites: Unit 04: conditions, validation and early return.

Each division by 10 removes one digit. do/while counts once even when the original
number is zero.

O(d) time/O(1) space for d digits.

while(remaining) alone reports zero digits for zero.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 1000000000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    int remaining = n;
    int count = 0;
    do {
        ++count;
        remaining /= 10;
    } while (remaining != 0);
    std::cout << count << '\n';
}
