/*
SUM A COUNT-PREFIXED STREAM
Route: Reinforcement | Prerequisites: Unit 05: loops and accumulators.

After k reads, sum equals the total of exactly those k values.

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
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int value = 0;
        if (!(std::cin >> value) || value < -1000 || value > 1000) {
            std::cerr << "Invalid input\n";
            return 1;
        }
        sum += value;
    }
    std::cout << sum << '\n';
}
