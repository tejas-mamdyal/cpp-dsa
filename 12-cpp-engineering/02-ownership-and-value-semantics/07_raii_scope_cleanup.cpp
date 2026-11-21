/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

Construction increments a live-resource counter and destruction decrements
it.

Throwing inside scope unwinds and runs the destructor.

Every successfully constructed guard is destroyed exactly once on scope exit.

O(1) time/storage.

A deleted copy prevents duplicating the cleanup obligation; destructors should not
throw.
*/
#include <iostream>
#include <cassert>
#include <stdexcept>

struct ScopeCount {
    int& live;

    explicit ScopeCount(int& count)
        : live(count) {
        ++live;
    }

    ~ScopeCount() {
        --live;
    }

    ScopeCount(const ScopeCount&) = delete;
    ScopeCount& operator=(const ScopeCount&) = delete;
};

int main() {
    int live = 0;
    try {
        ScopeCount scope(live);
        assert(live == 1);
        throw std::runtime_error("stop");
    } catch (const std::runtime_error&) {
    }
    assert(live == 0);
    std::cout << "checks passed\n";
    return 0;
}
