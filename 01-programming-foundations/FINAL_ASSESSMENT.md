# Phase 1 final assessment

Attempt in two sessions of60–90 minutes, adjusting for your pace. No worked source
or hints during the attempt. Compiler diagnostics and a debugger are allowed.
Use only Phase1 concepts; collections and recursion are unnecessary.

## Session A: explain and construct (50 points)

1. **Trace (10):** for input407, trace every state of a digit-sum loop. Explain
   why zero still needs explicit handling in a digit-count task. Then explain the
   difference between7/2 and static_cast<double>(7)/2.
2. **Validated statistics (20):** read n1..100, then n integers in[-1000,1000].
   Print min,max,sum and mean to two decimals. Reject failed/missing/out-of-range
   input with an error and nonzero exit. No arrays. Example:3 -5 -2 -8 produces
   `-8 -2 -15 -5.00`. Include a one-value test.
3. **Function composition (20):** write digitSum and isPrime, then read n0..1000000
   and print prime sum or nonprime sum. Example29 ->prime sum;10 ->nonprime sum.
   Explain helper preconditions, returned values, loop termination and cost.

## Session B: diagnose and transfer (50 points)

4. **Debug (15):** repair a maximum initialized to0, an integer average stored
   into double, and a loop with no progress update. For each, provide a failing
   input, the first wrong state and a regression test. Do not merely paste a fix.
5. **New pattern (15):** read n1..9. Print a centered pyramid whose row r has
   n-r leading spaces and the digit r repeated2*r-1 times. Example n2 produces
   ` 1` then `222`. Explain the two inner-loop bounds and O(n^2) output cost.
6. **Mini application (20):** make a repeated menu:1 n prints digit count;
   2 a b prints gcd;0 quits. Values0..1000000, at most100 operations. Reject
   unknown commands, invalid operands and EOF before quit. Helpers perform
   calculations; main coordinates the interaction. Example1 0 2 48 18 0
   produces1 and6 on separate lines.

## Self-review rubric

For each construction task: correct normal results40%; boundaries/error handling25%;
decomposition/readability15%; explanation/complexity10%; independent tests10%.
For explanation tasks: specific state-based reasoning matters more than terminology.

Target80/100, with both input-driven tasks working independently and no unresolved
division-by-zero, overflow within contract, invalid-input processing or nontermination.
Revisit weak units and retry with changed inputs later; a score is a learning tool.

## Review checklist after the attempt

- Statistics: initialize both extremes from actual input; widen/convert before needed.
- Composition: zero and1 are not prime; input29 has digit sum11.
- Debugging: a test must demonstrate why the original was wrong.
- Pyramid: spaces and symbols are separate runs; preserve leading spaces.
- Menu: quit has no operands; sentinel/control commands are not data.

Discuss your projects aloud: what problem they solve, how input is validated,
what each helper does, why loops terminate, which tests distinguish wrong solutions,
and what would change if you needed to store all individual records in Phase2.

