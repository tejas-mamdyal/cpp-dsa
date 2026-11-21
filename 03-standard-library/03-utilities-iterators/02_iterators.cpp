#include <iostream>
#include <vector>

using namespace std;

/*
* Iterators
 * 
 * Why use them?
 * They are position objects, not necessarily raw pointers. They let algorithms work on vectors, lists, 
 * and sets using the exact same syntax.
*/

int main() {
    vector<int> v = {10, 20, 30, 40};

    // 1. Basic Iterator
    // begin() points to the first element (10).
    // end() points to ONE PAST the last element. DO NOT dereference end()!
    cout << "Iterating with iterators: ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " "; // Dereference like a pointer
    }
    cout << endl;

    // 2. Reverse Iterator
    // rbegin() points to the last element (40).
    // rend() is the past-end reverse sentinel; it must not be dereferenced.
    cout << "Iterating in reverse: ";
    for (auto it = v.rbegin(); it != v.rend(); ++it) { // using auto is much cleaner!
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
