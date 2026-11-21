/*
MAXIMUM WITHOUT STORING THE SEQUENCE
Route: Reinforcement | Prerequisites: Unit 05: loops and accumulators.

Initialize from the first data value; every subsequent comparison preserves the largest
value seen.

O(n) time/O(1) space.

Respect the declared count; a missing data value is invalid.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 1 && n <= 100)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    int best = 0;
    for (int i = 0; i < n; ++i) {
        int value = 0;
        if (!(std::cin >> value) || value < -1000 || value > 1000) {
            std::cerr << "Invalid input\n";
            return 1;
        }
        if (i == 0 || value > best) {
            best = value; // First real value establishes the candidate.
        }
    }
    std::cout << best << '\n';
}
