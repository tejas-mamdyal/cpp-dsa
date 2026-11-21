/*
BRACKET CHECKING WITH A MANUALLY INDEXED STACK PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 All three bracket types; other characters ignored. IDEA AND STATE: A pre-sized char
buffer plus used count implements push/top/pop. TRACE: ([x]) is valid;([)] fails. CORRECTNESS:
The stack is exactly the unmatched openers in their nesting order. COST: O(n) time,O(n) stack
storage. PITFALL: Counts alone do not check nesting and a closing bracket cannot pop an empty
stack. PRACTICE: Change the example, predict each state update and add an empty/boundary case.
No input unless explicitly stated. Assertions are the teaching test harness and must remain
enabled; success prints checks passed. These bounds describe the helper, not a claim that a
fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>

bool validParentheses(const std::string& text) {
    std::vector<char> stack(text.size());
    std::size_t used = 0;
    for (char ch : text) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stack[used++] = ch;
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (used == 0) {
                return false;
            }
            char expected = '(';
            if (ch == ']') {
                expected = '[';
            } else if (ch == '}') {
                expected = '{';
            }
            if (stack[used - 1] != expected) {
                return false;
            }
            --used;
        }
    }
    return used == 0;
}

int main() {
    assert(validParentheses("([x])"));
    assert(validParentheses(""));
    assert(!validParentheses("([)]"));
    assert(!validParentheses(")"));
    assert(!validParentheses("("));
    std::cout << "checks passed\n";
    return 0;
}
