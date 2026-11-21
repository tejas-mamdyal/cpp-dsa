/*
 Rectangular X/O grid<=30x 30; temporary # is not an input symbol. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

Flood all boundary O regions with a temporary marker; only unprotected O
can be surrounded.

The bottom-row O is protected; the enclosed middle group is flipped.

An open cell escapes enclosure exactly when its component reaches a boundary.

O(R*C) time/copy/stack.

Starting from interior cells does not directly tell which components touch a
boundary.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>

void protect(std::vector<std::string>& a, int r, int c) {
    if (r < 0 || c < 0 || r >= static_cast<int>(a.size()) || c >= static_cast<int>(a[0].size())
        || a[r][c] != 'O') {
        return;
    }
    a[r][c] = '#';
    protect(a, r + 1, c);
    protect(a, r - 1, c);
    protect(a, r, c + 1);
    protect(a, r, c - 1);
}

std::vector<std::string> capture(std::vector<std::string> a) {
    if (a.empty()) {
        return a;
    }
    int rows = static_cast<int>(a.size());
    int cols = static_cast<int>(a[0].size());
    for (int r = 0; r < rows; ++r) {
        protect(a, r, 0);
        protect(a, r, cols - 1);
    }
    for (int c = 0; c < cols; ++c) {
        protect(a, 0, c);
        protect(a, rows - 1, c);
    }
    for (auto& row : a) {
        for (char& x : row) {
            x = x == '#' ? 'O' : 'X';
        }
    }
    return a;
}

int main() {
    assert((capture({"XXXX", "XOOX", "XXOX", "XOXX"})
            == std::vector<std::string>{"XXXX", "XXXX", "XXXX", "XOXX"}));
    assert(capture({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
