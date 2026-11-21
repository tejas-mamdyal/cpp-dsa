/*
SORT WHEN EACH ELEMENT IS AT MOST K PLACES AWAY PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Vector where each element is displaced by at most k from some sorted arrangement; k
nonnegative. IDEA AND STATE: A min heap of k+1 lookahead elements exposes the next correct
value. TRACE: 3,1,2,5,4 with k2 ->1,2,3,4,5. CORRECTNESS: The next smallest unplaced value
cannot lie beyond the permitted lookahead. COST: O(n log(k+2)) time,O(min(n,k+1)) heap space.
PITFALL: The precondition matters; k=0 is only for already sorted input. PRACTICE: Change the
example, predict each state update and add an empty/boundary case. No input unless explicitly
stated. Assertions are the teaching test harness and must remain enabled; success prints
checks passed. These bounds describe the helper, not a claim that a fixed-data demonstration
has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

void nearlySorted(std::vector<int>& a, std::size_t k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
    std::size_t write = 0;
    for (int value : a) {
        heap.push(value);
        if (heap.size() > k) {
            a[write++] = heap.top();
            heap.pop();
        }
    }
    while (!heap.empty()) {
        a[write++] = heap.top();
        heap.pop();
    }
}

int main() {
    std::vector<int> a = {3, 1, 2, 5, 4};
    nearlySorted(a, 2);
    assert((a == std::vector<int>{1, 2, 3, 4, 5}));
    std::vector<int> empty;
    nearlySorted(empty, 0);
    std::vector<int> b = {4, 1, 3};
    nearlySorted(b, 10);
    assert(std::is_sorted(b.begin(), b.end()));
    std::cout << "checks passed\n";
    return 0;
}
