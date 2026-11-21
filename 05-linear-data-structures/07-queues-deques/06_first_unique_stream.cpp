/*
QUEUE CANDIDATES FOR FIRST NONREPEATING STREAM CHARACTER PREREQUISITES: Phases1/2 C++ and STL,

README order, not old filenames.

 Lowercase English text; output one answer per prefix,using# for no unique character.
IDEA AND STATE: Count arrivals and discard queue-front candidates once repeated. TRACE: aabc
->a#bb. CORRECTNESS: The first surviving queued character is the earliest seen character whose
completed prefix count is1. COST: O(n) total time,O(n) queue/output storage; each arrival
enters/leaves at most once. PITFALL: The sentinel# is outside the input alphabet. PRACTICE:
Change the example, predict each state update and add an empty/boundary case. No input unless
explicitly stated. Assertions are the teaching test harness and must remain enabled; success
prints checks passed. These bounds describe the helper, not a claim that a fixed-data
demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <queue>
#include <string>

std::string firstUniqueStream(const std::string& text) {
    int counts[26] = {};
    std::queue<char> candidates;
    std::string out;
    for (char ch : text) {
        assert(ch >= 'a' && ch <= 'z');
        ++counts[ch - 'a'];
        candidates.push(ch);
        while (!candidates.empty() && counts[candidates.front() - 'a'] > 1) {
            candidates.pop();
        }
        if (candidates.empty()) {
            out += '#';
        } else {
            out += candidates.front();
        }
    }
    return out;
}

int main() {
    assert(firstUniqueStream("aabc") == "a#bb");
    assert(firstUniqueStream("").empty());
    assert(firstUniqueStream("aaaa") == "a###");
    assert(firstUniqueStream("abc") == "aaa");
    std::cout << "checks passed\n";
    return 0;
}
