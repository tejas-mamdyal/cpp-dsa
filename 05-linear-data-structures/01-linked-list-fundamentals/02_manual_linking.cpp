/*
ALLOCATE LINK TRAVERSE AND RELEASE A CHAIN PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Three uniquely owned dynamic nodes. The caller owns every allocated node unless
ownership is explicitly transferred. Test fixtures reclaim all nodes. IDEA AND STATE: Create
nodes, connect next links, then delete iteratively using a saved next position. TRACE:
1->2->3->null becomes an empty owner after clear. CORRECTNESS: Traversal follows one link per
node; clear advances before releasing the previous node. COST: O(n) traversal/cleanup,O(1)
cleanup working state,O(n) owned nodes. PITFALL: Deleting before reading next is a
use-after-free. PRACTICE: Change the example, predict each state update and add an
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

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    assert((view(head) == std::vector<int>{1, 2, 3}));
    clear(head);
    assert(head == nullptr);
    clear(head);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
