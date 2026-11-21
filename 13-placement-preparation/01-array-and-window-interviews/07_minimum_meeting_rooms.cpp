/*
 Nonempty half-open intervals, start<end.

The heap contains exactly meetings active at the new start.

Meeting ending 5 frees a room for the one beginning 5.

The maximum simultaneous active count is both a lower bound and achievable by
reusing freed rooms.

O(n log n) time, O(n) heap/copy.

Closed meetings would treat touching endpoints differently.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <functional>

int rooms(std::vector<std::pair<int, int>> meetings) {
    std::sort(meetings.begin(), meetings.end());
    std::priority_queue<int, std::vector<int>, std::greater<int>> end;
    int best = 0;
    for (auto [start, finish] : meetings) {
        while (!end.empty() && end.top() <= start) {
            end.pop();
        }
        end.push(finish);
        best = std::max(best, static_cast<int>(end.size()));
    }
    return best;
}

int main() {
    assert(rooms({{0, 10}, {2, 5}, {5, 7}}) == 2);
    assert(rooms({{0, 1}, {1, 2}}) == 1);
    std::cout << "checks passed\n";
    return 0;
}
