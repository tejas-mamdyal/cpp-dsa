/*
CLEANUP IS COMPLETE AND IDEMPOTENT PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Acyclic uniquely owned chain; clear resets the owner. The caller owns every
allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.
IDEA AND STATE: Remove one head at a time, keeping remaining nodes reachable. TRACE: Three
live nodes ->two ->one ->zero. CORRECTNESS: Each original node is deleted once and the loop
ends at null. COST: O(n) time,O(1) auxiliary stack; no recursive destructor chain. PITFALL: A
cycle must be broken before this acyclic cleanup helper is used. PRACTICE: Change the example,
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
    for (int n = 0; n <= 30; ++n) {
        Node* head = build(std::vector<int>(static_cast<std::size_t>(n), 7));
        assert(Node::live == n);
        clear(head);
        assert(head == nullptr);
        assert(Node::live == 0);
        clear(head);
    }
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
