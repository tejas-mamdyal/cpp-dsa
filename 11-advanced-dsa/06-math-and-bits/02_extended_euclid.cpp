/*
 a, b in[0,1000000].

extended(a, b) returns g, x, y satisfying a*x+b*y=g for nonnegative
inputs.

30=18+12;18=12+6; back substitution gives 6=2*18-30.

Substitute the recursive identity b*x+(a%b)*y=g and a%b=a-(a/b)*b.

O(log(max(a, b)+1)) time and recursion storage.

This lesson restricts inputs to nonnegative values; negative normalization requires
separate sign handling.
*/
#include <iostream>
#include <cassert>

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

int main() {
    auto r = extended(30, 18);
    assert(r.gcd == 6 && 30 * r.x + 18 * r.y == 6);
    assert(extended(0, 7).gcd == 7);
    assert(extended(0, 0).gcd == 0);
    std::cout << "checks passed\n";
    return 0;
}
