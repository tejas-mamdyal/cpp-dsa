/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

reference_wrapper is copyable observation of an existing object, not
ownership.

A vector of wrappers still changes the original a and b.

Each wrapper converts to an lvalue reference to its target.

O(n) time, O(n) wrapper argument storage.

Targets must outlive all wrapper use; wrappers do not prevent dangling.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <functional>

void increment(std::vector<std::reference_wrapper<int>> values) {
    for (int& x : values) {
        ++x;
    }
}

int main() {
    int a = 1;
    int b = 4;
    increment({std::ref(a), std::ref(b)});
    assert(a == 2 && b == 5);
    std::cout << "checks passed\n";
    return 0;
}
