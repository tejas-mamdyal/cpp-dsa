/*
PROGRAMMING FROM ZERO — no prerequisites.
A program is a precise sequence of instructions applied to data. An algorithm
is the method; C++ is the language used to express it. For a bill splitter:
input = bill and people, processing = division, output = each person's share.
Before coding, write pseudocode: read -> validate -> calculate -> display.
Source text is compiled, then linked with library code to create an executable.
Syntax errors prevent compilation; logic errors compile but give wrong answers.
Dry run: bill=90, people=3 -> valid -> share=30 -> print 30.
Exercise: add a tip percentage before dividing; test zero people and bad input.
Time O(1), auxiliary space O(1): no growing collection or repeated processing.
*/
#include <iostream> // Makes the standard input/output declarations available.

int main() {         // Execution begins here; braces delimit a block of instructions.
    double bill = 0; // A variable is named storage; double stores approximate real values.
    int people = 0;  // int stores whole numbers. Initialize before using a variable.
    std::cout << "Enter bill and number of people: ";
    // >> extracts formatted values; a failed extraction makes the stream false.
    if (!(std::cin >> bill >> people) || bill < 0 || people <= 0) {
        std::cerr << "Use a nonnegative bill and a positive whole number of people.\n";
        return 1; // Nonzero reports failure to the operating system.
    }
    // One operand is double, so this is real division rather than integer division.
    const double share = bill / people;         // const prevents reassignment.
    std::cout << "Each pays " << share << '\n'; // << inserts output; ; ends a statement.
    return 0;                                   // Zero reports successful completion.
}
