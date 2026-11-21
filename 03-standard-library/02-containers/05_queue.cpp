#include <iostream>
#include <queue>

using namespace std;

/*
* std::queue (Container Adapter)
 * 
 * Why use it?
 * Implements a FIFO (First-In, First-Out) data structure.
 * Useful for BFS (Breadth-First Search) in graphs.
 * 
 * Complexity:
 * - Push: O(1)
 * - Pop: O(1)
 * - Front/Back: O(1)
*/

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue size: " << q.size() << endl;

    // To process a queue, you must pop elements until it's empty
    cout << "Popping elements (FIFO): ";
    while (!q.empty()) {
        cout << q.front() << " "; // Access the front element
        q.pop();                  // Remove the front element
    }
    cout << endl;

    return 0;
}
