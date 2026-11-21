/*
RESTORE PROGRESS TOWARD TERMINATION
Route: Reinforcement | Prerequisites: Units 01–07; functions and input validation.

The counter increases on every iteration so eventually exceeds n. The sum update alone
cannot change the loop condition.

O(n) time; O(1) auxiliary space.

A timeout is a symptom; identify the unchanged condition variable.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 100)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    int i = 1;
    int sum = 0;
    while (i <= n) {
        sum += i;
        ++i; // Essential progress update.
    }
    std::cout << sum << '\n';
}
