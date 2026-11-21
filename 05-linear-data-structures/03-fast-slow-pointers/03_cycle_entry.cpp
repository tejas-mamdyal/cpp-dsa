/*
RESET ONE OBSERVER AFTER A FLOYD MEETING PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Return cycle entry identity, or null for acyclic input. The caller owns every
allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.
IDEA AND STATE: Move one observer from head and one from meeting, both at speed1. TRACE:
1->2->3->4->2 has entry node2, not necessarily the meeting node. CORRECTNESS: The distance
equation modulo cycle length makes both observers arrive at the entry together. COST: O(n)
time,O(1) space. PITFALL: A meeting position is not automatically the entry; compare
identities, not payloads. PRACTICE: Change the example, predict each state update and add an
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

void clear(Node*& head) {
    while (head != nullptr) {
        Node* victim = head;
        head = head->next;
        delete victim;
    }
}

Node* build(const std::vector<int>& values) {
    Node* head = nullptr;
    Node* tail = nullptr;
    try {
        for (int value : values) {
            Node* node = new Node(value);
            if (tail == nullptr) {
                head = node;
            } else {
                tail->next = node;
            }
            tail = node;
        }
    } catch (...) {
        clear(head);
        throw;
    }
    return head;
}

Node* meeting(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return slow;
        }
    }
    return nullptr;
}

Node* cycleEntry(Node* head) {
    Node* hit = meeting(head);
    if (hit == nullptr) {
        return nullptr;
    }
    Node* start = head;
    while (start != hit) {
        start = start->next;
        hit = hit->next;
    }
    return start;
}

int main() {
    assert(cycleEntry(nullptr) == nullptr);
    for (int index = 0; index < 5; ++index) {
        Node* head = build({7, 7, 7, 7, 7});
        Node* target = head;
        for (int i = 0; i < index; ++i) {
            target = target->next;
        }
        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = target;
        assert(cycleEntry(head) == target);
        tail->next = nullptr;
        assert(cycleEntry(head) == nullptr);
        clear(head);
    }
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
