/*
 n in [0,16]; count all calls, leaves and maximum frames of a full binary decision
tree. No input is required. Keep assertions enabled; a successful run prints checks passed.
Tiny bounds are intentional because output grows exponentially or factorially.

remaining decreases per level. Counters are reference accumulators; depth
counts active frames including the root. A leaf is a complete assignment, not every function
call.

n=2 has one root, two children and four leaves: seven calls, four leaves, three
simultaneously active frames.

A depth-n full binary tree has 2^d nodes at each depth d; summing gives 2^(n+1)-1
calls and 2^n leaves.

O(2^n) time, O(n+1) call-stack space, O(1) counters and no exponential saved output.

Exponential work does not imply exponential active recursion space. The
instrumentation is unnecessary when only a closed-form count is wanted.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

struct Counts {
    long long calls = 0;
    long long leaves = 0;
    int maxFrames = 0;
};

void measure(int remaining, int frames, Counts& out) {
    ++out.calls; // Count this invocation, including internal nodes.
    out.maxFrames = std::max(out.maxFrames, frames);
    if (remaining == 0) {
        ++out.leaves;
        return;
    }
    measure(remaining - 1, frames + 1, out);
    measure(remaining - 1, frames + 1, out);
}

int main() {
    for (int n = 0; n <= 12; ++n) {
        Counts out;
        measure(n, 1, out);
        assert(out.calls == (1LL << (n + 1)) - 1);
        assert(out.leaves == (1LL << n));
        assert(out.maxFrames == n + 1);
    }
    std::cout << "checks passed\n";
    return 0;
}
