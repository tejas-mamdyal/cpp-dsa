/*
ELIMINATE EVERY KTH LIVE NODE PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 n,k in1..10; return1-based surviving label; invalid values yield absence. A nonempty
tail observer identifies the uniquely owned ring; head=tail.next. The caller owns every
allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.
IDEA AND STATE: Move a predecessor k-1 links then unlink/delete the current victim. TRACE:
n5,k2 removes2,4,1,5 and leaves3. CORRECTNESS: The cursor always denotes the next counting
start and predecessor enables safe removal. COST: O(n*k) simulation time,O(n) owned nodes; all
are eventually deleted. PITFALL: The final survivor is still allocated and must also be
deleted. PRACTICE: Change the example, predict each state update and add an empty/boundary
case. No input unless explicitly stated. Assertions are the teaching test harness and must
remain enabled; success prints checks passed. These bounds describe the helper, not a claim
that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

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

void clearCircle(Node*& tail) {
    if (tail == nullptr) {
        return;
    }
    Node* head = tail->next;
    tail->next = nullptr;
    clear(head);
    tail = nullptr;
}

std::optional<int> josephus(int n, int k) {
    if (n < 1 || n > 10 || k < 1 || k > 10) {
        return std::nullopt;
    }
    Node* tail = nullptr;
    try {
        for (int value = 1; value <= n; ++value) {
            appendCircle(tail, value);
        }
    } catch (...) {
        clearCircle(tail);
        throw;
    }
    Node* previous = tail;
    Node* current = tail->next;
    while (current->next != current) {
        for (int step = 1; step < k; ++step) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        Node* victim = current;
        current = current->next;
        delete victim;
    }
    int answer = current->value;
    delete current;
    return answer;
}

int main() {
    assert(!josephus(0, 2));
    for (int n = 1; n <= 10; ++n) {
        for (int k = 1; k <= 10; ++k) {
            int expected = 0;
            for (int size = 1; size <= n; ++size) {
                expected = (expected + k) % size;
            }
            assert(josephus(n, k) == expected + 1);
            assert(Node::live == 0);
        }
    }
    assert(josephus(5, 2) == 3);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
