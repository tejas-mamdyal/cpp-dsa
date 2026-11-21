# Phase 1 projects

Attempt these after unit 08. Each source opens with a complete command/input
contract. The programs print results without menus or prompts so checks can compare
exact output. Read this guide to supply commands; later you can add a friendly menu.

1. **Calculator:** implement input validation and four operations as separate steps.
   Run `1 2 3 4 8 0 0`: add 2+3, attempt 8/0, then quit. Expect `5.00` and
   `undefined` on separate lines. Keep computation separate from menu handling.
2. **Number toolkit:** implement and test digit count, digit sum, prime and gcd
   helpers first; then connect command dispatch. Try `1 407 2 9 3 48 18 0`.
3. **Grade analyzer:** begin with one mark, then loop over a declared count. Try
   `4 30 40 80 100`; expect `30 100 62.50 3`. Do not introduce arrays yet.

For each project, first write pseudocode, predict the result for three inputs,
implement your own version, then compare with the worked source. Milestones:
valid case → boundary case → input failure → refactoring into functions → follow-up.

Review rubric (20 points): correct results 6; boundary/error handling 4; meaningful
decomposition 4; explanation and trace 3; independent tests 3. Target at least 16,
with no remaining division-by-zero, nontermination or invalid-input processing.

These three projects are additional to the 100 worked lessons. Use only syntax
already taught in Phase 1; the calculator introduces `std::isfinite` explicitly.

Before the number toolkit, read [the gcd helper](../07-functions-and-decomposition/11_gcd.cpp),
even if you followed only the first eight examples per unit. A reinforcement label
does not waive a named prerequisite. Before the calculator, review fixed precision
and the finite-value check explained in its opening comment.

