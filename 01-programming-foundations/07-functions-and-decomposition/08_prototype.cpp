/*
DECLARE A FUNCTION BEFORE ITS USE
Route: Core | Prerequisites: Units 01–06: decisions, loops and repeated input.

A declaration tells the compiler the interface before the body is encountered. The
linker still needs a definition.

O(1) time/space.

A declaration alone promises a definition; it does not implement the function.
*/
#include <iostream>

int twice(int value); // Declaration: no body yet.
// The definition appears after main; the declaration is enough to check the call.

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 100)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    std::cout << twice(n) << "\n";
}

int twice(int value) {
    return 2 * value;
} // Definition fulfills the earlier promise.
