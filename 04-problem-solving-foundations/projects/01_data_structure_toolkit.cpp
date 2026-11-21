/*
DATA-STRUCTURE TOOLKIT: MODEL, COMMANDS AND INDEPENDENT CHECKS Prerequisites: completed Phase3
searching/sorting/arrays and all linear structures. One complete command per line; EOF or QUIT
ends normally. Values are ints in [-1000000,1000000]. SEQ/LIST hold at most1000 elements;
STACK/QUEUE capacity8. Commands: SEQ_PUSH value, SEQ_INSERT index value, SEQ_ERASE index,
SEQ_REVERSE, SEQ_SHOW, SEQ_SORT, SEQ_FIND value; LIST_PUSH_FRONT/BACK value, LIST_INSERT index
value, LIST_ERASE index, LIST_REVERSE, LIST_SHOW, LIST_FIND value; STACK_PUSH/POP/PEEK;
QUEUE_PUSH/POP/FRONT; RESET, CHECK, SELFTEST, QUIT. Successful changes print OK, removals
print the removed value, empty stack/queue observations print EMPTY and capacity rejection
prints FULL without changing state. SHOW prints a normalized line, including a blank line for
an empty sequence. Invalid syntax/value/index prints stderr and exits1 before that command
mutates data; earlier successful output remains. No arbitrary command-count limit is imposed.

The list uniquely owns its nodes, forbids shallow copies, resets both endpoints on empty
transitions and deletes iteratively. Stack and queue use actual bounded arrays; the queue
separates logical order from physical wraparound. A vector owns the sequence. CLI parsing
validates before invoking these independent models. SELFTEST compares mixed list/stack/queue
operations with vector/deque oracles after every step, checks capacity boundaries and counts
live nodes. Assertions must stay on for that teaching harness; user-input validation does not
rely on assertions.

Trace: LIST_PUSH_BACK 1, LIST_PUSH_FRONT 2, LIST_REVERSE, LIST_SHOW prints OK three times then
1 2. Queue1,2,pop gives1 even after many physical wraps. Costs: insertion sorting
O(n^2);first-match search O(n) with O(1) working state;sequence middle shifts and list
positional operations O(n),list endpoint push/pop O(1),stack/ring operations
O(1),reverse/SHOW/CHECK O(n). State O(n) plus bounded arrays; SELFTEST uses separate bounded
reference storage. Practice: add a command transaction log or a doubly linked model after
preserving these contracts.

Parsing a command line of L characters takes O(L) time and temporary memory; model-operation
bounds above exclude that input/output work.
*/
#include <array>
#include <cassert>
#include <deque>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>

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

class List {
    Node* head = nullptr;
    Node* tail = nullptr;
    std::size_t count = 0;

public:
    List() = default;
    List(const List&) = delete;
    List& operator=(const List&) = delete;

    ~List() {
        clear();
    }

    std::size_t size() const {
        return count;
    }

    void clear() {
        while (head != nullptr) {
            Node* old = head;
            head = head->next;
            delete old;
        }
        tail = nullptr;
        count = 0;
    }

    bool pushFront(int value) {
        if (count == 1000) {
            return false;
        }
        Node* node = new Node(value);
        node->next = head;
        head = node;
        if (tail == nullptr) {
            tail = node;
        }
        ++count;
        return true;
    }

