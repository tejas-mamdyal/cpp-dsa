/*
DELETE NTH FROM END WITH A FIXED OBSERVER GAP PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 n>=1; reject invalid n before unlinking anything. The caller owns every allocated
node unless ownership is explicitly transferred. Test fixtures reclaim all nodes. IDEA AND
STATE: A dummy predecessor and an n-link lead let slow stop immediately before the victim.
TRACE: 1,2,3 with n3 deletes head1. CORRECTNESS: When fast reaches the tail, slow.next is n
positions from the end. COST: O(n) time,O(1) space. PITFALL: An oversized gap must return
failure without partially changing the list. PRACTICE: Change the example, predict each state
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

bool removeNth(Node*& head, int n) {
    if (n < 1) {
        return false;
    }
    Node dummy(0);
    dummy.next = head;
    Node* fast = &dummy;
    for (int i = 0; i < n; ++i) {
        if (fast->next == nullptr) {
            return false;
        }
        fast = fast->next;
    }
    Node* slow = &dummy;
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    Node* victim = slow->next;
    slow->next = victim->next;
    delete victim;
    head = dummy.next;
    return true;
}

int main() {
    Node* head = build({1, 2, 3});
    assert(!removeNth(head, 4));
    assert((view(head) == std::vector<int>{1, 2, 3}));
    assert(removeNth(head, 3));
    assert((view(head) == std::vector<int>{2, 3}));
    assert(removeNth(head, 1));
    assert(removeNth(head, 1));
    assert(head == nullptr);
    assert(!removeNth(head, 1));
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
