/*
Circle area/circumference: a distinct formula application. Input finite radius0..1e6.
Output area then circumference to two decimals. Invalid input -> error/exit1.
pi is a named constant; A=pi*r*r, C=2*pi*r. Radius1 gives3.14 and6.28;
radius0 gives0.00 twice. O(1) time/space. Exercise: explain square vs linear units.
*/
#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    double radius = 0;
    if (!(std::cin >> radius) || !std::isfinite(radius) || radius < 0 || radius > 1000000) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    const double pi = 3.141592653589793;
    std::cout << std::fixed << std::setprecision(2) << pi * radius * radius << '\n'
              << 2 * pi * radius << '\n';
}
