/*
SECOND-LARGEST DISTINCT VALUE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use a boolean to represent whether a second distinct value exists, not a magic sentinel.
Trace: 3,9,9,5 -> second largest5; 7,7 has no answer.
Why it works: largest and optional second contain the two greatest distinct values of the processed prefix.
Cost: O(n) time and O(1) extra space.
Common mistake: Duplicates of the maximum are not the second-largest distinct value.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

bool secondLargest(const std::vector<int>& values, int& result) {
    if (values.empty()) {
        return false;
    }
    int largest = values[0];
    int second = 0;
    bool hasSecond = false;
    for (int value : values) {
        if (value > largest) {
            second = largest;
            hasSecond = true;
            largest = value;
        } else if (value < largest && (!hasSecond || value > second)) {
            second = value;
            hasSecond = true;
        }
    }
    if (hasSecond) {
        result = second;
    }
    return hasSecond;
}

int main() {
    int answer = 0;
    assert(secondLargest({3, 9, 9, 5}, answer) && answer == 5);
    assert(secondLargest({-5, -2, -9}, answer) && answer == -5);
    assert(!secondLargest({7, 7}, answer));
    assert(!secondLargest({}, answer));
    std::cout << "checks passed\n";
}
