/*
COUNT WITH A FOR LOOP
Route: Core | Prerequisites: Unit 04: conditions, validation and early return.

i begins at 1 and increases until it exceeds n; every required integer is visited once.

O(n) time/O(1) space.

n=0 should print no lines, not an unwanted first value.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 100)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int i = 1; i <= n; ++i) { // ++i increases i by one.
        std::cout << i << '\n';
    }
}
