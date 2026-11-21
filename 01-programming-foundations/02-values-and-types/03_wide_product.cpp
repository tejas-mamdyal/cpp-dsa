/*
MULTIPLY IN A SUFFICIENTLY WIDE TYPE
Route: Core | Prerequisites: Unit 01: statements, variables and streams.

1LL makes the first multiplication use long long, before any int overflow could occur.

O(1) time and O(1) auxiliary space for these bounded examples.

Assigning an already overflowing int product to long long is too late.
*/
#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    long long product = 1LL * a * b; // Widen before multiplying.
    std::cout << product << "\n";
}
