# Two pointers: staged hints

Read the first hint before revealing the second. Write your own attempt before consulting either.

## 1. Reverse vowels

1. Move inward past non-vowels; swap only confirmed vowels.
2. Test no vowels and one vowel.

## 2. Remove a chosen value

1. Read visits every value; write advances only for retained values.
2. The unused tail is unspecified.

## 3. Sorted distinct prefix

1. Compare the next value with the last retained value.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 4. At most two copies

1. Once two outputs exist, compare with output[write-2].
2. Trace the state on a tiny input, then compare against a direct baseline.

## 5. Closest pair sum

1. Record a wide difference before moving the side that can approach target.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 6. Distinct target pairs

1. After a match, skip duplicates on both sides; value pairs differ from index-pair counts.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 7. Three-sum closest

1. Fix an anchor; apply pair movement and explicitly implement the tie rule.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 8. Water reference

1. Compute both maximum walls independently at each index.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 9. Merged unique union

1. Consume smaller values and suppress repeated output; handle exhausted input.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 10. Subsequence list

1. Scan each word against text first; state the resulting cost.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 11. Maximum text partition count

1. A segment cannot close before the last occurrence of every byte already inside it.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 12. Invalid movement

1. Use[3,2,4], target 6.
2. Sort records containing both value and original index.

