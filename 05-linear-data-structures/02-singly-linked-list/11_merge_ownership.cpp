/*
MERGE BY TRANSFERRING EXISTING NODES PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Two disjoint sorted owned chains; consume both owner pointers and return one owner.
The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures
reclaim all nodes. IDEA AND STATE: Use a dummy/tail to attach the smaller current head. TRACE:
1,3 and2,3 ->1,2,3,3 without allocating new data nodes. CORRECTNESS: Each selected head is the
smallest remaining value; no node belongs to two result positions. COST: O(n+m) time,O(1)
extra working space. PITFALL: Input owners become null after transfer and must not later
delete the transferred nodes. PRACTICE: Change the example, predict each state update and add
an empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
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

Node* merge(Node*& first, Node*& second) {
    Node dummy(0);
    Node* tail = &dummy;
    Node* a = first;
    Node* b = second;
    while (a != nullptr && b != nullptr) {
        if (a->value <= b->value) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    if (a != nullptr) {
        tail->next = a;
    } else {
        tail->next = b;
    }
    first = nullptr;
    second = nullptr;
    return dummy.next;
}

int main() {
    Node* first = build({1, 3});
    Node* second = build({2, 3});
    Node* head = merge(first, second);
    assert(first == nullptr && second == nullptr);
    assert((view(head) == std::vector<int>{1, 2, 3, 3}));
    clear(head);
    head = merge(first, second);
    assert(head == nullptr);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
