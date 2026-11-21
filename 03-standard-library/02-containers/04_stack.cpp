#include <iostream>
#include <stack>

using namespace std;

/*
* std::stack (Container Adapter)
 * 
 * Why use it?
 * Implements a LIFO (Last-In, First-Out) data structure.
 * Useful for DFS, matching parentheses, reversing things.
 * 
 * Note: It relies on a deque or vector internally. It restricts your access
 * to ONLY the top element. You CANNOT iterate through a stack.
 * 
 * Complexity:
 * - Push: O(1)
 * - Pop: O(1)
 * - Top: O(1)
*/

int main() {
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack size: " << s.size() << endl;

    // To process a stack, you must pop elements until it's empty
    cout << "Popping elements (LIFO): ";
    while (!s.empty()) {
        cout << s.top() << " "; // Access the top element
        s.pop();                // Remove the top element (returns void!)
    }
    cout << endl;

    return 0;
}
