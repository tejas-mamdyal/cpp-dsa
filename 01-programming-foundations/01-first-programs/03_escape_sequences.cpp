/*
REPRESENTING SPECIAL CHARACTERS
Route: Core | Prerequisites: None; read 00-start-here first.

A backslash introduces an escape sequence: \" is a quote, \\ is a literal backslash, and
\n is a newline.

O(1) time/space.

A source escape sequence and its displayed character are different representations.
*/
#include <iostream>

int main() {
    std::cout << "\"C++\"\n"; // Escaped quotes belong to the output, not the string delimiter.
    std::cout << "C:\\course\\lesson.cpp\n"; // Double each literal backslash.
}
