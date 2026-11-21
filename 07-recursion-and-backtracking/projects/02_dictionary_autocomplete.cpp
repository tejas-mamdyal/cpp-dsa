/*
 One command per input line,at most200 bytes. Lowercase words/prefixes
have length0..30;quoted empty strings represent the empty word/prefix. Commands:
ADD word,DELETE word,FIND word,COUNT prefix,PREFIX prefix limit,CLEAR,QUIT.
Fields may be quoted using std::quoted;limit is0..100. At most1000 distinct words.
Print explicit responses;malformed lines print ERROR and leave the dictionary
unchanged. Empty lines are ignored. State lasts for this process;no persistence
is promised. SUGGEST n precedes n quoted output words in lexicographic order.

STATE: Each trie node owns its children;terminal marks a complete stored word.
Dictionary::words counts terminals,not nodes. Input is fully parsed/validated
before any mutation. The baseline filters std::set for each prefix;the trie
locates the matching subtree without scanning unrelated stored words.

ADD app,ADD apple,ADD ape ->three words. PREFIX ap 2 yields ape,app.
DELETE app leaves apple intact. COUNT ap then reports2. Repeating DELETE app
reports NOT FOUND. Invalid ADD Bad! does not leave partial prefix nodes.

Insert/search/delete use the released trie invariants. A prefix
word is exactly a terminal below its prefix node;alphabetic child traversal
and terminal-before-extension give lexical order. Capacity is checked before
new insertion,and word count changes only after a successful mutation.

Exact operations O(L),erase O(26*L),COUNT O(P+26*S),suggestions
O(P+26*S+output characters),where S is the visited matching subtree. Storage
O(26*total prefix nodes),bounded by the1000-word/30-character contract.

Empty word differs from an empty dictionary. Erasing app must not erase
apple. A suggestion limit is an output bound,not a promise of constant query
work. Borrowed prefix pointers never escape a query or survive mutation.
*/
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <array>
#include <iomanip>
#include <sstream>
#include <cstddef>

struct TrieNode {
    bool terminal = false;
    std::array<std::unique_ptr<TrieNode>, 26> children{};
};

bool lowercase(const std::string& word) {
    for (char ch : word) {
        if (ch < 'a' || ch > 'z') {
            return false;
        }
    }
    return true;
}

bool insert(TrieNode& root, const std::string& word) {
    if (!lowercase(word)) {
        return false;
    }
    auto current = &root;
    for (char ch : word) {
        std::size_t index = static_cast<std::size_t>(ch - 'a');
        if (!current->children[index]) {
            current->children[index] = std::make_unique<TrieNode>();
        }
        current = current->children[index].get();
    }
    bool added = !current->terminal;
    current->terminal = true;
    return added;
}

const TrieNode* locate(const TrieNode& root, const std::string& prefix) {
    if (!lowercase(prefix)) {
        return nullptr;
    }
    auto current = &root;
    for (char ch : prefix) {
        current = current->children[static_cast<std::size_t>(ch - 'a')].get();
        if (!current) {
            return nullptr;
        }
    }
    return current;
}

bool contains(const TrieNode& root, const std::string& word) {
    auto node = locate(root, word);
    return node && node->terminal;
}

bool emptyNode(const TrieNode& root) {
    if (root.terminal) {
        return false;
    }
    for (const auto& child : root.children) {
        if (child) {
            return false;
        }
    }
    return true;
}

bool eraseAt(TrieNode& root, const std::string& word, std::size_t index) {
    if (index == word.size()) {
        if (!root.terminal) {
            return false;
        }
        root.terminal = false;
        return true;
    }
    std::size_t edge = static_cast<std::size_t>(word[index] - 'a');
    auto& child = root.children[edge];
    if (!child || !eraseAt(*child, word, index + 1)) {
        return false;
    }
    if (emptyNode(*child)) {
        child.reset();
    }
    return true;
}

bool erase(TrieNode& root, const std::string& word) {
    if (!lowercase(word)) {
        return false;
    }
    return eraseAt(root, word, 0);
}

void collect(const TrieNode* root,
             std::string& path,
             std::size_t limit,
             std::vector<std::string>& out) {
    if (!root || out.size() >= limit) {
        return;
    }
    if (root->terminal) {
        out.push_back(path);
    }
    for (std::size_t i = 0; i < 26 && out.size() < limit; ++i) {
        if (root->children[i]) {
            path.push_back(static_cast<char>('a' + i));
            collect(root->children[i].get(), path, limit, out);
            path.pop_back();
        }
    }
}

std::vector<std::string>
suggest(const TrieNode& root, const std::string& prefix, std::size_t limit) {
    std::string path = prefix;
    std::vector<std::string> out;
    collect(locate(root, prefix), path, limit, out);
    return out;
}

int terminals(const TrieNode* root) {
    if (!root) {
        return 0;
    }
    int total = root->terminal ? 1 : 0;
    for (const auto& child : root->children) {
        total += terminals(child.get());
    }
    return total;
}

struct Dictionary {
    TrieNode root;
    int words = 0;
};

bool endOfCommand(std::istringstream& input) {
    input >> std::ws;
    return input.eof();
}

bool execute(Dictionary& dictionary, const std::string& line, std::ostream& output) {
    if (line.size() > 200) {
        output << "ERROR\n";
        return true;
    }
    std::istringstream input(line);
    std::string command;
    if (!(input >> command)) {
        return true;
    }
    if (command == "QUIT" || command == "CLEAR") {
        if (!endOfCommand(input)) {
            output << "ERROR\n";
            return true;
        }
        if (command == "QUIT") {
            return false;
        }
        dictionary = Dictionary{}; // Move in an empty owner;old children are destroyed.
        output << "CLEARED\n";
        return true;
    }
    if (command != "ADD" && command != "DELETE" && command != "FIND" && command != "COUNT"
        && command != "PREFIX") {
        output << "ERROR\n";
        return true;
    }
    std::string word;
    if (!(input >> std::quoted(word)) || word.size() > 30 || !lowercase(word)) {
        output << "ERROR\n";
        return true;
    }
    int limit = 0;
    if (command == "PREFIX" && (!(input >> limit) || limit < 0 || limit > 100)) {
        output << "ERROR\n";
        return true;
    }
    if (!endOfCommand(input)) {
        output << "ERROR\n";
        return true;
    }
    // All parsing is complete before any state can change.
    if (command == "ADD") {
        if (contains(dictionary.root, word)) {
            output << "EXISTS\n";
        } else if (dictionary.words == 1000) {
            output << "FULL\n";
        } else {
            insert(dictionary.root, word);
            ++dictionary.words;
            output << "ADDED\n";
        }
    } else if (command == "DELETE") {
        if (erase(dictionary.root, word)) {
            --dictionary.words;
            output << "REMOVED\n";
        } else {
            output << "NOT FOUND\n";
        }
    } else if (command == "FIND") {
        output << (contains(dictionary.root, word) ? "FOUND\n" : "NOT FOUND\n");
    } else if (command == "COUNT") {
        output << "COUNT " << terminals(locate(dictionary.root, word)) << '\n';
    } else {
        auto words = suggest(dictionary.root, word, static_cast<std::size_t>(limit));
        output << "SUGGEST " << words.size() << '\n';
        for (const auto& suggestion : words) {
            output << std::quoted(suggestion) << '\n';
        }
    }
    return true;
}

int main() {
    Dictionary dictionary;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (!execute(dictionary, line, std::cout)) {
            break;
        }
    }
    return 0;
}
