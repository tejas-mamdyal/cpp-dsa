/*
APPEND PRESERVES PREVIOUS RECORDS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Write one line, append another, then count complete lines.
Trace: first then second -> two records.
Why it works: app directs every write to the file end, retaining the earlier line.
Cost: O(L) time, O(M) space for the longest line.
Common mistake: Default ofstream truncates; do not accidentally use it when appending.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>

int main() {
    {
        std::ofstream output("build/append_records.txt");
        assert(output);
        output << "first\n";
        output.close();
        assert(output);
    }
    {
        std::ofstream output("build/append_records.txt", std::ios::app);
        assert(output);
        output << "second\n";
        output.close();
        assert(output);
    }
    std::ifstream input("build/append_records.txt");
    assert(input);
    std::string line;
    int count = 0;
    while (std::getline(input, line)) {
        ++count;
    }
    assert(input.eof());
    assert(count == 2);
    std::cout << "checks passed\n";
}
