/*
BORROW TEXT AND SHRINK A HALF-OPEN RANGE
PREREQUISITES
Phase1 functions/loops/validation, Phase2 references/strings/vectors, and Phase3
complexity. Follow this unit's README order; the first factorial lesson introduces
recursion and the later lessons build on it. No capturing lambda is required.

CONTRACT
Read one full line of at most80 characters. Compare exact char units, including spaces and case; empty and singleton strings are palindromes. Print0/1. Missing line or excess length: stderr/exit1; subsequent lines are ignored.

IDEA AND STATE
Use [left,right):left is included and right excluded. No string is copied in recursive calls. Ranges of length0 or1 are complete; otherwise compare endpoints and shrink inward.

TRACE
level:[0,5) compares l/l, then[1,4) e/e, then[2,3) returns true.

WHY IT WORKS AND TERMINATES
A longer string is a palindrome exactly when its endpoints match and its interior is a palindrome. The range length decreases by2; the base is checked before subtracting from right.

O(n) worst time, O(n) stack space; an early mismatch can finish in O(1). Passing const string& avoids O(n) copies at each call.

PITFALL AND PRACTICE
The helper requires0<=left<=right<=text.size(). Do not form size()-1 for an empty unsigned size. Byte/char symmetry is not Unicode grapheme normalization.
Predict a new small trace and test a boundary before changing the contract.
*/
#include <iostream>
#include <string>

bool palindromeRange(const std::string& text, std::size_t left, std::size_t right) {
    if (right - left <= 1) {
        return true;
    }
    if (text[left] != text[right - 1]) {
        return false;
    }
    return palindromeRange(text, left + 1, right - 1);
}

int main() {
    std::string text;
    if (!std::getline(std::cin, text) || text.size() > 80) {
        std::cerr << "Expected a line of at most80 characters.\n";
        return 1;
    }
    std::cout << palindromeRange(text, 0, text.size()) << '\n';
    return 0;
}
