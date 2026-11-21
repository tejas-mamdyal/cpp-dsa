/*
MIX NUMERIC EXTRACTION WITH FULL-LINE TEXT
Prerequisites: Phase1 streams/loops/validation and Phase2 strings/vectors.
This is a standalone program: all its code is here; only standard headers are used.

INPUT / OUTPUT
Read age in [0,120], then a nonblank full name. Print name | age. Leading whitespace before the name is ignored; spaces inside the name are retained.
Invalid required input prints an error to stderr and exits with status 1. Results have no prompts.

IDEA AND NEW SYNTAX
Formatted extraction leaves whitespace behind. getline(cin >> ws,name) consumes that whitespace before reading the full name; it therefore cannot represent an intentionally blank name. This policy is explicit rather than an accidental empty getline result.

TRACE
Input20 then Ada Lovelace on the next line -> outputAda Lovelace | 20.

COST AND PRACTICE
O(L) time and space for a name of L characters.
Numeric extraction rejects int overflow.
Try an empty/boundary case and a malformed field before changing the program.
Follow-up: add one computed statistic without hiding the parsing in another file.
*/
#include <iostream>
#include <string>

int main() {
    int age = 0;
    std::string name;
    if (!(std::cin >> age) || age < 0 || age > 120) {
        std::cerr << "Invalid age.\n";
        return 1;
    }
    if (!std::getline(std::cin >> std::ws, name)) {
        std::cerr << "Expected a nonblank name.\n";
        return 1;
    }
    std::cout << name << " | " << age << '\n';
}
