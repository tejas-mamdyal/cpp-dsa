/*
 Precompute 0<=n<=1000000; queries 0<=n<=precomputed bound; fixed prime 1000000007.

factorial[i]=i! modulo prime P; inverseFactorial[i] is its multiplicative
inverse.

5 choose 2=120*(2!)^-1*(3!)^-1=10 modulo P.

Factorial cancellation counts unordered selections; Fermat inversion is valid
because n<P and P is prime.

O(n+log P) construction, O(1) query, O(n) storage.

n>=P makes the factorial zero and this formula invalid.
*/
#include <iostream>
#include <cassert>
#include <vector>

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

constexpr long long P = 1000000007;

class Combinations {
    std::vector<long long> factorial;
    std::vector<long long> inverseFactorial;

public:
    explicit Combinations(int n)
        : factorial(n + 1, 1),
          inverseFactorial(n + 1, 1) {
        for (int i = 1; i <= n; ++i) {
            factorial[i] = factorial[i - 1] * i % P;
        }
        inverseFactorial[n] = modPower(factorial[n], P - 2, P);
        for (int i = n; i > 0; --i) {
            inverseFactorial[i - 1] = inverseFactorial[i] * i % P;
        }
    }

    long long choose(int n, int r) const {
        if (r < 0 || r > n) {
            return 0;
        }
        return factorial[n] * inverseFactorial[r] % P * inverseFactorial[n - r] % P;
    }
};

int main() {
    Combinations c(100);
    assert(c.choose(5, 2) == 10 && c.choose(0, 0) == 1 && c.choose(4, 6) == 0
           && c.choose(100, 1) == 100);
    std::cout << "checks passed\n";
    return 0;
}
