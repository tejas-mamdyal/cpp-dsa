# Independent practice

Use the corresponding lesson bounds. For each task provide the full input/output contract,a simple baseline,state definition,trace,proof,costs and normal/boundary/counterexample checks. Attempt without copying worked source.

## 1. Exercise 1

Eliminate highest bits to maximize a subset XOR. Domain:Unsigned integers in[0,65535], any subset including empty. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare maximum subset XOR with enumerating all subsets.

## 2. Exercise 2

Retain coefficients while applying Euclid. Domain:a, b in[0,1000000]. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Verify the returned linear combination equals gcd for every small pair.

## 3. Exercise 3

Mark composites from each prime square. Domain:0<=n<=1000000. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare primality with trial division for all values through100.

## 4. Exercise 4

Extract prime powers and count exponent choices. Domain:1<=n<=1000000. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Enumerate divisors and check the factor-exponent product.

## 5. Exercise 5

Square the base while consuming exponent bits. Domain:Signed base magnitude<=1000000; unsigned exponent;1<=modulus<=1000000007. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare small powers with repeated modular multiplication.

## 6. Exercise 6

Use Bezout coefficients only when the gcd is one. Domain:2<=modulus<=1000000; value magnitude<=1000000. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Reject noncoprime modular inverse requests explicitly.

## 7. Exercise 7

Precompute factorials and inverse factorials for repeated queries. Domain:Precompute 0<=n<=1000000; queries 0<=n<=precomputed bound; fixed prime 1000000007. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare prime-modulus combinations with exact small binomial values.

## 8. Exercise 8

Avoid division when the modulus is composite. Domain:0<=n<=1000; integer r;1<=modulus<=1000000007. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Use a composite modulus where factorial division fails.

## 9. Exercise 9

Merge compatible residue classes with a gcd test. Domain:Residues magnitude<=1000000; moduli 1..1000. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Enumerate a full lcm period to validate compatible and incompatible CRT cases.

## 10. Exercise 10

Remove each distinct prime fraction from all its multiples. Domain:0<=n<=1000000; phi[0]=0 is a table convention. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare totients with a direct gcd count.

## 11. Exercise 11

Exponentiate a fixed-size recurrence transition. Domain:Unsigned exponent; answers modulo 1000000007. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare matrix Fibonacci with a rolling recurrence.

## 12. Exercise 12

Compress powers into the unique base-k representation. Domain:0<=n<=1000000;1<=k<=1000000; includes a batch-processing example. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare base-k digit counts with a tiny shortest-operation search.

