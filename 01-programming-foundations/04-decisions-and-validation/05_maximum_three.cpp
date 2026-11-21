/*
MAINTAIN THE BEST CANDIDATE
Route: Core | Prerequisites: Units 01–03: values, expressions and bool.

Start with a real candidate; replace it only when a larger candidate is observed. After
each comparison it is best among values examined.

O(1) time and O(1) auxiliary space.

An else-if would skip c after updating b; independent checks are required here.
*/
#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    if (!(std::cin >> a >> b >> c)
        || !(a >= -1000 && a <= 1000 && b >= -1000 && b <= 1000 && c >= -1000 && c <= 1000)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    int best = a; // Start from input, not an arbitrary zero.
    if (b > best) {
        best = b;
    }
    if (c > best) {
        best = c;
    }
    std::cout << best << '\n';
}
