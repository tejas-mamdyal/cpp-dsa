/*
VALIDATE AN OPTIMIZED METHOD AGAINST A SIMPLE ORACLE
PREREQUISITES
Phase1 loops/functions/validation and Phase2 vector/reference/library interfaces.
Read this unit's NOTES.md before the programs. No recursion is used here.

PROBLEM AND CONTRACT
No input. Compare duplicate detection by all unordered pairs and by a hash set. Exhaust every vector of lengths0..5 over alphabet{-1,0,1}; print how many cases agreed.

IDEA
Keep the simple method as a small-input oracle. Generate vectors iteratively by interpreting an integer in base3, with no recursion or random sampling.

TRACE
Lengths0..5 contribute1+3+9+27+81+243=364 vectors. {1,2,1} is duplicate, empty and{1,2,3} are not.

WHY IT WORKS
Pairwise checking returns true exactly when two different positions agree. The set detects a repeat exactly when an insertion finds a previously seen value. Base3 visits every alphabet choice for each position.

For an input of n values: brute-force O(n*n) worst time/O(1) space; hashing expected O(n) time, O(n*n) worst collision behavior, O(n) storage. General exhaustive harness work is O(sum(3^n*n*n)) up to length L; L=5 is fixed here.

PITFALL AND PRACTICE
Agreement is strong regression evidence on the enumerated domain, not a proof for all possible inputs. Test larger boundaries separately and state expected versus worst hash costs.
Change the traced size, predict the result, and test the smallest valid size.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

bool hasDuplicateSlow(const std::vector<int>& values) {
    for (std::size_t i = 0; i < values.size(); ++i) {
        for (std::size_t j = i + 1; j < values.size(); ++j) {
            if (values[i] == values[j]) {
                return true;
            }
        }
    }
    return false;
}

bool hasDuplicateFast(const std::vector<int>& values) {
    std::unordered_set<int> seen;
    for (int value : values) {
        if (!seen.insert(value).second) {
            return true;
        }
    }
    return false;
}

int main() {
    assert(hasDuplicateSlow({1, 2, 1}));
    assert(!hasDuplicateSlow({}));
    assert(!hasDuplicateFast({1, 2, 3}));
    int checked = 0;
    for (int length = 0; length <= 5; ++length) {
        int combinations = 1;
        for (int i = 0; i < length; ++i) {
            combinations *= 3;
        }
        for (int code = 0; code < combinations; ++code) {
            int remaining = code;
            std::vector<int> values(static_cast<std::size_t>(length));
            for (int& value : values) {
                value = remaining % 3 - 1;
                remaining /= 3;
            }
            assert(hasDuplicateSlow(values) == hasDuplicateFast(values));
            ++checked;
        }
    }
    assert(checked == 364);
    std::cout << "checked " << checked << " cases\n";
    return 0;
}
