/*
DISABLE UNSAFE SHALLOW OWNERSHIP COPYING PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 An owner class holds a raw owning head; copies are forbidden. The caller owns every
allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.
IDEA AND STATE: Destructor clears the chain; borrowed access cannot transfer deletion
responsibility. TRACE: Two pushed nodes disappear when the owning scope ends. CORRECTNESS:
Only the single owner releases its nodes, preventing two destructors deleting the same chain.
COST: Push O(1),destruction O(n); O(n) owned nodes. PITFALL: A raw observer must not outlive
its owner. PRACTICE: Change the example, predict each state update and add an empty/boundary
case. No input unless explicitly stated. Assertions are the teaching test harness and must
remain enabled; success prints checks passed. These bounds describe the helper, not a claim
that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <type_traits>

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

class Owner {
    Node* head = nullptr;

public:
    Owner() = default;
    Owner(const Owner&) = delete;
    Owner& operator=(const Owner&) = delete;

    ~Owner() {
        clear(head);
    }

    void push(int value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
    }

    const Node* borrow() const {
        return head;
    }
};

int main() {
    static_assert(!std::is_copy_constructible<Owner>::value, "owning shallow copy forbidden");
    {
        Owner owner;
        owner.push(2);
        owner.push(1);
        assert((view(owner.borrow()) == std::vector<int>{1, 2}));
        assert(Node::live == 2);
    }
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
