/*
RETURN A COMPUTED VALUE
Route: Core | Prerequisites: Units 01–06: decisions, loops and repeated input.

square receives a value, computes a result and returns it; main handles input and
output.

O(1) time/space.

A non-void function must return a value on every reachable path.
*/
#include <iostream>

int square(int x) { // int before the name is the return type.
    return x * x;
}

int main() {
    int x = 0;
    if (!(std::cin >> x) || !(x >= -1000 && x <= 1000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    std::cout << square(x) << "\n";
}
