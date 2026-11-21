/*
MANUAL INSERTION AND ERASURE IN A FIXED ARRAY PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Capacity5 with active count0..5; validate positions. IDEA AND STATE: Shift backward
to open a slot and forward to close one. TRACE: 1,3 insert2 at1 ->1,2,3;erase1 ->1,3.
CORRECTNESS: Shifting in the correct direction preserves unread active values. COST: O(n)
shifts,O(1) extra space. PITFALL: Capacity is not active length; reject full insertion and
invalid erase before mutation. PRACTICE: Change the example, predict each state update and add
an empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>

bool insert(int a[], int& size, int position, int value) {
    if (size == 5 || position < 0 || position > size) {
        return false;
    }
    for (int i = size; i > position; --i) {
        a[i] = a[i - 1];
    }
    a[position] = value;
    ++size;
    return true;
}

bool erase(int a[], int& size, int position) {
    if (position < 0 || position >= size) {
        return false;
    }
    for (int i = position; i + 1 < size; ++i) {
        a[i] = a[i + 1];
    }
    --size;
    return true;
}

int main() {
    int a[5] = {1, 3};
    int size = 2;
    assert(insert(a, size, 1, 2));
    assert(size == 3 && a[1] == 2 && a[2] == 3);
    assert(erase(a, size, 1));
    assert(size == 2 && a[1] == 3);
    assert(!erase(a, size, 2));
    size = 5;
    assert(!insert(a, size, 0, 7));
    std::cout << "checks passed\n";
    return 0;
}
