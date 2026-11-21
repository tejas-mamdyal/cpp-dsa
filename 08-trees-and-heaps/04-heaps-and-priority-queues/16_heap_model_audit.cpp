/*
 Use a deterministic small operation stream including duplicates, negatives and empty
pops. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Multiset stores all reference values in sorted order; its last value
independently defines max.

Push, push, pop patterns compare the complete observed sequence and validate every
parent inequality after each update.

Reference insert/erase models the heap multiset; matching extrema and invariants
checks both returned behavior and internal order.

O(M log(M+1)) model time plus O(M^2) repeated diagnostic invariant scans; O(M) space.

Do not inspect only one final top; interleaved state transitions expose more failures.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <utility>
#include <set>
#include <iterator>
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
    MaxHeap heap;
    std::multiset<int> model;
    for (int step = 0; step < 200; ++step) {
        if (step % 3 != 0) {
            int x = (step * 17) % 23 - 11;
            heap.push(x);
            model.insert(x);
        } else {
            auto got = heap.pop();
            if (model.empty()) {
                assert(!got);
            } else {
                auto it = std::prev(model.end());
                assert(got == *it);
                model.erase(it);
            }
        }
        assert(heap.valid());
        if (model.empty()) {
            assert(!heap.top());
        } else {
            assert(heap.top() == *model.rbegin());
        }
    }
    std::cout << "checks passed\n";
    return 0;
}
