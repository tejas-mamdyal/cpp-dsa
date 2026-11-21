/*
AN ELSE-IF CHAIN CLASSIFIES VALUES
Route: Core | Prerequisites: Units 01–03: values, expressions and bool.

The three sign categories are mutually exclusive and cover the whole accepted domain.

O(1) time and O(1) auxiliary space.

Several independent if statements are not always interchangeable with a chain.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= -1000 && n <= 1000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    if (n < 0) {
        std::cout << "negative\n";
    } else if (n == 0) {
        std::cout << "zero\n";
    } else {
        std::cout << "positive\n";
    }
}
