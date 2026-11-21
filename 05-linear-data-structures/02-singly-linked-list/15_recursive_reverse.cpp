/*
RECURSIVE REVERSAL RETAINS PENDING FRAMES PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Acyclic chain of at most100 nodes. The caller owns every allocated node unless
ownership is explicitly transferred. Test fixtures reclaim all nodes. IDEA AND STATE: Reverse
the suffix, point the old next back at head, then terminate the old head link. TRACE: 1->2->3
->suffix3->2,then3->2->1. CORRECTNESS: The smaller suffix is reversed correctly; one back-link
attaches the old head at its end. COST: O(n) time,O(n) call-stack space; no new data nodes.
PITFALL: Set head.next=null or the back-link creates a cycle. PRACTICE: Change the example,
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

Node* recursiveReverse(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* newHead = recursiveReverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

int main() {
    for (std::vector<int> a : std::vector<std::vector<int>>{{}, {1}, {1, 2, 3}}) {
        Node* head = build(a);
        head = recursiveReverse(head);
        std::reverse(a.begin(), a.end());
        assert(view(head) == a);
        clear(head);
    }
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
