/*
REMOVE LATER DUPLICATES WHILE PRESERVING FIRST NODES PREREQUISITES: Phases1/2 C++ and STL,

README order, not old filenames.

 Any acyclic int chain. Chains are acyclic and uniquely owned; tail is an observer.
IDEA AND STATE: A hash set identifies repeated values; save next before unlink/delete. TRACE:
2,1,2,3,1 ->2,1,3. CORRECTNESS: Only the first occurrence of each key is retained and all
removed nodes are reclaimed. COST: Expected O(n) time,O(u) set space; worst hashing can be
quadratic. PITFALL: Advance using the saved next, not a deleted node. PRACTICE: Change the
example, predict each state update and add an empty/boundary case. No input unless explicitly
stated. Assertions are the teaching test harness and must remain enabled; success prints
checks passed. These bounds describe the helper, not a claim that a fixed-data demonstration
has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <unordered_set>

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

void dedup(DNode*& head, DNode*& tail) {
    std::unordered_set<int> seen;
    DNode* current = head;
    while (current != nullptr) {
        DNode* next = current->next;
        if (!seen.insert(current->value).second) {
            unlink(head, tail, current);
        }
        current = next;
    }
}

int main() {
    DNode* head = buildD({2, 1, 2, 3, 1});
    DNode* tail = lastD(head);
    dedup(head, tail);
    assert((forward(head) == std::vector<int>{2, 1, 3}));
    assert((backward(tail) == std::vector<int>{3, 1, 2}));
    clearD(head);
    tail = nullptr;
    dedup(head, tail);
    assert(DNode::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
