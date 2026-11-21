/*
 n in [0,8] pairs;return balanced parentheses strings,opening branches first. n=0
returns one empty string. No input is required. Keep assertions enabled; a successful run
prints checks passed. Tiny bounds are intentional because output grows exponentially or
factorially.

opened and closed count choices already made;path is their text. Baseline
generates all 2^(2n) strings then validates. Prefix rules reject impossible branches
immediately.

n=2: after (, try (( then close twice to (());backtrack to (,close to (),then open
and close to ()(). A prefix starting ) is never created.

A valid string never closes more than it has opened and uses exactly n opens.
These conditions are necessary at each prefix and sufficient at a full-length leaf.

A simple upper bound is O((n+1)*4^n) time; O(n) auxiliary path/stack; output
O((n+1)*C_n),where C_n is the number of valid strings (Catalan count).

Balance at the end alone is insufficient: )( has equal counts but an invalid prefix.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

void visit(int n, int opened, int closed, std::string& path, std::vector<std::string>& out) {
    if (closed == n) {
        out.push_back(path);
        return;
    }
    if (opened < n) {
        path.push_back('(');
        visit(n, opened + 1, closed, path, out);
        path.pop_back();
    }
    if (closed < opened) {
        path.push_back(')');
        visit(n, opened, closed + 1, path, out);
        path.pop_back();
    }
}

std::vector<std::string> parentheses(int n) {
    assert(n >= 0 && n <= 8);
    std::string path;
    std::vector<std::string> out;
    visit(n, 0, 0, path, out);
    return out;
}

int main() {
    assert((parentheses(2) == std::vector<std::string>{"(())", "()()"}));
    assert(parentheses(3).size() == 5);
    assert((parentheses(0) == std::vector<std::string>{""}));
    assert(parentheses(8).size() == 1430);
    std::cout << "checks passed\n";
    return 0;
}
