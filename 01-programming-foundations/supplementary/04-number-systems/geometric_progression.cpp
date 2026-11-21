/*
A geometric progression multiplies each term by a fixed ratio. This lesson accepts
positive first/end values and an integer ratio >=2, so terms strictly increase.
Ratio 0 or 1 would not progress toward a larger endpoint; negatives need a
different stopping rule. Example 2,20,3 -> 2,6,18.
Before multiplying, term>last/ratio means the next term exceeds the bound; stop
without forming a potentially overflowing product. O(log_ratio(last/first)+1)
time/O(1) space. Exercise: define a finite term-count version for negative ratios.
*/
#include <iostream>

int main() {
    long long first = 0;
    long long last = 0;
    long long ratio = 0;
    std::cout << "Enter positive first, last bound, and ratio >=2: ";
    if (!(std::cin >> first >> last >> ratio) || first <= 0 || last < first || ratio < 2) {
        return 1;
    }
    for (long long term = first;;) {
        std::cout << term << '\n';
        if (term > last / ratio) {
            break;
        }
        term *= ratio;
    }
}
