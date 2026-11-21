/*
Expression calculator using a class: an object-oriented variation of Phase1.
Read expressions such as 2 + 3 until EOF. Finite operands must be in [-1e6,1e6].
Reject unknown operators, missing operands and division by zero with error/exit1.
EOF between expressions ends normally; no command quota is needed. The class computes;
main validates and handles streams. O(k) time/O(1) space for k expressions.
Exercise: add an explicit quit command. Example 2+3 then8/2 prints5 then4.
*/
#include <cmath>
#include <iostream>

class Calculator {
public:
    double calculate(double x, char operation, double y) const {
        switch (operation) {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            default:
                return x / y; // Validated nonzero divisor.
        }
    }
};

int main() {
    Calculator calculator;
    while (true) {
        std::cin >> std::ws;
        if (std::cin.eof()) {
            return 0;
        }
        double x = 0;
        double y = 0;
        char operation = '?';
        if (!(std::cin >> x >> operation >> y) || !std::isfinite(x) || !std::isfinite(y)
            || x < -1000000 || x > 1000000 || y < -1000000 || y > 1000000
            || (operation != '+' && operation != '-' && operation != '*' && operation != '/')
            || (operation == '/' && y == 0)) {
            std::cerr << "Invalid input\n";
            return 1;
        }
        std::cout << calculator.calculate(x, operation, y) << '\n';
    }
}
