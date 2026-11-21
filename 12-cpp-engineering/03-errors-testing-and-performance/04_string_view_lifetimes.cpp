/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

string_view stores pointer and length without copying characters.

Changing the existing first character is visible through the view.

substr narrows the same valid storage range without changing ownership.

O(n) delimiter search, O(1) view storage.

Returning a view into a local temporary string dangles; reallocation of storage also
invalidates views.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <string_view>

std::string_view firstWord(std::string_view text) {
    return text.substr(0, text.find(' '));
}

int main() {
    std::string storage = "alpha beta";
    auto view = firstWord(storage);
    assert(view == "alpha");
    storage[0] = 'A';
    assert(view == "Alpha");
    assert(firstWord("").empty());
    std::cout << "checks passed\n";
    return 0;
}
