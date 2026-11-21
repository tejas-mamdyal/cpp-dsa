/*
FIBONACCI WITH TWO STATE VARIABLES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Print the first ten Fibonacci numbers beginning 0,1. Values through F(92) fit a typical 64-bit signed long long; do not compute F(93).
Trace: previous=0,current=1; next=1, then 2, then 3.
Why it works: The helper encodes the definition directly and the main function exercises different boundary classes.
Cost: O(n) time, O(1) extra space.
Common mistake: Keep products within long long and distinguish zero, one and negative values according to the contract.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

int main() {
    long long previous = 0;
    long long current = 1;
    for (int i = 0; i < 10; ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << previous;
        long long next = previous + current;
        previous = current;
        current = next;
    }
    std::cout << '\n';
}
