# Independent practice: Classes records and value semantics

Write each solution from a blank file. Use C++17 and state input constraints,
return/absence policy, cost and at least one empty/invalid/boundary case.
Small exercise integers have absolute value <=1000000 unless stated otherwise.

## 1. Validated rectangle

Create a class accepting dimensions0..1000 and returning area.

Example: 3,4 ->12; negative update rejected.

## 2. Withdrawal invariant

Add transfer between two accounts without partial changes.

Example: A50,B10 transfer20 ->A30,B30.

## 3. Record equality

Compare ID and name using operator==.

Example: same fields ->true; different ID ->false.

## 4. Composition address

Let Student own an Address record.

Example: Ada with city Pune prints its own city.

## 5. Copy isolation

Copy a record with vector marks and modify the copy.

Example: original marks remain unchanged.

## 6. Scoped status

Represent pending,accepted,rejected without magic numbers.

Example: Status::accepted is a valid named state.

## 7. Static counter

Count calls to an issuing function and explain persistence.

Example: two issued IDs1,2.

## 8. Student class

Add checked mark replacement and derived average.

Example: 80,100 ->90; mark101 rejected.


