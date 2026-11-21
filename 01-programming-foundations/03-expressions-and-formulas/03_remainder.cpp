/*
QUOTIENT AND REMAINDER PARTITION A COUNT
Route: Core | Prerequisites: Units 01–02: streams, types and conversions.

Division counts complete groups; remainder counts elements not in complete groups.

O(1) time and O(1) auxiliary space for bounded scalar input.

Remainder is not a fractional part; it has the unit of the dividend.
*/
#include <iostream>

int main() {
    int items = 0;
    int capacity = 1;
    std::cin >> items >> capacity;
    std::cout << items / capacity << ' ' << items % capacity << '\n';
}
