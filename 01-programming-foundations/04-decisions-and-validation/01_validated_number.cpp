/*
VALIDATE BEFORE PROCESSING
Route: Core | Prerequisites: Units 01–03: values, expressions and bool.

Reject failed extraction or an out-of-range value before normal processing. Valid input
reaches the final output.

O(1) time and O(1) auxiliary space.

Do not use a value after failed extraction or silently replace it with its initializer.
*/
#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 100)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    std::cout << n << "\n";
}
