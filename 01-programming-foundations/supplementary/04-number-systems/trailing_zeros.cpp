/*
LEARNING NOTES
Each trailing decimal zero contributes a factor 10=2*5. In n!, factors of 2
outnumber factors of 5, so count fives: floor(n/5)+floor(n/25)+... . Repeatedly
divide by 5 to avoid constructing powers or the enormous factorial itself.
For 25!: 5+1=6 zeros. Intended domain n>=0; 0!=1 has zero trailing zeros.
O(log_5(n+1)) time/O(1) space. Exercise: adapt the reasoning to another base.
*/
#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int n = num;
    int ans = 0;
    while (n >= 5) {
        ans += n / 5;
        n /= 5;
    }
    cout << "\nFacctorial of " << num << " has " << ans << " trailing zeros";
    return 0;
}