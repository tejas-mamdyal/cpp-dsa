/*
FLOYD DETECTION VERSUS POINTER-SET DETECTION PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Borrow a possibly cyclic chain; cleanup breaks the known fixture cycle first. The
caller owns every allocated node unless ownership is explicitly transferred. Test fixtures
reclaim all nodes. IDEA AND STATE: Floyd observers eventually meet in a cycle; a set detects a
repeated node identity. TRACE: 1->2->3->2 creates a cycle even when all values are distinct.
CORRECTNESS: Within a cycle the relative position advances by one modulo its length, forcing a
meeting. COST: Floyd O(n) time/O(1) space; hash expected O(n) time/O(n) space. PITFALL:
Repeated values do not imply repeated nodes; ordinary null-terminated cleanup cannot traverse
a cycle. PRACTICE: Change the example, predict each state update and add an empty/boundary
case. No input unless explicitly stated. Assertions are the teaching test harness and must
remain enabled; success prints checks passed. These bounds describe the helper, not a claim
that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <unordered_set>

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

Node* meeting(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return slow;
        }
    }
    return nullptr;
}

bool hasCycleHashSet(Node* head) {
    std::unordered_set<Node*> seen;
    while (head != nullptr) {
        if (!seen.insert(head).second) {
            return true;
        }
        head = head->next;
    }
    return false;
}

bool hasCycleFloyd(Node* head) {
    return meeting(head) != nullptr;
}

int main() {
    assert(!hasCycleFloyd(nullptr));
    for (int entry = 0; entry < 4; ++entry) {
        Node* head = build({1, 2, 3, 4});
        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        assert(!hasCycleHashSet(head) && !hasCycleFloyd(head));
        Node* target = head;
        for (int i = 0; i < entry; ++i) {
            target = target->next;
        }
        tail->next = target;
        assert(hasCycleHashSet(head) && hasCycleFloyd(head));
        tail->next = nullptr;
        clear(head);
    }
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
