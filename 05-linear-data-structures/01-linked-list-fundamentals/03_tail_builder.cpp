/*
BUILD A LIST IN LINEAR TIME WITH A TAIL OBSERVER PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Input values form a new independently owned chain. The caller owns every allocated
node unless ownership is explicitly transferred. Test fixtures reclaim all nodes. IDEA AND
STATE: Keep a tail pointer so each append avoids rescanning the chain. TRACE: Append1,2,3
using three constant-time link updates. CORRECTNESS: Head stays at the first node; tail is
always the last node and its next is null. COST: O(n) construction/O(n) owned storage; output
snapshot also O(n). PITFALL: The tail is an observer into the same allocation set, not another
owner. PRACTICE: Change the example, predict each state update and add an empty/boundary case.
No input unless explicitly stated. Assertions are the teaching test harness and must remain
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

int main() {
    for (int n = 0; n <= 40; ++n) {
        std::vector<int> values;
        for (int i = 0; i < n; ++i) {
            values.push_back(i);
        }
        Node* head = build(values);
        assert(view(head) == values);
        clear(head);
    }
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
