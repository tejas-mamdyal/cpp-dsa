#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* Algorithms: Sorting and Searching
*/

int main() {
    vector<int> v = {40, 10, 50, 20, 30};

    // 1. Sorting (O(N log N))
    sort(v.begin(), v.end());
    cout << "Sorted: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    // 2. Linear Search (O(N)) - Works on unsorted data too
    auto it = find(v.begin(), v.end(), 20);
    if (it != v.end()) {
        cout << "Found 20 at index " << (it - v.begin()) << endl;
    }

    // 3. Binary Search Utilities (O(log N)) - MUST BE SORTED!

    // A. binary_search() returns a simple true/false
    bool exists = binary_search(v.begin(), v.end(), 50);
    cout << "50 exists? " << exists << endl;

    // B. lower_bound() returns an iterator to the FIRST element >= target
    vector<int> v2 = {10, 20, 20, 20, 30};
    auto lb = lower_bound(v2.begin(), v2.end(), 20);

    // C. upper_bound() returns an iterator to the FIRST element > target
    auto ub = upper_bound(v2.begin(), v2.end(), 20);

    cout << "Number of 20s: " << (ub - lb) << endl; // Powerful trick to count duplicates!

    return 0;
}
