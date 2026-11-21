/*
REMOVE AN NTH-FROM-END NODE WITH TWO TRAVERSALS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 n counts from1 at the tail; invalid n returns false. The caller owns every allocated
node unless ownership is explicitly transferred. Test fixtures reclaim all nodes. IDEA AND
STATE: Compute length then erase zero-based index length-n. TRACE: 1,2,3 remove n1
->1,2;remove n2 then deletes head. CORRECTNESS: The nth-from-end position is exactly length-n
when1<=n<=length. COST: O(length) time for two traversals,O(1) space. PITFALL: Two sequential
linear scans are still linear; the next unit reduces to one gap-based traversal. PRACTICE:
Change the example, predict each state update and add an empty/boundary case. No input unless
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

bool eraseAt(Node*& head, int index) {
    if (index < 0) {
        return false;
    }
    if (index == 0) {
        if (head == nullptr) {
            return false;
        }
        Node* victim = head;
        head = head->next;
        delete victim;
        return true;
    }
    Node* previous = head;
    for (int i = 1; i < index && previous != nullptr; ++i) {
        previous = previous->next;
    }
    if (previous == nullptr || previous->next == nullptr) {
        return false;
    }
    Node* victim = previous->next;
    previous->next = victim->next;
    delete victim;
    return true;
}

bool removeNth(Node*& head, int n) {
    int length = 0;
    for (Node* p = head; p != nullptr; p = p->next) {
        ++length;
    }
    if (n < 1 || n > length) {
        return false;
    }
    return eraseAt(head, length - n);
}

int main() {
    Node* head = build({1, 2, 3});
    assert(!removeNth(head, 0));
    assert(!removeNth(head, 4));
    assert(removeNth(head, 1));
    assert((view(head) == std::vector<int>{1, 2}));
    assert(removeNth(head, 2));
    assert((view(head) == std::vector<int>{2}));
    clear(head);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
