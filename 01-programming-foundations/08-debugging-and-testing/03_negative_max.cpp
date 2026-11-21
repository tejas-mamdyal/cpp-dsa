/*
AVOID AN IMAGINARY CANDIDATE
Route: Core | Prerequisites: Units 01–07; functions and input validation.

Initialize the candidate from actual data, not zero, because zero may not occur.

O(1) time and O(1) auxiliary space.

Positive-only examples conceal this defect.
*/
#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    if (!(std::cin >> a >> b >> c)
        || !(a >= -100 && a <= 100 && b >= -100 && b <= 100 && c >= -100 && c <= 100)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    int best = a;
    if (b > best) {
        best = b;
    }
    if (c > best) {
        best = c;
    }
    std::cout << best << '\n';
}
