/*
RECLAIM DUPLICATE ADJACENT NODES IN A SORTED LIST PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Keep one node per distinct value. The caller owns every allocated node unless
ownership is explicitly transferred. Test fixtures reclaim all nodes. IDEA AND STATE: When
next equals current, bypass/delete next without advancing current. TRACE: 1,1,1,2,2 ->1,2.
CORRECTNESS: Sorted equal values are contiguous; one representative survives each run. COST:
O(n) time,O(1) space. PITFALL: Deleting a node must not leak its successor or skip another
duplicate. PRACTICE: Change the example, predict each state update and add an empty/boundary
case. No input unless explicitly stated. Assertions are the teaching test harness and must
remain enabled; success prints checks passed. These bounds describe the helper, not a claim
that a fixed-data demonstration has growing runtime input.
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

void deduplicate(Node* head) {
    while (head != nullptr && head->next != nullptr) {
        if (head->value == head->next->value) {
            Node* victim = head->next;
            head->next = victim->next;
            delete victim;
        } else {
            head = head->next;
        }
    }
}

int main() {
    Node* head = build({1, 1, 1, 2, 2});
    deduplicate(head);
    assert((view(head) == std::vector<int>{1, 2}));
    deduplicate(head);
    assert((view(head) == std::vector<int>{1, 2}));
    clear(head);
    deduplicate(nullptr);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
