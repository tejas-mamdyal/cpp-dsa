/*
 Signed base magnitude<=1000000; unsigned exponent;1<=modulus<=1000000007. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

answer*base^remaining equals the requested power modulo modulus.

2^10 uses bits 1010; successively square 2,4,16,256.

Even exponents permit squaring and halving; odd exponents first move one base
factor into answer.

O(log(exponent+1)) time, O(1) space.

Reduce factors before multiplication and prove the product fits; modulo does not
prevent earlier overflow.
*/
#include <iostream>
#include <cassert>

long long modPower(long long base, unsigned long long exponent, long long modulus) {
    assert(modulus >= 1 && modulus <= 1000000007);
    base = (base % modulus + modulus) % modulus;
    long long answer = 1 % modulus;
    while (exponent) {
        if (exponent & 1ULL) {
            answer = answer * base % modulus;
        }
        base = base * base % modulus;
        exponent /= 2;
    }
    return answer;
}

int main() {
    assert(modPower(2, 10, 1000) == 24);
    assert(modPower(-2, 3, 5) == 2);
    assert(modPower(7, 0, 1) == 0);
    std::cout << "checks passed\n";
    return 0;
}
