/*
LOCATE A POSITION THEN UPDATE RECIPROCAL LINKS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Sorted list; insert after equal values. Chains are acyclic and uniquely owned; tail
is an observer. IDEA AND STATE: Walk to first greater key; insert before it or append at tail.
TRACE: 1,3 insert2 ->1,2,3. CORRECTNESS: Search establishes ordered neighbors; pointer wiring
preserves reciprocal links. COST: O(n) search,O(1) linking and extra state. PITFALL: Empty and
after-tail insertion need both endpoint updates. PRACTICE: Change the example, predict each
state update and add an empty/boundary case. No input unless explicitly stated. Assertions are
the teaching test harness and must remain enabled; success prints checks passed. These bounds
describe the helper, not a claim that a fixed-data demonstration has growing runtime input.
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

void sortedInsert(DNode*& head, DNode*& tail, int value) {
    DNode* next = head;
    while (next != nullptr && next->value <= value) {
        next = next->next;
    }
    DNode* node = new DNode(value);
    if (next == nullptr) {
        node->prev = tail;
        if (tail != nullptr) {
            tail->next = node;
        } else {
            head = node;
        }
        tail = node;
        return;
    }
    node->next = next;
    node->prev = next->prev;
    if (next->prev != nullptr) {
        next->prev->next = node;
    } else {
        head = node;
    }
    next->prev = node;
}

int main() {
    DNode* head = nullptr;
    DNode* tail = nullptr;
    for (int value : {3, 1, 2, 2, 4}) {
        sortedInsert(head, tail, value);
    }
    assert((forward(head) == std::vector<int>{1, 2, 2, 3, 4}));
    assert((backward(tail) == std::vector<int>{4, 3, 2, 2, 1}));
    clearD(head);
    assert(DNode::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
