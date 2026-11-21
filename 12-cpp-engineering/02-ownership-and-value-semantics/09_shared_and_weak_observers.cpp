/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

weak_ptr records observation; lock obtains temporary shared ownership if
the object still lives.

While owner exists, lock sees 7; after both strong owners leave, the observer
expires.

The object is destroyed at the last strong-owner release; weak observers do not
keep it alive.

O(1) handles plus one allocation/control block.

Checking expired then using a raw pointer is unsafe; use the ownership returned by
lock.
*/
#include <iostream>
#include <cassert>
#include <memory>

struct Item {
    int value;
};

int main() {
    std::weak_ptr<Item> observer;
    {
        auto owner = std::make_shared<Item>(Item{7});
        observer = owner;
        auto locked = observer.lock();
        assert(locked && locked->value == 7);
    }
    assert(observer.expired() && !observer.lock());
    std::cout << "checks passed\n";
    return 0;
}
