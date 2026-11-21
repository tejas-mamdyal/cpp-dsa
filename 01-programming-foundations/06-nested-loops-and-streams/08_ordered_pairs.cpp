/*
ENUMERATE A CARTESIAN PRODUCT
Route: Core | Prerequisites: Unit 05: loops and accumulators.

For each first choice enumerate every second choice. Order matters, so (1,2) differs
from (2,1).

O(n^2) time/O(1) space.

Do not confuse ordered pairs with pairs where a<b.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 5)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= n; ++b) {
            std::cout << a << ' ' << b << '\n';
        }
    }
}
