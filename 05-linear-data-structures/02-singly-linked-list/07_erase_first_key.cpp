/*
ERASE ONLY THE FIRST MATCHING KEY PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Return false if absent; preserve later equal values. The caller owns every allocated
node unless ownership is explicitly transferred. Test fixtures reclaim all nodes. IDEA AND
STATE: Treat the head separately, then inspect predecessor.next. TRACE: 2,1,2 erase2 ->1,2.
CORRECTNESS: The first matching node is bypassed and deleted; the unvisited suffix is
unchanged. COST: O(n) time,O(1) space. PITFALL: Value equality does not mean all duplicate
nodes should be removed. PRACTICE: Change the example, predict each state update and add an
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

bool eraseKey(Node*& head, int key) {
    if (head == nullptr) {
        return false;
    }
    if (head->value == key) {
        Node* victim = head;
        head = head->next;
        delete victim;
        return true;
    }
    Node* previous = head;
    while (previous->next != nullptr && previous->next->value != key) {
        previous = previous->next;
    }
    if (previous->next == nullptr) {
        return false;
    }
    Node* victim = previous->next;
    previous->next = victim->next;
    delete victim;
    return true;
}

int main() {
    Node* head = build({2, 1, 2});
    assert(eraseKey(head, 2));
    assert((view(head) == std::vector<int>{1, 2}));
    assert(eraseKey(head, 2));
    assert(!eraseKey(head, 7));
    clear(head);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
