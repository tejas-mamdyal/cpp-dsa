/*
BALANCED BRACKETS WITH A STACK
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Push opening brackets and match every closing bracket with the latest opener. Other characters are ignored.
Trace: ([x]) succeeds;([)] fails.
Why it works: The stack stores exactly the unmatched opening brackets in nesting order.
Cost: O(n) time and O(n) stack space.
Common mistake: Equal total counts do not prove correct order or nesting.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <stack>
#include <string>

bool balanced(const std::string& text) {
    std::stack<char> open;
    for (char ch : text) {
        if (ch == '(' || ch == '[' || ch == '{') {
            open.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (open.empty()) {
                return false;
            }
            char expected = '(';
            if (ch == ']') {
                expected = '[';
            } else if (ch == '}') {
                expected = '{';
            }
            if (open.top() != expected) {
                return false;
            }
            open.pop();
        }
    }
    return open.empty();
}

int main() {
    assert(balanced("([x])"));
    assert(balanced(""));
    assert(!balanced("([)]"));
    assert(!balanced(")"));
    assert(!balanced("("));
    std::cout << "checks passed\n";
}
