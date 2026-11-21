/*
READ COMMA-SEPARATED INTEGERS WITHOUT A HELPER HEADER
Prerequisites: Phase1 streams/loops/validation and Phase2 strings/vectors.
This is a standalone program: all its code is here; only standard headers are used.

INPUT / OUTPUT
Read one nonempty line of comma-separated signed ints. Whitespace around each number is allowed. Reject empty fields, a trailing comma, partial numbers and overflow. Print normalized numbers separated by single spaces.
Invalid required input prints an error to stderr and exits with status 1. Results have no prompts.

IDEA AND NEW SYNTAX
getline(fields,field,',') splits on commas. An istringstream for each field reads the int; attempting one extra char skips trailing whitespace and detects leftover junk. Checking the final comma matters because getline does not return a new empty field after a delimiter at EOF. There are no pointers, conversion exceptions, include guards or custom headers.

TRACE
12, 5,-8,+3 -> fields 12 / 5 / -8 / +3 -> values 12 5 -8 3. A field 12abc leaves a character and is rejected.

COST AND PRACTICE
O(L) time and O(L) space for a line of L characters, its fields and parsed values.
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
    if (!std::getline(std::cin, line) || line.empty() || line.back() == ',') {
        std::cerr << "Invalid comma-separated integer list.\n";
        return 1;
    }
    std::istringstream fields(line);
    std::vector<int> values;
    std::string field;
    while (std::getline(fields, field, ',')) {
        std::istringstream number(field);
        int value = 0;
        char extra = ' ';
        // A successful integer followed by another character is not a whole field.
        if (!(number >> value) || (number >> extra)) {
            std::cerr << "Invalid comma-separated integer list.\n";
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
