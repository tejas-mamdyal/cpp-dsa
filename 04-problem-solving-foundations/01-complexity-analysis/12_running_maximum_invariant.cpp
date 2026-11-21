/*
EXPLAIN A LOOP USING INITIALIZATION MAINTENANCE TERMINATION
PREREQUISITES
Phase1 loops/functions/validation and Phase2 vector/reference/library interfaces.
Read this unit's NOTES.md before the programs. No recursion is used here.

PROBLEM AND CONTRACT
No input. Return the maximum of a nonempty bounded vector via an output parameter, or false for empty input without modifying the output.

IDEA
The invariant: before index i is processed, best is the maximum of indices0..i-1. Start from the first actual value, not0.

TRACE
{-5,-2,-9}: best=-5 ->-2 ->-2. Empty input leaves the caller result unchanged.

WHY IT WORKS
Initialization: the first-element prefix has that element as its maximum. Maintenance: comparing the next value extends the prefix correctly. Termination: the prefix is the whole input.

Theta(n+1) time, O(1) auxiliary storage. Only constant-size scalar state is retained.

PITFALL AND PRACTICE
Initializing the maximum to0 fails for all-negative input. An invariant explains correctness; a few passing samples are supporting checks rather than a proof.
Change the traced size, predict the result, and test the smallest valid size.
*/
#include <iostream>
#include <vector>
#include <cassert>

bool maximum(const std::vector<int>& values, int& answer) {
    if (values.empty()) {
        return false;
    }
    int best = values[0];
    for (std::size_t i = 1; i < values.size(); ++i) {
        // best describes the processed prefix, then includes this new element.
        if (values[i] > best) {
            best = values[i];
        }
    }
    answer = best;
    return true;
}

int main() {
    int answer = 99;
    assert(maximum({-5, -2, -9}, answer) && answer == -2);
    assert(maximum({7}, answer) && answer == 7);
    assert(maximum({3, 3, 1}, answer) && answer == 3);
    assert(!maximum({}, answer));
    assert(answer == 3);
    std::cout << "checks passed\n";
    return 0;
}
