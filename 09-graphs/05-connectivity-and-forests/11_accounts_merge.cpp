/*
 At most 30 accounts, at most 10 emails each; shared-email components have consistent
names; empty-email accounts are retained.

Map each email to its first account; shared email unions account indices;
collect sorted distinct emails by final root.

Accounts(a, b) and(b, c) merge transitively into(a, b, c); unrelated x stays
separate.

Shared-key edges define equivalence closure, which DSU computes exactly.

O(total email comparisons*log(total emails)+DSU work), O(total emails+accounts) storage.

Assume names are consistent within each shared-email component; equal names alone do
not imply identity.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <set>
#include <cstddef>
#include <numeric>

class DSU {
    std::vector<int> parent;
    std::vector<int> size;

public:
    explicit DSU(int n)
        : parent(static_cast<std::size_t>(n)),
          size(static_cast<std::size_t>(n), 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (size[a] < size[b]) {
            std::swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    int count(int u) {
        return size[find(u)];
    }
};

struct Account {
    std::string name;
    std::vector<std::string> emails;
};

std::vector<Account> mergeAccounts(const std::vector<Account>& accounts) {
    DSU dsu(static_cast<int>(accounts.size()));
    std::map<std::string, int> owner;
    for (int i = 0; i < static_cast<int>(accounts.size()); ++i) {
        for (const auto& email : accounts[i].emails) {
            auto found = owner.find(email);
            if (found == owner.end()) {
                owner[email] = i;
            } else {
                dsu.unite(i, found->second);
            }
        }
    }
    std::map<int, std::set<std::string>> groups;
    for (int i = 0; i < static_cast<int>(accounts.size()); ++i) {
        auto& emails = groups[dsu.find(i)];
        emails.insert(accounts[i].emails.begin(), accounts[i].emails.end());
    }
    std::vector<Account> out;
    for (const auto& group : groups) {
        out.push_back({accounts[group.first].name, {group.second.begin(), group.second.end()}});
    }
    return out;
}

int main() {
    auto out = mergeAccounts({{"Ada", {"a", "b"}}, {"Ada", {"b", "c"}}, {"Bob", {"x"}}});
    assert(out.size() == 2);
    std::size_t ada = out[0].name == "Ada" ? 0 : 1;
    assert((out[ada].emails == std::vector<std::string>{"a", "b", "c"}));
    Account empty;
    empty.name = "Empty";
    std::vector<Account> accounts;
    accounts.push_back(empty);
    auto single = mergeAccounts(accounts);
    assert(single.size() == 1);
    std::cout << "checks passed\n";
    return 0;
}
