/*
 Return sum and half-open indices; ties prefer earliest start, then earliest end; empty
absent.

IDEA AND STATE: Discard a negative suffix; record its new start, and update only for strict
improvement.

TRACE: 0,1,-1,1 ->sum 1,[0,2).

Carried0 is not discarded before1;sum1 is first saved with start0,end2,and equal later sums
keep those bounds.

A negative carried sum hurts every extension; retaining a zero sum preserves the
earliest start.

O(n) time, O(1) auxiliary space.

Restarting on zero breaks the documented tie policy.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>

struct Answer {
    long long sum;
    int left;
    int right;
};

std::optional<Answer> interval(const std::vector<int>& a) {
    if (a.empty()) {
        return std::nullopt;
    }
    long long ending = 0;
    int start = 0;
    Answer best{a[0], 0, 1};
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        if (ending < 0) {
            ending = 0;
            start = i;
        }
        ending += a[i];
        if (ending > best.sum) {
            best = {ending, start, i + 1};
        }
    }
    return best;
}

int main() {
    auto x = interval({0, 1, -1, 1});
    assert(x && x->sum == 1 && x->left == 0 && x->right == 2);
    auto y = interval({-5, -2, -2});
    assert(y && y->left == 1 && y->right == 2);
    assert(!interval({}));
    std::cout << "checks passed\n";
    return 0;
}
