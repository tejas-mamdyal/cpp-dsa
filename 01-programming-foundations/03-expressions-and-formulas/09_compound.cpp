/*
COMPOUND ASSIGNMENT UPDATES A BALANCE
Route: Reinforcement | Prerequisites: Units 01–02: streams, types and conversions.

x+=y means x=x+y; x-=y subtracts from the current state.

O(1) time and O(1) auxiliary space for bounded scalar input.

Updates happen sequentially and do not modify the input operands.
*/
#include <iostream>

int main() {
    int balance = 0;
    int deposit = 0;
    int withdrawal = 0;
    std::cin >> balance >> deposit >> withdrawal;
    balance += deposit;    // First transaction.
    balance -= withdrawal; // Uses the updated balance.
    std::cout << balance << '\n';
}
