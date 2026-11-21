# Recursion: smaller problems and returning results

**Phase3 unit2: delivered.**13 standalone programs,14 independent exercises,
separate hints, a debugging lab and a20-point checkpoint. Complete the
[complexity unit](../01-complexity-analysis/README.md) first. Functions, references,
strings, vectors and library interfaces were taught in Phases1/2.

Start with [NOTES.md](NOTES.md). Draw the active frames and pending work before
running a program. Follow the order below: the retained string-reversal filename
is historical and is intentionally read after the half-open palindrome example.

1. [First recursive function: factorial](01_factorial.cpp)
2. [Watch descending calls and returning frames](03_call_and_return_trace.cpp)
3. [Define a smaller answer before combining it](04_sum_of_naturals.cpp)
4. [Reduce a number by removing its last digit](05_recursive_digit_sum.cpp)
5. [Recursive power by removing one factor](06_linear_power.cpp)
6. [Halve the exponent and reuse the returned answer](07_power_by_squaring.cpp)
7. [Euclidean recursion changes two arguments](08_recursive_gcd.cpp)
8. [Borrow text and shrink a half-open range](09_recursive_palindrome.cpp)
9. [Reverse text by shrinking its unsolved interval](02_reverse_string.cpp)
10. [Many calls are not the same as deep calls](10_fibonacci_call_tree.cpp)
11. [An accumulator can turn pending work into state](11_tail_recursion_and_iteration.cpp)
12. [Split a range into two disjoint smaller problems](12_divide_and_conquer_range_sum.cpp)
13. [Tower of Hanoi: ordered branching with a legality oracle](13_tower_of_hanoi.cpp)

The original budget was12 programs; Hanoi is an additional standard worked
question. The first two old filenames remain in place so migration links continue
to work, but they now have explicit domains, boundary handling and wider checks.

Read comments, predict a trace, compile one source, then implement a variation
without looking. Attempt [practice](PRACTICE.md) before [hints](HINTS.md), complete
the debugging lab, then take [the checkpoint](CHECKPOINT.md).
Assertions in the bounded oracle examples must stay enabled.

## Focused compilation and checks

From the repository root:

```powershell
New-Item -ItemType Directory -Force build
g++ -std=c++17 -Wall -Wextra -pedantic 04-problem-solving-foundations/02-recursion-basics/01_factorial.cpp -o build/factorial.exe
```

Run the generated executable and enter5 to get120. Input bounds are part of each
source's contract, not arbitrary restrictions on the mathematical definition.

programs. Next is [the delivered searching unit](../03-searching/README.md).
Follow [the completed Phase3 sequence](../PHASE3_PLAN.md) through the toolkit.

