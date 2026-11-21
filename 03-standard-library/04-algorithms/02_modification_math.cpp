#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Required for accumulate

using namespace std;

/*
* Algorithms: Modification and Math
*/

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    // 1. Reverse (O(N))
    reverse(v.begin(), v.end());
    cout << "Reversed: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl; // 5 4 3 2 1

    // 2. Accumulate (Summing elements)
    // The 3rd argument (0) is the initial sum.
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum: " << sum << endl;

    // 3. Min/Max Element
    auto min_it = min_element(v.begin(), v.end());
    auto max_it = max_element(v.begin(), v.end());
    cout << "Min: " << *min_it << ", Max: " << *max_it << endl;

    // 4. Next Permutation
    // Generates the next lexicographical permutation. Useful for backtracking.
    vector<int> p = {1, 2, 3};
    cout << "Permutations:" << endl;
    do {
        for (int x : p) {
            cout << x << " ";
        }
        cout << endl;
    } while (next_permutation(p.begin(), p.end()));

    return 0;
}
