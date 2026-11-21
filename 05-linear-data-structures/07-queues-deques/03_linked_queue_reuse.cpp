/*
DRAIN AND REUSE AN OWNING LINKED QUEUE PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 No shallow copies; empty dequeue throws. IDEA AND STATE: Observe head/tail
transitions over many complete fill/drain cycles. TRACE: After the last pop, enqueue must
start a new valid chain. CORRECTNESS: Resetting tail on final removal makes later enqueue
behave like a fresh empty queue. COST: O(1) endpoint operations,O(n) cleanup/storage. PITFALL:
A dangling old tail may appear to work until memory is reused. PRACTICE: Change the example,
predict each state update and add an empty/boundary case. No input unless explicitly stated.
Assertions are the teaching test harness and must remain enabled; success prints checks
passed. These bounds describe the helper, not a claim that a fixed-data demonstration has
growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <stdexcept>

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

class LinkedListQueue {
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    LinkedListQueue() = default;
    LinkedListQueue(const LinkedListQueue&) = delete;
    LinkedListQueue& operator=(const LinkedListQueue&) = delete;

    ~LinkedListQueue() {
        clear(head);
    }

    void enqueue(int value) {
        Node* node = new Node(value);
        if (tail == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    void dequeue() {
        if (head == nullptr) {
            throw std::underflow_error("empty queue");
        }
        Node* old = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete old;
    }

    int getFront() const {
        if (head == nullptr) {
            throw std::underflow_error("empty queue");
        }
        return head->value;
    }

    bool empty() const {
        return head == nullptr;
    }
};

int main() {
    {
        LinkedListQueue queue;
        for (int round = 0; round < 20; ++round) {
            for (int value = 0; value < 5; ++value) {
                queue.enqueue(round * 10 + value);
            }
            for (int value = 0; value < 5; ++value) {
                assert(queue.getFront() == round * 10 + value);
                queue.dequeue();
            }
            assert(queue.empty());
            assert(Node::live == 0);
        }
        bool failed = false;
        try {
            queue.dequeue();
        } catch (const std::underflow_error&) {
            failed = true;
        }
        assert(failed);
    }
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
