/*
PROJECT 1 — MENU-DRIVEN CALCULATOR
Prerequisites: all Phase 1 units. Goal: combine functions, decisions and repetition.
Input: repeated commands: 1 a b (add), 2 a b (subtract), 3 a b (multiply),
4 a b (divide), or 0 (quit). Operands are finite doubles in [-1000000,1000000].
Print one result per command with two decimals; division by zero prints undefined.
Malformed input, unknown command, missing quit or out-of-range operands: stderr
Invalid input and exit 1. Quit exits 0. Commands continue until quit; there is no unrelated command quota.

Trace: 1 2 3 ->5.00; 4 8 0 ->undefined; 0 ->exit. Main controls the menu;
calculate computes one valid operation. Validation establishes its preconditions.
std::isfinite (cmath) rejects infinities and NaN; comparisons alone miss NaN.
Fixed formatting changes display, not the precision of arithmetic.
O(k) time for k commands, O(1) space; all arithmetic here is bounded.
Test normal operations, every invalid command, zero divisors, EOF and bounds.
Follow-ups: add a percentage operation; add memory storage without global variables.
*/
#include <cmath>
#include <iomanip>
#include <iostream>

double calculate(int choice, double a, double b) {
    switch (choice) {
        case 1:
            return a + b;
        case 2:
            return a - b;
        case 3:
            return a * b;
        default:
            return a / b; // Caller has established choice=4 and b!=0.
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(2);
    while (true) {
        int choice = -1;
        if (!(std::cin >> choice)) {
            std::cerr << "Invalid input\n";
            return 1;
        }
        if (choice == 0) {
            return 0; // Quit takes no operands.
        }
        double a = 0;
        double b = 0;
        if (choice < 1 || choice > 4 || !(std::cin >> a >> b) || !std::isfinite(a)
            || !std::isfinite(b) || a < -1000000 || a > 1000000 || b < -1000000 || b > 1000000) {
            std::cerr << "Invalid input\n";
            return 1;
        }
        if (choice == 4 && b == 0) {
            std::cout << "undefined\n";
        } else {
            std::cout << calculate(choice, a, b) << '\n';
        }
    }
}
