/*
LCM FROM THE EUCLIDEAN GCD
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Compute lcm for nonnegative a,b <=1000000; lcm(0,b)=0.
Trace: gcd(12,18)=6, so (12/6)*18=36.
Why it works: The helper encodes the definition directly and the main function exercises different boundary classes.
Cost: O(log(min(a,b))) division steps for positive inputs; O(1) space.
Common mistake: Keep products within long long and distinguish zero, one and negative values according to the contract.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return (a / gcd(a, b)) * b;
}

int main() {
    std::cout << lcm(12, 18) << ' ' << lcm(0, 7) << ' ' << lcm(7, 5) << '\n';
}
