/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

The forward declaration establishes the callable signature; the later body
defines behavior.

twiceDifference compiles before the called body because its declaration is
visible.

The linker ultimately sees exactly one definition in this example.

O(1) time/storage for bounded inputs.

A declaration alone cannot supply a missing definition at link time.
*/
#include <iostream>
#include <cassert>
#include <cstdlib>

int absoluteDifference(int a, int b);

int twiceDifference(int a, int b) {
    return 2 * absoluteDifference(a, b);
}

int absoluteDifference(int a, int b) {
    return std::abs(a - b);
}

int main() {
    assert(twiceDifference(3, 8) == 10 && absoluteDifference(8, 3) == 5);
    std::cout << "checks passed\n";
    return 0;
}
