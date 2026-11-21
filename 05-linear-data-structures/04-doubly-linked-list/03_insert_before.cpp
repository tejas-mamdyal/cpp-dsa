/*
INSERT BEFORE A KNOWN VALID OBSERVER PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Target belongs to the chain; null is rejected. Chains are acyclic and uniquely
owned; tail is an observer. IDEA AND STATE: Wire the new node between target.prev and target.
TRACE: 1,3 insert2 before3 ->1,2,3. CORRECTNESS: Both neighboring directions are updated
before the new node becomes part of traversal. COST: O(1) insertion given target,plus one
node. PITFALL: A foreign pointer is outside the API contract. PRACTICE: Change the example,
predict each state update and add an empty/boundary case. No input unless explicitly stated.
Assertions are the teaching test harness and must remain enabled; success prints checks
passed. These bounds describe the helper, not a claim that a fixed-data demonstration has
growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

struct DNode {
    int value;
    DNode* prev = nullptr;
    DNode* next = nullptr;
    inline static int live = 0;

    explicit DNode(int data)
        : value(data) {
        ++live;
    }

    ~DNode() {
        --live;
    }

    DNode(const DNode&) = delete;
    DNode& operator=(const DNode&) = delete;
};

void clearD(DNode*& head) {
    while (head != nullptr) {
        DNode* old = head;
        head = head->next;
        delete old;
    }
}

DNode* lastD(DNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    while (head->next != nullptr) {
        head = head->next;
    }
    return head;
}

std::vector<int> forward(DNode* head) {
    std::vector<int> out;
    DNode* previous = nullptr;
    while (head != nullptr) {
        assert(head->prev == previous);
        out.push_back(head->value);
        previous = head;
        head = head->next;
    }
    return out;
}

std::vector<int> backward(DNode* tail) {
    std::vector<int> out;
    DNode* next = nullptr;
    while (tail != nullptr) {
        assert(tail->next == next);
        out.push_back(tail->value);
        next = tail;
        tail = tail->prev;
    }
    return out;
}

DNode* buildD(const std::vector<int>& values) {
    DNode* head = nullptr;
    DNode* tail = nullptr;
    try {
        for (int value : values) {
            DNode* node = new DNode(value);
            node->prev = tail;
            if (tail == nullptr) {
                head = node;
            } else {
                tail->next = node;
            }
            tail = node;
        }
    } catch (...) {
        clearD(head);
        throw;
    }
    return head;
}

bool insertBefore(DNode*& head, DNode* target, int value) {
    if (target == nullptr) {
        return false;
    }
    DNode* node = new DNode(value);
    node->prev = target->prev;
    node->next = target;
    if (target->prev != nullptr) {
        target->prev->next = node;
    } else {
        head = node;
    }
    target->prev = node;
    return true;
}

int main() {
    DNode* head = buildD({1, 3});
    assert(insertBefore(head, head->next, 2));
    assert(insertBefore(head, head, 0));
    assert((forward(head) == std::vector<int>{0, 1, 2, 3}));
    assert((backward(lastD(head)) == std::vector<int>{3, 2, 1, 0}));
    assert(!insertBefore(head, nullptr, 7));
    clearD(head);
    assert(DNode::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
