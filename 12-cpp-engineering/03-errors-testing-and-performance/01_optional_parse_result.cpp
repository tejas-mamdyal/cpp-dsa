/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

An optional contains a parsed int exactly when the complete
whitespace-trimmed input is valid.

12x parses a prefix but leaves x, so it is rejected.

Extraction range-checks int; the extra-character probe rejects trailing nonspace
text.

O(text length) time, O(text length) stream storage.

Zero is valid data and cannot double as a failure sentinel.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <optional>
#include <sstream>

std::optional<int> parse(const std::string& text) {
    std::istringstream input(text);
    int value;
    char extra;
    if (!(input >> value) || (input >> extra)) {
        return std::nullopt;
    }
    return value;
}

int main() {
    assert(parse(" -12 ") == -12 && parse("0") == 0);
    assert(!parse("12x") && !parse("") && !parse("999999999999999999999"));
    std::cout << "checks passed\n";
    return 0;
}
