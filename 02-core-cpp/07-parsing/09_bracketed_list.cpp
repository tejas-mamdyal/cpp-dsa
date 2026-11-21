/*
VALIDATE PUNCTUATION IN A BRACKETED LIST
Prerequisites: Phase1 streams/loops/validation and Phase2 strings/vectors.
This is a standalone program: all its code is here; only standard headers are used.

INPUT / OUTPUT
Read a line such as [1, 2, -3]. Require brackets and commas; allow an empty list []. Reject trailing text/commas, missing brackets and malformed integers. Print normalized values on one line.
Invalid required input prints an error to stderr and exits with status 1. Results have no prompts.

IDEA AND NEW SYNTAX
Read one punctuation character at a time and check it. peek() looks at the next character without consuming it, so after whitespace it can recognize an empty list. Each successful iteration reads a number and then a comma or closing bracket.

TRACE
[1, -2] -> opening bracket, value 1, comma, value -2, closing bracket -> output 1 -2.

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
        std::cerr << "Expected a list.\n";
        return 1;
    }
    std::istringstream input(line);
    char symbol = ' ';
    if (!(input >> symbol) || symbol != '[') {
        std::cerr << "Expected opening bracket.\n";
        return 1;
    }
    std::vector<int> values;
    input >> std::ws;
    if (input.peek() == ']') {
        input.get(symbol); // Consume the closing bracket seen by peek().
    } else {
        while (true) {
            int value = 0;
            if (!(input >> value >> symbol)) {
                std::cerr << "Expected an integer and separator.\n";
                return 1;
            }
            values.push_back(value);
            if (symbol == ']') {
                break;
            }
            if (symbol != ',') {
                std::cerr << "Expected comma or closing bracket.\n";
                return 1;
            }
        }
    }
    if (input >> symbol) {
        std::cerr << "Unexpected text after the list.\n";
        return 1;
    }

    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << values[i];
    }
    std::cout << '\n';
}
