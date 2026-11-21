/*
 0<=n<=1000000; phi[0]=0 is a table convention.

phi[x] starts at x and multiplies by(1-1/p) for each distinct prime
divisor p.

phi(12)=12*(1-1/2)*(1-1/3)=4.

Inclusion-exclusion over distinct prime divisors counts residues coprime to x;
each prime is processed exactly once.

O(n log log(n+2)) time, O(n) storage.

Repeated prime factors must not be applied repeatedly.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>

std::vector<int> totients(int n) {
    std::vector<int> phi(n + 1);
    std::iota(phi.begin(), phi.end(), 0);
    for (int p = 2; p <= n; ++p) {
        if (phi[p] == p) {
            for (int x = p; x <= n; x += p) {
                phi[x] -= phi[x] / p;
            }
        }
    }
    return phi;
}

int main() {
    auto phi = totients(12);
    assert(phi[1] == 1 && phi[7] == 6 && phi[12] == 4 && phi[0] == 0);
    std::cout << "checks passed\n";
    return 0;
}
