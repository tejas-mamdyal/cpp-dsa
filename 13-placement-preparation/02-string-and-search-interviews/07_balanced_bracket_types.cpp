/*
 Input consists only of()[]{} characters.

The stack holds unmatched openings in nesting order.

([)] closes parenthesis while bracket is on top, so reject.

A close must match the most recent unmatched opening in every properly nested
sequence.

O(n) time, O(n) stack.

Equal total counts do not imply proper nesting.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>

bool balanced(const std::string& s) {
    std::vector<char> stack;
    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push_back(ch);
        } else {
            char wanted = ch == ')' ? '(' : ch == ']' ? '[' : '{';
            if (stack.empty() || stack.back() != wanted) {
                return false;
            }
            stack.pop_back();
        }
    }
    return stack.empty();
}

int main() {
    assert(balanced("{[()]}"));
    assert(!balanced("([)]") && !balanced("("));
    assert(balanced(""));
    std::cout << "checks passed\n";
    return 0;
}
