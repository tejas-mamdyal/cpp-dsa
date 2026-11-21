/*
RETURN A BORROWED MATCHING NODE PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Find first matching value; nullptr represents absence. The caller owns every
allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.
IDEA AND STATE: Walk from head and return the first equal node without allocating. TRACE:
1,2,2 target2 returns the first2;updating it gives1,9,2. CORRECTNESS: Every earlier node was
checked and rejected, establishing first occurrence. COST: O(n) worst search,O(1) space.
PITFALL: The returned pointer borrows its owner; never delete it separately. PRACTICE: Change
the example, predict each state update and add an empty/boundary case. No input unless
explicitly stated. Assertions are the teaching test harness and must remain enabled; success
prints checks passed. These bounds describe the helper, not a claim that a fixed-data
demonstration has growing runtime input.
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

Node* find(Node* head, int key) {
    while (head != nullptr) {
        if (head->value == key) {
            return head;
        }
        head = head->next;
    }
    return nullptr;
}

int main() {
    Node* head = build({1, 2, 2});
    Node* found = find(head, 2);
    assert(found == head->next);
    found->value = 9;
    assert((view(head) == std::vector<int>{1, 9, 2}));
    assert(find(head, 7) == nullptr);
    clear(head);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
