#include <iostream>

using namespace std;

/*
* Pass by Value:
 * A copy of the variable is passed. Modifying it inside the function
 * does NOT affect the original variable.
*/
void modifyValue(int x) {
    x = 100;
    (void)x; // The local copy changes; the caller does not observe it.
}

/*
* Pass by Reference (&):
 * The actual memory address is passed. Modifying it inside the function
 * DOES affect the original variable.
 * 
 * CRITICAL FOR DSA: If you are passing a large Array/Vector to a function,
 * always pass by reference to avoid the massive performance cost of copying it.
*/
void modifyReference(int& x) {
    x = 100;
    (void)x; // The local copy changes; the caller does not observe it.
}

int main() {
    int a = 10;
    int b = 10;

    cout << "Before modifyValue: a = " << a << endl;
    modifyValue(a);
    cout << "After modifyValue: a = " << a << " (Unchanged!)" << endl << endl;

    cout << "Before modifyReference: b = " << b << endl;
    modifyReference(b);
    cout << "After modifyReference: b = " << b << " (Changed!)" << endl;

    return 0;
}
