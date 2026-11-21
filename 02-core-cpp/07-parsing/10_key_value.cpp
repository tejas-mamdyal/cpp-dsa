/*
READ A KEY=VALUE SETTING
Prerequisites: Phase1 streams/loops/validation and Phase2 strings/vectors.
This is a standalone program: all its code is here; only standard headers are used.

INPUT / OUTPUT
Read one line with a nonempty single-word key, one equals sign, and an int value. Spaces around the key/sign/value are allowed. Print normalized key=value.
Invalid required input prints an error to stderr and exits with status 1. Results have no prompts.

IDEA AND NEW SYNTAX
find locates the delimiter and substr copies the parts around it. A string stream checks that each part contains exactly the expected field. string::npos means no delimiter was found; substr(start) takes the remaining suffix.

TRACE
 attempts = 3 -> key attempts, value 3 -> attempts=3.

COST AND PRACTICE
O(L) time and space for a line of L characters.
Numeric extraction rejects int overflow.
Try an empty/boundary case and a malformed field before changing the program.
Follow-up: add one computed statistic without hiding the parsing in another file.
*/
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    if (!std::getline(std::cin, line)) {
        std::cerr << "Expected a setting.\n";
        return 1;
    }
    std::size_t equal = line.find('=');
    if (equal == std::string::npos || line.find('=', equal + 1) != std::string::npos) {
        std::cerr << "Expected exactly one equals sign.\n";
        return 1;
    }
    std::istringstream keyInput(line.substr(0, equal));
    std::string key;
    char extra = ' ';
    if (!(keyInput >> key) || (keyInput >> extra)) {
        std::cerr << "Invalid key.\n";
        return 1;
    }
    std::istringstream valueInput(line.substr(equal + 1));
    int value = 0;
    if (!(valueInput >> value) || (valueInput >> extra)) {
        std::cerr << "Invalid integer value.\n";
        return 1;
    }
    std::cout << key << '=' << value << '\n';
}
