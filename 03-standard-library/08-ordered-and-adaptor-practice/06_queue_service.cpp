/*
FIFO SERVICE WITH A QUEUE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Process requests in arrival order; front reads and pop removes.
Trace: arrivals4,7,2 are served4,7,2.
Why it works: Queue insertion at the back and removal at the front preserve arrival order.
Cost: O(n) total operations and O(n) stored requests/output.
Common mistake: pop returns no element; read front before removing and only when nonempty.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <queue>
#include <vector>

int main() {
    std::queue<int> pending;
    pending.push(4);
    pending.push(7);
    pending.push(2);
    std::vector<int> served;
    while (!pending.empty()) {
        served.push_back(pending.front());
        pending.pop();
    }
    assert((served == std::vector<int>{4, 7, 2}));
    std::cout << "checks passed\n";
}
