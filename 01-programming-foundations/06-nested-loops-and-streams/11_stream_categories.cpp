/*
COUNT DISJOINT CATEGORIES
Route: Reinforcement | Prerequisites: Unit 05: loops and accumulators.

Each value contributes to exactly one sign category; their counts sum to the processed
length.

O(n) time/O(1) space.

Respect the declared count; a missing data value is invalid.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 100)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    int negative = 0;
    int zero = 0;
    int positive = 0;
    for (int i = 0; i < n; ++i) {
        int value = 0;
        if (!(std::cin >> value) || value < -1000 || value > 1000) {
            std::cerr << "Invalid input\n";
            return 1;
        }
        if (value < 0) {
            ++negative;
        } else if (value == 0) {
            ++zero;
        } else {
            ++positive;
        }
    }
    std::cout << negative << ' ' << zero << ' ' << positive << '\n';
}
