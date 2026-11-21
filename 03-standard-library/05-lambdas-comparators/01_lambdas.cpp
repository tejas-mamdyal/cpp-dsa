#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* Lambdas and Custom Comparators
 * 
 * Why use them?
 * Sometimes the default sorting (ascending) isn't what you want.
 * You want to sort descending, or sort pairs by the second element, 
 * or sort custom structs.
*/

// Traditional approach: A custom comparator function
bool compareDescending(int a, int b) {
    return a > b; // True means 'a' should come BEFORE 'b'
}

int main() {
    vector<int> v = {10, 50, 20, 40};

    // 1. Using standard library comparators
    sort(v.begin(), v.end(), greater<int>()); // Built-in descending

    // 2. Using a custom function
    sort(v.begin(), v.end(), compareDescending);

    // 3. Using a C++11 Lambda (The Modern Way!)
    // Syntax: [](params) { body }
    sort(v.begin(), v.end(), [](int a, int b) {
        return a < b; // Ascending
    });

    // 4. Advanced Example: Sorting a vector of pairs by the SECOND element
    vector<pair<int, int>> pairs = {{1, 100}, {2, 50}, {3, 75}};

    sort(pairs.begin(), pairs.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second; // Compare the second elements
    });

    cout << "Pairs sorted by second element:" << endl;
    for (auto p : pairs) {
        cout << "{" << p.first << ", " << p.second << "} ";
    }
    cout << endl;

    return 0;
}
