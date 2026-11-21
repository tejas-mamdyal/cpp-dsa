/*
USE NEXT_PERMUTATION AS AN INDEPENDENT ENUMERATION

 n<=8; unique orderings sorted lexicographically even with repeated values. Unless
narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume
valid acyclic owned structures; exponential searches use the smaller bounds stated here. No
input; keep assertions enabled. Success prints checks passed.

Sort first; do-while records the current sequence before advancing to the
next lexicographic sequence.

2,1,1 sorts to 1,1,2 then advances to 1,2,1 and 2,1,1.

Each successor is the least greater arrangement; starting at minimum visits all
value orderings once.

O((n+1)*n!+n log n) upper-bound time; O(n) copied input plus output.

A while loop that advances before recording loses the first permutation, including the
empty one.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> permutations(std::vector<int> a) {
    std::sort(a.begin(), a.end());
    std::vector<std::vector<int>> out;
    do {
        out.push_back(a);
    } while (std::next_permutation(a.begin(), a.end()));
    return out;
}

int main() {
    assert((permutations({2, 1, 1})
            == std::vector<std::vector<int>>{{1, 1, 2}, {1, 2, 1}, {2, 1, 1}}));
    assert(permutations({}).size() == 1);
    std::cout << "checks passed\n";
    return 0;
}
