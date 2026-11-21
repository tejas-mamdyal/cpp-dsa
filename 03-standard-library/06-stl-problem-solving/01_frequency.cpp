#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

using namespace std;

/*
* PROBLEM 1: Frequency Counting
 * Given an array, find the most frequent element.
 * 
 * Tool selected: unordered_map
 * Why? We need Key (element) -> Value (frequency) mapping. O(1) average lookup.
*/

int findMostFrequent(const vector<int>& nums) {
    // Contract: at least one value. Ties choose the smaller value.
    assert(!nums.empty());
    unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++; // STL makes this trivial!
    }

    int maxFreq = 0;
    int mostFrequentElement = -1;

    for (const auto& [num, count] : freq) { // Using structured bindings
        if (count > maxFreq || (count == maxFreq && num < mostFrequentElement)) {
            maxFreq = count;
            mostFrequentElement = num;
        }
    }

    return mostFrequentElement;
}

int main() {
    assert(findMostFrequent({2, 1}) == 1);
    assert(findMostFrequent({-1, -1, 2}) == -1);
    vector<int> arr = {1, 3, 2, 1, 4, 1, 3, 3, 3};
    cout << "Most frequent element: " << findMostFrequent(arr) << endl;
    return 0;
}
