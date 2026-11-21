/*
REVERSE LINKS WITH THREE POINTER ROLES PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Acyclic list; return the new owning head without allocating. The caller owns every
allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.
IDEA AND STATE: Save the next unprocessed node before reversing the current link. TRACE:
1->2->3 becomes3->2->1. CORRECTNESS: previous is the reversed processed prefix; head starts
the untouched suffix. COST: O(n) time,O(1) extra space. PITFALL: Assign the returned head;
keeping the old head loses access to the rest of the reversed chain. PRACTICE: Change the
example, predict each state update and add an empty/boundary case. No input unless explicitly
stated. Assertions are the teaching test harness and must remain enabled; success prints
checks passed. These bounds describe the helper, not a claim that a fixed-data demonstration
has growing runtime input.
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

Node* reverse(Node* head) {
    Node* previous = nullptr;
    while (head != nullptr) {
        Node* next = head->next;
        head->next = previous;
        previous = head;
        head = next;
    }
    return previous;
}

int main() {
    for (std::vector<int> values : std::vector<std::vector<int>>{{}, {1}, {1, 2, 3, 4}}) {
        Node* head = build(values);
        head = reverse(head);
        std::reverse(values.begin(), values.end());
        assert(view(head) == values);
        clear(head);
    }
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
