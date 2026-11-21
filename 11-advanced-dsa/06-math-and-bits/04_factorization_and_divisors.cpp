/*
 1<=n<=1000000.

Remove every copy of a trial factor; the remaining value has no smaller
divisor.

12=2^2*3; divisors independently choose exponents 0..2 and 0..1, so 3*2=6.

Unique prime factorization gives a bijection between exponent choices and
positive divisors.

O(sqrt(n)) worst time, O(log(n+1)) output.

Use p<=n/p instead of a potentially overflowing p*p.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>

std::vector<std::pair<long long, int>> factors(long long n) {
    std::vector<std::pair<long long, int>> out;
    for (long long p = 2; p <= n / p; ++p) {
        if (n % p == 0) {
            int count = 0;
            do {
                n /= p;
                ++count;
            } while (n % p == 0);
            out.push_back({p, count});
        }
    }
    if (n > 1) {
        out.push_back({n, 1});
    }
    return out;
}

long long divisors(long long n) {
    long long count = 1;
    for (auto [prime, exponent] : factors(n)) {
        (void)prime;
        count *= exponent + 1;
    }
    return count;
}

int main() {
    assert((factors(12) == std::vector<std::pair<long long, int>>{{2, 2}, {3, 1}}));
    assert(divisors(12) == 6 && divisors(1) == 1);
    std::cout << "checks passed\n";
    return 0;
}
