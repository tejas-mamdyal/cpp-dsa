/*
AN ACCUMULATOR CAN TURN PENDING WORK INTO STATE
PREREQUISITES
Phase1 functions/loops/validation, Phase2 references/strings/vectors, and Phase3
complexity. Follow this unit's README order; the first factorial lesson introduces
recursion and the later lessons build on it. No capturing lambda is required.

CONTRACT
No input. Compare tail-recursive and loop sums for all n in0..100. Both compute1+...+n. Print checked101 sums; assertions must remain enabled.

IDEA AND STATE
The accumulator stores the sum already consumed. The recursive call is the last action, with no addition waiting afterward. A loop can update the same two scalar state variables.

TRACE
sumTail(3,0) ->sumTail(2,3) ->sumTail(1,5) ->sumTail(0,6)=6.

WHY IT WORKS AND TERMINATES
Invariant: total+sum(1..remaining) equals the requested original sum. Moving remaining into total preserves that value; at remaining0 the accumulator is complete.

Both methods take Theta(n+1) time. The loop needs O(1) extra space. Without relying on compiler tail-call elimination, allow O(n+1) recursive stack space.

PITFALL AND PRACTICE
C++ does not guarantee tail-call elimination. Tail position alone is not permission to recurse millions of times. Prefer the loop when stack depth is a practical concern.
Predict a new small trace and test a boundary before changing the contract.
*/
#include <iostream>
#include <cassert>

long long sumTail(int remaining, long long total) {
    if (remaining == 0) {
        return total;
    }
    return sumTail(remaining - 1, total + remaining);
}

long long sumLoop(int n) {
    long long total = 0;
    while (n > 0) {
        total += n;
        --n;
    }
    return total;
}

int main() {
    int checked = 0;
    for (int n = 0; n <= 100; ++n) {
        assert(sumTail(n, 0) == sumLoop(n));
        assert(sumLoop(n) == 1LL * n * (n + 1) / 2);
        ++checked;
    }
    assert(checked == 101);
    std::cout << "checked " << checked << " sums\n";
    return 0;
}
