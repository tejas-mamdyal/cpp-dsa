/*
 At most 1000 bounded integers; duplicates allowed; empty operations return explicit
absence. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

push bubbles a new leaf upward; pop replaces root with the last leaf and
sifts downward toward the larger child. This expands the inherited max-heap implementation.

Push 3,1,5 yields root 5; pop 5 moves a leaf to root and repairs the remaining root 3.

All untouched edges remain valid; swapping along the single violating path
restores each crossed inequality.

O(log(n+1)) push/pop, O(1) top; vector growth amortized with occasional O(n) reallocation.

After removing the last value, do not index an empty root.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <utility>
#include <cstddef>

class MaxHeap {
    std::vector<int> a;

    void down(std::size_t i) {
        while (2 * i + 1 < a.size()) {
            std::size_t child = 2 * i + 1;
            if (child + 1 < a.size() && a[child + 1] > a[child]) {
                ++child;
            }
            if (a[i] >= a[child]) {
                break;
            }
            std::swap(a[i], a[child]);
            i = child;
        }
    }

public:
    void push(int value) {
        a.push_back(value);
        std::size_t i = a.size() - 1;
        while (i > 0) {
            std::size_t p = (i - 1) / 2;
            if (a[p] >= a[i]) {
                break;
            }
            std::swap(a[p], a[i]);
            i = p;
        }
    }

    std::optional<int> top() const {
        if (a.empty()) {
            return std::nullopt;
        }
        return a[0];
    }

    std::optional<int> pop() {
        if (a.empty()) {
            return std::nullopt;
        }
        int answer = a[0];
        a[0] = a.back();
        a.pop_back();
        if (!a.empty()) {
            down(0);
        }
        return answer;
    }

    bool valid() const {
        for (std::size_t i = 1; i < a.size(); ++i) {
            if (a[(i - 1) / 2] < a[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    MaxHeap h;
    assert(!h.pop() && !h.top());
    for (int x : {3, 1, 5, 5, -2}) {
        h.push(x);
        assert(h.valid());
    }
    for (int x : {5, 5, 3, 1, -2}) {
        assert(h.pop() == x && h.valid());
    }
    assert(!h.pop());
    std::cout << "checks passed\n";
    return 0;
}
