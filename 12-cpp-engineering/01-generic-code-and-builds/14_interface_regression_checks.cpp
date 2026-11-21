/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

The interface promises nonnegative increments and unchanged state on
rejection.

After 2+3, negative add throws and value remains 5.

Validation occurs before mutation, so failed calls preserve state.

O(1) time/storage within total<=1000000.

Testing the member field name would couple tests to an irrelevant implementation
detail.
*/
#include <iostream>
#include <cassert>
#include <stdexcept>

class Counter {
    int count = 0;

public:
    void add(int amount) {
        if (amount < 0) {
            throw std::invalid_argument("negative");
        }
        count += amount;
    }

    int value() const {
        return count;
    }
};

int main() {
    Counter c;
    c.add(2);
    c.add(3);
    assert(c.value() == 5);
    try {
        c.add(-1);
        assert(false);
    } catch (const std::invalid_argument&) {
    }
    assert(c.value() == 5);
    std::cout << "checks passed\n";
    return 0;
}
