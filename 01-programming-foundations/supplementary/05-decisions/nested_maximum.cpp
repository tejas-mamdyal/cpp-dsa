/*
LEARNING NOTES
A condition chooses which block executes. if/else-if selects the first true
branch; else handles the remaining cases. Order matters when conditions overlap.
Use == to compare, not =. Test values just below, equal to and above a boundary.
Exercise: turn the conditions into a decision table before changing the program.
*/
#include <iostream>
using namespace std;

int main() {
    int a;
    int b;
    int c;
    cout << "Enter three numbrs : " << endl;
    cin >> a >> b >> c;
    if (a > b) {
        if (a > c) {
            cout << a << endl;
        } else {
            cout << c << endl;
        }
    } else {
        if (b > c) {
            cout << b << endl;
        } else {
            cout << c << endl;
        }
    }
    return 0;
}