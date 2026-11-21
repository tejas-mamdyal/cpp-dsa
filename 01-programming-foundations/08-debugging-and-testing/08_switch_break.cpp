/*
PREVENT ACCIDENTAL FALLTHROUGH
Route: Core | Prerequisites: Units 01–07; functions and input validation.

break exits switch after the selected output; otherwise the next case body could also
execute.

O(1) time and O(1) auxiliary space.

A switch default should not silently accept unsupported operation codes.
*/
#include <iostream>

int main() {
    int code = 0;
    if (!(std::cin >> code) || !(code == 1 || code == 2)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    switch (code) {
        case 1:
            std::cout << "one\n";
            break;
        case 2:
            std::cout << "two\n";
            break;
    }
}
