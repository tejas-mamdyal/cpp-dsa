/*
EVALUATE A VALIDATED POSTFIX TOKEN STREAM PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Space-separated signed ints[-1000,1000] and +,-,*,/;intermediate values must
stay[-1000000,1000000]. Return absence on malformed input. IDEA AND STATE: Pop right operand
then left, compute safely in long long, and push the bounded result. TRACE: 3 4 + 2 * ->14;10
3 - ->7. CORRECTNESS: The stack stores results of complete preceding subexpressions; an
operator combines the latest two. COST: O(tokens+characters) time,O(tokens) space. PITFALL:
Division by0,missing operands,extra results and overflow of the stated bound are errors.
PRACTICE: Change the example, predict each state update and add an empty/boundary case. No
input unless explicitly stated. Assertions are the teaching test harness and must remain
enabled; success prints checks passed. These bounds describe the helper, not a claim that a
fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <string>
#include <sstream>

std::optional<long long> evaluate(const std::string& expression) {
    std::istringstream input(expression);
    std::string token;
    std::vector<long long> stack;
    while (input >> token) {
        bool operation = token == "+" || token == "-" || token == "*" || token == "/";
        if (!operation) {
            std::istringstream number(token);
            long long value = 0;
            char extra = ' ';
            if (!(number >> value) || (number >> extra) || value < -1000 || value > 1000) {
                return std::nullopt;
            }
            stack.push_back(value);
            continue;
        }
        if (stack.size() < 2) {
            return std::nullopt;
        }
        long long right = stack.back();
        stack.pop_back();
        long long left = stack.back();
        stack.pop_back();
        long long value = 0;
        if (token == "+") {
            value = left + right;
        } else if (token == "-") {
            value = left - right;
        } else if (token == "*") {
            value = left * right;
        } else {
            if (right == 0) {
                return std::nullopt;
            }
            value = left / right;
        }
        if (value < -1000000 || value > 1000000) {
            return std::nullopt;
        }
        stack.push_back(value);
    }
    if (stack.size() != 1) {
        return std::nullopt;
    }
    return stack.back();
}

int main() {
    assert(evaluate("3 4 + 2 *") == 14);
    assert(evaluate("10 3 -") == 7);
    assert(evaluate("6 3 /") == 2);
    assert(evaluate("-3 2 *") == -6);
    assert(!evaluate("3 +"));
    assert(!evaluate("3 4"));
    assert(!evaluate("1 0 /"));
    assert(!evaluate("1000 1000 * 1000 *"));
    assert(!evaluate(""));
    std::cout << "checks passed\n";
    return 0;
}
