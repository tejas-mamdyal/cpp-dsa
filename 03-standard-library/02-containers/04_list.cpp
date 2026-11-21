#include <iostream>
#include <list>

using namespace std;

/*
* std::list (Doubly Linked List)
 * 
 * Why use it?
 * Unlike vector, elements are not stored in contiguous memory.
 * This allows O(1) insertions and deletions anywhere, PROVIDED you already 
 * have an iterator pointing to that spot.
 * 
 * Why NOT use it?
 * It lacks random access. You cannot do list[5]. You must iterate one by one.
 * It is extremely cache-unfriendly. For 99% of DSA problems, a vector is faster.
 * 
 * Complexity:
 * - Access: O(N) (No random access!)
 * - Push/Pop Front/Back: O(1)
 * - Insert/Erase (with iterator): O(1)
*/

int main() {
    list<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_front(5);

    cout << "List elements: ";
    for (int val : l) {
        cout << val << " ";
    }
    cout << endl;

    // To insert in the middle, we must advance an iterator (O(N) operation)
    auto it = l.begin();
    advance(it, 1); // Move iterator forward by 1

    // Now insertion is O(1)
    l.insert(it, 15);

    cout << "After insertion: ";
    for (int val : l) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
