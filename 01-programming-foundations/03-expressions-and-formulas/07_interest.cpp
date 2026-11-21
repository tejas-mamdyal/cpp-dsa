/*
TRANSLATE A PERCENTAGE FORMULA
Route: Core | Prerequisites: Units 01–02: streams, types and conversions.

Simple interest is principal*rate*years/100; it does not compound each year.

O(1) time and O(1) auxiliary space for bounded scalar input.

Five percent means 5/100, not 5 times the principal.
*/
#include <iostream>
#include <iomanip>

int main() {
    double principal = 0;
    double rate = 0;
    double years = 0;
    std::cin >> principal >> rate >> years;
    std::cout << std::fixed << std::setprecision(2) << principal * rate * years / 100.0 << '\n';
}
