# Independent practice

Use the corresponding lesson bounds. For each task provide the full input/output contract,a simple baseline,state definition,trace,proof,costs and normal/boundary/counterexample checks. Attempt without copying worked source.

## 1. Exercise 1

Let containers supply independent copy ownership. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Copy then mutate nested values to demonstrate independence.

## 2. Exercise 2

Allocate a separate resource when copying an owner. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Copy an empty moved-from owner and define its result.

## 3. Exercise 3

Prepare then swap to preserve the old value on allocation failure. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Test self-copy and assignment from an independent owner.

## 4. Exercise 4

Transfer ownership and inspect only a promised moved-from state. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Move then safely reuse the source under its documented contract.

## 5. Exercise 5

Release the previous resource before accepting a transferred owner. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Test self-move through an alias and move into a nonempty destination.

## 6. Exercise 6

Make relocation guarantees visible to generic containers. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Verify noexcept traits and explain vector relocation choices.

## 7. Exercise 7

Tie a non-memory resource obligation to scope lifetime. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Throw after guard construction and verify cleanup.

## 8. Exercise 8

Return a unique owner without manual cleanup branches. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Transfer ownership through two function calls without raw delete.

## 9. Exercise 9

Observe shared lifetime without extending it accidentally. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Expire all strong owners and verify observer lock fails.

## 10. Exercise 10

Store explicit nonowning references to existing objects. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Show why a reference wrapper must not outlive its target.

## 11. Exercise 11

Give value comparison a coherent meaning. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Check reflexivity,symmetry and transitivity of equality.

## 12. Exercise 12

Build nonmutating arithmetic from a mutating primitive. Domain:Small deterministic in-memory examples; keep assertions enabled. No input or external services. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Verify chained compound assignment returns the original lvalue.

