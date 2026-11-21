/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

inline permits identical definitions in multiple translation units; it is
not a guarantee of machine-code inlining.

A header with this body can be included by both project source files.

Clamping preserves values inside the closed range and selects the nearest
boundary outside.

O(1) time/storage.

All definitions of the inline entity must agree; an include guard alone does not
grant this permission.
*/
#include <iostream>
#include <cassert>
#include <algorithm>

inline int clampScore(int x) {
    return std::min(100, std::max(0, x));
}

int main() {
    assert(clampScore(-1) == 0 && clampScore(40) == 40 && clampScore(101) == 100);
    std::cout << "checks passed\n";
    return 0;
}
