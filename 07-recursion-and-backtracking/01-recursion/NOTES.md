# From recursive calls to decision trees

Prerequisites: functions, values versus references, vector/string copying, optional results, assertions and bit masks from Phases 1-3; complete Phase 4 before entering this phase. Existing recursion lessons introduced shrinking arguments and call stacks. Here, each level decides part of an answer and branches over alternatives.

## 1. Draw the decisions first

For length-two binary strings, draw root "", children 0 and 1, then leaves 00, 01, 10 and 11. A node is a partial assignment, an edge is one choice, and a leaf is a complete assignment. Depth describes simultaneous unfinished calls; total nodes describe work across the whole run. Seven calls can have only three frames active at once.

The baseline uses one loop per position. Recursion lets the number of loop levels follow the input rather than requiring new source code. Every recursive branch must make progress toward a finite base case. Do not save incomplete states unless the specification asks for them.

## 2. Copy first, then share carefully

Lesson 01 passes path by value: each child owns a copy, so siblings cannot contaminate each other. The simplicity has a cost: active frames may hold prefixes of lengths 0 through n, totaling O(n^2) character storage, apart from saved output. Lesson 02 shares one path by reference and restores it, reducing active path storage to O(n).

The contract for a shared-path helper is: on return, path has exactly the value it had on entry. Choose appends a decision; explore visits all its completions; undo removes that same decision. Restore route-specific work, not every mutable variable: saved output and measurement counters intentionally accumulate across branches. Saving with out.push_back(path) copies the current vector or string. A later pop changes the work buffer, not the saved result.

## 3. Subsets, subsequences, combinations and permutations

Subsets decide exclude/include for each position. Subsequences use the same decisions but preserve text order; they need not be contiguous. Equal input values at different positions are different positional choices: aa has four positional subsequences but only three distinct resulting strings. Duplicate-value suppression is a later unit, not an implicit part of the first subset helper.

A size-k combination chooses strictly increasing indices or values;start says where the next choice may begin. A permutation instead chooses any unused position at each level;used flags describe availability. Undo every changed component: both path and the used flag. These patterns cannot be exchanged without changing the meaning or duplicating results.

## 4. A pruning rule must exclude only impossible completions

If need values remain to be chosen but fewer eligible values exist, no completion is possible. That is a safe cutoff. By contrast, sum>target is not safe for signed subset sums: choosing5 may later be corrected by -4 to reach1. Signed counting therefore checks equality at complete leaves.

Balanced parentheses prune a prefix when closing would exceed opening,or opening would exceed n. At a complete leaf those prefix rules guarantee a valid string. Keypad products demonstrate that a level can have three or four legal choices rather than two. Validate mapping indices before use. The empty Cartesian product has one empty string in these lessons.

## 5. Early returns still restore state

An enumeration explores every sibling. A search may stop after its first witness, but it still owes the caller its original state. Store bool found, undo your push, then return found. Copy the witness before undoing it. optional<vector<int>> distinguishes no witness from a valid empty witness for target zero.

## 6. Explain costs honestly

Generating 2^n subsets cannot generally take polynomial time because the output itself may be exponential. Copying a length-n result costs O(n);include those copies rather than counting leaves alone. Enumerating permutations has n! leaves. Recursion stack, work buffer, and saved output are separate storage categories. Small input limits prevent demonstrations from consuming unreasonable time or memory.

An oracle should follow a different control structure. Lesson 12 enumerates bit masks and compares sorted multisets to recursion,including repeated values. Sorting vectors of vectors uses lexicographic order:compare the first differing element,or put a proper prefix first. Sorting is only for comparison;the lesson03 contract still preserves exclude-first traversal order. Comparing only the number of outputs can miss repeated wrong answers. Finite checks complement the exhaustive-choice correctness argument;they do not prove every possible input.

For each lesson, reproduce its hand trace, explain why sibling states are independent,and modify one constraint before proceeding. A template memorized without a restoration invariant is not yet mastery.

