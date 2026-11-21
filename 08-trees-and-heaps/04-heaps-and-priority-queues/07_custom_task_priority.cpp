/*
 At most 1000 bounded integers; duplicates allowed; empty operations return explicit
absence. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Comparator returns true when a should come after b; lower numeric priority
wins, then lexicographically smaller name.

Tasks(2, B),(1, Z),(1, A) pop A, Z, B.

A strict ordering on(priority, name) determines one consistent queue extreme.

O(log(n+1)) push/pop comparisons; string comparisons additionally depend on name length.

Comparator must be strict; using <= violates equal-element ordering.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <queue>

struct Task {
    int priority;
    std::string name;
};

struct Later {
    bool operator()(const Task& a, const Task& b) const {
        if (a.priority != b.priority) {
            return a.priority > b.priority;
        }
        return a.name > b.name;
    }
};

int main() {
    std::priority_queue<Task, std::vector<Task>, Later> q;
    q.push({2, "B"});
    q.push({1, "Z"});
    q.push({1, "A"});
    assert(q.top().name == "A");
    q.pop();
    assert(q.top().name == "Z");
    q.pop();
    assert(q.top().name == "B");
    std::cout << "checks passed\n";
    return 0;
}
