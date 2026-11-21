#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* STL FUNDAMENTALS
 * 
 * The STL is built on three pillars:
 * 1. Containers (Stores the data)
 * 2. Iterators (Points to the data)
 * 3. Algorithms (Processes the data)
 * 
 * Notice how `sort` doesn't know it's sorting a `vector`. It just takes 
 * two iterators (begin and end). This decoupling is the genius of the STL.
*/

int main() {
    // 1. Container
    vector<int> numbers = {42, 15, 8, 23, 4};

    // 2. Iterators (v.begin() and v.end())
    // 3. Algorithm (std::sort)
    sort(numbers.begin(), numbers.end());

    cout << "Sorted numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
