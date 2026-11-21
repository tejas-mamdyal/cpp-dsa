/*
SINGLE NUMBER WITH XOR
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Read n (1..1000), followed by n nonnegative ints. Exactly one value occurs once; every other value occurs twice. Print the unique value. This multiplicity is a precondition.
Trace: 4 1 4 1 7 cancels to 7 because x^x=0 and x^0=x.
Why it works: The loop invariant or arithmetic identity below preserves exactly the desired result.
Cost: O(n) time and O(1) extra space.
Common mistake: Read the stated input bounds and multiplicity assumptions; the program is not a general solution outside them.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || n < 1 || n > 1000) {
        std::cerr << "Invalid count.\n";
        return 1;
    }
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        int value = 0;
        if (!(std::cin >> value) || value < 0) {
            std::cerr << "Invalid value.\n";
            return 1;
        }
        // XOR is associative and commutative, so separated pairs also cancel.
        answer ^= value;
    }
    std::cout << answer << '\n';
}
