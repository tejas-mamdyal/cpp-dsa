/*
LOCAL STATE IS FRESH ON EACH CALL
Route: Reinforcement | Prerequisites: Units 01–06: decisions, loops and repeated input.

Each call creates its own automatic local variable; the previous call does not persist
its state.

O(1) time/space.

A local variable is not an accumulating global variable.
*/
#include <iostream>

int nextValue(int input) {
    int local = input;
    ++local;
    return local;
}

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 100)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    std::cout << nextValue(n) << ' ' << nextValue(n) << "\n";
}