    bool pushBack(int value) {
        if (count == 1000) {
            return false;
        }
        Node* node = new Node(value);
        if (tail == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
        ++count;
        return true;
    }

    bool insert(std::size_t index, int value) {
        if (index > count || count == 1000) {
            return false;
        }
        if (index == 0) {
            return pushFront(value);
        }
        if (index == count) {
            return pushBack(value);
        }
        Node* previous = head;
        for (std::size_t i = 1; i < index; ++i) {
            previous = previous->next;
        }
        Node* node = new Node(value);
        node->next = previous->next;
        previous->next = node;
        ++count;
        return true;
    }

    std::optional<int> erase(std::size_t index) {
        if (index >= count) {
            return std::nullopt;
        }
        Node* victim = head;
        if (index == 0) {
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
        } else {
            Node* previous = head;
            for (std::size_t i = 1; i < index; ++i) {
                previous = previous->next;
            }
            victim = previous->next;
            previous->next = victim->next;
            if (victim == tail) {
                tail = previous;
            }
        }
        int value = victim->value;
        delete victim;
        --count;
        return value;
    }

    void reverse() {
        Node* previous = nullptr;
        Node* current = head;
        tail = head;
        while (current != nullptr) {
            Node* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }

    std::vector<int> values() const {
        std::vector<int> out;
        for (const Node* p = head; p != nullptr; p = p->next) {
            out.push_back(p->value);
        }
        return out;
    }

    int find(int value) const {
        int index = 0;
        for (const Node* current = head; current != nullptr; current = current->next) {
            if (current->value == value) {
                return index;
            }
            ++index;
        }
        return -1;
    }

    bool valid() const {
        if (count == 0) {
            return head == nullptr && tail == nullptr;
        }
        if (head == nullptr || tail == nullptr) {
            return false;
        }
        const Node* p = head;
        const Node* last = nullptr;
        std::size_t visited = 0;
        // The count bound also makes a mistaken cycle fail rather than loop forever.
        while (p != nullptr && visited <= count) {
            last = p;
            p = p->next;
            ++visited;
        }
        return p == nullptr && visited == count && last == tail && tail->next == nullptr;
    }
};

class Stack {
    std::array<int, 8> data{};
    std::size_t count = 0;

public:
    bool push(int value) {
        if (count == data.size()) {
            return false;
        }
        data[count++] = value;
        return true;
    }

    std::optional<int> pop() {
        if (count == 0) {
            return std::nullopt;
        }
        return data[--count];
    }

    std::optional<int> peek() const {
        if (count == 0) {
            return std::nullopt;
        }
        return data[count - 1];
    }
};

class Queue {
    std::array<int, 8> data{};
    std::size_t first = 0;
    std::size_t count = 0;

public:
    bool push(int value) {
        if (count == data.size()) {
            return false;
        }
        data[(first + count) % data.size()] = value;
        ++count;
        return true;
    }

    std::optional<int> pop() {
        if (count == 0) {
            return std::nullopt;
        }
        int value = data[first];
        first = (first + 1) % data.size();
        --count;
        return value;
    }

    std::optional<int> front() const {
        if (count == 0) {
            return std::nullopt;
        }
        return data[first];
    }
};

void runModelChecks() {
    int baseline = Node::live;
    {
        List list;
        std::vector<int> listModel;
        Stack stack;
        std::vector<int> stackModel;
        Queue queue;
        std::deque<int> queueModel;
        for (int step = 0; step < 200; ++step) {
            if (step % 6 == 0) {
                assert(list.pushBack(step));
                listModel.push_back(step);
            } else if (step % 6 == 1) {
                assert(list.pushFront(-step));
                listModel.insert(listModel.begin(), -step);
            } else if (step % 6 == 2) {
                std::size_t middle = listModel.size() / 2;
                assert(list.insert(middle, step));
                listModel.insert(listModel.begin() + static_cast<std::ptrdiff_t>(middle), step);
            } else if (step % 6 == 3 && !listModel.empty()) {
                assert(list.erase(0) == listModel.front());
                listModel.erase(listModel.begin());
            } else if (step % 6 == 4 && !listModel.empty()) {
                assert(list.erase(listModel.size() - 1) == listModel.back());
                listModel.pop_back();
            } else {
                list.reverse();
                std::reverse(listModel.begin(), listModel.end());
            }
            assert(list.valid() && list.values() == listModel);
            assert(Node::live == baseline + static_cast<int>(list.size()));
            if (step % 3 != 2) {
                bool room = stackModel.size() < 8;
                assert(stack.push(step) == room);
                if (room) {
                    stackModel.push_back(step);
                }
            } else {
                auto actual = stack.pop();
                if (stackModel.empty()) {
                    assert(!actual);
                } else {
                    assert(actual == stackModel.back());
                    stackModel.pop_back();
                }
            }
            if (stackModel.empty()) {
                assert(!stack.peek());
            } else {
                assert(stack.peek() == stackModel.back());
            }
            if (step % 5 < 3) {
                bool room = queueModel.size() < 8;
                assert(queue.push(step) == room);
                if (room) {
                    queueModel.push_back(step);
                }
            } else {
                auto actual = queue.pop();
                if (queueModel.empty()) {
                    assert(!actual);
                } else {
                    assert(actual == queueModel.front());
                    queueModel.pop_front();
                }
            }
            if (queueModel.empty()) {
                assert(!queue.front());
            } else {
                assert(queue.front() == queueModel.front());
            }
        }
        list.clear();
        assert(list.valid());
        assert(!list.erase(0));
        for (int i = 0; i < 1000; ++i) {
            assert(list.pushBack(i));
        }
        assert(!list.pushBack(1001));
        assert(!list.insert(1001, 7));
        assert(list.valid());
    }
    assert(Node::live == baseline);
}

bool finished(std::istringstream& input) {
    char extra = ' ';
    return !(input >> extra);
}

bool readValue(std::istringstream& input, int& value) {
    return static_cast<bool>(input >> value) && value >= -1000000 && value <= 1000000
           && finished(input);
}

void printValue(std::optional<int> value) {
    if (value) {
        std::cout << *value << '\n';
    } else {
        std::cout << "EMPTY\n";
    }
}

void insertionSort(std::vector<int>& values) {
    for (std::size_t i = 1; i < values.size(); ++i) {
        int saved = values[i];
        std::size_t position = i;
        while (position > 0 && values[position - 1] > saved) {
            values[position] = values[position - 1];
            --position;
        }
        values[position] = saved;
    }
}

void printSequence(const std::vector<int>& values) {
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << values[i];
    }
    std::cout << '\n';
}

struct Toolkit {
    std::vector<int> sequence;
    List list;
    Stack stack;
    Queue queue;
};

bool execute(const std::string& line, Toolkit& state, bool& quit) {
    std::istringstream input(line);
    std::string command;
    if (!(input >> command)) {
        return false;
    }
    if (command == "SEQ_FIND" || command == "LIST_FIND") {
        int value = 0;
        if (!readValue(input, value)) {
            return false;
        }
        int index = -1;
        if (command == "LIST_FIND") {
            index = state.list.find(value);
        } else {
            for (std::size_t i = 0; i < state.sequence.size(); ++i) {
                if (state.sequence[i] == value) {
                    index = static_cast<int>(i);
                    break;
                }
            }
        }
        std::cout << index << '\n';
        return true;
    }
    if (command == "SEQ_PUSH" || command == "LIST_PUSH_FRONT" || command == "LIST_PUSH_BACK"
        || command == "STACK_PUSH" || command == "QUEUE_PUSH") {
        int value = 0;
        if (!readValue(input, value)) {
            return false;
        }
        bool success = false;
        if (command == "SEQ_PUSH") {
            if (state.sequence.size() < 1000) {
                state.sequence.push_back(value);
                success = true;
            }
        } else if (command == "LIST_PUSH_FRONT") {
            success = state.list.pushFront(value);
        } else if (command == "LIST_PUSH_BACK") {
            success = state.list.pushBack(value);
        } else if (command == "STACK_PUSH") {
            success = state.stack.push(value);
        } else {
            success = state.queue.push(value);
        }
        if (success) {
            std::cout << "OK\n";
        } else {
            std::cout << "FULL\n";
        }
        return true;
    }
    if (command == "SEQ_INSERT" || command == "LIST_INSERT") {
        int index = 0;
        int value = 0;
        if (!(input >> index) || index < 0 || !readValue(input, value)) {
            return false;
        }
        std::size_t position = static_cast<std::size_t>(index);
        std::size_t size = state.sequence.size();
        if (command == "LIST_INSERT") {
            size = state.list.size();
        }
        if (position > size) {
            return false;
        }
        if (size == 1000) {
            std::cout << "FULL\n";
            return true;
        }
        if (command == "SEQ_INSERT") {
            state.sequence.insert(state.sequence.begin() + index, value);
        } else {
            state.list.insert(position, value);
        }
        std::cout << "OK\n";
        return true;
    }
    if (command == "SEQ_ERASE" || command == "LIST_ERASE") {
        int index = 0;
        if (!(input >> index) || index < 0 || !finished(input)) {
            return false;
        }
        std::size_t position = static_cast<std::size_t>(index);
        std::size_t size = state.sequence.size();
        if (command == "LIST_ERASE") {
            size = state.list.size();
        }
        if (position >= size) {
            return false;
        }
        if (command == "SEQ_ERASE") {
            int value = state.sequence[position];
            state.sequence.erase(state.sequence.begin() + index);
            printValue(value);
        } else {
            printValue(state.list.erase(position));
        }
        return true;
    }
    if (!finished(input)) {
        return false;
    }
    if (command == "SEQ_SHOW") {
        printSequence(state.sequence);
    } else if (command == "LIST_SHOW") {
        printSequence(state.list.values());
    } else if (command == "SEQ_SORT") {
        insertionSort(state.sequence);
        std::cout << "OK\n";
    } else if (command == "SEQ_REVERSE") {
        std::reverse(state.sequence.begin(), state.sequence.end());
        std::cout << "OK\n";
    } else if (command == "LIST_REVERSE") {
        state.list.reverse();
        std::cout << "OK\n";
    } else if (command == "STACK_POP") {
        printValue(state.stack.pop());
    } else if (command == "STACK_PEEK") {
        printValue(state.stack.peek());
    } else if (command == "QUEUE_POP") {
        printValue(state.queue.pop());
    } else if (command == "QUEUE_FRONT") {
        printValue(state.queue.front());
    } else if (command == "CHECK") {
        if (!state.list.valid() || Node::live != static_cast<int>(state.list.size())) {
            return false;
        }
        std::cout << "valid\n";
    } else if (command == "RESET") {
        state.sequence.clear();
        state.list.clear();
        state.stack = Stack{};
        state.queue = Queue{};
        std::cout << "OK\n";
    } else if (command == "SELFTEST") {
        runModelChecks();
        std::cout << "self-test passed\n";
    } else if (command == "QUIT") {
        quit = true;
    } else {
        return false;
    }
    return true;
}

int main() {
    Toolkit state;
    std::string line;
    bool quit = false;
    while (!quit && std::getline(std::cin, line)) {
        if (!execute(line, state, quit)) {
            std::cerr << "Invalid command, value, index or invariant.\n";
            return 1;
        }
    }
    if (std::cin.bad()) {
        std::cerr << "Input read failed.\n";
        return 1;
    }
    return 0;
}
