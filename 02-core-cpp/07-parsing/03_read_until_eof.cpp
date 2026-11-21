/*
READ VALUES ACROSS LINES UNTIL END OF INPUT
Prerequisites: Phase1 streams/loops/validation and Phase2 strings/vectors.
This is a standalone program: all its code is here; only standard headers are used.

INPUT / OUTPUT
Read whitespace-separated integer tokens until EOF; print them on one line. Empty input gives an empty line. In a Windows console, signal EOF with Ctrl+Z then Enter; redirected input ends at file end.
Invalid required input prints an error to stderr and exits with status 1. Results have no prompts.

IDEA AND NEW SYNTAX
Reading a string token first gives an exact field boundary. A small istringstream must read one int and no further non-whitespace character. This rejects partial tokens such as 12x as well as overflow. Only print after all tokens have been checked.

TRACE
Input 1 2 on line 1 and 3 on line 2 -> three tokens -> output 1 2 3.

COST AND PRACTICE
O(L) time over L input characters; O(n + T) storage for n values and the longest token of T characters.
Numeric extraction rejects int overflow.
Try an empty/boundary case and a malformed field before changing the program.
Follow-up: add one computed statistic without hiding the parsing in another file.
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::vector<int> values;
    std::string token;
    while (std::cin >> token) {
        std::istringstream number(token);
        int value = 0;
        char extra = ' ';
        if (!(number >> value) || (number >> extra)) {
            std::cerr << "Invalid integer token.\n";
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
