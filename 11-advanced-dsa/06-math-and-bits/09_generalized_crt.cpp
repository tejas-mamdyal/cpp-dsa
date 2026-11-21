/*
 Residues magnitude<=1000000; moduli 1..1000.

x=a+m*t; solve m*t=b-a modulo n after dividing by the gcd.

x=2 mod 6 and 5 mod 9 meet at 14 and repeat every 18.

The gcd must divide the residue difference; Bezout gives a solution, and all
solutions differ by lcm(m, n).

O(log(max(m, n))) time/recursion storage.

Noncoprime moduli can be compatible; their combined period is the lcm, not the
product.
*/
#include <iostream>
#include <cassert>
#include <optional>
#include <utility>

struct Bezout {
    long long gcd;
    long long x;
    long long y;
};

Bezout extended(long long a, long long b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    auto next = extended(b, a % b);
    return {next.gcd, next.y, next.x - (a / b) * next.y};
}

std::optional<std::pair<long long, long long>>
crt(long long a, long long m, long long b, long long n) {
    a = (a % m + m) % m;
    b = (b % n + n) % n;
    auto e = extended(m, n);
    long long difference = b - a;
    if (difference % e.gcd != 0) {
        return std::nullopt;
    }
    long long reduced = n / e.gcd;
    long long t = ((difference / e.gcd * e.x) % reduced + reduced) % reduced;
    long long period = m * reduced;
    return std::pair<long long, long long>{(a + m * t) % period, period};
}

int main() {
    auto r = crt(2, 6, 5, 9);
    assert(r && r->first == 14 && r->second == 18);
    assert(!crt(0, 2, 1, 4));
    assert(crt(0, 1, 0, 1)->first == 0);
    auto coprime = crt(2, 3, 3, 5);
    assert(coprime && coprime->first == 8 && coprime->second == 15);
    auto same = crt(1, 4, 1, 4);
    assert(same && same->first == 1 && same->second == 4);
    std::cout << "checks passed\n";
    return 0;
}
