/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

N is a value template parameter known at compile time.

Fixed<int,3> and Fixed<int,4> are different types.

Value initialization zero-initializes the int elements; array fixes the extent.

O(N) initialization/storage.

Runtime input cannot be used as this template argument.
*/
#include <iostream>
#include <cassert>
#include <array>
#include <cstddef>

template <typename T, std::size_t N> struct Fixed {
    std::array<T, N> values{};

    constexpr std::size_t size() const {
        return N;
    }
};

int main() {
    Fixed<int, 3> a;
    a.values[1] = 9;
    assert(a.size() == 3 && a.values[0] == 0 && a.values[1] == 9);
    Fixed<int, 0> empty;
    assert(empty.size() == 0);
    std::cout << "checks passed\n";
    return 0;
}
