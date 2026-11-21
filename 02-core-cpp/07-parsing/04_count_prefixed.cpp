/*
READ A COUNT FOLLOWED BY THAT MANY VALUES
Prerequisites: Phase1 streams/loops/validation and Phase2 strings/vectors.
This is a standalone program: all its code is here; only standard headers are used.

INPUT / OUTPUT
Read n in [0,100], followed by n ints. Print those values. Missing values and invalid n are errors; tokens after the required sequence are ignored.
Invalid required input prints an error to stderr and exits with status 1. Results have no prompts.

IDEA AND NEW SYNTAX
The count determines the number of extractions. Validate it before using it to control storage or a loop. This input style is common in programming exercises.

TRACE
Input3 8 -1 5 -> n3 -> three reads -> output8 -1 5. n0 gives an empty line.

COST AND PRACTICE
O(n) integer reads and O(n) storage for n values, with n at most 100.
Numeric extraction rejects int overflow.
Try an empty/boundary case and a malformed field before changing the program.
Follow-up: add one computed statistic without hiding the parsing in another file.
*/
#include <iostream>
#include <vector>

int main() {
    int count = 0;
    if (!(std::cin >> count) || count < 0 || count > 100) {
        std::cerr << "Invalid count.\n";
        return 1;
    }
    std::vector<int> values;
    for (int i = 0; i < count; ++i) {
        int value = 0;
        if (!(std::cin >> value)) {
            std::cerr << "Missing or invalid value.\n";
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
