/*
OWN AND TRAVERSE A CIRCULAR LIST PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Noncopyable owner supports append and one-lap traversal. A nonempty tail observer
identifies the uniquely owned ring; head=tail.next. The caller owns every allocated node
unless ownership is explicitly transferred. Test fixtures reclaim all nodes. IDEA AND STATE:
The first node links to itself; later appends preserve tail.next=head. TRACE: 1,2,3 traverses
exactly1,2,3, then returns to head. CORRECTNESS: Each append changes two links while keeping a
single cycle through every node. COST: O(1) append,O(n) traversal/cleanup,O(n) nodes. PITFALL:
Null termination is not a circular-list stopping condition; cleanup breaks the cycle first.
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
        Node* victim = head;
        head = head->next;
        delete victim;
    }
}

void appendCircle(Node*& tail, int value) {
    Node* node = new Node(value);
    if (tail == nullptr) {
        node->next = node;
    } else {
        node->next = tail->next;
        tail->next = node;
    }
    tail = node;
}

std::vector<int> circleValues(const Node* tail) {
    std::vector<int> out;
    if (tail == nullptr) {
        return out;
    }
    const Node* head = tail->next;
    const Node* p = head;
    do {
        out.push_back(p->value);
        p = p->next;
    } while (p != head);
    return out;
}

void clearCircle(Node*& tail) {
    if (tail == nullptr) {
        return;
    }
    Node* head = tail->next;
    tail->next = nullptr;
    clear(head);
    tail = nullptr;
}

class CircularLinkedList {
    Node* tail = nullptr;

public:
    CircularLinkedList() = default;
    CircularLinkedList(const CircularLinkedList&) = delete;
    CircularLinkedList& operator=(const CircularLinkedList&) = delete;

    ~CircularLinkedList() {
        clearCircle(tail);
    }

    void insertBack(int value) {
        appendCircle(tail, value);
    }

    std::vector<int> traverse() const {
        return circleValues(tail);
    }
};

int main() {
    {
        CircularLinkedList list;
        assert(list.traverse().empty());
        list.insertBack(1);
        assert((list.traverse() == std::vector<int>{1}));
        list.insertBack(2);
        list.insertBack(3);
        assert((list.traverse() == std::vector<int>{1, 2, 3}));
    }
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
