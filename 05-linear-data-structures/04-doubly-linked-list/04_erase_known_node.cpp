/*
ERASE AN INTERIOR NODE WITHOUT PREDECESSOR SEARCH PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 The supplied nonnull node belongs to this list. Chains are acyclic and uniquely
owned; tail is an observer. IDEA AND STATE: prev and next directly identify the two affected
neighbors. TRACE: 1,2,3 erase observer2 ->1,3. CORRECTNESS: Reconnecting both directions
bypasses exactly the victim. COST: O(1) given-node deletion,O(1) auxiliary space. PITFALL: The
erased observer must never be dereferenced afterward. PRACTICE: Change the example, predict
each state update and add an empty/boundary case. No input unless explicitly stated.
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

int main() {
    DNode* head = buildD({1, 2, 3});
    DNode* tail = lastD(head);
    unlink(head, tail, head->next);
    assert((forward(head) == std::vector<int>{1, 3}));
    assert((backward(tail) == std::vector<int>{3, 1}));
    unlink(head, tail, head);
    unlink(head, tail, tail);
    assert(head == nullptr && tail == nullptr);
    assert(DNode::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
