/*
DELETING ENDPOINTS MUST CLEAR THE OPPOSITE LINK PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Known head/tail; pop returns false for empty. Chains are acyclic and uniquely owned;
tail is an observer. IDEA AND STATE: Use the shared unlink rule, updating neighbors before
deletion. TRACE: 1,2 ->pop front gives2 with prev null ->pop back gives empty. CORRECTNESS:
Surviving endpoints no longer refer to the deleted node; singleton removal clears both. COST:
O(1) erasure,O(1) working space. PITFALL: A stale tail after the last deletion causes later
use-after-free. PRACTICE: Change the example, predict each state update and add an
empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
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

void unlink(DNode*& head, DNode*& tail, DNode* node) {
    assert(node != nullptr);
    if (node->prev != nullptr) {
        node->prev->next = node->next;
    } else {
        head = node->next;
    }
    if (node->next != nullptr) {
        node->next->prev = node->prev;
    } else {
        tail = node->prev;
    }
    delete node;
}

bool popFront(DNode*& head, DNode*& tail) {
    if (head == nullptr) {
        return false;
    }
    unlink(head, tail, head);
    return true;
}

bool popBack(DNode*& head, DNode*& tail) {
    if (tail == nullptr) {
        return false;
    }
    unlink(head, tail, tail);
    return true;
}

int main() {
    DNode* head = buildD({1, 2});
    DNode* tail = lastD(head);
    assert(popFront(head, tail));
    assert(head == tail && head->prev == nullptr);
    assert(popBack(head, tail));
    assert(head == nullptr && tail == nullptr);
    assert(!popFront(head, tail));
    assert(DNode::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
