/*
emplace operations construct an element from the supplied arguments in container storage. They are not automatically faster than push/insert, especially when an element has already been constructed. Container growth can still allocate and invalidate references.
*/
#include <iostream>
#include <vector>

using namespace std;

/*
* std::vector (Dynamic Array)
 * 
 * Why use it?
 * It's the default container in C++. Use it when you need ordered elements 
 * and fast access by index. It grows automatically.
 * 
 * Complexity:
 * - Access O(1)
 * - Push back: Amortized O(1)
 * - Insert/Erase in middle: O(N)
*/

int main() {
    vector<int> vec;

    // Size vs Capacity
    // size() = how many elements are currently in the vector.
    // capacity() = how much memory is currently allocated.
    cout << "Initial size: " << vec.size() << ", capacity: " << vec.capacity() << endl;

    // reserve() allocates memory in advance. CRITICAL for performance to avoid reallocations.
    vec.reserve(10);
    cout << "After reserve(10) -> size: " << vec.size() << ", capacity: " << vec.capacity() << endl;

    vec.push_back(10);
    vec.push_back(20);
    vec.emplace_back(
        30); // Constructs from arguments in place;not automatically faster than push_back.

    // Iteration (Range-based for loop)
    cout << "Elements: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    // Erasing an element (O(N) operation because elements must shift left)
    vec.erase(vec.begin() + 1); // Erases '20'

    // Resizing (changes actual size, fills with default value if expanding)
    vec.resize(5, -1);

    cout << "After erase and resize: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
