/*
BUILD A NUMBER ONE DIGIT AT A TIME
Route: Core | Prerequisites: Unit 04: conditions, validation and early return.

Appending digit d to a decimal number r gives r*10+d. Removing digits from the input
reverses their order.

O(d) time/O(1) space.

The reversed value may exceed int even if the input fits; use long long.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 1000000000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    int remaining = n;
    long long reversed = 0;
    do {
        reversed = reversed * 10 + remaining % 10;
        remaining /= 10;
    } while (remaining != 0);
    std::cout << reversed << '\n';
}
