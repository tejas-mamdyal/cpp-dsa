/*
 Valid nonempty grammar number((+|-|*)number)*; nonnegative numbers<=9 except a
single 10 allowed; at most 8 operators; results fit 64 bits. Unless a different bound is
stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

term holds the current signed multiplication chain; total contains
completed additive terms.

2+3*4-5 commits 2, then 12, then-5 to obtain 9.

Multiplication is completed within a term before additive commitment, matching
the grammar precedence.

O(text length) time, O(1) work.

This is not a general C++ parser; unary signs, division, spaces and parentheses are
outside this declared grammar.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <cstddef>

long long evaluate(const std::string& text) {
    long long total = 0;
    long long term = 0;
    char operation = '+';
    std::size_t i = 0;
    while (i < text.size()) {
        long long number = 0;
        while (i < text.size() && text[i] >= '0' && text[i] <= '9') {
            number = number * 10 + text[i++] - '0';
        }
        if (operation == '*') {
            term *= number;
        } else {
            total += term;
            term = operation == '+' ? number : -number;
        }
        if (i < text.size()) {
            operation = text[i++];
        }
    }
    return total + term;
}

int main() {
    assert(evaluate("2+3*4-5") == 9);
    assert(evaluate("10-2*3") == 4);
    assert(evaluate("7") == 7);
    std::cout << "checks passed\n";
    return 0;
}
