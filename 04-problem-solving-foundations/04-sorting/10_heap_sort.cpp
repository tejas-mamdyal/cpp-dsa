/*
TEACH THE ARRAY HEAP INVARIANT BEFORE HEAP SORT PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations. IDEA
AND STATE: A max heap has parent>=children; children of i are2*i+1 and2*i+2. Repair downward,
build bottom-up, then extract the maximum to the suffix. TRACE: 3,1,4 builds root4; swap root
to final slot then repair the shorter heap. CORRECTNESS: Bottom-up repairs make every subtree
a heap. Each extracted root is the largest remaining value and enters its final position.
COST: O(n) heap construction,O(n log(n+1)) sorting,O(1) extra space; unstable. PITFALL: The
heap is a prefix, not the entire vector after extraction; later heap chapters expand this
invariant. PRACTICE: Change the example, predict each state update and add an empty/boundary
case. No input unless explicitly stated. Assertions are the teaching test harness and must
remain enabled; success prints checks passed. These bounds describe the helper, not a claim
that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void sift(std::vector<int>& a, int root, int size) {
    while (root < size / 2) {
        int child = 2 * root + 1;
        if (child + 1 < size && a[child + 1] > a[child]) {
            ++child;
        }
        if (a[root] >= a[child]) {
            return;
        }
        std::swap(a[root], a[child]);
        root = child;
    }
}

void sortValues(std::vector<int>& a) {
    int n = static_cast<int>(a.size());
    for (int root = n / 2; root > 0; --root) {
        sift(a, root - 1, n);
    }
    for (int end = n - 1; end > 0; --end) {
        std::swap(a[0], a[end]);
        sift(a, 0, end);
    }
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
