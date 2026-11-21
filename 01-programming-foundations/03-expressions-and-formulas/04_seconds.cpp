/*
DECOMPOSE A DURATION
Route: Core | Prerequisites: Units 01–02: streams, types and conversions.

Divide by 3600 for hours; remove those hours with %3600, then split the remaining
minutes and seconds.

O(1) time and O(1) auxiliary space for bounded scalar input.

Use total%3600 before dividing minutes, or hours are counted twice.
*/
#include <iostream>

int main() {
    int total = 0;
    std::cin >> total;
    int hours = total / 3600;
    int minutes = (total % 3600) / 60;
    int seconds = total % 60;
    std::cout << hours << ' ' << minutes << ' ' << seconds << '\n';
}
