/*
TRUTH VALUES
Route: Core | Prerequisites: Unit 01: statements, variables and streams.

bool stores true/false; output normally uses 1/0. boolalpha changes their display to
true/false.

O(1) time and O(1) auxiliary space for these bounded examples.

A display flag changes later output on the same stream.
*/
#include <iostream>

int main() {
    bool ready = true;
    bool finished = false;
    std::cout << ready << ' ' << finished << "\n";
    std::cout << std::boolalpha << ready << ' ' << finished << "\n";
}
