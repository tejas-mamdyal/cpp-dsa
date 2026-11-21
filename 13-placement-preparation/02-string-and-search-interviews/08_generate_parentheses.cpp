/*
 0<=n<=8.

open and close count the current valid prefix.

For n 2,(() ) without its space and()() are the two outputs.

Every valid sequence obeys the prefix constraint, and each legal next character
is explored exactly once.

O(C_n*n) output work/storage, O(n) recursion excluding output.

Restore prefix after every recursive branch.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>

void generate(int n, int open, int close, std::string& prefix, std::vector<std::string>& out) {
    if (close == n) {
        out.push_back(prefix);
        return;
    }
    if (open < n) {
        prefix += '(';
        generate(n, open + 1, close, prefix, out);
        prefix.pop_back();
    }
    if (close < open) {
        prefix += ')';
        generate(n, open, close + 1, prefix, out);
        prefix.pop_back();
    }
}

std::vector<std::string> parentheses(int n) {
    std::vector<std::string> out;
    std::string prefix;
    generate(n, 0, 0, prefix, out);
    return out;
}

int main() {
    assert(parentheses(3).size() == 5);
    assert((parentheses(0) == std::vector<std::string>{""}));
    std::cout << "checks passed\n";
    return 0;
}
