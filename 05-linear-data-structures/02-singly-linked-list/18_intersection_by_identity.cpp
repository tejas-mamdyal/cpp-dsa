/*
SHARED SUFFIX INTERSECTION IS IDENTITY NOT EQUALITY PREREQUISITES: Phases1/2 C++ and STL,

README order, not old filenames.

 Two acyclic observed chains may share a suffix. The caller owns all allocations but
must detach shared links before independently clearing prefixes. IDEA AND STATE: Walk each
observer through both chains; equal total traversed length aligns their suffix positions.
TRACE: Prefixes1,2 and3 both link to7,8;intersection is the shared7 node. CORRECTNESS: After
switching heads,both paths have equal combined length; they meet at the shared suffix or at
null if disjoint. COST: O(n+m) time,O(1) extra space. PITFALL: Equal values do not prove
shared nodes. Clearing two overlapping chains independently would double-delete the suffix.
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
        Node* old = head;
        head = head->next;
        delete old;
    }
}

Node* build(const std::vector<int>& a) {
    Node* head = nullptr;
    Node* tail = nullptr;
    try {
        for (int value : a) {
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

const Node* intersection(const Node* first, const Node* second) {
    const Node* a = first;
    const Node* b = second;
    while (a != b) {
        if (a == nullptr) {
            a = second;
        } else {
            a = a->next;
        }
        if (b == nullptr) {
            b = first;
        } else {
            b = b->next;
        }
    }
    return a;
}

int main() {
    Node* first = build({1, 2});
    Node* second = build({3});
    Node* shared = build({7, 8});
    assert(intersection(first, second) == nullptr);
    first->next->next = shared;
    second->next = shared;
    assert(intersection(first, second) == shared);
    assert(intersection(shared, shared) == shared);
    assert(intersection(nullptr, second) == nullptr);
    first->next->next = nullptr;
    second->next = nullptr;
    clear(first);
    clear(second);
    clear(shared);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
