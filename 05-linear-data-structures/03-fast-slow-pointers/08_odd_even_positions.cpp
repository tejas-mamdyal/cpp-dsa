/*
GROUP NODES BY POSITION RATHER THAN VALUE PARITY PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Acyclic chain; odd-indexed positions1,3,5 precede2,4,6 stably. The caller owns every
allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.
IDEA AND STATE: Two link chains grow in parallel, then the odd tail joins the even head.
TRACE: 1,2,3,4,5 ->1,3,5,2,4. CORRECTNESS: Each original node joins exactly one chain in its
original relative order. COST: O(n) time,O(1) extra space. PITFALL: Odd/even refers to
positions, not stored integer parity. PRACTICE: Change the example, predict each state update
and add an empty/boundary case. No input unless explicitly stated. Assertions are the teaching
test harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
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

Node* oddEven(Node* head) {
    if (head == nullptr) {
        return head;
    }
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    while (even != nullptr && even->next != nullptr) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main() {
    for (int n = 0; n <= 8; ++n) {
        std::vector<int> a;
        for (int i = 0; i < n; ++i) {
            a.push_back(i);
        }
        std::vector<int> expected;
        for (int i = 0; i < n; i += 2) {
            expected.push_back(i);
        }
        for (int i = 1; i < n; i += 2) {
            expected.push_back(i);
        }
        Node* head = build(a);
        head = oddEven(head);
        assert(view(head) == expected);
        clear(head);
    }
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
