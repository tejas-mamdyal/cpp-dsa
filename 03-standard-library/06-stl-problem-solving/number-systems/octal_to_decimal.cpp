/*
Parse a nonnegative base-8 integer without floating-point powers.
Prerequisites: loops, characters, strings, conditionals. Process left to right:
value = value*base + digit. Invariant: value equals the prefix consumed so far.
Example base 16: "1F" -> 1 -> 1*16+15=31. A..F and a..f mean 10..15.
Reject digits outside the base. Before multiplying, require
value <= (maximum-digit)/base; otherwise the next step would overflow.
Using string avoids overflowing a fixed-size input buffer. Leading zeros are legal;
signs and 0x prefixes are deliberately unsupported. O(L) time/O(L) input storage.
Exercise: accept a chosen base in [2,16] and verify conversion round trips.
*/
#include <iostream>
#include <limits>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter a base-8 nonnegative integer: ";
    if (!(std::cin >> input)) {
        std::cerr << "Expected a number.\n";
        return 1;
    }
    unsigned long long value = 0;
    for (char c : input) {
        int digit = -1;
        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            digit = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
        }
        if (digit < 0 || digit >= 8) {
            std::cerr << "Invalid digit.\n";
            return 1;
        }
        if (value > (std::numeric_limits<unsigned long long>::max() - digit) / 8) {
            std::cerr << "Number too large.\n";
            return 1;
        }
        value = value * 8 + digit; // Append one positional digit.
    }
    std::cout << "Decimal: " << value << '\n';
}
