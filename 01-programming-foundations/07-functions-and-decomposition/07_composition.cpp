/*
COMPOSE FUNCTIONS WITH CLEAR RESPONSIBILITIES
Route: Core | Prerequisites: Units 01–06: decisions, loops and repeated input.

digitSum computes a number; isEven classifies it. Their composition expresses a new task
without duplicating either algorithm.

O(d) time/O(1) space for d digits.

Separate returned values from side effects; neither helper should read input.
*/
#include <iostream>

int digitSum(int n) {
    int sum = 0;
    do {
        sum += n % 10;
        n /= 10;
    } while (n);
    return sum;
}

bool isEven(int n) {
    return n % 2 == 0;
}

int main() {
    int n = 0;
    if (!(std::cin >> n) || !(n >= 0 && n <= 1000000000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    std::cout << isEven(digitSum(n)) << "\n";
}
