/*
LIST ACCESS IS TRAVERSAL RATHER THAN INDEXING PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Return a const borrowed kth node or nullptr; k is zero-based. The caller owns every
allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.
IDEA AND STATE: Advance at most k links after validating nonnegative index. TRACE: 4,7,9 kth2
->9; kth3 absent. CORRECTNESS: After i steps the observer denotes index i, if it exists. COST:
O(n) length and O(k+1) access,O(1) space. PITFALL: A linked list does not offer vector-like
constant-time random access. PRACTICE: Change the example, predict each state update and add
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

int length(const Node* head) {
    int n = 0;
    while (head != nullptr) {
        ++n;
        head = head->next;
    }
    return n;
}

const Node* kth(const Node* head, int k) {
    if (k < 0) {
        return nullptr;
    }
    for (int i = 0; i < k && head != nullptr; ++i) {
        head = head->next;
    }
    return head;
}

int main() {
    Node* head = build({4, 7, 9});
    assert(length(head) == 3);
    assert(kth(head, 2)->value == 9);
    assert(kth(head, 3) == nullptr);
    assert(kth(head, -1) == nullptr);
    assert(length(nullptr) == 0);
    clear(head);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
