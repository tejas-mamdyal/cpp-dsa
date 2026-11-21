#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

/*
* Unordered Containers (Hash Tables)
 * std::unordered_map & std::unordered_set
 * 
 * Why use them?
 * Expected constant-time lookup; ordered containers offer different guarantees.
 * Internally implemented using Hash Tables.
 * 
 * Complexity:
 * - Average Case (Insert, Erase, Find): O(1)
 * - Worst Case (Hash Collisions): O(N)
*/

int main() {
    // 1. Unordered Map (Frequency Counting is its #1 use case)
    unordered_map<string, int> freq;

    freq["apple"]++;
    freq["banana"]++;
    freq["apple"]++;

    cout << "Unordered Map (Unspecified Order):" << endl;
    for (const auto& [fruit, count] : freq) {
        cout << fruit << " : " << count << endl;
    }

    // 2. Unordered Set (Fast O(1) deduplication)
    unordered_set<int> seen;
    seen.insert(100);
    seen.insert(200);

    if (seen.count(100)) {
        cout << "100 was found (average O(1) lookup)." << endl;
    }

    return 0;
}
