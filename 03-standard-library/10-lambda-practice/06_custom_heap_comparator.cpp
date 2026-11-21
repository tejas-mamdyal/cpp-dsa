/*
CUSTOM HEAP ORDERING WITH DETERMINISTIC TIES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use a strict functor comparator for priority_queue: greater priority first, smaller ID first on ties.
Trace: priority5 IDs2,1 ->serve ID1 then2 before priority3 ID0.
Why it works: The comparator returns true when the left job has lower precedence than the right job.
Cost: O(log n) push/pop, O(1) top, O(n) stored jobs.
Common mistake: Heap comparator direction differs from sorted-output intuition; never use <= and test ties explicitly.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <queue>
#include <vector>

struct Job {
    int priority;
    int id;
};

struct LowerPrecedence {
    bool operator()(const Job& left, const Job& right) const {
        if (left.priority != right.priority) {
            return left.priority < right.priority;
        }
        return left.id > right.id;
    }
};

int main() {
    std::priority_queue<Job, std::vector<Job>, LowerPrecedence> jobs;
    jobs.push({5, 2});
    jobs.push({3, 0});
    jobs.push({5, 1});
    assert(jobs.top().id == 1);
    jobs.pop();
    assert(jobs.top().id == 2);
    jobs.pop();
    assert(jobs.top().id == 0);
    LowerPrecedence compare;
    assert(!compare(Job{5, 1}, Job{5, 1}));
    std::cout << "checks passed\n";
}
