# Independent practice

Try without the worked source. Unless specified otherwise, accept only the stated
domain. From unit04 onward, reject malformed/out-of-domain input with an error
message and exit1. Before unit04, document the valid-input assumption instead.
A slash in a sample below separates output lines; it is not a printed character.

## 1. Voting classification

Read integer age0..120; reject invalid input. Print eligible for age>=18, otherwise not eligible.

**Sample:** Input18 ->eligible

## 2. Divisibility categories

Read n in [-1000,1000]. Print both if divisible by3 and5, three if only3, five if only5, neither otherwise.

**Sample:** Input15 ->both

## 3. Absolute magnitude

Read n in [-1000,1000]. Output nonnegative magnitude.

**Sample:** Input-7 ->7

## 4. Median of three

Read three ints in [-100,100]. Output the middle value, including duplicates.

**Sample:** Input9 2 5 ->5

## 5. Triangle kind

Read positive sides<=1000. Print invalid if they cannot form a triangle; otherwise equilateral, isosceles or scalene.

**Sample:** Input3 3 4 ->isosceles

## 6. Parking bill

Read nonnegative integer hours<=24. First2 hours cost20 each; later hours cost10 each. Output total.

**Sample:** Input5 ->70

## 7. Menu conversion

Read code1 or2 and positive value<=1000. Code1 converts hours to minutes; code2 converts minutes to seconds. Reject unsupported codes.

**Sample:** Input1 3 ->180

## 8. Boundary report

Write a validated pass/fail program with pass mark40. List tests covering malformed input, below0,0,39,40,41,100 and above100.

**Sample:** Input40 ->pass

