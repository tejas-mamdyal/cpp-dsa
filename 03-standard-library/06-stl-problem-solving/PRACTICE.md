# Independent bridge practice

## 1. Type ranges

Report numeric_limits bounds and explain why exact byte widths are not assumed.

## 2. Mixed signs

Explain how comparing a negative int with an unsigned size can go wrong.

## 3. Default argument

Add a trailing default parameter without creating an ambiguous overload.

## 4. Compile-time evaluation

Check a small constexpr arithmetic result with static_assert.

## 5. Base conversion

Convert255 to binary, octal and hexadecimal; results11111111,377,FF.

## 6. Invalid digit

Reject102 as binary and8 as octal before updating a result.

## 7. Overflow guard

Derive value<=(max-digit)/base for positional input.

## 8. Deterministic tie

Count a frequency tie and select the smaller key explicitly.

