/*
CHOOSE PRIORITY_QUEUE ORDERING EXPLICITLY

 At most 1000 bounded integers; duplicates allowed; empty operations return explicit
absence. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Default priority_queue exposes largest; greater<int> exposes smallest.

Insert 3,1,2: max top 3, min top 1; pop then reveals 2 in both.

The container maintains the selected heap comparator after each push/pop.

O(log(n+1)) push/pop, O(1) top, O(n) stored values.

pop removes but does not return a value; read top first and check nonempty.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <functional>

// These are owning integer containers,not pointer owners.

int main() {
    std::priority_queue<int> high;
    std::priority_queue<int, std::vector<int>, std::greater<int>> low;
    for (int x : {3, 1, 2}) {
        high.push(x);
        low.push(x);
    }
    assert(high.top() == 3 && low.top() == 1);
    high.pop();
    low.pop();
    assert(high.top() == 2 && low.top() == 2);
    std::cout << "checks passed\n";
    return 0;
}
