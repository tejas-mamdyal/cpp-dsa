/*
 Vertices 0..n-1; at most 30 vertices; state whether graph is directed or undirected;
empty graphs are permitted.

Sort and deduplicate names, then assign deterministic indices; keep
external labels separate from storage indices.

Agra, Delhi, Pune map to 0,1,2 regardless of original name order.

Each distinct name receives exactly one dense unique index.

O(L*n log(n+1)) upper-bound time with label length L, O(total labels) storage.

Map operator[] on an unknown queried label would create a false index; use find or
at.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstddef>

std::map<std::string, int> labels(std::vector<std::string> names) {
    std::sort(names.begin(), names.end());
    names.erase(std::unique(names.begin(), names.end()), names.end());
    std::map<std::string, int> index;
    for (std::size_t i = 0; i < names.size(); ++i) {
        index[names[i]] = static_cast<int>(i);
    }
    return index;
}

int main() {
    auto index = labels({"Pune", "Delhi", "Pune", "Agra"});
    assert(index.size() == 3 && index.at("Agra") == 0 && index.at("Pune") == 2);
    assert(labels({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
