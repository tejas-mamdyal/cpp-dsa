/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

operator+= mutates this and returns an lvalue reference; operator+
receives a copy.

a 2+b 3 returns 5 while a remains 2.

The copied left operand isolates nonmutating addition from original state.

O(1) for bounded integer totals.

Return a reference from += to support chaining; return a value from + to avoid
dangling.
*/
#include <iostream>
#include <cassert>

struct Count {
    int value;

    Count& operator+=(Count b) {
        value += b.value;
        return *this;
    }
};

Count operator+(Count a, Count b) {
    a += b;
    return a;
}

int main() {
    Count a{2};
    Count b{3};
    Count sum = a + b;
    assert(sum.value == 5 && a.value == 2);
    (a += b) += Count{1};
    assert(a.value == 6);
    std::cout << "checks passed\n";
    return 0;
}
