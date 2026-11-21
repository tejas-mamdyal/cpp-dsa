/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

An unnamed namespace gives the helper internal linkage.

Another source may have its own normalize without an external-symbol collision.

Only the public wrapper is part of the intended external interface.

O(1) time/storage.

Putting unrelated stateful helpers in headers can create one independent state per
translation unit.
*/
#include <iostream>
#include <cassert>
#include <algorithm>

namespace {
int normalize(int x) {
    return std::max(0, x);
}
} // namespace

int publicScore(int x) {
    return normalize(x) + 1;
}

int main() {
    assert(publicScore(-5) == 1 && publicScore(3) == 4);
    std::cout << "checks passed\n";
    return 0;
}
