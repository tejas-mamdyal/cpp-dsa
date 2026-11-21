# FIFO rings deques and amortized queues: notes

A queue preserves arrival order. A ring maps logical front/count into physical indices modulo positive capacity. Full and empty may share physical endpoint positions,so count is explicit. A deque applies this representation at both ends. Linked queue deletion must reset tail when the final node disappears.

A deque reference checks repeated full/empty/wrap transitions after every operation. A two-stack queue transfers only when outgoing is empty;each item crosses stacks at most once,so the sequence has amortized constant work despite a linear individual transfer. First-unique candidates enter/leave at most once. Half interleaving and first-k reversal compose FIFO/LIFO operations under stated size policies. Monotonic/window patterns are Phase4 work.

## Worked reasoning

### Ring-buffer and linked FIFO implementations

CONTRACT: Ring capacity1..1000; full/empty operations throw documented exceptions. Linked owner is noncopyable.

IDEA AND STATE: Ring count separates full from empty; linked enqueue uses tail and dequeue uses head.

TRACE: Capacity3:enqueue1,2,3,dequeue1,enqueue4 ->front2 after wraparound.

CORRECTNESS: Both representations preserve arrival order; deleting the last linked node clears both endpoints.

COST: O(1) enqueue/dequeue/front,O(capacity) ring storage or O(n) nodes.

PITFALL: Modulo requires positive capacity, and copying a raw owning queue would double-delete.

### A ring deque implements both endpoints

CONTRACT: Positive fixed capacity; failed pushes and empty pops leave state unchanged.

IDEA AND STATE: Logical front/count map both endpoints into circular indices.

TRACE: pushBack2,pushFront1,pushBack3 ->popBack3,popFront1,popFront2.

CORRECTNESS: The used logical interval retains its order even when physical indices wrap.

COST: O(1) operations,O(capacity) storage.

PITFALL: Use front+capacity-1 instead of unsigned front-1 before modulo.

### Drain and reuse an owning linked queue

CONTRACT: No shallow copies; empty dequeue throws.

IDEA AND STATE: Observe head/tail transitions over many complete fill/drain cycles.

TRACE: After the last pop, enqueue must start a new valid chain.

CORRECTNESS: Resetting tail on final removal makes later enqueue behave like a fresh empty queue.

COST: O(1) endpoint operations,O(n) cleanup/storage.

PITFALL: A dangling old tail may appear to work until memory is reused.

### Two stacks give amortized FIFO behavior

CONTRACT: enqueue,front,pop; optional absence when empty.

IDEA AND STATE: Push into incoming; transfer to outgoing only when outgoing is empty.

TRACE: enqueue1,2;pop1;enqueue3;next remains2.

CORRECTNESS: Reversing incoming exposes its earliest item; old outgoing items must leave before newer incoming ones.

COST: Amortized O(1) operations,O(n) worst transfer,O(n) storage.

PITFALL: Transferring while outgoing is nonempty breaks FIFO order.

### Compare wraparound behavior with an independent deque

CONTRACT: Fixed capacity4; deterministic mixed operations.

IDEA AND STATE: After every push/pop compare return status,front and size against std::deque.

TRACE: Repeated filling,overflow rejection,popping and wrapping preserve FIFO state.

CORRECTNESS: The model independently records logical order rather than reproducing ring arithmetic.

COST: O(1) operations,O(capacity) storage;200 bounded test operations.

PITFALL: Checking only one wrap does not cover repeated full/empty transitions.

### Queue candidates for first nonrepeating stream character

CONTRACT: Lowercase English text; output one answer per prefix,using# for no unique character.

IDEA AND STATE: Count arrivals and discard queue-front candidates once repeated.

TRACE: aabc ->a#bb.

CORRECTNESS: The first surviving queued character is the earliest seen character whose completed prefix count is1.

COST: O(n) total time,O(n) queue/output storage; each arrival enters/leaves at most once.

PITFALL: The sentinel# is outside the input alphabet.

### Interleave two FIFO halves

CONTRACT: Even-length queue; empty allowed.

IDEA AND STATE: Move the first half to a spare queue,then alternately append its front and the original second-half front.

TRACE: 1,2,3,4 ->1,3,2,4.

CORRECTNESS: Each half keeps its original order and contributes exactly one item per pair.

COST: O(n) time,O(n/2) auxiliary queue storage.

PITFALL: Odd length needs a different explicitly specified policy.

### Reverse only a queue prefix

CONTRACT: 0<=k<=size; invalid k returns false without mutation.

IDEA AND STATE: Pop k items onto a stack,append them reversed,then rotate the untouched suffix behind them.

TRACE: 1,2,3,4 with k3 ->3,2,1,4.

CORRECTNESS: The stack reverses exactly the selected prefix; rotating the suffix restores the desired concatenation.

COST: O(n) time,O(k) extra space; k0 may return immediately.

PITFALL: Validate k before popping any item.


