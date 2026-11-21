/*
STABLE MERGE SORT WITH ONE REUSABLE BUFFER PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations. IDEA
AND STATE: Split half-open ranges, sort halves, merge their ordered heads. TRACE: 3,1 plus2,0
->sorted halves1,3 and0,2 ->0,1,2,3. CORRECTNESS: Sorted halves partition the input; the
smallest remaining head is the next output. COST: O(n log(n+1)) time,O(n) buffer plus
O(log(n+1)) stack; stable. PITFALL: Choose the left value on equality and do not allocate/copy
full sub-vectors at every call. PRACTICE: Change the example, predict each state update and
add an empty/boundary case. No input unless explicitly stated. Assertions are the teaching
test harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void mergeRange(std::vector<int>& a,
                std::vector<int>& buffer,
                std::size_t left,
                std::size_t right) {
    if (right - left < 2) {
        return;
    }
    std::size_t middle = left + (right - left) / 2;
    mergeRange(a, buffer, left, middle);
    mergeRange(a, buffer, middle, right);
    std::size_t i = left;
    std::size_t j = middle;
    std::size_t write = left;
    while (i < middle && j < right) {
        if (a[i] <= a[j]) {
            buffer[write++] = a[i++];
        } else {
            buffer[write++] = a[j++];
        }
    }
    while (i < middle) {
        buffer[write++] = a[i++];
    }
    while (j < right) {
        buffer[write++] = a[j++];
    }
    for (std::size_t k = left; k < right; ++k) {
        a[k] = buffer[k];
    }
}

void sortValues(std::vector<int>& a) {
    std::vector<int> buffer(a.size());
    mergeRange(a, buffer, 0, a.size());
}

int main() {
    for (std::vector<int> values : std::vector<std::vector<int>>{
             {}, {1}, {3, -1, 2, -1, 0}, {0, 0, 0}, {-2, 0, 3, 4}, {4, 3, 0, -2}}) {
        auto expected = values;
        std::sort(expected.begin(), expected.end());
        sortValues(values);
        assert(values == expected);
    }
    std::cout << "checks passed\n";
    return 0;
}
