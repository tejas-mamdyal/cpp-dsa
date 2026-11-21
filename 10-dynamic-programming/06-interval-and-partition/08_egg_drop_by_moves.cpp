/*
 Arrays/text length<=30; integer magnitudes<=1000; state additional sign and counting
bounds explicitly.

cover[e] is maximum floors solvable with e eggs and the currently
processed move count; broken and surviving branches use one fewer move.

For two eggs, coverage grows 1,3,6,10,...105 by 14 moves, covering 100 floors.

One chosen floor separates cover[e-1] lower floors after a break and cover[e]
upper floors after survival, plus itself.

O(eggs*answerMoves) time, O(eggs) storage; coverage clamped to required floors.

Scan egg counts downward so both terms still represent the previous move count.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <cstddef>

std::optional<int> moves(int eggs, int floors) {
    assert(eggs >= 0 && eggs <= 10 && floors >= 0 && floors <= 1000);
    if (floors == 0) {
        return 0;
    }
    if (eggs == 0) {
        return std::nullopt;
    }
    std::vector<long long> cover(static_cast<std::size_t>(eggs + 1), 0);
    int count = 0;
    while (cover[eggs] < floors) {
        ++count;
        for (int e = eggs; e >= 1; --e) {
            cover[e] = std::min(1LL * floors, cover[e] + cover[e - 1] + 1);
        }
    }
    return count;
}

int main() {
    assert(moves(2, 100) == 14);
    assert(moves(1, 5) == 5);
    assert(!moves(0, 1));
    assert(moves(0, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
