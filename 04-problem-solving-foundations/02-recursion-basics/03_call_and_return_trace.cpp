/*
WATCH DESCENDING CALLS AND RETURNING FRAMES
PREREQUISITES
Phase1 functions/loops/validation, Phase2 references/strings/vectors, and Phase3
complexity. Follow this unit's README order; the first factorial lesson introduces
recursion and the later lessons build on it. No capturing lambda is required.

CONTRACT
Read depth in [0,5]. Print enter messages before recursion, base0 at the base, and leave messages after the child returns. Reject invalid/missing input with stderr/exit1; later tokens are ignored.

IDEA AND STATE
The same function body has two phases. Execution before the recursive call happens while descending; execution after it waits until returning. Each frame retains its own depth value.

TRACE
depth2: enter2,enter1,base0,leave1,leave2. The leave order reverses the enter order.

WHY IT WORKS AND TERMINATES
Depth decreases by1 until0. Each nonbase frame prints exactly once on entry and once after its child completes; no frame is skipped on return.

Theta(depth+1) calls/output records; O(depth+1) stack space. Exact output records:2*depth+1.

PITFALL AND PRACTICE
A return leaves only the current call. It does not erase the suspended caller. Moving a print across the call changes output order even if the recursion still terminates.
Predict a new small trace and test a boundary before changing the contract.
*/
#include <iostream>

void trace(int depth) {
    if (depth == 0) {
        std::cout << "base 0\n";
        return;
    }
    std::cout << "enter " << depth << '\n';
    trace(depth - 1);
    std::cout << "leave " << depth << '\n';
}

int main() {
    int depth = 0;
    if (!(std::cin >> depth) || depth < 0 || depth > 5) {
        std::cerr << "Expected depth in 0..5.\n";
        return 1;
    }
    trace(depth);
    return 0;
}
