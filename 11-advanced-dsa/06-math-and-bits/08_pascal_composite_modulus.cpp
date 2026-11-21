/*
 0<=n<=1000; integer r;1<=modulus<=1000000007.

row[j] counts selections of j from the elements processed so far.

C(5,2)=10 reduces to 4 modulo 6 despite noninvertible factorials.

Partition subsets by whether they contain the newest element; descending j
preserves the previous row.

O(n*r) time, O(r) storage.

Ascending updates would reuse the newest element more than once.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

long long choose(int n, int r, long long modulus) {
    if (r < 0 || r > n) {
        return 0;
    }
    std::vector<long long> row(r + 1);
    row[0] = 1 % modulus;
    for (int i = 1; i <= n; ++i) {
        for (int j = std::min(i, r); j >= 1; --j) {
            row[j] = (row[j] + row[j - 1]) % modulus;
        }
    }
    return row[r];
}

int main() {
    assert(choose(5, 2, 6) == 4 && choose(0, 0, 1) == 0 && choose(7, 3, 10) == 5);
    std::cout << "checks passed\n";
    return 0;
}
