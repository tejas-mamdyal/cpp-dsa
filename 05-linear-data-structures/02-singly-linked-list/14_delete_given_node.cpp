/*
DELETION WITH ONLY A NON-TAIL NODE OBSERVER PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 A writable node in a live singly linked list; tail/null cannot be deleted by this
method. The caller owns every allocated node unless ownership is explicitly transferred. Test
fixtures reclaim all nodes. IDEA AND STATE: Copy the next value into this node and remove the
physical next node. TRACE: 1,2,3 with pointer to2 ->values1,3. CORRECTNESS: The visible value
sequence loses the requested position, although its original node identity survives. COST:
O(1) time/space. PITFALL: This invalidates observers to the next node, not to the supplied
node; it is unsuitable when identity matters. PRACTICE: Change the example, predict each state
update and add an empty/boundary case. No input unless explicitly stated. Assertions are the
teaching test harness and must remain enabled; success prints checks passed. These bounds
describe the helper, not a claim that a fixed-data demonstration has growing runtime input.
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

bool deleteGiven(Node* node) {
    if (node == nullptr || node->next == nullptr) {
        return false;
    }
    Node* victim = node->next;
    node->value = victim->value;
    node->next = victim->next;
    delete victim;
    return true;
}

int main() {
    Node* head = build({1, 2, 3});
    Node* given = head->next;
    assert(deleteGiven(given));
    assert(given == head->next && given->value == 3);
    assert((view(head) == std::vector<int>{1, 3}));
    assert(!deleteGiven(given));
    assert(!deleteGiven(nullptr));
    clear(head);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
