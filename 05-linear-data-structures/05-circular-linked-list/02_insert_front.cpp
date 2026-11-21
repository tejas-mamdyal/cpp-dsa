/*
INSERT IMMEDIATELY AFTER TAIL PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Empty and nonempty rings supported. A nonempty tail observer identifies the uniquely
owned ring; head=tail.next. The caller owns every allocated node unless ownership is
explicitly transferred. Test fixtures reclaim all nodes. IDEA AND STATE: Insert a node before
the old head without moving a nonempty tail. TRACE: 1,2 insert0 ->0,1,2. CORRECTNESS:
tail.next selects the new head while the old head remains its successor. COST: O(1)
time/working space plus one new node. PITFALL: Empty insertion must form a self-loop.
PRACTICE: Change the example, predict each state update and add an empty/boundary case. No
input unless explicitly stated. Assertions are the teaching test harness and must remain
enabled; success prints checks passed. These bounds describe the helper, not a claim that a
fixed-data demonstration has growing runtime input.
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

void clear(Node*& head) {
    while (head != nullptr) {
        Node* victim = head;
        head = head->next;
        delete victim;
    }
}

std::vector<int> circleValues(const Node* tail) {
    std::vector<int> out;
    if (tail == nullptr) {
        return out;
    }
    const Node* head = tail->next;
    const Node* p = head;
    do {
        out.push_back(p->value);
        p = p->next;
    } while (p != head);
    return out;
}

void clearCircle(Node*& tail) {
    if (tail == nullptr) {
        return;
    }
    Node* head = tail->next;
    tail->next = nullptr;
    clear(head);
    tail = nullptr;
}

void frontCircle(Node*& tail, int value) {
    Node* node = new Node(value);
    if (tail == nullptr) {
        tail = node;
        node->next = node;
    } else {
        node->next = tail->next;
        tail->next = node;
    }
}

int main() {
    Node* tail = nullptr;
    frontCircle(tail, 2);
    frontCircle(tail, 1);
    frontCircle(tail, 0);
    assert((circleValues(tail) == std::vector<int>{0, 1, 2}));
    assert(tail->value == 2);
    clearCircle(tail);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
