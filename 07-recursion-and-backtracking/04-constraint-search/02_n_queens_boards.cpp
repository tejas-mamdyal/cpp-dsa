/*
 n 0..8; return row strings using Q and dot. Unless narrowed, at most 100
nodes/elements with values in [-1000,1000]. Recursive examples assume valid acyclic owned
structures; exponential searches use the smaller bounds stated here. No input; keep assertions
enabled. Success prints checks passed.

Keep chosen columns; check each earlier row directly as a readable O(n)
validity baseline.

Columns 1,3,0,2 render .Q..,...Q, Q...,..Q.

Each row chooses one legal column, and a complete column route uniquely defines a
board.

O(n^2*n!) upper-bound time; O(n) auxiliary plus O(n^2) per saved board.

A board is copied at the leaf before undoing its last column.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstddef>

void visit(int n, std::vector<int>& columns, std::vector<std::vector<std::string>>& out) {
    int row = static_cast<int>(columns.size());
    if (row == n) {
        std::vector<std::string> board(static_cast<std::size_t>(n),
                                       std::string(static_cast<std::size_t>(n), '.'));
        for (int r = 0; r < n; ++r) {
            board[r][columns[r]] = 'Q';
        }
        out.push_back(board);
        return;
    }
    for (int c = 0; c < n; ++c) {
        bool legal = true;
        for (int r = 0; r < row; ++r) {
            if (columns[r] == c || std::abs(columns[r] - c) == row - r) {
                legal = false;
                break;
            }
        }
        if (!legal) {
            continue;
        }
        columns.push_back(c);
        visit(n, columns, out);
        columns.pop_back();
    }
}

std::vector<std::vector<std::string>> boards(int n) {
    std::vector<int> columns;
    std::vector<std::vector<std::string>> out;
    visit(n, columns, out);
    return out;
}

int main() {
    assert(boards(4).size() == 2);
    assert(boards(2).empty());
    assert(boards(0).size() == 1);
    assert(boards(4)[0][0] == ".Q..");
    std::cout << "checks passed\n";
    return 0;
}
