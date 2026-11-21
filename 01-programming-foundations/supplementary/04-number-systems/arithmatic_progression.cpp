/*
An arithmetic progression adds a constant difference each step. Here print terms
from first toward last, inclusive if reached exactly; either direction is allowed.
Reject zero difference and a direction that moves away from the endpoint.
Example 2,8,3 -> 2,5,8. Bounded inputs ensure the update cannot overflow.
Invariant: term = first + index*difference. O(number of terms) time/O(1) space.
Exercise: use a term count instead of an endpoint and derive the sum formula.
*/
#include <iostream>

int main() {
    long long first = 0;
    long long last = 0;
    long long d = 0;
    std::cout << "Enter first term, last bound and nonzero difference: ";
    if (!(std::cin >> first >> last >> d) || first < -1000000 || first > 1000000 || last < -1000000
        || last > 1000000 || d < -1000000 || d > 1000000 || d == 0 || (first < last && d < 0)
        || (first > last && d > 0)) {
        return 1;
    }
    if (d > 0) {
        for (long long term = first; term <= last; term += d) {
            std::cout << term << '\n';
        }
    } else {
        for (long long term = first; term >= last; term += d) {
            std::cout << term << '\n';
        }
    }
}
