/*
Sum squares1..n with a for-loop and n*(n+1)*(2*n+1)/6. This is NOT a do/while
example. Accept n0..1000; invalid input -> error/exit1. Use wide arithmetic.
The sum contains squares already processed. O(n) time/O(1) space.
Exercise: compare both methods across many small n; n3 gives14 both ways.
*/
// WAP to print sum of n natural numbers
#include <iostream>
using namespace std;

int main() {
    long long n = 0;
    long long sum = 0;
    cout << "Enter a Number: ";
    if (!(cin >> n) || n < 0 || n > 1000) {
        cerr << "Invalid input\n";
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    cout << "Sum of squares of 1 to " << n << " is " << sum << endl;
    sum = (n * (n + 1) * ((2 * n) + 1)) / 6;
    cout << "Sum using formula is " << sum;
    return 0;
}