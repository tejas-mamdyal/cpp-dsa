/*
READ WHOLE LINES UNTIL AN EXACT SENTINEL
Prerequisites: Phase1 streams/loops/validation and Phase2 strings/vectors.
This is a standalone program: all its code is here; only standard headers are used.

INPUT / OUTPUT
Read up to 1000 data lines, each at most 1000 characters, terminated by an exact line END. Blank lines are data. Print the number of data lines and total characters excluding newlines. Missing END or exceeding limits is an error.
Invalid required input prints an error to stderr and exits with status 1. Results have no prompts.

IDEA AND NEW SYNTAX
getline retains spaces inside a line. Compare the entire line before counting it, so the sentinel is not data. END with a trailing space is a different line. Only two counters are retained rather than storing every line.

TRACE
hello, a blank line, then END -> two data lines and five characters -> 2 5.

COST AND PRACTICE
O(L) time over all L characters; O(M) space for the longest line of M characters. Previous lines are not retained.
The explicit line and length limits keep both counters within range.
Try an empty/boundary case and a malformed field before changing the program.
Follow-up: add one computed statistic without hiding the parsing in another file.
*/
#include <iostream>
#include <string>

int main() {
    std::string line;
    int lineCount = 0;
    long long characters = 0;
    while (std::getline(std::cin, line)) {
        if (line == "END") {
            std::cout << lineCount << ' ' << characters << '\n';
            return 0;
        }
        if (lineCount == 1000 || line.size() > 1000) {
            std::cerr << "Input limit exceeded.\n";
            return 1;
        }
        ++lineCount;
        characters += static_cast<long long>(line.size());
    }
    std::cerr << "Missing END line.\n";
    return 1;
}
