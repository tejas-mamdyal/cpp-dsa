/*
READ SEVERAL INDEPENDENT TEST CASES
Prerequisites: Phase1 streams/loops/validation and Phase2 strings/vectors.
This is a standalone program: all its code is here; only standard headers are used.

INPUT / OUTPUT
Read test count in [0,100], then two ints in [-1000,1000] per case. Print their sum per line. Missing or invalid fields are errors. If a later case fails, results already printed for earlier cases remain.
Invalid required input prints an error to stderr and exits with status 1. Results have no prompts.

IDEA AND NEW SYNTAX
An outer loop repeats the same input contract. Reinitialize the two operands for each case; the case count is not a data value. Bounds keep addition representable.

TRACE
2 then3 4 then-1 5 -> output7 and4 on separate lines.

COST AND PRACTICE
O(T) arithmetic operations for T cases; O(1) stored numeric values. Input text length also affects extraction time.
Numeric extraction rejects int overflow.
Try an empty/boundary case and a malformed field before changing the program.
Follow-up: add one computed statistic without hiding the parsing in another file.
*/
#include <iostream>

int main() {
    int testCount = 0;
    if (!(std::cin >> testCount) || testCount < 0 || testCount > 100) {
        std::cerr << "Invalid test count.\n";
        return 1;
    }
    for (int test = 0; test < testCount; ++test) {
        int first = 0;
        int second = 0;
        if (!(std::cin >> first >> second) || first < -1000 || first > 1000 || second < -1000
            || second > 1000) {
            std::cerr << "Invalid test case.\n";
            return 1;
        }
        std::cout << first + second << '\n';
    }
}
