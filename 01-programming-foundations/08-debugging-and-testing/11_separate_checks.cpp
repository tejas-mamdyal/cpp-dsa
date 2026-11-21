/*
INDEPENDENT UPDATES NEED INDEPENDENT CONDITIONS
Route: Reinforcement | Prerequisites: Units 01–07; functions and input validation.

Compare every candidate even if an earlier comparison already changed the current
minimum.

O(1) time and O(1) auxiliary space.

A mutually exclusive chain is wrong when both updates may be required.
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
    if (b < best) {
        best = b;
    }
    if (c < best) {
        best = c;
    }
    std::cout << best << '\n';
}
