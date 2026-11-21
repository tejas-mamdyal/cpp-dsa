/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

constexpr allows compile-time evaluation when arguments permit;
static_assert requires a constant true condition.

square(4) is evaluated for static_assert; runtime value 7 is also legal.

Multiplication implements square within the bounded domain.

O(1) time/storage.

constexpr functions can also run at runtime; it does not make runtime data constant.
*/
#include <iostream>
#include <cassert>

constexpr int square(int x) {
    return x * x;
}

static_assert(square(4) == 16, "compile-time square failed");
static_assert(sizeof(long long) >= 8, "requires at least64 bits");

int main() {
    int value = 7;
    assert(square(value) == 49);
    std::cout << "checks passed\n";
    return 0;
}
