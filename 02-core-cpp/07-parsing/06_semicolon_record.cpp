/*
SPLIT A SMALL RECORD USING ANOTHER DELIMITER
Prerequisites: Phase1 streams/loops/validation and Phase2 strings/vectors.
This is a standalone program: all its code is here; only standard headers are used.

INPUT / OUTPUT
Read name;department;year on one line. Name and department must be nonempty; year is1..4. Exactly three fields are required. Text fields retain their spaces. Print name | department | year.
Invalid required input prints an error to stderr and exits with status 1. Results have no prompts.

IDEA AND NEW SYNTAX
getline accepts a chosen delimiter, not just comma. Read three fields, reject any fourth field, then validate the numeric field using a string stream. Quoted delimiters are not part of this simple record format.

TRACE
Ada Lovelace;CSE;2 -> nameAda Lovelace,departmentCSE,year2.

COST AND PRACTICE
O(L) time and space for a record of L characters.
Numeric extraction rejects int overflow.
Try an empty/boundary case and a malformed field before changing the program.
Follow-up: add one computed statistic without hiding the parsing in another file.
*/
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    if (!std::getline(std::cin, line) || line.empty() || line.back() == ';') {
        std::cerr << "Invalid record.\n";
        return 1;
    }
    std::istringstream fields(line);
    std::string name;
    std::string department;
    std::string yearText;
    std::string extraField;
    if (!std::getline(fields, name, ';') || !std::getline(fields, department, ';')
        || !std::getline(fields, yearText, ';') || std::getline(fields, extraField, ';')
        || name.empty() || department.empty()) {
        std::cerr << "Expected three nonempty fields.\n";
        return 1;
    }
    std::istringstream number(yearText);
    int year = 0;
    char extra = ' ';
    if (!(number >> year) || (number >> extra) || year < 1 || year > 4) {
        std::cerr << "Invalid year.\n";
        return 1;
    }
    std::cout << name << " | " << department << " | " << year << '\n';
}
