/*
DISTRIBUTE BY RANGE THEN SORT EACH BUCKET PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Mutable vector of small ints; n<=1000. Values0..100. IDEA AND STATE: Scores0..100;
use11 buckets by value/10 then comparison-sort within each. TRACE: 29,11,24
->bucket1:[11],bucket2:[29,24] ->11,24,29. CORRECTNESS: All values in an earlier bucket
precede later buckets; sorting each completes the global order. COST: O(n log(n+1)) worst time
plus bucket overhead; O(n+11) space. PITFALL: Bucket performance depends on distribution and
bucket design; this example does not promise universal linear time. PRACTICE: Change the
example, predict each state update and add an empty/boundary case. No input unless explicitly
stated. Assertions are the teaching test harness and must remain enabled; success prints
checks passed. These bounds describe the helper, not a claim that a fixed-data demonstration
has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void sortValues(std::vector<int>& a) {
    std::vector<std::vector<int>> buckets(11);
    for (int value : a) {
        assert(value >= 0 && value <= 100);
        buckets[value / 10].push_back(value);
    }
    std::size_t write = 0;
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
        for (int value : bucket) {
            a[write++] = value;
        }
    }
}

int main() {
    for (std::vector<int> values : std::vector<std::vector<int>>{
             {}, {1}, {3, 1, 2, 1, 0}, {0, 0, 0}, {1, 2, 3, 4}, {4, 3, 2, 1}}) {
        auto expected = values;
        std::sort(expected.begin(), expected.end());
        sortValues(values);
        assert(values == expected);
    }
    std::cout << "checks passed\n";
    return 0;
}
