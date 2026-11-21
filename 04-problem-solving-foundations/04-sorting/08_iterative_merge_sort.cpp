/*
BOTTOM-UP MERGE SORT REMOVES RECURSIVE FRAMES PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations. IDEA
AND STATE: Merge sorted runs of width1,2,4,... using a buffer; n<=1000. TRACE: Individual
elements become sorted pairs then runs of4. CORRECTNESS: At each level every run of the
current width is sorted; merging creates the next level. COST: O(n log(n+1)) time,O(n) buffer,
no recursive stack; stable. PITFALL: The final run may be shorter; clamp both middle and right
boundaries. PRACTICE: Change the example, predict each state update and add an empty/boundary
case. No input unless explicitly stated. Assertions are the teaching test harness and must
remain enabled; success prints checks passed. These bounds describe the helper, not a claim
that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void sortValues(std::vector<int>& a) {
    std::vector<int> buffer(a.size());
    for (std::size_t width = 1; width < a.size(); width *= 2) {
        for (std::size_t left = 0; left < a.size(); left += 2 * width) {
            std::size_t middle = std::min(left + width, a.size());
            std::size_t right = std::min(left + 2 * width, a.size());
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
        }
        a.swap(buffer);
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
