/*
A VARIABLE REMEMBERS A VALUE
Route: Core | Prerequisites: None; read 00-start-here first.

int declares a whole-number type; score is its name; =7 initializes its value. Later
expressions can read it.

O(1) time/space.

An uninitialized built-in local variable must not be read.
*/
#include <iostream>

int main() {
    int score = 7;              // Declaration and initialization happen together.
    std::cout << score << '\n'; // Read the stored value.
}
