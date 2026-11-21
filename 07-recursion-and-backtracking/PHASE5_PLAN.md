# Phase 5 delivery plan

Status: complete for the defined scope. All nine units and both projects are released. Prerequisite: completed Phase4. Target:130 distinct worked programs,50 backtracking plus80 trees/heaps,excluding two projects. Existing programs count only after review and integration. Do not treat planned counts as delivered content.

|Order|Unit|Worked target|Status|
|---|---|---:|---|
|1|Decision trees and restored state|12|released|
|2|Subsets, permutations, combinations and duplicate handling|14|released|
|3|Partitioning, grid/word search and meet in the middle|12|released|
|4|N queens, Sudoku, graph coloring and pruning|12|released|
|5|Tree ownership, construction, serialization and traversals|20|released|
|6|Views, paths, balance, diameter and general-tree LCA|20|released|
|7|BST search, insert, delete, validation and queries|16|released|
|8|Heap implementation, building, sorting, top-k and merging|16|released|
|9|Trie ownership, prefix queries and dictionary operations|8|released|

## Dependencies and migration

Decision trees follow Phase3 recursive calls and Phase4 invariants. Copied paths precede shared mutable paths;full enumeration precedes early success;positional subsets precede duplicate-value suppression. The inherited subset program is incorporated into unit1 with a descriptive filename. N queens and unique permutations are integrated into the released constraint and enumeration units. The older tree/heap examples are integrated into the five sequential tree/heap units.

Grid and word search will introduce their movement and visited-state representation before using it. Graph coloring will explain vertices,edges and its small adjacency matrix locally before constraints;it does not require the later graph-algorithm course. Meet in the middle follows subset enumeration,sorting and binary search. Tree lessons introduce ownership and the tree model before traversals;postorder child summaries precede balance,diameter and LCA. General-tree LCA precedes its BST specialization. Heap array mappings and invariants precede operations,building,sorting and top-k applications. Trie nodes and ownership precede prefix queries and autocomplete.

## Projects and completion gates

The expression evaluator follows parsing fundamentals and tree traversal:tokenization,precedence,expression-tree construction,evaluation and malformed-input tests. Dictionary autocomplete follows tries:insert/delete/search,prefix suggestions,ordering and empty/missing-prefix handling. Projects are counted separately from the130 worked lessons.
