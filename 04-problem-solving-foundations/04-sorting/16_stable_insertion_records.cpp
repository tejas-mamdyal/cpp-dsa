/*
OBSERVE STABILITY WITH TAGGED EQUAL KEYS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Sort records by score only and retain arrival order among ties. IDEA AND STATE:
Shift only records with strictly greater keys. TRACE: (2,A),(1,B),(2,C) ->(1,B),(2,A),(2,C).
CORRECTNESS: A later equal key never crosses an earlier equal key. COST: O(n^2) worst
time,O(1) auxiliary record storage. PITFALL: Using >= in the shift condition reverses equal
records; ordinary std::sort does not guarantee stability. PRACTICE: Change the example,
predict each state update and add an empty/boundary case. No input unless explicitly stated.
Assertions are the teaching test harness and must remain enabled; success prints checks
passed. These bounds describe the helper, not a claim that a fixed-data demonstration has
growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

struct Record {
    int score;
    char tag;
};

void stableInsertion(std::vector<Record>& a) {
    for (std::size_t i = 1; i < a.size(); ++i) {
        Record saved = a[i];
        std::size_t j = i;
        while (j > 0 && a[j - 1].score > saved.score) {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = saved;
    }
}

int main() {
    std::vector<Record> a = {{2, 'A'}, {1, 'B'}, {2, 'C'}};
    stableInsertion(a);
    assert(a[0].tag == 'B' && a[1].tag == 'A' && a[2].tag == 'C');
    std::vector<Record> empty;
    stableInsertion(empty);
    assert(empty.empty());
    std::cout << "checks passed\n";
    return 0;
}
