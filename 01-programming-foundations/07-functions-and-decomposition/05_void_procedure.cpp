/*
A PROCEDURE PERFORMS AN ACTION
Route: Core | Prerequisites: Units 01–06: decisions, loops and repeated input.

void indicates there is no returned value. This function intentionally owns a small
output task.

O(count) time/O(1) space.

A void call cannot be used as a numeric result.
*/
#include <iostream>

void printRule(int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << '-';
    }
    std::cout << '\n';
}

int main() {
    int count = 0;
    if (!(std::cin >> count) || !(count >= 0 && count <= 10)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    printRule(count);
}
