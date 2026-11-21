/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

Qualified names identify which namespace supplies an operation.

combine(2,5) means sum in counts and maximum in scores.

Name lookup resolves each fully qualified function without ambiguity.

O(1) time/storage.

Avoid using-directives in public headers; they affect includers unexpectedly.
*/
#include <iostream>
#include <cassert>
#include <algorithm>

namespace counts {
int combine(int a, int b) {
    return a + b;
}
} // namespace counts

namespace scores {
int combine(int a, int b) {
    return std::max(a, b);
}
} // namespace scores

int main() {
    assert(counts::combine(2, 5) == 7 && scores::combine(2, 5) == 5);
    std::cout << "checks passed\n";
    return 0;
}
