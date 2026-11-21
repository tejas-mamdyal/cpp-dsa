/*
READ A FIXED NUMBER OF WHITESPACE-SEPARATED INTEGERS
Prerequisites: Phase1 streams/loops/validation and Phase2 strings/vectors.
This is a standalone program: all its code is here; only standard headers are used.

INPUT / OUTPUT
Read three formatted int values. Print them on one line. Spaces, tabs and newlines all separate values. Further input after the third value is not checked in this introductory example.
Invalid required input prints an error to stderr and exits with status 1. Results have no prompts.

IDEA AND NEW SYNTAX
std::cin >> a >> b >> c skips whitespace before each integer. No string splitting is needed when the number of fields is already known. The strict line example follows next.

TRACE
Input 12 5 8 -> first12, second5, third8 -> output 12 5 8.

COST AND PRACTICE
O(1) stored integers and extraction operations; the size of numeric text affects parsing time.
Numeric extraction rejects int overflow.
Try an empty/boundary case and a malformed field before changing the program.
Follow-up: add one computed statistic without hiding the parsing in another file.
*/
#include <iostream>

int main() {
    int first = 0;
    int second = 0;
    int third = 0;
    if (!(std::cin >> first >> second >> third)) {
        std::cerr << "Expected three integers.\n";
        return 1;
    }
    std::cout << first << ' ' << second << ' ' << third << '\n';
}
