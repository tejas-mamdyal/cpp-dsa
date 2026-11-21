# Stack mechanisms minima and expression handling: notes

A stack serves the most recent live arrival. Vector back and linked head implement top;fixed arrays add full-state checks. Specify exceptions,optional absence or boolean status consistently. Linked owners disable shallow copies and delete iteratively. Minimum stacks save prefix minima so popping one equal minimum retains the preceding one.

Manual bracket checking stores unmatched openers in nesting order. Postfix pops right before left and validates syntax,arity,division and intermediate bounds. Infix conversion tracks precedence,left associativity,parentheses and whether the next token must be an operand;its contract allows only single-character operands and binary operators. Two queues trade linear push for constant pop. Recursive bottom insertion makes stack reversal quadratic despite linear live depth. Monotonic patterns follow in Phase4.

## Worked reasoning

### Array and uniquely owned linked stacks

CONTRACT: push/pop/top use a consistent underflow exception policy.

IDEA AND STATE: The vector back and linked head both represent the top.

TRACE: push1,push2,pop ->top1.

CORRECTNESS: Both representations add and remove the most recently pushed live value.

COST: Vector push amortized O(1),linked push/pop O(1); O(n) owned storage.

PITFALL: Linked owners forbid copying and clean every node; vector growth can invalidate observers.

### Bracket checking with a manually indexed stack

CONTRACT: All three bracket types; other characters ignored.

IDEA AND STATE: A pre-sized char buffer plus used count implements push/top/pop.

TRACE: ([x]) is valid;([)] fails.

CORRECTNESS: The stack is exactly the unmatched openers in their nesting order.

COST: O(n) time,O(n) stack storage.

PITFALL: Counts alone do not check nesting and a closing bracket cannot pop an empty stack.

### Full and empty are separate states

CONTRACT: Capacity3; push false on full, pop/peek optional on empty.

IDEA AND STATE: A count identifies the first unused array slot.

TRACE: push1,2,3 fills;push4 fails;pop yields3.

CORRECTNESS: Indices[0,count) are live values and count stays within0..capacity.

COST: O(1) operations,O(capacity) storage.

PITFALL: A failed push must leave the old top unchanged.

### Store the minimum of every live prefix

CONTRACT: An unbounded value stack; return absence when empty.

IDEA AND STATE: Each entry stores value and minimum up to that entry.

TRACE: push3,1,1,pop still has minimum1.

CORRECTNESS: The previous entry already contains the correct minimum when the top is removed.

COST: Amortized O(1) push,O(1) pop/min,O(n) storage.

PITFALL: Equal minima need independent entries so one pop does not discard both.

### Evaluate a validated postfix token stream

CONTRACT: Space-separated signed ints[-1000,1000] and +,-,*,/;intermediate values must stay[-1000000,1000000]. Return absence on malformed input.

IDEA AND STATE: Pop right operand then left, compute safely in long long, and push the bounded result.

TRACE: 3 4 + 2 * ->14;10 3 - ->7.

CORRECTNESS: The stack stores results of complete preceding subexpressions; an operator combines the latest two.

COST: O(tokens+characters) time,O(tokens) space.

PITFALL: Division by0,missing operands,extra results and overflow of the stated bound are errors.

### Operator stack handles precedence and parentheses

CONTRACT: Single ASCII letter/digit operands,binary +,-,*,/,parentheses/spaces. No unary operators or multi-character operands;invalid syntax returns absence.

IDEA AND STATE: Emit operands immediately, delay operators until higher/equal precedence or closing parentheses.

TRACE: a+b*c ->abc*+;(a+b)*c ->ab+c*.

CORRECTNESS: Operators leave the stack only after their required operands have been emitted; left associativity pops equal precedence.

COST: O(n) time and space; each operator pushes/pops once.

PITFALL: Operand order and unmatched parentheses need validation, not merely precedence handling.

### Build LIFO behavior from FIFO operations

CONTRACT: Two queues;push rearranges so the newest value becomes front.

IDEA AND STATE: Enqueue new value into a spare queue, move old values behind it, then swap queues.

TRACE: push1,push2 ->front2,pop ->front1.

CORRECTNESS: Every push establishes newest-first queue order; pop removes its first element.

COST: Push O(n),pop/peek O(1),O(n) total storage.

PITFALL: A different tradeoff is possible; do not claim all operations are constant-time.

### Reverse a stack using recursive bottom insertion

CONTRACT: Vector back represents top; at most20 elements.

IDEA AND STATE: Pop top, reverse the smaller stack, then insert the old top at its bottom.

TRACE: bottom-to-top1,2,3 becomes3,2,1.

CORRECTNESS: The recursive reverse orders the smaller stack and bottom insertion places the removed top in its final position.

COST: O(n^2) time,O(n) call stack.

PITFALL: It is not linear: each bottom insertion traverses the current stack.


