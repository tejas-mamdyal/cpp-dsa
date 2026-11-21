#include <iostream>
#include <deque>

using namespace std;

/*
* std::deque (Double-Ended Queue)
 * 
 * Why use it?
 * Like a vector, but you can push/pop from the FRONT in O(1) time.
 * Internally, it is not a single contiguous block of memory, but a series of chunks.
 * 
 * Complexity:
 * - Access O(1)
 * - Push/Pop Front/Back: O(1)
 * - Insert/Erase middle: O(N)
*/

int main() {
    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5); // O(1) operation! (Vector would take O(N))
    dq.push_front(1);

    cout << "Deque elements: ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;

    dq.pop_front();
    dq.pop_back();

    cout << "After popping both ends: ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
