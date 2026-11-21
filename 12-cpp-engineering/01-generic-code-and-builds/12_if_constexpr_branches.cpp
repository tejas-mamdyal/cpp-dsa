/*
if constexpr selects from a compile-time condition. During template instantiation the discarded dependent branch is not instantiated, allowing different valid operations for different types. An ordinary if still requires both branches to be well formed.
*/
/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

if constexpr selects a branch from a compile-time condition; is_integral_v
is a standard type trait variable template.

For string, the to_string branch is discarded rather than instantiated.

Each supported type uses its valid conversion branch.

O(output length) time/storage.

This intentionally supports integral and std:: string types; an arbitrary custom type
still needs a conversion contract.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <type_traits>

template <typename T> std::string describe(const T& value) {
    if constexpr (std::is_integral_v<T>) {
        return std::to_string(value);
    } else {
        return value;
    }
}

int main() {
    assert(describe(42) == "42");
    assert(describe(std::string("text")) == "text");
    std::cout << "checks passed\n";
    return 0;
}
