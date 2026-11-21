#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
* std::priority_queue (Container Adapter)
 * 
 * Why use it?
 * Always gives you the LARGEST (or smallest) element in O(1) time.
 * Internally implemented as a Heap (Tree data structure).
 * Extremely important for Dijkstra's algorithm and "Top K" problems.
 * 
 * Complexity:
 * - Push: O(log N)
 * - Pop: O(log N)
 * - Top: O(1)
*/

int main() {
    // By default, it's a MAX-HEAP (Largest element is at the top)
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(50);
    maxHeap.push(30);

    cout << "Max-Heap popping: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    // To create a MIN-HEAP (Smallest element at the top), the syntax is verbose:
    // priority_queue<Type, Container, Comparator>
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(50);
    minHeap.push(30);

    cout << "Min-Heap popping: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}
