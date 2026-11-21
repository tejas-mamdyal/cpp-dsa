/*
 Compare English alphanumeric characters ignoring case; other bytes are skipped using
cctype safely.

IDEA AND STATE: Move each endpoint past nonalphanumeric bytes, then compare lowercase forms.

TRACE: A man, a plan, a canal: Panama ->true.

Skip the initial punctuation,compare the outer normalized letters,then advance both sides;all
pairs match for Panama.

Every relevant endpoint pair must agree; skipped characters cannot affect the
specified comparison.

O(n) time, O(1) extra space.

Cast char to unsigned char before cctype; this is not Unicode normalization.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <cctype>

bool validPalindrome(const std::string& text) {
    std::size_t left = 0;
    std::size_t right = text.size();
    while (left < right) {
        while (left < right && !std::isalnum(static_cast<unsigned char>(text[left]))) {
            ++left;
        }
        while (left < right && !std::isalnum(static_cast<unsigned char>(text[right - 1]))) {
            --right;
        }
        if (left == right) {
            break;
        }
        if (std::tolower(static_cast<unsigned char>(text[left]))
            != std::tolower(static_cast<unsigned char>(text[right - 1]))) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

int main() {
    assert(validPalindrome("A man, a plan, a canal: Panama"));
    assert(validPalindrome(""));
    assert(validPalindrome("!!!"));
    assert(!validPalindrome("race a car"));
    assert(!validPalindrome("0P"));
    std::cout << "checks passed\n";
    return 0;
}
