# Reasoning before code

A trie stores prefixes rather than BST value partitions. Each node owns 26 lowercase-letter children; the root is empty prefix. terminal distinguishes a complete word from a prefix of a longer word. Validate all characters before indexing or mutation. The empty word marks root terminal and differs from an empty dictionary.

Exact search requires terminal. Prefix counts count word terminals, not character nodes or duplicate insertions. Erase unmarks the endpoint and prunes only child subtrees containing no words. A shorter word may disappear while its path remains needed by a longer word.

Autocomplete visits terminal before extensions and children a..z, then stops at its answer limit. Include visited nodes and output characters in cost claims. Longest stored prefix follows a query and remembers its last terminal; it is not longest common prefix of all words. Distinct-substring counting inserts suffix routes and counts new nodes, a small-input quadratic baseline rather than a suffix automaton.

Core:01-05. Reinforcement:06-07. Challenge:08. Read owned nodes before 01, exact terminals before counts, shared prefixes before erasure, and lexicographic traversal before the project. Unicode or arbitrary bytes need a different edge representation.

Every source supplies a contract, state, hand trace, correctness, cost and pitfall. Trace a normal and boundary case before compiling. Explain returned summaries and ownership transfers. Count work buffers, call stack and output separately. Finite comparisons support proofs; they do not replace them.

