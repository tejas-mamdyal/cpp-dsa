/*
PRESERVE A VALUE BEFORE OVERWRITING IT
Route: Reinforcement | Prerequisites: None; read 00-start-here first.

A temporary storage location saves the original first value while it is overwritten.
Each assignment has one precise effect.

O(1) time/space.

a=b followed by b=a loses the original a; both become the old b.
*/
#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    int saved = a; // Save before replacing a.
    a = b;
    b = saved;
    std::cout << a << ' ' << b << '\n';
}
