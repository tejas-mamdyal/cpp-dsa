/*
AN INNER SEARCH CLASSIFIES EACH OUTER CANDIDATE
Route: Reinforcement | Prerequisites: Unit 05: loops and accumulators.

Test each candidate independently; reset its prime flag before starting its divisor
loop.

O(n*sqrt(n)) upper time/O(1) space.

A flag from an earlier candidate must not leak into the next candidate.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 100)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int candidate = 2; candidate <= n; ++candidate) {
        bool prime = true; // Reset for this candidate, not once for the whole range.
        for (int d = 2; d <= candidate / d; ++d) {
            if (candidate % d == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            std::cout << candidate << '\n';
        }
    }
}
