/*
READ AN UNKNOWN NUMBER OF INTEGERS FROM ONE LINE
Prerequisites: Phase1 streams/loops/validation and Phase2 strings/vectors.
This is a standalone program: all its code is here; only standard headers are used.

INPUT / OUTPUT
Read one line of whitespace-separated ints and print the numbers. An empty/blank line gives an empty output line. Missing the line or malformed numbers are errors.
Invalid required input prints an error to stderr and exits with status 1. Results have no prompts.

IDEA AND NEW SYNTAX
getline obtains the whole line. istringstream from sstream reads that string like input. std::ws consumes whitespace; eof() tells whether the end was reached. Check end BEFORE trying the next number, then reject a failed extraction: this also catches overflow at the very end.

TRACE
Line 12 5 -8 -> stream yields12,5,-8; after whitespace the stream reaches its end -> print 12 5 -8. For 12abc, the next extraction fails at a, so the line is rejected.

COST AND PRACTICE
O(L) time and O(L) space for a line of L characters and its parsed values.
Numeric extraction rejects int overflow.
Try an empty/boundary case and a malformed field before changing the program.
Follow-up: add one computed statistic without hiding the parsing in another file.
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string line;
    if (!std::getline(std::cin, line)) {
        std::cerr << "Expected a line.\n";
        return 1;
    }
    std::istringstream numbers(line);
    std::vector<int> values;
    while (true) {
        numbers >> std::ws;
        if (numbers.eof()) {
            break;
        }
        int value = 0;
        if (!(numbers >> value)) {
            std::cerr << "Invalid integer.\n";
            return 1;
        }
        values.push_back(value);
    }

    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << values[i];
    }
    std::cout << '\n';
}
