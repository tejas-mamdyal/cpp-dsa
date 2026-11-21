/*
CASE-SENSITIVE WORD FREQUENCY WITH EXACT TOKENS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Split whitespace words and count them in a hash map; punctuation remains part of a word.
Trace: red blue red ->red2 blue1.
Why it works: Each successfully extracted token contributes exactly one occurrence.
Cost: Expected O(L) hashing/token work for L characters; worst collisions can degrade lookup; O(L) key storage.
Common mistake: Define normalization before counting natural-language text; this example is deliberately case-sensitive and punctuation-sensitive.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <sstream>
#include <unordered_map>
#include <string>

int main() {
    std::istringstream input("red blue red");
    std::unordered_map<std::string, int> counts;
    std::string word;
    while (input >> word) {
        ++counts[word];
    }
    assert(counts.at("red") == 2);
    assert(counts.at("blue") == 1);
    assert(counts.size() == 2);
    std::cout << "checks passed\n";
}
