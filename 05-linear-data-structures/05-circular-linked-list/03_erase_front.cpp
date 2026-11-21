/*
REMOVE THE HEAD OF A RING PREREQUISITES: Phases1/2 C++ and STL, Phase3 complexity/recursion,

filenames.

 Return false for empty; singleton removal empties the owner. A nonempty tail
observer identifies the uniquely owned ring; head=tail.next. The caller owns every allocated
node unless ownership is explicitly transferred. Test fixtures reclaim all nodes. IDEA AND
STATE: Bypass tail.next or clear tail for a singleton, then delete the victim. TRACE: 1,2 ->2
self-loop ->empty. CORRECTNESS: Every surviving ring still begins at tail.next and contains
each remaining node once. COST: O(1) time and extra space. PITFALL: Do not retain the old head
observer after deletion. PRACTICE: Change the example, predict each state update and add an
empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

struct Node {
    int value;
    Node* next = nullptr;
    inline static int live = 0;

    explicit Node(int data)
        : value(data) {
        ++live;
    }

    ~Node() {
        --live;
    }

    Node(const Node&) = delete;
    Node& operator=(const Node&) = delete;
};

void appendCircle(Node*& tail, int value) {
    Node* node = new Node(value);
    if (tail == nullptr) {
        node->next = node;
    } else {
        node->next = tail->next;
        tail->next = node;
    }
    tail = node;
}

bool popCircle(Node*& tail) {
    if (tail == nullptr) {
        return false;
    }
    Node* victim = tail->next;
    if (victim == tail) {
        tail = nullptr;
    } else {
        tail->next = victim->next;
    }
    delete victim;
    return true;
}

int main() {
    Node* tail = nullptr;
    assert(!popCircle(tail));
    appendCircle(tail, 1);
    appendCircle(tail, 2);
    assert(popCircle(tail));
    assert(tail->next == tail && tail->value == 2);
    assert(popCircle(tail));
    assert(tail == nullptr);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
