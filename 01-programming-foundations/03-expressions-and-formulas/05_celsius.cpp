/*
REAL-VALUED UNIT CONVERSION
Route: Core | Prerequisites: Units 01–02: streams, types and conversions.

F=C*9/5+32; a floating operand avoids an unintended integer approximation of 9/5.

O(1) time and O(1) auxiliary space for bounded scalar input.

Writing C*(9/5) with integer 9 and 5 multiplies by 1.
*/
#include <iostream>
#include <iomanip>

int main() {
    double c = 0;
    std::cin >> c;
    double fahrenheit = c * 9.0 / 5.0 + 32;
    std::cout << std::fixed << std::setprecision(2) << fahrenheit << '\n';
}
