/*
KEEP SPACES INSIDE QUOTED FIELDS
Prerequisites: Phase1 streams/loops/validation and Phase2 strings/vectors.
This is a standalone program: all its code is here; only standard headers are used.

INPUT / OUTPUT
Read one line containing name, department and age0..120. Text fields may be quoted to contain spaces, or unquoted single words. Fields must be nonempty. Reject missing closing quotes and extra fields. Print name | department | age.
Invalid required input prints an error to stderr and exits with status 1. Results have no prompts.

IDEA AND NEW SYNTAX
std::quoted from iomanip extracts quoted text, removes its delimiters and handles escaped quotes. Unlike plain >> string, it can read Ada Lovelace as one field. A string stream keeps validation confined to this one line.

TRACE
"Ada Lovelace" "Computer Science" 20 -> two text fields plus age -> Ada Lovelace | Computer Science | 20.

COST AND PRACTICE
O(L) time and space for a record of L characters.
Numeric extraction rejects int overflow.
Try an empty/boundary case and a malformed field before changing the program.
Follow-up: add one computed statistic without hiding the parsing in another file.
*/
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    if (!std::getline(std::cin, line)) {
        std::cerr << "Expected a record.\n";
        return 1;
    }
    std::istringstream record(line);
    std::string name;
    std::string department;
    int age = 0;
    char extra = ' ';
    if (!(record >> std::quoted(name) >> std::quoted(department) >> age) || name.empty()
        || department.empty() || age < 0 || age > 120 || (record >> extra)) {
        std::cerr << "Invalid quoted record.\n";
        return 1;
    }
    std::cout << name << " | " << department << " | " << age << '\n';
}
