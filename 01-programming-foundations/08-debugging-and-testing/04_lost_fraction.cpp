/*
CONVERT BEFORE DIVISION
Route: Core | Prerequisites: Units 01–07; functions and input validation.

Converting a before / selects real division; converting the already-truncated quotient
cannot recover the fraction.

O(1) time and O(1) auxiliary space.

A double destination alone does not change integer operand division.
*/
#include <iostream>
#include <iomanip>

int main() {
    int a = 0;
    int b = 0;
    if (!(std::cin >> a >> b) || !(a >= 1 && a <= 100 && b >= 1 && b <= 100)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    double quotient = static_cast<double>(a) / b;
    std::cout << std::fixed << std::setprecision(2) << quotient << '\n';
}
