/*
DEEP COPYING DIFFERS FROM BORROWING A LINK PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Copy values into a new allocation set; a raw alias continues to observe the
original. The caller owns every allocated node unless ownership is explicitly transferred.
Test fixtures reclaim all nodes. IDEA AND STATE: Clone through the fixture builder and compare
independent node identities. TRACE: Original1,2 changes to9,2 through alias; clone remains1,2.
CORRECTNESS: Each copied value belongs to a new node; aliasing creates no node or new
lifetime. COST: O(n) copy time/storage; this simple clone uses an additional O(n) snapshot.
PITFALL: After clearing the original, its alias dangles and must not be dereferenced.
PRACTICE: Change the example, predict each state update and add an empty/boundary case. No
input unless explicitly stated. Assertions are the teaching test harness and must remain
enabled; success prints checks passed. These bounds describe the helper, not a claim that a
fixed-data demonstration has growing runtime input.
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

Node* clone(const Node* head) {
    return build(view(head));
}

int main() {
    Node* head = build({1, 2});
    Node* copy = clone(head);
    Node* alias = head;
    assert(copy != head);
    alias->value = 9;
    assert((view(head) == std::vector<int>{9, 2}));
    assert((view(copy) == std::vector<int>{1, 2}));
    clear(head);
    alias = nullptr;
    assert(alias == nullptr);
    clear(copy);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
