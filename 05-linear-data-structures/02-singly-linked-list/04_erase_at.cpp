/*
ERASE HEAD INTERIOR AND TAIL SAFELY PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Index0..length-1; invalid index returns false without mutation. The caller owns
every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all
nodes. IDEA AND STATE: Relink around the victim before deleting it. TRACE: 1,2,3 erase1
->1,3;erase0 ->3. CORRECTNESS: All surviving nodes remain in original order and exactly one
victim is reclaimed. COST: O(index+1) time,O(1) extra space. PITFALL: Any observer to the
deleted node becomes invalid. PRACTICE: Change the example, predict each state update and add
an empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
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

std::vector<int> view(const Node* head) {
    std::vector<int> out;
    while (head != nullptr) {
        out.push_back(head->value);
        head = head->next;
    }
    return out;
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

bool eraseAt(Node*& head, int index) {
    if (index < 0) {
        return false;
    }
    if (index == 0) {
        if (head == nullptr) {
            return false;
        }
        Node* victim = head;
        head = head->next;
        delete victim;
        return true;
    }
    Node* previous = head;
    for (int i = 1; i < index && previous != nullptr; ++i) {
        previous = previous->next;
    }
    if (previous == nullptr || previous->next == nullptr) {
        return false;
    }
    Node* victim = previous->next;
    previous->next = victim->next;
    delete victim;
    return true;
}

int main() {
    Node* head = build({1, 2, 3});
    assert(eraseAt(head, 1));
    assert((view(head) == std::vector<int>{1, 3}));
    assert(eraseAt(head, 1));
    assert(eraseAt(head, 0));
    assert(head == nullptr);
    assert(!eraseAt(head, 0));
    assert(!eraseAt(head, -1));
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
