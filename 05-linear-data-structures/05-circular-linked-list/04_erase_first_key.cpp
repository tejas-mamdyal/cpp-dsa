/*
ERASE A RING NODE INCLUDING THE TAIL PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Remove the first matching key in head order, returning false if absent. A nonempty
tail observer identifies the uniquely owned ring; head=tail.next. The caller owns every
allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.
IDEA AND STATE: Start predecessor at tail and stop after one complete lap. TRACE: 1,2,3
delete3 ->tail becomes2;delete1 ->2 singleton. CORRECTNESS: The predecessor bypasses the
victim and the tail observer is replaced when necessary. COST: O(n) time,O(1) extra space.
PITFALL: Deleting the singleton must clear tail rather than leave it dangling. PRACTICE:
Change the example, predict each state update and add an empty/boundary case. No input unless
explicitly stated. Assertions are the teaching test harness and must remain enabled; success
prints checks passed. These bounds describe the helper, not a claim that a fixed-data
demonstration has growing runtime input.
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

bool eraseCircle(Node*& tail, int key) {
    if (tail == nullptr) {
        return false;
    }
    Node* previous = tail;
    Node* current = tail->next;
    Node* start = current;
    do {
        if (current->value == key) {
            if (current == previous) {
                tail = nullptr;
            } else {
                previous->next = current->next;
                if (current == tail) {
                    tail = previous;
                }
            }
            delete current;
            return true;
        }
        previous = current;
        current = current->next;
    } while (current != start);
    return false;
}

int main() {
    Node* tail = nullptr;
    for (int value : {1, 2, 3}) {
        appendCircle(tail, value);
    }
    assert(!eraseCircle(tail, 9));
    assert(eraseCircle(tail, 3));
    assert(tail->value == 2);
    assert(eraseCircle(tail, 1));
    assert(tail->next == tail);
    assert(eraseCircle(tail, 2));
    assert(tail == nullptr);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
