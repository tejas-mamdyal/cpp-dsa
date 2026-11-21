/*
INSERT BEFORE A ZERO-BASED LIST POSITION PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Valid positions0..length; reject others without changing the chain. The caller owns
every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all
nodes. IDEA AND STATE: Find the predecessor before allocating the new node. TRACE: 1,3 insert2
at1 ->1,2,3. CORRECTNESS: Only the predecessor link changes; the old suffix remains linked
after the inserted node. COST: O(position+1) time,O(1) working space plus one new node.
PITFALL: Validate first so an invalid insertion allocates nothing. PRACTICE: Change the
example, predict each state update and add an empty/boundary case. No input unless explicitly
stated. Assertions are the teaching test harness and must remain enabled; success prints
checks passed. These bounds describe the helper, not a claim that a fixed-data demonstration
has growing runtime input.
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

bool insertAt(Node*& head, int index, int value) {
    if (index < 0) {
        return false;
    }
    if (index == 0) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
        return true;
    }
    Node* previous = head;
    for (int i = 1; i < index && previous != nullptr; ++i) {
        previous = previous->next;
    }
    if (previous == nullptr) {
        return false;
    }
    Node* node = new Node(value);
    node->next = previous->next;
    previous->next = node;
    return true;
}

int main() {
    Node* head = build({1, 3});
    assert(insertAt(head, 1, 2));
    assert(insertAt(head, 3, 4));
    auto before = view(head);
    assert(!insertAt(head, 6, 9));
    assert(view(head) == before);
    assert((view(head) == std::vector<int>{1, 2, 3, 4}));
    clear(head);
    assert(insertAt(head, 0, 7));
    clear(head);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
