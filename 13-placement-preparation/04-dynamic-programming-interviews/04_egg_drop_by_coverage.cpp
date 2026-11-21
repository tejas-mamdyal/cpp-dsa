/*
 0<=eggs<=10;0<=floors<=10000; answer-1 means impossible. Unless a different bound is
stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

cover[e] is the maximum floors testable with the current move count and e
eggs.

Two eggs and 14 moves cover 14+13+...+1=105 floors.

A drop separates covered lower floors with e-1 eggs, one current floor, and
covered upper floors with e eggs.

O(eggs*answer) time, O(eggs) storage.

Descending e preserves the previous-move lower-egg state.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int moves(int eggs, long long floors) {
    if (floors == 0) {
        return 0;
    }
    if (eggs == 0) {
        return -1;
    }
    std::vector<long long> cover(eggs + 1);
    int used = 0;
    while (cover[eggs] < floors) {
        ++used;
        for (int e = eggs; e >= 1; --e) {
            cover[e] = std::min(floors, cover[e] + cover[e - 1] + 1);
        }
    }
    return used;
}

int main() {
    assert(moves(2, 100) == 14 && moves(1, 10) == 10 && moves(0, 1) == -1 && moves(0, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
