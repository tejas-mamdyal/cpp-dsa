/*
A structured binding decomposes a pair, tuple or supported aggregate. auto [x,y] owns a decomposition of a copied value; auto& [x,y] aliases the original fields. const auto& reads fields without copying their object.
*/
#include <iostream>
#include <utility>
#include <tuple>
#include <string>

using namespace std;

/*
* std::pair & std::tuple
 * 
 * Why use them?
 * To group 2 (pair) or more (tuple) heterogeneous items together without 
 * having to write a custom struct every time. 
 * Heavy usage in Graphs (Edges = pair<weight, node>).
*/

int main() {
    // 1. PAIR
    pair<int, string> p1 = {1, "Alice"}; // C++11 init
    pair<int, string> p2 = make_pair(2, "Bob");

    cout << "Pair 1: ID=" << p1.first << ", Name=" << p1.second << endl;

    // 2. TUPLE (For 3 or more items)
    tuple<int, string, double> t1 = {1, "Charlie", 99.5};

    // Accessing a tuple is ugly: get<index>(tuple)
    cout << "Tuple: ID=" << get<0>(t1) << ", Name=" << get<1>(t1) << endl;

    // 3. STRUCTURED BINDINGS (C++17) - The modern way!
    auto [id, name, score] = t1;
    cout << "Structured binding: " << name << " got " << score << endl;

    return 0;
}
