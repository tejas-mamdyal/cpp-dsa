# Independent practice

Use small stated bounds,n<=1000 unless the problem requires a smaller bound.
Explain preconditions,errors,correctness,time and owned/auxiliary memory. Reclaim
node allocations and never dereference erased observers.

## 1. Task

Reject zero/negative ring capacity before modulo.

Example/result: no division by zero.

## 2. Task

Design two successive wrap cycles.

Example/result: FIFO order unchanged.

## 3. Task

Drain and reuse a linked queue.

Example/result: new singleton has fresh head/tail.

## 4. Task

Wrap a deque front backward from index0.

Example/result: (front+capacity-1)%capacity.

## 5. Task

Account for two-stack transfers across n arrivals.

Example/result: linear total transfers.

## 6. Task

Compute first-unique answers foraaaa.

Example/result: a###.

## 7. Task

Specify an odd-length interleave policy.

Example/result: current helper requires even length.

## 8. Task

Try prefix reversal k greater than queue size.

Example/result: unchanged failure.


