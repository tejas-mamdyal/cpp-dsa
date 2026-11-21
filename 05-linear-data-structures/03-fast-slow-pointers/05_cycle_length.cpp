/*
COUNT ONE LAP AFTER MEETING PREREQUISITES: Phases1/2 C++ and STL, Phase3 complexity/recursion,

filenames.

 A possibly cyclic list; acyclic length answer0. The caller owns every allocated node
unless ownership is explicitly transferred. Test fixtures reclaim all nodes. IDEA AND STATE:
Find a meeting then walk until returning to that same node. TRACE: Five nodes with
tail->index2 have cycle length3. CORRECTNESS: One complete lap visits each distinct cycle node
once. COST: O(n) time,O(1) space. PITFALL: Count only cycle nodes, not the leading noncyclic
prefix. PRACTICE: Change the example, predict each state update and add an empty/boundary
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

Node* meeting(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return slow;
        }
    }
    return nullptr;
}

int cycleLength(Node* head) {
    Node* hit = meeting(head);
    if (hit == nullptr) {
        return 0;
    }
    int length = 1;
    for (Node* p = hit->next; p != hit; p = p->next) {
        ++length;
    }
    return length;
}

int main() {
    Node* head = build({1, 2, 3, 4, 5});
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    assert(cycleLength(head) == 0);
    tail->next = head->next->next;
    assert(cycleLength(head) == 3);
    tail->next = tail;
    assert(cycleLength(head) == 1);
    tail->next = nullptr;
    clear(head);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
