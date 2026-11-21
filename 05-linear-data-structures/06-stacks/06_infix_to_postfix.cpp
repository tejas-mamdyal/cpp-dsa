/*
OPERATOR STACK HANDLES PRECEDENCE AND PARENTHESES PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Single ASCII letter/digit operands,binary +,-,*,/,parentheses/spaces. No unary
operators or multi-character operands;invalid syntax returns absence. IDEA AND STATE: Emit
operands immediately, delay operators until higher/equal precedence or closing parentheses.
TRACE: a+b*c ->abc*+;(a+b)*c ->ab+c*. CORRECTNESS: Operators leave the stack only after their
required operands have been emitted; left associativity pops equal precedence. COST: O(n) time
and space; each operator pushes/pops once. PITFALL: Operand order and unmatched parentheses
need validation, not merely precedence handling. PRACTICE: Change the example, predict each
state update and add an empty/boundary case. No input unless explicitly stated. Assertions are
the teaching test harness and must remain enabled; success prints checks passed. These bounds
describe the helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <optional>

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

std::optional<std::string> postfix(const std::string& text) {
    std::string output;
    std::vector<char> operators;
    bool needOperand = true;
    for (char ch : text) {
        if (ch == ' ') {
            continue;
        }
        bool operand =
            (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
        if (operand) {
            if (!needOperand) {
                return std::nullopt;
            }
            output += ch;
            needOperand = false;
        } else if (ch == '(') {
            if (!needOperand) {
                return std::nullopt;
            }
            operators.push_back(ch);
        } else if (ch == ')') {
            if (needOperand) {
                return std::nullopt;
            }
            while (!operators.empty() && operators.back() != '(') {
                output += operators.back();
                operators.pop_back();
            }
            if (operators.empty()) {
                return std::nullopt;
            }
            operators.pop_back();
        } else if (precedence(ch) > 0) {
            if (needOperand) {
                return std::nullopt;
            }
            while (!operators.empty() && operators.back() != '('
                   && precedence(operators.back()) >= precedence(ch)) {
                output += operators.back();
                operators.pop_back();
            }
            operators.push_back(ch);
            needOperand = true;
        } else {
            return std::nullopt;
        }
    }
    if (needOperand) {
        return std::nullopt;
    }
    while (!operators.empty()) {
        if (operators.back() == '(') {
            return std::nullopt;
        }
        output += operators.back();
        operators.pop_back();
    }
    return output;
}

int main() {
    assert(postfix("a+b*c") == "abc*+");
    assert(postfix("(a+b)*c") == "ab+c*");
    assert(postfix("a-b-c") == "ab-c-");
    assert(!postfix("a+"));
    assert(!postfix("(a+b"));
    assert(!postfix("ab"));
    assert(!postfix("()"));
    assert(!postfix("-a"));
    std::cout << "checks passed\n";
    return 0;
}
