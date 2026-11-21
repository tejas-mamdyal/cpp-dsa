/*
ORDER OVERLAPPING THRESHOLDS
Route: Core | Prerequisites: Units 01–03: values, expressions and bool.

Descending thresholds make the first satisfied threshold the correct grade; lower checks
are needed only after higher ones failed.

O(1) time and O(1) auxiliary space.

Putting >=40 first would classify almost every passing mark as D.
*/
#include <iostream>

int main() {
    int mark = 0;
    if (!(std::cin >> mark) || !(mark >= 0 && mark <= 100)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    if (mark >= 90) {
        std::cout << "A\n";
    } else if (mark >= 75) {
        std::cout << "B\n";
    } else if (mark >= 60) {
        std::cout << "C\n";
    } else if (mark >= 40) {
        std::cout << "D\n";
    } else {
        std::cout << "F\n";
    }
}
