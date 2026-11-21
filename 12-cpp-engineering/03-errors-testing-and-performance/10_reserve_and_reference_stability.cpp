/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

Reserve ensures enough capacity for the known insertion count without
promising exact capacity.

Ten appends after reserve 10 fit without reallocation.

No capacity growth is needed until the requested size would exceed capacity.

O(n) construction/storage.

reserve changes capacity, not size; indexing unconstructed elements is invalid.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstddef>

std::vector<int> prepared(int n) {
    std::vector<int> a;
    a.reserve(static_cast<std::size_t>(n));
    for (int i = 0; i < n; ++i) {
        a.push_back(i);
    }
    return a;
}

int main() {
    auto a = prepared(10);
    assert(a.size() == 10 && a.capacity() >= 10);
    int* first = &a[0];
    a[0] = 99;
    assert(*first == 99);
    assert(prepared(0).empty());
    std::cout << "checks passed\n";
    return 0;
}
