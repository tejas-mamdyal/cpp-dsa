/*
READ AND COMBINE TWO VALUES
Route: Reinforcement | Prerequisites: None; read 00-start-here first.

Chained extraction reads left to right. Both values are stored before the sum expression
is evaluated.

O(1) time/space.

A newline and a space both separate numeric input; punctuation such as a comma does not.
*/
#include <iostream>

int main() {
    // Two independent storage locations.
    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
}
