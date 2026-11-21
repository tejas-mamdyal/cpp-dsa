/*
 n 0..20; count ordered 1/2-step routes.

State f(n) counts ordered sequences of 1/2 steps totaling n. f(0)=1
represents the completed empty continuation; f(negative)=0. Dynamic programming will cache
this same state in lesson 02.

f 5 calls f 4 and f 3; f 4 calls f 3 again, so the same remaining-distance state
is recomputed.

Every nonempty route begins with 1 or 2; the two disjoint possibilities reduce
the remaining distance accordingly.

O(2^n) upper-bound time, O(n) stack; baseline intentionally n<=20.

The empty continuation must count 1, not 0, or every route count vanishes.
*/
#include <iostream>
#include <cassert>

long long ways(int n, long long& calls) {
    ++calls;
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    return ways(n - 1, calls) + ways(n - 2, calls);
}

int main() {
    long long calls = 0;
    assert(ways(5, calls) == 8);
    assert(calls > 6);
    calls = 0;
    assert(ways(0, calls) == 1 && calls == 1);
    std::cout << "checks passed\n";
    return 0;
}
