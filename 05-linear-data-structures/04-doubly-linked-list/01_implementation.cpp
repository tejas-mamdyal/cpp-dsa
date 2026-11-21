/*
A NONCOPYABLE DOUBLY LINKED OWNER PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Front/back insertion and forward/backward traversal. Chains are acyclic and uniquely
owned; tail is an observer. IDEA AND STATE: Update both directions and both endpoints when
starting an empty list. TRACE: front2,front1,back3 ->1,2,3 and reverse3,2,1. CORRECTNESS:
Adjacent next/prev links remain reciprocal and head.prev/tail.next are null. COST: O(1)
endpoint insertion,O(n) traversal/cleanup. PITFALL: An owning raw-pointer class must disable
shallow copies. PRACTICE: Change the example, predict each state update and add an
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

class DoublyLinkedList {
    DNode* head = nullptr;
    DNode* tail = nullptr;

public:
    DoublyLinkedList() = default;
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    ~DoublyLinkedList() {
        clearD(head);
    }

    void insertFront(int value) {
        DNode* node = new DNode(value);
        node->next = head;
        if (head != nullptr) {
            head->prev = node;
        } else {
            tail = node;
        }
        head = node;
    }

    void insertBack(int value) {
        DNode* node = new DNode(value);
        node->prev = tail;
        if (tail != nullptr) {
            tail->next = node;
        } else {
            head = node;
        }
        tail = node;
    }

    std::vector<int> values() const {
        return forward(head);
    }

    std::vector<int> reversed() const {
        return backward(tail);
    }
};

int main() {
    {
        DoublyLinkedList list;
        assert(list.values().empty());
        list.insertFront(2);
        list.insertFront(1);
        list.insertBack(3);
        assert((list.values() == std::vector<int>{1, 2, 3}));
        assert((list.reversed() == std::vector<int>{3, 2, 1}));
    }
    assert(DNode::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
