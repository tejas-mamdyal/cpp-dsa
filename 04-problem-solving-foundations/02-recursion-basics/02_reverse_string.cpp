/*
REVERSE TEXT BY SHRINKING ITS UNSOLVED INTERVAL
PREREQUISITES
Phase1 functions/loops/validation, Phase2 references/strings/vectors, and Phase3
complexity. Follow this unit's README order; the first factorial lesson introduces
recursion and the later lessons build on it. No capturing lambda is required.

CONTRACT
Read one full line of at most80 characters and print its reversal. Preserve spaces; empty input line prints an empty output line. Missing line or excess length gives stderr/exit1; later lines are ignored.

IDEA AND STATE
This adopts the earlier reverseString/reverseHelper example with [left,right) bounds. Exchange the outer characters, then recursively solve only the interior. Each call borrows the same string.

TRACE
hello:[0,5) swaps h/o ->oellh;[1,4) swaps e/l ->olleh;[2,3) stops.

WHY IT WORKS AND TERMINATES
Once the endpoints are swapped they already occupy their final positions. Recursing on the interior preserves those endpoints and finishes the remaining positions. Length decreases by2.

Theta(n+1) traversal work and O(n+1) stack depth bound; in-place character updates use O(1) non-stack working state. The string input/output occupies O(n).

PITFALL AND PRACTICE
In-place does not mean O(1) auxiliary space when recursion uses a stack. A copied substring would add allocations; borrow one string and move indices instead.
Predict a new small trace and test a boundary before changing the contract.
*/
#include <iostream>
#include <string>
#include <utility>

void reverseHelper(std::string& text, std::size_t left, std::size_t right) {
    if (right - left <= 1) {
        return;
    }
    std::swap(text[left], text[right - 1]);
    reverseHelper(text, left + 1, right - 1);
}

void reverseString(std::string& text) {
    reverseHelper(text, 0, text.size());
}

int main() {
    std::string text;
    if (!std::getline(std::cin, text) || text.size() > 80) {
        std::cerr << "Expected a line of at most80 characters.\n";
        return 1;
    }
    reverseString(text);
    std::cout << text << '\n';
    return 0;
}
