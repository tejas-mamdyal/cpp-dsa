# Recursion checkpoint:20 points

Work without copying a solution. Each task is worth5: correct implementation or
trace2, base/progress argument1, time and stack/output cost1, boundary checks1.
Aim for16/20, with no unchecked invalid input or unexplained recursive cycle.

1. Trace factorial(4) and a print-before/print-after countdown. Identify each frame's
   parameter, pending work, deepest live stack and order of returned results.
2. Implement a bounded recursive digit count that treats0 as one digit. Include
   zero, a singleton digit, a power of10 and the largest permitted input.
3. Implement one-call power by squaring and compare it with an independent loop on
   a bounded signed-base domain. Explain why two repeated half calls lose the
   logarithmic work guarantee, and why arithmetic bounds still matter.
4. Compare naive Fibonacci, balanced range sum and Hanoi. Derive total work and
   maximum active depth, distinguish stored output from call-stack memory, and
   propose an independent bounded oracle for one of them.

Review guide: factorial(4) uses5 frames with the0 base; digit count should stop at
n<10; one cached half-power gives one smaller recursive call per level; Fibonacci
repeats overlapping work, range sum partitions its data, and Hanoi needs2^n-1 moves.
A finite set of passing cases supports but does not replace the correctness argument.

