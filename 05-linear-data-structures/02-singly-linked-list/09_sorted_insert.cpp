/*
INSERT AFTER EXISTING EQUAL KEYS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Input chain sorted nondecreasingly. The caller owns every allocated node unless
ownership is explicitly transferred. Test fixtures reclaim all nodes. IDEA AND STATE: Find the
final predecessor with value<=new key, including a dummy before head. TRACE: 1,3,3 insert2
->1,2,3,3. CORRECTNESS: The new node lies between the last <= predecessor and first greater
successor. COST: O(n) time,O(1) working space plus one node. PITFALL: A sorted-input
precondition is required; this is not a sorting algorithm. PRACTICE: Change the example,
predict each state update and add an empty/boundary case. No input unless explicitly stated.
Assertions are the teaching test harness and must remain enabled; success prints checks
passed. These bounds describe the helper, not a claim that a fixed-data demonstration has
growing runtime input.
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

void sortedInsert(Node*& head, int value) {
    Node dummy(0);
    dummy.next = head;
    Node* previous = &dummy;
    while (previous->next != nullptr && previous->next->value <= value) {
        previous = previous->next;
    }
    Node* node = new Node(value);
    node->next = previous->next;
    previous->next = node;
    head = dummy.next;
}

int main() {
    Node* head = build({1, 3, 3});
    sortedInsert(head, 2);
    sortedInsert(head, 0);
    sortedInsert(head, 4);
    assert((view(head) == std::vector<int>{0, 1, 2, 3, 3, 4}));
    clear(head);
    sortedInsert(head, 7);
    clear(head);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
