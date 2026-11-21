/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

A concrete overload and a template instantiation compete in overload
resolution.

String chooses the equally good non-template; explicit template syntax selects the
template.

The selected overload is determined statically from argument types.

O(1) runtime.

A string literal is an array type, not already a std:: string.
*/
#include <iostream>
#include <cassert>
#include <string>

template <typename T> int category(const T&) {
    return 1;
}

int category(const std::string&) {
    return 2;
}

int main() {
    assert(category(7) == 1);
    std::string s = "x";
    assert(category(s) == 2);
    assert(category<std::string>(s) == 1);
    std::cout << "checks passed\n";
    return 0;
}
