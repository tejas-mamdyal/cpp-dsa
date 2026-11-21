/*
SECOND MIDDLE WITH ONE-SPEED AND TWO-SPEED OBSERVERS PREREQUISITES: Phases1/2 C++ and STL,

README order, not old filenames.

 Acyclic list; even length returns the second middle; empty returns null. The caller
owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim
all nodes. IDEA AND STATE: Slow advances one link and fast two. TRACE: 1,2,3,4 ->middle3.
CORRECTNESS: When fast reaches the end, slow has traversed half as many links. COST: O(n)
time,O(1) extra space. PITFALL: Check fast and fast.next before following two links. PRACTICE:
Change the example, predict each state update and add an empty/boundary case. No input unless
explicitly stated. Assertions are the teaching test harness and must remain enabled; success
prints checks passed. These bounds describe the helper, not a claim that a fixed-data
demonstration has growing runtime input.
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

Node* middle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* middleTwoPass(Node* head) {
    int length = 0;
    for (Node* current = head; current != nullptr; current = current->next) {
        ++length;
    }
    for (int i = 0; i < length / 2; ++i) {
        head = head->next;
    }
    return head;
}

int main() {
    for (int n = 0; n <= 8; ++n) {
        std::vector<int> a;
        for (int i = 0; i < n; ++i) {
            a.push_back(i);
        }
        Node* head = build(a);
        Node* result = middle(head);
        assert(result == middleTwoPass(head));
        if (n == 0) {
            assert(result == nullptr);
        } else {
            assert(result->value == n / 2);
        }
        clear(head);
    }
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
