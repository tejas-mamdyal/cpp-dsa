/*
 2<=modulus<=1000000; value magnitude<=1000000.

A Bezout coefficient of value gives its inverse exactly when gcd(value,
modulus)=1.

3*7=21=1 modulo 10;6 has no inverse modulo 9.

Bezout establishes sufficiency; any common divisor must divide 1 if an inverse
exists, establishing necessity.

O(log modulus) time and recursion storage.

Composite moduli may have invertible residues; test gcd rather than rejecting all
composites.
*/
#include <iostream>
#include <cassert>
#include <optional>

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

std::optional<long long> inverse(long long value, long long modulus) {
    assert(modulus >= 2);
    value = (value % modulus + modulus) % modulus;
    auto r = extended(value, modulus);
    if (r.gcd != 1) {
        return std::nullopt;
    }
    return (r.x % modulus + modulus) % modulus;
}

int main() {
    assert(inverse(3, 10) == 7);
    assert(!inverse(6, 9));
    assert(inverse(-3, 10) == 3);
    std::cout << "checks passed\n";
    return 0;
}
