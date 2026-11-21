/*
RING-BUFFER AND LINKED FIFO IMPLEMENTATIONS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Ring capacity1..1000; full/empty operations throw documented exceptions. Linked
owner is noncopyable. IDEA AND STATE: Ring count separates full from empty; linked enqueue
uses tail and dequeue uses head. TRACE: Capacity3:enqueue1,2,3,dequeue1,enqueue4 ->front2
after wraparound. CORRECTNESS: Both representations preserve arrival order; deleting the last
linked node clears both endpoints. COST: O(1) enqueue/dequeue/front,O(capacity) ring storage
or O(n) nodes. PITFALL: Modulo requires positive capacity, and copying a raw owning queue
would double-delete. PRACTICE: Change the example, predict each state update and add an
empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
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

class CircularQueue {
    std::vector<int> data;
    std::size_t front = 0;
    std::size_t used = 0;

public:
    explicit CircularQueue(int capacity) {
        if (capacity <= 0 || capacity > 1000) {
            throw std::invalid_argument("capacity");
        }
        data.resize(static_cast<std::size_t>(capacity));
    }

    void enqueue(int value) {
        if (used == data.size()) {
            throw std::overflow_error("full queue");
        }
        data[(front + used) % data.size()] = value;
        ++used;
    }

    void dequeue() {
        if (used == 0) {
            throw std::underflow_error("empty queue");
        }
        front = (front + 1) % data.size();
        --used;
    }

    int getFront() const {
        if (used == 0) {
            throw std::underflow_error("empty queue");
        }
        return data[front];
    }

    bool empty() const {
        return used == 0;
    }
};

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
        CircularQueue ring(3);
        LinkedListQueue linked;
        for (int value : {1, 2, 3}) {
            ring.enqueue(value);
            linked.enqueue(value);
        }
        bool full = false;
        try {
            ring.enqueue(4);
        } catch (const std::overflow_error&) {
            full = true;
        }
        assert(full);
        ring.dequeue();
        linked.dequeue();
        ring.enqueue(4);
        linked.enqueue(4);
        for (int value : {2, 3, 4}) {
            assert(ring.getFront() == value && linked.getFront() == value);
            ring.dequeue();
            linked.dequeue();
        }
        assert(ring.empty() && linked.empty());
        linked.enqueue(9);
        assert(linked.getFront() == 9);
        bool invalid = false;
        try {
            CircularQueue bad(0);
        } catch (const std::invalid_argument&) {
            invalid = true;
        }
        assert(invalid);
        bool empty = false;
        try {
            ring.dequeue();
        } catch (const std::underflow_error&) {
            empty = true;
        }
        assert(empty);
    }
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
