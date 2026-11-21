/*
 0<=n<=1000000.

An unmarked integer>=2 is prime once all possible smaller prime divisors
have been processed.

For p=3, begin at 9;6 was already marked by 2.

Every composite has a prime factor no larger than its square root; smaller
multiples have already been covered.

O(n log log(n+2)) time, O(n) flags.

0 and 1 are not prime; handle a length-one table.
*/
#include <iostream>
#include <cassert>
#include <vector>

std::vector<bool> sieve(int n) {
    std::vector<bool> prime(n + 1, true);
    prime[0] = false;
    if (n >= 1) {
        prime[1] = false;
    }
    for (int p = 2; p <= n / p; ++p) {
        if (prime[p]) {
            for (int x = p * p; x <= n; x += p) {
                prime[x] = false;
            }
        }
    }
    return prime;
}

int main() {
    auto p = sieve(20);
    assert(p[2] && p[19] && !p[0] && !p[1] && !p[15]);
    assert(!sieve(0)[0]);
    std::cout << "checks passed\n";
    return 0;
}
