/*
CHARGE ONLY THE EXCESS AT THE NEXT RATE
Route: Reinforcement | Prerequisites: Units 01–03: values, expressions and bool.

For units>100, preserve the fixed first-band charge and add the price of only units-100
excess units.

O(1) time and O(1) auxiliary space.

Charging every unit at the higher rate creates an incorrect jump.
*/
#include <iostream>

int main() {
    int units = 0;
    if (!(std::cin >> units) || !(units >= 0 && units <= 10000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    int bill = 0;
    if (units <= 100) {
        bill = units * 2;
    } else {
        bill = 200 + (units - 100) * 3;
    }
    std::cout << bill << '\n';
}
