# Phase 5 cumulative projects

Two independently buildable C++17 projects combine earlier input validation with new tree/trie algorithms. They are separate from the 130 worked programs. Sources include detailed design, grammar/contracts, hand traces, proofs, costs, error behavior and follow-ups.

## Expression evaluator

[Source](01_expression_evaluator.cpp). Complete owned-tree construction and postorder traversal first. One line is one expression, up to 200 bytes; decimal literals are 0..1000000. Supports parentheses, whitespace, unary signs and binary +,-,*,/. Multiplication/division bind before addition/subtraction; each binary level associates left-to-right. Division truncates toward zero. Every intermediate result must stay within +/-10^12.

The recursive-descent grammar appears in the source before parser code. Parsing creates unique-owned nodes; evaluation visits children before applying their operator. Complete consumption rejects trailing junk. A failed parse destroys partial trees. Each line prints its integer result or `error: invalid expression`, `error: division by zero`, or `error: result out of range`. Later lines continue. An empty line is invalid; end-of-file simply ends the program.

Milestones: tokenize through a position cursor; parse literals/parentheses/unary factors; add multiplicative terms; add additive expressions; construct owned nodes; evaluate safely; add malformed and boundary checks. Explain why `2+3*4` is14, `(2+3)*4` is20, `8/4/2` is1 and `-7/2` is-3.

Extension tasks: print a fully parenthesized tree, add modulus with a stated sign rule, or implement a separately specified floating-point language. Do not silently change the integer contract.

## Dictionary autocomplete

[Source](02_dictionary_autocomplete.cpp). Complete all trie lessons first. One command per line, up to 200 bytes. Lowercase words/prefixes have length 0..30. Fields may be quoted; empty values require `""`. No persistence is promised across processes. The dictionary holds at most 1000 distinct words.

|Command|Response|
|---|---|
|`ADD word`|`ADDED`, `EXISTS`, or `FULL`|
|`DELETE word`|`REMOVED` or `NOT FOUND`|
|`FIND word`|`FOUND` or `NOT FOUND`|
|`COUNT prefix`|`COUNT n`|
|`PREFIX prefix limit`|`SUGGEST n`, then n quoted words in lexical order|
|`CLEAR`|`CLEARED`|
|`QUIT`|Ends processing without output|

Limit is 0..100. Empty lines are ignored; malformed, unknown, extra-field or invalid-alphabet commands print `ERROR` and preserve dictionary state. Missing words/prefixes are normal query results. Empty word membership is independent of root existence. The parser fully validates a command before a mutation. Erasing `app` preserves `apple`; shared unused prefixes are pruned only when safe.

Milestones: exact insertion/search; prefix traversal; lexicographic suggestions; safe erasure/pruning; quoted command parsing; capacity and transactional validation; independent set-model comparisons. Extensions: transactional persistence, ranked suggestions with deterministic ties, or a different explicitly defined alphabet.

## Build and verify

From the repository root:

Use the compiler first-command examples from the entry guide if the build directory does not exist. Project checks cover valid operations, precedence, empty input, arithmetic bounds, missing values, quoted empty words, malformed commands and continuation after errors. Independent models compare generated arithmetic groupings and dictionary behavior/capacity with direct references.

