/*
CHARACTER LITERALS AND VARIABLES
Route: Core | Prerequisites: Unit 01: statements, variables and streams.

Single quotes denote one character; double quotes denote a text literal. Formatted char
extraction skips whitespace.

O(1) time and O(1) auxiliary space for these bounded examples.

This lesson handles one char, not a full word or Unicode code point.
*/
#include <iostream>

int main() {
    char letter = '?';
    std::cin >> letter;
    std::cout << '[' << letter << "]\n";
}
