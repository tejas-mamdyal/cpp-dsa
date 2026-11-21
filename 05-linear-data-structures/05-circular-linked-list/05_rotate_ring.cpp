/*
ROTATE THE LOGICAL HEAD BY MOVING AN OBSERVER PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Nonnegative k; empty ring unchanged. A nonempty tail observer identifies the
uniquely owned ring; head=tail.next. The caller owns every allocated node unless ownership is
explicitly transferred. Test fixtures reclaim all nodes. IDEA AND STATE: Count nodes, reduce k
modulo length, advance tail k links. TRACE: 1,2,3 left1 ->2,3,1 with the same edges.
CORRECTNESS: Changing tail changes which node is called head without allocating or relinking.
COST: O(n+k%n) time,O(1) extra space. PITFALL: Do not apply modulo before checking the empty
ring. PRACTICE: Change the example, predict each state update and add an empty/boundary case.
No input unless explicitly stated. Assertions are the teaching test harness and must remain
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

void rotateCircle(Node*& tail, std::size_t k) {
    if (tail == nullptr) {
        return;
    }
    std::size_t length = 1;
    for (Node* p = tail->next; p != tail; p = p->next) {
        ++length;
    }
    k %= length;
    for (std::size_t i = 0; i < k; ++i) {
        tail = tail->next;
    }
}

int main() {
    Node* tail = nullptr;
    rotateCircle(tail, 7);
    for (int value : {1, 2, 3}) {
        appendCircle(tail, value);
    }
    int live = Node::live;
    rotateCircle(tail, 4);
    assert((circleValues(tail) == std::vector<int>{2, 3, 1}));
    assert(Node::live == live);
    clearCircle(tail);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
