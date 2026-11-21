/*
A FOR LOOP STILL UPDATES AFTER CONTINUE
Route: Reinforcement | Prerequisites: Units 01–07; functions and input validation.

continue skips even values; the for update runs before the next condition check.

O(n) time; O(1) auxiliary space.

In a while loop, continue can skip a manually placed update and cause an infinite loop.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 10)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            continue;
        }
        std::cout << i << '\n';
    }
}
