/*
 Unsigned exponent; answers modulo 1000000007.

Matrix[[1,1],[1,0]] advances the vector[F(k+1), F(k)] by one step.

Identity gives F(0)=0; the tenth power has top-right 55.

Associative matrix composition permits binary exponentiation; induction on steps
establishes the recurrence vector.

O(log(n+1)) time, O(1) fixed-size matrices.

The exponent-zero result must be identity rather than an all-zero matrix.
*/
#include <iostream>
#include <cassert>
#include <array>

using Matrix = std::array<std::array<long long, 2>, 2>;

Matrix multiply(const Matrix& a, const Matrix& b) {
    Matrix c{};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % 1000000007;
            }
        }
    }
    return c;
}

long long fibonacci(unsigned n) {
    Matrix base{{{1, 1}, {1, 0}}};
    Matrix result{{{1, 0}, {0, 1}}};
    while (n) {
        if (n & 1U) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        n /= 2;
    }
    return result[0][1];
}

int main() {
    assert(fibonacci(0) == 0 && fibonacci(1) == 1 && fibonacci(10) == 55
           && fibonacci(50) == 586268941);
    std::cout << "checks passed\n";
    return 0;
}
