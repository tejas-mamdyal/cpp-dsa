/*
AVERAGE WITHOUT INTEGER TRUNCATION
Route: Core | Prerequisites: Units 01–02: streams, types and conversions.

The sum is exact here; dividing by 3.0 yields a floating-point result.

O(1) time and O(1) auxiliary space for bounded scalar input.

Dividing by integer 3 loses the fraction before output formatting.
*/
#include <iostream>
#include <iomanip>

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    std::cin >> a >> b >> c;
    double mean = (a + b + c) / 3.0;
    std::cout << std::fixed << std::setprecision(2) << mean << '\n';
}
