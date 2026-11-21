/*
MOVE A NODE WITHOUT CHANGING ITS IDENTITY PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Known node belongs to nonempty chain. Chains are acyclic and uniquely owned; tail is
an observer. IDEA AND STATE: Detach its existing links, then attach it before the old head.
TRACE: 1,2,3 move observer3 to front ->3,1,2. CORRECTNESS: The same allocation is relinked;
all other nodes keep their relative order. COST: O(1) time and space with known
node/endpoints. PITFALL: This is the list mechanism used by later cache designs, not a reason
to allocate a replacement node. PRACTICE: Change the example, predict each state update and
add an empty/boundary case. No input unless explicitly stated. Assertions are the teaching
test harness and must remain enabled; success prints checks passed. These bounds describe the
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

void moveFront(DNode*& head, DNode*& tail, DNode* node) {
    assert(node != nullptr);
    if (node == head) {
        return;
    }
    node->prev->next = node->next;
    if (node->next != nullptr) {
        node->next->prev = node->prev;
    } else {
        tail = node->prev;
    }
    node->prev = nullptr;
    node->next = head;
    head->prev = node;
    head = node;
}

int main() {
    DNode* head = buildD({1, 2, 3});
    DNode* tail = lastD(head);
    DNode* observer = tail;
    int allocated = DNode::live;
    moveFront(head, tail, observer);
    assert(head == observer && DNode::live == allocated);
    assert((forward(head) == std::vector<int>{3, 1, 2}));
    assert((backward(tail) == std::vector<int>{2, 1, 3}));
    moveFront(head, tail, head);
    clearD(head);
    assert(DNode::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
