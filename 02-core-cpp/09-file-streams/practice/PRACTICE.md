# Independent practice: Files serialization and persistence

Write each solution from a blank file. Use C++17 and state input constraints,
return/absence policy, cost and at least one empty/invalid/boundary case.
Small exercise integers have absolute value <=1000000 unless stated otherwise.

## 1. Count nonblank lines

Ignore truly empty lines while counting file records.

Example: A,empty,B ->2.

## 2. Append records

Write two records across separate opens with app.

Example: both records remain.

## 3. Quoted round trip

Store a name with spaces and embedded quotes.

Example: Ada "Ace" restores exactly.

## 4. Malformed load

Reject a record with extra trailing fields.

Example: 1,90,junk ->failure.

## 5. Missing file policy

Choose empty initial state or a reported error and document it.

Example: contact LOAD reports failure.

## 6. Write failure

Check stream state after close.

Example: a failed save is not reported as SAVED.

## 7. Duplicate ID load

Reject duplicates even if each line is individually valid.

Example: ID1 twice ->failure.

## 8. Report formatting

Print averages with fixed two decimal places.

Example: 90 ->90.00.


