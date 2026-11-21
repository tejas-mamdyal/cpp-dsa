/*
 Nonnegative amount<=100; positive descending denominations include 1.

IDEA AND STATE: Compare largest-coin-first with independent bounded count enumeration.

TRACE: Coins 4,3,1 at 6: greedy 4+1+1 uses 3, but 3+3 uses 2.

Largest-first on6 takes4,then1,then1;the alternative3+3 uses fewer coins and refutes the
universal rule.

Enumeration covers every coin count combination; US-style agreement over tested
amounts is finite evidence, not a universal canonicality proof.

Greedy O(d); teaching four-denomination enumeration O(amount^3), small inputs only.

Do not generalize a rule from a convenient currency.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int greedy(const std::vector<int>& coins, int amount) {
    int count = 0;
    for (int coin : coins) {
        count += amount / coin;
        amount %= coin;
    }
    assert(amount == 0);
    return count;
}

int enumerate(const std::vector<int>& c, int amount) {
    assert(c.size() == 4 && c.back() == 1);
    int best = amount;
    for (int a = 0; a * c[0] <= amount; ++a) {
        for (int b = 0; a * c[0] + b * c[1] <= amount; ++b) {
            for (int d = 0; a * c[0] + b * c[1] + d * c[2] <= amount; ++d) {
                int rest = amount - a * c[0] - b * c[1] - d * c[2];
                best = std::min(best, a + b + d + rest);
            }
        }
    }
    return best;
}

int main() {
    assert(greedy({4, 3, 1}, 6) == 3);
    assert(3 + 3 == 6);
    for (int amount = 0; amount <= 100; ++amount) {
        assert(greedy({25, 10, 5, 1}, amount) == enumerate({25, 10, 5, 1}, amount));
    }
    std::cout << "checks passed\n";
    return 0;
}
