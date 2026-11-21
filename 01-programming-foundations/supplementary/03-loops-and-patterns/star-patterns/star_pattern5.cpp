/*
PATTERN LAB — prerequisites: output, for loops and integer expressions.
The outer loop selects a row; inner loops choose spaces, symbols or numbers in
that row. Before running, draw a table: row index, leading spaces, item count,
and printed value at each column. Derive each loop bound from that table.
Output order matters: spaces must be emitted before symbols when aligning right.
An n-row triangle prints about n*(n+1)/2 symbols: O(n^2) time, O(1) extra space.
For fixed dimensions, count the actual output; for a rectangle use O(rows*columns).
Exercise: mirror this pattern, then parameterize its size; test zero and one row.
Explain why each inner loop starts and stops at its particular bounds.
*/
#include <iostream>
using namespace std;

int main() {
    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        for (int j = i; j < 5; j++) {
            cout << "    ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        for (int j = i; j < 5; j++) {
            cout << "    ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 5; i >= 1; i--) {
        for (int j = i; j < 5; j++) {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = i; j < 5; j++) {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = i; j < 5; j++) {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 5; i >= 1; i--) {
        for (int j = i; j < 5; j++) {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        for (int j = i; j < 5; j++) {
            cout << "    ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        for (int j = i; j < 5; j++) {
            cout << "    ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}