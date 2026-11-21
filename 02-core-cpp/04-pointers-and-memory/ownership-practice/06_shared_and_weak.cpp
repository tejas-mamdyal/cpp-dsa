/*
weak_ptr observes shared ownership without keeping the object alive. lock() returns a temporary shared_ptr if the object still exists, or an empty one otherwise. Use that returned owner for access rather than checking expired and later dereferencing a raw pointer.
*/
/*
SHARED OWNERSHIP AND WEAK OBSERVATION
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: shared_ptr shares a lifetime; weak_ptr observes without extending it. lock obtains a temporary owner.
Trace: two owners -> one -> expired weak observation.
Why it works: The last shared owner destroys the int; a weak observer alone does not keep it alive.
Cost: O(1) handles; reference-count updates and allocation add overhead.
Common mistake: Shared cycles leak ownership; use weak links where ownership should not be circular. Counts are only illustrative in single-threaded code.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <memory>

int main() {
    std::weak_ptr<int> observer;
    {
        auto first = std::make_shared<int>(8);
        observer = first;
        {
            auto second = first;
            assert(first.use_count() == 2);
            assert(*second == 8);
        }
        assert(first.use_count() == 1);
        auto locked = observer.lock();
        assert(locked && *locked == 8);
    }
    assert(observer.expired());
    assert(!observer.lock());
    std::cout << "checks passed\n";
}
