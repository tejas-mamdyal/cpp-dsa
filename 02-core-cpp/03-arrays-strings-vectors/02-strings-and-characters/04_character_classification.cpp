/*
CLASSIFY AND CONVERT CHARACTERS SAFELY
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use cctype functions with an unsigned-char conversion; this lesson handles ordinary English text.
Trace: A1 ! contains one letter and one decimal digit.
Why it works: The unsigned-char conversion satisfies the cctype argument contract.
Cost: O(n) time in the length of the data; O(1) auxiliary space.
Common mistake: Passing a negative signed char to cctype is invalid. Byte-wise conversion is not general Unicode case folding.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <cctype>

int main() {
    std::string text = "A1 !";
    int letters = 0;
    int digits = 0;
    for (char ch : text) {
        unsigned char byte = static_cast<unsigned char>(ch);
        if (std::isalpha(byte)) {
            ++letters;
        }
        if (std::isdigit(byte)) {
            ++digits;
        }
    }
    assert(letters == 1);
    assert(digits == 1);
    char lowered = static_cast<char>(std::tolower(static_cast<unsigned char>('A')));
    assert(lowered == 'a');
    std::cout << "checks passed\n";
}
