/*
READ UNTIL A TERMINATING VALUE
Route: Reinforcement | Prerequisites: Unit 04: conditions, validation and early return.

The sentinel controls termination and is not included in the sum. A bounded read count
prevents unlimited work on malformed input.

O(k) time/O(1) space for k data values.

Check the sentinel before adding it; EOF before sentinel violates this contract.
*/
#include <iostream>

int main() {
    long long sum = 0;
    for (int count = 0; count <= 1000; ++count) {
        int value = 0;
        if (!(std::cin >> value)) {
            std::cerr << "Invalid input\n";
            return 1;
        }
        if (value == -1) {
            std::cout << sum << '\n';
            return 0;
        }
        if (value < 0 || value > 1000 || count == 1000) {
            std::cerr << "Invalid input\n";
            return 1;
        }
        sum += value;
    }
    return 1;
}
