/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

T is replaced by the deduced argument type before compilation of an
instantiation.

Two int arguments instantiate int swap; two strings instantiate string swap.

The temporary retains the first value while assignments exchange the two
originals.

Three copies; cost depends on T, not necessarily constant.

Both arguments must have the same deduced T and support copying/assignment.
*/
#include <iostream>
#include <cassert>
#include <string>

template <typename T> void mySwap(T& a, T& b) {
    T saved = a;
    a = b;
    b = saved;
}

int main() {
    int a = 5;
    int b = 10;
    mySwap(a, b);
    assert(a == 10 && b == 5);
    std::string x = "Hello";
    std::string y = "World";
    mySwap(x, y);
    assert(x == "World" && y == "Hello");
    std::cout << "checks passed\n";
    return 0;
}
