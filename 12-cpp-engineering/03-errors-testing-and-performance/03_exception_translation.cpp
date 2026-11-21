/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

The boundary converts implementation-specific parse exceptions into a
documented application error.

-2 parses but violates positivity and is translated.

All failures from parse/domain checks leave no partial application state.

O(text length) time/storage.

Broad translation can hide details; preserve more context in larger applications if
needed.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <cstddef>
#include <stdexcept>

int positive(const std::string& text) {
    try {
        std::size_t used = 0;
        int value = std::stoi(text, &used);
        if (used != text.size() || value <= 0) {
            throw std::invalid_argument("domain");
        }
        return value;
    } catch (const std::exception&) {
        throw std::runtime_error("positive integer required");
    }
}

int main() {
    assert(positive("12") == 12);
    bool failed = false;
    try {
        positive("-2");
    } catch (const std::runtime_error& e) {
        failed = std::string(e.what()) == "positive integer required";
    }
    assert(failed);
    std::cout << "checks passed\n";
    return 0;
}
