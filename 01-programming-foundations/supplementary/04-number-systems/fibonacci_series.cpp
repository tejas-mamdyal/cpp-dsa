/*
Fibonacci begins F0=0,F1=1; Fn=F(n-1)+F(n-2). Before each iteration, a=Fi,
b=F(i+1). Save a+b before overwriting either operand, then shift the pair.
Print n terms, where 0<=n<=93. F92 fits signed long long; F93 does not, so the
last iteration prints without computing an unused next value.
O(n) time/O(1) extra space. Exercise: contrast this with exponential recursion.
*/
#include <iostream>

int main() {
    int n = 0;
    std::cout << "Number of terms (0..93): ";
    if (!(std::cin >> n) || n < 0 || n > 93) {
        return 1;
    }
    long long a = 0;
    long long b = 1;
    for (int i = 0; i < n; ++i) {
        std::cout << a << '\n';
        if (i == n - 1) {
            break;
        }
        // At the step producing F92, no F93 is needed.
        if (i == 91) {
            a = b;
            continue;
        }
        long long next = a + b;
        a = b;
        b = next;
    }
}
