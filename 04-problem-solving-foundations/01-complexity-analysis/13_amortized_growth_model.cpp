/*
AMORTIZED COST IS A SEQUENCE GUARANTEE
PREREQUISITES
Phase1 loops/functions/validation and Phase2 vector/reference/library interfaces.
Read this unit's NOTES.md before the programs. No recursion is used here.

PROBLEM AND CONTRACT
No input. Simulate an array whose capacity starts at1 and doubles when full. Count element moves during growth for all push counts0..1024; print pushes and moves for8 and9.

IDEA
This is a teaching model, not an assertion about std::vector exact capacities. A resize copies every currently stored element; ordinary pushes add no copy moves.

TRACE
8 pushes copy1+2+4=7 elements; the9th push adds8 moves, total15.

WHY IT WORKS
Geometric growth sums1+2+4+... to less than2*n moves for n>0. Thus n pushes plus all moves are below3*n despite one push sometimes moving Theta(n) elements.

Simulating n pushes takes Theta(n+1) time and O(1) scalar simulator space. The modeled real array stores Theta(n) elements; one real growth needs temporary old/new allocations.

PITFALL AND PRACTICE
Amortized does not mean probabilistic average, nor that every individual push is constant-time. reserve policies and actual std::vector growth factors are implementation-specific.
Change the traced size, predict the result, and test the smallest valid size.
*/
#include <iostream>
#include <cassert>

long long growthMoves(int pushes) {
    int size = 0;
    int capacity = 1;
    long long moves = 0;
    for (int i = 0; i < pushes; ++i) {
        if (size == capacity) {
            moves += size;
            capacity *= 2;
        }
        ++size;
    }
    return moves;
}

int main() {
    for (int n = 0; n <= 1024; ++n) {
        long long moves = growthMoves(n);
        if (n == 0) {
            assert(moves == 0);
        } else {
            assert(moves < 2LL * n);
            assert(n + moves < 3LL * n);
        }
    }
    assert(growthMoves(8) == 7);
    assert(growthMoves(9) == 15);
    std::cout << "8 " << growthMoves(8) << '\n' << "9 " << growthMoves(9) << '\n';
    return 0;
}
