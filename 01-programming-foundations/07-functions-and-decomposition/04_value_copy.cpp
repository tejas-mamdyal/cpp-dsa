/*
PASSING BY VALUE DOES NOT UPDATE THE CALLER
Route: Core | Prerequisites: Units 01–06: decisions, loops and repeated input.

increment has its own local parameter. Returning its updated value does not assign
anything to the caller variable.

O(1) time/space.

If the caller wants to change n, it can explicitly write n=increment(n).
*/
#include <iostream>

int increment(int value) {
    ++value; // Changes the local copy only.
    return value;
}

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= -100 && n <= 100)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    std::cout << increment(n) << ' ' << n << "\n";
}
