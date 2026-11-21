/*
LINEAR PROBING NEEDS TOMBSTONES AFTER DELETION PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Fixed7-slot set; insert returns false for duplicate or full, erase/find for absence.
IDEA AND STATE: Probe a circular sequence; deleted slots are reusable but do not end search.
TRACE: 1,8,15 collide; deleting8 must not hide15. CORRECTNESS: Every live key remains
reachable along its probe path until an originally empty slot. COST: O(capacity) worst
operation,O(capacity) storage; fixed capacity7 here. PITFALL: Clearing a deleted slot to empty
incorrectly breaks a collision chain. PRACTICE: Change the example, predict each state update
and add an empty/boundary case. No input unless explicitly stated. Assertions are the teaching
test harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <array>

enum class State {
    empty,
    occupied,
    deleted
};

struct Slot {
    int key = 0;
    State state = State::empty;
};

class ProbeSet {
    std::array<Slot, 7> slots{};

    int hash(int key) const {
        int h = key % 7;
        if (h < 0) {
            h += 7;
        }
        return h;
    }

public:
    bool contains(int key) const {
        for (int step = 0; step < 7; ++step) {
            const Slot& slot = slots[(hash(key) + step) % 7];
            if (slot.state == State::empty) {
                return false;
            }
            if (slot.state == State::occupied && slot.key == key) {
                return true;
            }
        }
        return false;
    }

    bool insert(int key) {
        int dead = -1;
        for (int step = 0; step < 7; ++step) {
            int index = (hash(key) + step) % 7;
            Slot& slot = slots[index];
            if (slot.state == State::occupied && slot.key == key) {
                return false;
            }
            if (slot.state == State::deleted && dead == -1) {
                dead = index;
            }
            if (slot.state == State::empty) {
                if (dead != -1) {
                    index = dead;
                }
                slots[index] = {key, State::occupied};
                return true;
            }
        }
        if (dead != -1) {
            slots[dead] = {key, State::occupied};
            return true;
        }
        return false;
    }

    bool erase(int key) {
        for (int step = 0; step < 7; ++step) {
            Slot& slot = slots[(hash(key) + step) % 7];
            if (slot.state == State::empty) {
                return false;
            }
            if (slot.state == State::occupied && slot.key == key) {
                slot.state = State::deleted;
                return true;
            }
        }
        return false;
    }
};

int main() {
    ProbeSet set;
    assert(set.insert(1));
    assert(set.insert(8));
    assert(set.insert(15));
    assert(set.erase(8));
    assert(set.contains(15));
    assert(set.insert(22));
    assert(!set.insert(22));
    assert(set.insert(-6));
    ProbeSet full;
    for (int i = 0; i < 7; ++i) {
        assert(full.insert(i));
    }
    assert(!full.insert(10));
    assert(full.erase(3));
    assert(full.insert(10));
    assert(full.contains(10));
    std::cout << "checks passed\n";
    return 0;
}
