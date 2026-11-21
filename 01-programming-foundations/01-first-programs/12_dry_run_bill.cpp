/*
A COMPLETE INPUT-PROCESS-OUTPUT ALGORITHM
Route: Reinforcement | Prerequisites: None; read 00-start-here first.

An algorithm names inputs, a transformation and outputs. Separating the total variable
makes the intermediate state easy to trace.

O(1) time/space.

The stated integer price model uses whole currency units; fractional prices need a
different representation.
*/
#include <iostream>

int main() {
    int price = 0;
    int quantity = 0;
    std::cin >> price >> quantity;
    int total = price * quantity; // Processing step.
    std::cout << total << '\n';   // Output step.
}
