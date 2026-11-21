# Hints: Sequences utilities and iterator contracts

Try the problem and hand trace before reading its hint.

## 1. Container selection

First: identify the state and precondition.

Next: Match the operation costs and interface.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 2. Erase odds

First: identify the state and precondition.

Next: Do not increment an invalidated iterator.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 3. List splice

First: identify the state and precondition.

Next: Use splice with a valid iterator and compatible allocators.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 4. Forward-list filter

First: identify the state and precondition.

Next: before_begin lets you remove the first node too.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 5. Reverse copy

First: identify the state and precondition.

Next: Use rbegin/rend with a result container.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 6. Const iteration

First: identify the state and precondition.

Next: Constness applies through the iterator interface.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 7. Variant query

First: identify the state and precondition.

Next: Use holds_alternative or get_if.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 8. Invalidation trace

First: identify the state and precondition.

Next: Do not execute the dangling access.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.


