# Independent practice

Use the corresponding lesson bounds. For each task provide the full input/output contract,a simple baseline,state definition,trace,proof,costs and normal/boundary/counterexample checks. Attempt without copying worked source.

## 1. Exercise 1

Represent expected parse failure without a sentinel value. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Reject a valid numeric prefix followed by junk.

## 2. Exercise 2

Carry a typed error alongside successful data. Domain:Operands magnitude<=1000000; integer division truncates toward zero. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Return different typed errors for zero divisor and invalid domain.

## 3. Exercise 3

Add context at an abstraction boundary. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Preserve context while translating an implementation exception.

## 4. Exercise 4

Borrow a substring while its owner stays alive. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Change a character without reallocating the string and observe the view.

## 5. Exercise 5

Distinguish unpacked values from unpacked references. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Contrast a value decomposition with a reference decomposition.

## 6. Exercise 6

Dispatch behavior through a generic visitor. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Add one variant alternative and handle every active type.

## 7. Exercise 7

Check a metamorphic sorting property across a finite domain. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Construct an output that passes sortedness but violates multiplicity.

## 8. Exercise 8

Compare a fast implementation with a different exhaustive model. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare an optimized pair count with enumeration across all small arrays.

## 9. Exercise 9

Count work separately from machine-dependent timing. Domain:Benchmark workload 1000 elements; no timing threshold used as a correctness assertion. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare first,last and absent searches using operation counts.

## 10. Exercise 10

Reserve capacity before keeping element references. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Explain capacity versus size without indexing unconstructed storage.

## 11. Exercise 11

Measure a workload only after checking its answer. Domain:10000-element input and 100 repetitions; no performance pass/fail threshold. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Report construction and query timings separately with output verification.

## 12. Exercise 12

Reduce a boundary bug to its smallest failing example. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Reduce a boundary bug and add a neighboring regression.

