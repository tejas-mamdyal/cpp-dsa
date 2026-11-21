/*
INSTRUCTIONS UPDATE STATE
Route: Core | Prerequisites: None; read 00-start-here first.

Assignment replaces a stored value. In points=points+3, the old value is read before the
new value is stored.

O(1) time/space.

In C++, = means assignment, not mathematical equality.
*/
#include <iostream>

int main() {
    int points = 4;
    std::cout << points << '\n';
    points = points + 3; // The right-hand expression uses the previous state.
    std::cout << points << '\n';
}
