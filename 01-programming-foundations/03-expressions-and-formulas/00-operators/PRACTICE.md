# Operator practice

Solve from a blank file; state constraints and add a boundary test.

## 1. Arithmetic trace

Compute -17/5 and -17%5 and verify quotient*5+remainder=-17.

Expected example: -3,-2.

## 2. Conversion timing

Compare double(5/2) and static_cast<double>(5)/2.

Expected example: 2 and2.5.

## 3. Compound trace

Start7, add3, multiply2, subtract5, divide3.

Expected example: 5.

## 4. Range predicate

Check whether x is in inclusive[-5,5].

Expected example: x6 ->false.

## 5. Guarded division

Compute n/d only when d is not zero.

Expected example: 10,0 ->invalid.

## 6. Prefix/postfix

Trace x3, old=x++, current=--x.

Expected example: old3,current3,x3.

## 7. Conditional maximum

Choose the larger of two bounded ints using ?: and then if/else.

Expected example: 4,9 ->9.

## 8. Bit table

Compute6&3,6|3,6^3.

Expected example: 2,7,5.

## 9. Bit toggle

Toggle position2 twice starting from1U.

Expected example: 1 ->5 ->1.

## 10. Size distinction

Explain sizeof(int*) versus the length of an int array.

Expected example: pointer size is not element count.

## 11. Precedence

Compare2+3*4 and(2+3)*4; explain associativity versus evaluation order.

Expected example: 14 and20.

## 12. Comma versus separator

Classify commas in f(a,b) and(a=2,a+3).

Expected example: separator versus comma operator.

