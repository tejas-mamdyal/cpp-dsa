
#include <map>
#include <set>
#include <string>
#include <vector>


// A guard prevents repeated inclusion within one translation unit.
namespace search {
std::set<std::string> tokenize(const std::string& text);

class Index {
    // A posting list contains each document ID once, in ascending order.
    std::map<std::string, std::set<int>> postings;
    int nextId = 0;

public:
    void add(const std::string& document);
    std::vector<int> allTerms(const std::string& query) const;
};
} // namespace search

#include <algorithm>
#include <iterator>
#include <utility>

namespace search {
std::set<std::string> tokenize(const std::string& text) {
    std::set<std::string> words;
    std::string word;
    for (unsigned char c : text) {
        if (c >= 'A' && c <= 'Z') {
            c = static_cast<unsigned char>(c - 'A' + 'a');
        }
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            word += static_cast<char>(c);
        } else if (!word.empty()) {
            words.insert(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        words.insert(word);
    }
    return words;
}

void Index::add(const std::string& document) {
    for (const auto& word : tokenize(document)) {
        postings[word].insert(nextId);
    }
    ++nextId;
}

std::vector<int> Index::allTerms(const std::string& query) const {
    auto words = tokenize(query);
    std::vector<int> result;
    bool first = true;
    for (const auto& word : words) {
        auto found = postings.find(word);
        if (found == postings.end()) {
            return {};
        }
        if (first) {
            result.assign(found->second.begin(), found->second.end());
            first = false;
        } else {
            std::vector<int> common;
            std::set_intersection(result.begin(),
                                  result.end(),
                                  found->second.begin(),
                                  found->second.end(),
                                  std::back_inserter(common));
            result = std::move(common);
        }
    }
    return result;
}
} // namespace search

#include <iostream>
#include <sstream>

namespace {
bool countLine(int& count) {
    std::string line;
    if (!std::getline(std::cin, line)) {
        return false;
    }
    std::istringstream input(line);
    char extra;
    return (input >> count) && !(input >> extra) && count >= 0 && count <= 100;
}

bool lines(int count, std::vector<std::string>& output) {
    for (int i = 0; i < count; ++i) {
        std::string line;
        if (!std::getline(std::cin, line) || line.size() > 10000) {
            return false;
        }
        output.push_back(line);
    }
    return true;
}

int invalid() {
    std::cerr << "invalid input\n";
    return 1;
}
} // namespace

int main() {
    int n;
    int q;
    std::vector<std::string> documents;
    std::vector<std::string> queries;
    if (!countLine(n) || !lines(n, documents) || !countLine(q) || !lines(q, queries)) {
        return invalid();
    }
    char extra;
    if (std::cin >> extra) {
        return invalid();
    }
    search::Index index;
    for (const auto& document : documents) {
        index.add(document);
    }
    for (const auto& query : queries) {
        auto matches = index.allTerms(query);
        if (matches.empty()) {
            std::cout << "NONE";
        } else {
            for (std::size_t i = 0; i < matches.size(); ++i) {
                if (i > 0) {
                    std::cout << ' ';
                }
                std::cout << matches[i];
            }
        }
        std::cout << '\n';
    }
    return 0;
}
