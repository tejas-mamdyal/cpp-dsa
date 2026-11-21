/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

The return value owns the result or represents absence.

The factory creates 4; moving a into b leaves a empty.

unique_ptr destruction releases its resource on every scope-exit path.

O(1) allocation/storage.

Use std:: move to transfer an existing unique_ptr; copying it is intentionally
forbidden.
*/
#include <iostream>
#include <cassert>
#include <utility>
#include <memory>

std::unique_ptr<int> makePositive(int x) {
    if (x <= 0) {
        return nullptr;
    }
    return std::make_unique<int>(x);
}

int main() {
    auto a = makePositive(4);
    assert(a && *a == 4);
    assert(!makePositive(0));
    auto b = std::move(a);
    assert(!a && *b == 4);
    std::cout << "checks passed\n";
    return 0;
}
