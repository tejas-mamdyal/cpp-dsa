#include <iostream>
#include <set>

using namespace std;

/*
* std::set (Ordered Associative Container)
 * 
 * Why use it?
 * Stores UNIQUE elements in SORTED order. 
 * Internally implemented as a Self-Balancing Binary Search Tree (Red-Black Tree).
 * 
 * Complexity:
 * - Insert: O(log N)
 * - Erase: O(log N)
 * - Find/Count: O(log N)
*/

int main() {
    set<int> s;

    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(10); // Duplicate! Will be ignored.

    // Automatically ordered!
    cout << "Set elements: ";
    for (int val : s) {
        cout << val << " ";
    }
    cout << endl;

    // Finding elements (Always use s.find(), NOT std::find() for sets!)
    if (s.find(20) != s.end()) {
        cout << "20 is in the set." << endl;
    }

    // Deleting
    s.erase(10);

    // count() returns 1 if present, 0 if absent
    if (s.count(30)) {
        cout << "30 is present." << endl;
    }

    return 0;
}
