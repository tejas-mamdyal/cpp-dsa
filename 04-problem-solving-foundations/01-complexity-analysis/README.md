# Algorithmic thinking and complexity

**Phase3 unit1: delivered.**14 standalone worked programs,12 independent problems,
separate hints, a debugging lab and a20-point checkpoint. Prerequisites: completed
Phases1/2—loops, functions, vectors, references and the basic STL interfaces.
No recursion or new manual-memory machinery appears in this unit.

Read [NOTES.md](NOTES.md), predict each program's trace, then compile/run it.
The first two filenames preserve the earlier time/space demonstrations while
expanding their explanations and checking their behavior.

1. [Count work instead of guessing elapsed time](01_time_complexity.cpp)
2. [Separate input output and working storage](02_space_complexity.cpp)
3. [Use constraints to reject an unsuitable approach](03_constraints_and_budget.cpp)
4. [Count one full scan](04_linear_scan_count.cpp)
5. [Sequential loops add their work](05_independent_loops.cpp)
6. [Independent nested loops multiply their work](06_rectangular_nested_loops.cpp)
7. [Dependent nested bounds form a sum](07_triangular_pairs.cpp)
8. [Repeated halving creates logarithmic work](08_repeated_halving.cpp)
9. [Repeated doubling also creates logarithmic work](09_repeated_doubling.cpp)
10. [One logarithmic process for every element](10_linear_times_logarithmic.cpp)
11. [The same size can require different work](11_best_and_worst_cases.cpp)
12. [Explain a loop using initialization maintenance termination](12_running_maximum_invariant.cpp)
13. [Amortized cost is a sequence guarantee](13_amortized_growth_model.cpp)
14. [Validate an optimized method against a simple oracle](14_bruteforce_oracle.cpp)

Attempt [practice](PRACTICE.md) before [hints](HINTS.md), fix the examples in the
debugging lab, then take the [checkpoint](CHECKPOINT.md).
The notes explain how to derive a cost, not merely attach a Big-O label.

## Run one lesson or unit

From the repository root:

The budget program accepts a size and an abstract operation allowance, for example
`100000 10000000`. Its output is a model comparison, not a runtime prediction.
Add `--changed` to skip already checked, unchanged code. Assertions in teaching
harnesses must remain enabled. Each example documents its exact input and errors.

Next:[the delivered recursion unit](../02-recursion-basics/README.md). Then follow
[the completed Phase3 sequence](../PHASE3_PLAN.md) through the toolkit and assessment.

