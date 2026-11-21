# How to learn programming and DSA

## Start without programming knowledge

A computer stores data and executes instructions. An **algorithm** is a finite,
unambiguous method for obtaining a result. A **program** expresses that method in
a language. To find a maximum: read a sequence, remember the largest value seen,
compare each new value, and output the result. Write this in words before coding.

A variable is named storage, a type constrains values and operations, an expression
produces a value, and a statement performs a step. A condition chooses a branch;
a loop repeats a block. A function names reusable behavior. A data structure
organizes values and an algorithm operates on them.

## Tools and debugging

You need an editor, a C++17 compiler and a terminal. On Windows, a GCC toolchain
such as MinGW-w64 provides `g++`; put its executable directory on PATH and restart
the terminal. `g++ --version` should print a version. The README commands assume
this toolchain. An editor's Run button may invoke a different compiler.

The preprocessor handles `#include`, compilation translates a source unit, linking
resolves definitions, and running executes the result. A missing semicolon is a
compile error; a missing function definition can cause a link error; invalid memory
access is a runtime defect; a wrong calculation is a logic defect. Start with the
first diagnostic. Recompile after changing source: an existing executable is stale.

A debugger pauses at breakpoints, steps through statements, inspects variables,
and shows the call stack. For small inputs, trace a table of variable values on
paper. Find the FIRST incorrect state, fix its cause, and repeat the original test.

## Study method

1. Read prerequisites and the opening comment.
2. Restate inputs, outputs and constraints.
3. Predict the smallest example by tracing each update.
4. Compile and run; reconcile any difference with your prediction.
5. Explain the invariant: what remains true before and after each step?
6. Close the source, implement independently, then complete the exercise.
7. Test boundaries and explain time and auxiliary space.

Proceed by mastery, not dates. Revisit problems a day later and a week later.
Keep notes of misconceptions, counterexamples and corrected reasoning.

## Complexity from first principles

Let n be input size. One pass is O(n); two independent passes are still O(n).
Comparing all pairs is O(n²); halving a search interval is O(log n). Subsets number
2^n; permutations number n!. Big O is an upper bound; Theta is a tight bound.

Nested syntax alone does not establish quadratic cost. A monotonic stack pops each
item at most once: total O(n). Count recursion stack space. Separate auxiliary
storage from returned output. Hash-table operations have expected fast lookup,
not guaranteed constant worst-case lookup. A short program can still allocate an
impossibly large DP table. Estimate both time and memory from constraints.

## Prove and test

For loops: establish an invariant, preserve it, and show termination gives the
answer. For recursion: prove the base case and progress toward smaller problems.
For greedy: give an exchange or stays-ahead proof. For DP: define exactly what a
state means and show its recurrence considers every legal choice.

Test empty input if allowed, one element, equal values, sorted/reversed order,
duplicates, negatives if allowed, absent targets, extreme parameters, disconnected
graphs, cycles and repeated edges. Compare optimized code with a simple brute-force
oracle on small generated inputs. Assertions check programmer assumptions; they
can be disabled, so external input validation needs ordinary conditions.

## C++ mistakes to recognize

- `=` assigns; `==` compares. `&&`/`||` short circuit; `&`/`|` operate on bits.
- Integer division truncates toward zero; convert before dividing for fractions.
- Signed overflow and out-of-bounds accesses are undefined behavior.
- `size()` is unsigned: subtracting one from an empty size is dangerous.
- References to locals dangle after scope exit.
- Vector growth can invalidate element pointers and iterators.
- Sorting comparators must return false on equal arguments; do not use `<=`.
- Recursion needs a base case; excessive depth can exhaust the stack.
- `getline` after `>>` may consume the leftover newline.
- Floating point is approximate; exact money calculations usually use integer units.

## Milestones

- Write and debug a small input-driven program independently.
- Derive binary search, two pointers and windows with invariants.
- Implement a list, stack, queue, BST and heap; explain their tradeoffs.
- Choose BFS, Dijkstra, Bellman-Ford, topological ordering or MST from the goal.
- Derive DP states before coding and reconstruct a solution.
- Explain lazy tags, SCCs and residual edges; test failure cases.
- Solve an unfamiliar mixed problem and justify the chosen method.

