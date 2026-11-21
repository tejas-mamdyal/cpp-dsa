/*
TOWER OF HANOI: ORDERED BRANCHING WITH A LEGALITY ORACLE
PREREQUISITES
Phase1 functions/loops/validation, Phase2 references/strings/vectors, and Phase3
complexity. Follow this unit's README order; the first factorial lesson introduces
recursion and the later lessons build on it. No capturing lambda is required.

CONTRACT
Read disk count in[0,5]. Move all disks from peg A to C using B. Print each move as disk from ->to, then moves count. Disks are numbered1(smallest)..n. Invalid/missing input gives stderr/exit1; later tokens are ignored.

IDEA AND STATE
Move n-1 disks to the spare peg, move disk n to the destination, then move the smaller stack onto it. A Move record stores disk/from/to so a separate rules simulator can validate the result.

TRACE
n=2:disk1 A->B,disk2 A->C,disk1 B->C; total3. n=0 generates no moves.

WHY IT WORKS AND TERMINATES
By induction the smaller stack moves legally out of the way, freeing the largest disk. Moving the smaller stack back onto a larger disk is legal. Every branch decreases n, and operation order is essential.

T(n)=2*T(n-1)+Theta(1):Theta(2^n) time, O(n+1) call stack. This implementation also stores2^n-1 output moves, so total retained output is exponential. The simulator uses O(n) peg storage.

PITFALL AND PRACTICE
Two smaller calls are still exponential here because both have size n-1, unlike balanced range sum. The small input bound limits output. The validator checks game rules rather than reproducing the recursive recurrence.
Predict a new small trace and test a boundary before changing the contract.
*/
#include <iostream>
#include <vector>
#include <cassert>

struct Move {
    int disk;
    int from;
    int to;
};

void hanoi(int n, int from, int spare, int to, std::vector<Move>& moves) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, from, to, spare, moves);
    moves.push_back({n, from, to});
    hanoi(n - 1, spare, from, to, moves);
}

bool legalSolution(int n, const std::vector<Move>& moves) {
    std::vector<std::vector<int>> pegs(3);
    for (int disk = n; disk >= 1; --disk) {
        pegs[0].push_back(disk);
    }
    for (const Move& move : moves) {
        if (move.from < 0 || move.from >= 3 || move.to < 0 || move.to >= 3
            || move.from == move.to) {
            return false;
        }
        if (pegs[move.from].empty() || pegs[move.from].back() != move.disk) {
            return false;
        }
        if (!pegs[move.to].empty() && pegs[move.to].back() < move.disk) {
            return false;
        }
        pegs[move.from].pop_back();
        pegs[move.to].push_back(move.disk);
    }
    return pegs[0].empty() && pegs[1].empty() && pegs[2].size() == static_cast<std::size_t>(n);
}

int main() {
    int n = 0;
    if (!(std::cin >> n) || n < 0 || n > 5) {
        std::cerr << "Expected disk count in 0..5.\n";
        return 1;
    }
    for (int disks = 0; disks <= 5; ++disks) {
        std::vector<Move> check;
        hanoi(disks, 0, 1, 2, check);
        assert(legalSolution(disks, check));
        assert(check.size() == static_cast<std::size_t>((1 << disks) - 1));
    }
    assert(!legalSolution(2, {{2, 0, 2}}));
    std::vector<Move> moves;
    hanoi(n, 0, 1, 2, moves);
    for (const Move& move : moves) {
        std::cout << move.disk << ' ' << static_cast<char>('A' + move.from) << " -> "
                  << static_cast<char>('A' + move.to) << '\n';
    }
    std::cout << "moves " << moves.size() << '\n';
    return 0;
}
