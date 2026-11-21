#include <algorithm>
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
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter value of n : ";
    cin >> n;

    for (int i = 0; i < (2 * n - 1); i++) {
        for (int j = 0; j < (2 * n - 1); j++) {
            int top = i;
            int left = j;

            int bottom = (2 * n - 2) - i;
            int right = (2 * n - 2) - j;

            int MinVal = min(min(top, bottom), min(left, right));

            cout << (n - MinVal) << " ";
        }
        cout << endl;
    }
    return 0;
}