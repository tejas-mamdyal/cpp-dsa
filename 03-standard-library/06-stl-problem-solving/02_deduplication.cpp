#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
* PROBLEM 2: Deduplication and Sorting
 * Given an array with duplicates, return a sorted array of unique elements.
 * 
 * Tool selected: std::set
 * Why? It automatically handles uniqueness AND ordering.
*/

vector<int> getSortedUniques(const vector<int>& nums) {
    set<int> uniqueSorted(nums.begin(), nums.end()); // Initialize set from vector!

    // Convert back to vector to return
    return vector<int>(uniqueSorted.begin(), uniqueSorted.end());
}

int main() {
    vector<int> arr = {5, 2, 9, 5, 2, 3, 1};
    vector<int> result = getSortedUniques(arr);

    cout << "Unique and sorted: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
