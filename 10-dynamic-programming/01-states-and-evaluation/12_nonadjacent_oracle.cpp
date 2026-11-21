/*
 Oracle n<=8, values-1,0,1; empty selection allowed. Unless a different bound is
stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

The optimized prefix state is compared with every legal nonadjacent mask;
values-1,0,1 test empty and tie policies.

Mask 011 is rejected for adjacent choices; mask 101 can contribute first+third.

Masks independently enumerate every valid selection; matching values checks the
recurrence and compression on a finite domain.

Test reference O(n*2^n) per tiny input, plus all 3^n arrays; not a large-input solver.

Independent tests supplement, but do not replace, the take-or-skip proof.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

long long robRange(const std::vector<int>& a, std::size_t left, std::size_t right) {
    long long two = 0;
    long long one = 0;
    for (std::size_t i = left; i < right; ++i) {
        long long next = std::max(one, two + a[i]);
        two = one;
        one = next;
    }
    return one;
}

long long brute(const std::vector<int>& a) {
    long long best = 0;
    for (unsigned int mask = 0; mask < (1U << a.size()); ++mask) {
        if (mask & (mask << 1U)) {
            continue;
        }
        long long sum = 0;
        for (std::size_t i = 0; i < a.size(); ++i) {
            if (mask & (1U << i)) {
                sum += a[i];
            }
        }
        best = std::max(best, sum);
    }
    return best;
}

int main() {
    for (int n = 0; n <= 8; ++n) {
        int cases = 1;
        for (int i = 0; i < n; ++i) {
            cases *= 3;
        }
        for (int code = 0; code < cases; ++code) {
            int value = code;
            std::vector<int> a(static_cast<std::size_t>(n));
            for (int& x : a) {
                x = value % 3 - 1;
                value /= 3;
            }
            assert(robRange(a, 0, a.size()) == brute(a));
        }
    }
    std::cout << "checks passed\n";
    return 0;
}
