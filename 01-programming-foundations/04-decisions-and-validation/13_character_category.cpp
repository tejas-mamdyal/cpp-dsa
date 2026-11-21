/*
CHARACTER COMPARISONS AND LOGICAL RANGES
Route: Reinforcement | Prerequisites: Units 01–03: values, expressions and bool.

Within ASCII, digit and letter ranges are contiguous; combine uppercase and lowercase
ranges with ||.

O(1) time and O(1) auxiliary space.

This lesson assumes ASCII-compatible input, not general Unicode classification.
*/
#include <iostream>

int main() {
    char c = '?';
    if (!(std::cin >> c) || !(true)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    if (c >= '0' && c <= '9') {
        std::cout << "digit\n";
    } else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        std::cout << "letter\n";
    } else {
        std::cout << "other\n";
    }
}
