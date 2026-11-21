#include <iostream>
#include <array>

using namespace std;

/*
* std::array
 * 
 * Why use it?
 * It is a safer, modern alternative to C-style arrays (int arr[5]).
 * It has a FIXED size known at compile time. It does not grow.
 * 
 * Complexity:
 * - Access O(1)
*/

int main() {
    // Syntax: array<type, size> name;
    array<int, 5> arr = {1, 2, 3, 4, 5};

    cout << "Size: " << arr.size() << endl;
    cout << "Front: " << arr.front() << endl;
    cout << "Back: " << arr.back() << endl;

    // Bounds checking (unlike C-style arrays)
    // arr[10] = 5; // Undefined behavior (silent crash)
    // arr.at(10) = 5; // Throws an out_of_range exception safely!

    arr.fill(0); // Fills entire array with 0

    return 0;
}
