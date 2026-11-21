/*
 Start n zeros; n<=1000; updates are inclusive valid[l, r] plus signed delta.

IDEA AND STATE: Add delta at l, subtract it at r+1 in an n+1 difference array.

TRACE: n 5 updates[1,3]+2 and[2,4]-1 ->0,2,1,1,-1.

Difference markers are0,2,-1,0,-2,1;integrating the first five entries yields0,2,1,1,-1.

A prefix scan activates each update at its start and cancels it after its end.

O(n+q) time, O(n) storage.

The sentinel at index n handles updates ending at n-1.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

struct Update {
    std::size_t left;
    std::size_t right;
    long long delta;
};

std::vector<long long> apply(std::size_t n, const std::vector<Update>& changes) {
    std::vector<long long> difference(n + 1, 0);
    for (const Update& change : changes) {
        assert(change.left <= change.right && change.right < n);
        difference[change.left] += change.delta;
        difference[change.right + 1] -= change.delta;
    }
    std::vector<long long> out(n);
    long long value = 0;
    for (std::size_t i = 0; i < n; ++i) {
        value += difference[i];
        out[i] = value;
    }
    return out;
}

int main() {
    assert((apply(5, {{1, 3, 2}, {2, 4, -1}}) == std::vector<long long>{0, 2, 1, 1, -1}));
    assert(apply(0, {}).empty());
    assert((apply(1, {{0, 0, 7}}) == std::vector<long long>{7}));
    std::cout << "checks passed\n";
    return 0;
}
