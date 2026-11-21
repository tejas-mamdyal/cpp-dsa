/*
TOP K LARGEST USING A MIN HEAP
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Keep at most k values; remove the smallest whenever the heap exceeds k.
Trace: 3,1,9,5 with k2 retains5,9; output is descending.
Why it works: After each prefix the heap contains its k largest values, with the smallest retained one ready for removal.
Cost: O(n log(k+2)+k) time and O(k) heap/output space, capped by n.
Common mistake: This application follows algorithm interfaces; priority_queue does not expose sorted iteration.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

std::vector<int> topK(const std::vector<int>& values, std::size_t k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> best;
    for (int value : values) {
        best.push(value);
        if (best.size() > k) {
            best.pop();
        }
    }
    std::vector<int> result;
    while (!best.empty()) {
        result.push_back(best.top());
        best.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    assert((topK({3, 1, 9, 5}, 2) == std::vector<int>{9, 5}));
    assert(topK({1}, 0).empty());
    assert((topK({2, 2}, 5) == std::vector<int>{2, 2}));
    std::cout << "checks passed\n";
}
