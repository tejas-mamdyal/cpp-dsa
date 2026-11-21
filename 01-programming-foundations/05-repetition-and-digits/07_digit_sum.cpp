/*
EXTRACT AND ACCUMULATE DIGITS
Route: Core | Prerequisites: Unit 04: conditions, validation and early return.

%10 extracts the last digit; /10 removes it. sum contains the total of all removed
digits.

O(d) time/O(1) space.

Update remaining every iteration or the loop cannot terminate.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 1000000000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    int remaining = n;
    int sum = 0;
    do {
        sum += remaining % 10;
        remaining /= 10;
    } while (remaining != 0);
    std::cout << sum << '\n';
}
