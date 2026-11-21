/*
 n 0..60.

Before iteration i, previous=f(i-2), current=f(i-1); compute next before
overwriting either.

At i 2,1+1 yields 2; at i 3, the retained pair 1,2 yields 3.

The full table recurrence reads only the last two entries, so older entries can
be discarded.

O(n) time, O(1) auxiliary.

Compression may prevent later reconstruction or queries for arbitrary previous
states.
*/
#include <iostream>
#include <cassert>

long long ways(int n) {
    assert(n >= 0 && n <= 60);
    long long previous = 1;
    long long current = 1;
    for (int i = 2; i <= n; ++i) {
        long long next = previous + current;
        previous = current;
        current = next;
    }
    return n == 0 ? 1 : current;
}

int main() {
    assert(ways(0) == 1);
    assert(ways(2) == 2);
    assert(ways(10) == 89);
    std::cout << "checks passed\n";
    return 0;
}
