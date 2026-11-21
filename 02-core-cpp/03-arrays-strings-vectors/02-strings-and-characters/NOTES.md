# Strings and characters: notes

A string owns a variable-length sequence of char values. size counts stored char units, not necessarily human-readable Unicode characters. Empty strings have no front/back element; at checks an index while [] assumes it is valid. Editing the middle can shift many characters, so account for linear work rather than treating every method as constant-time.

Use two passes when information about the whole string is needed before choosing an answer: frequency counting first, then scanning for the first unique character. A 26-entry table is suitable only for a..z. General byte counts or Unicode text require different representations. Run-length encoding counts adjacent groups, while anagram counting ignores order; these solve different problems.

Use ordinary index loops before library algorithms. Functions taking const string& borrow read-only text and avoid copying. The decimal-conversion bridge is deliberately later: it needs pointers and exception handling. Read its route entry after exceptions, not merely because its filename appears here.

## Concepts in the worked programs

### 01 construction access

Construct empty, repeated and literal strings; inspect size, front, back and at.

Trace: hello has length 5; at(1) is e. A string owns its characters and knows its length.

Cost: O(n) construction and O(1) indexed access. Pitfall: Check empty input and bounds before indexing; valid indices end at size()-1.

### 02 append insert erase

Use +=, push_back, insert, erase and replace with explicit positions.

Trace: cat -> cats -> Cats -> Cute -> Cut. Each edit addresses a valid position in the current string, not an earlier version.

Cost: O(n) time in the length of the data; O(1) auxiliary space. Pitfall: Check empty input and bounds before indexing; valid indices end at size()-1.

### 03 find and substr

find returns an index or npos; substr copies a selected segment.

Trace: banana.find(ana)=1; the next match starts at 3. Starting the second search one character later permits overlapping matches.

Cost: find can take O(n*m) comparisons for pattern length m; substr copies O(k) characters. Pitfall: npos is an unsigned sentinel; test equality with npos before adding or indexing.

### 04 character classification

Use cctype functions with an unsigned-char conversion; this lesson handles ordinary English text.

Trace: A1 ! contains one letter and one decimal digit. The unsigned-char conversion satisfies the cctype argument contract.

Cost: O(n) time in the length of the data; O(1) auxiliary space. Pitfall: Passing a negative signed char to cctype is invalid. Byte-wise conversion is not general Unicode case folding.

### 05 reverse and palindrome

Copy characters in reverse order; compare symmetric positions. Case and spaces matter.

Trace: level equals its reverse; Level does not. Each pair of mirrored positions must match; half the positions cover all pairs.

Cost: O(n) time; reverse uses O(n) result storage, palindrome uses O(1) space. Pitfall: Check empty input and bounds before indexing; valid indices end at size()-1.

### 06 anagram counts

Compare lowercase-English strings by letter multiplicity. Inputs must contain only a..z.

Trace: silent and listen have identical letter counts. Incrementing for one string and decrementing for the other leaves all zeros exactly when multiplicities match.

Cost: O(n+26) time, O(26) space. Pitfall: Validate/normalize the alphabet before using ch-a as an index; this helper has a lowercase-only precondition.

### 07 first unique character

Return its index or -1 using counting then a left-to-right scan.

Trace: swiss has first unique character w at index 1. Counts establish uniqueness, while the second scan establishes first position.

Cost: O(n+26) time, O(26) space. Pitfall: The alphabet is a..z and the length must fit int; do not return the first alphabetically unique letter.

### 08 run length encoding

Encode each maximal adjacent run as its character followed by its count.

Trace: aaabbc -> a3b2c1; the empty string stays empty. The inner loop ends at the first different character, so each input position belongs to exactly one emitted run.

Cost: O(n) time and O(n) output space. Pitfall: This simple encoding is not unambiguous for digit-valued characters; decoding needs a specified alphabet or separators.

### 09 naive substring search

Return an occurrence count including overlaps; the empty pattern matches at n+1 boundaries.

Trace: aaaa contains aa at positions 0,1,2. Every legal start is checked character by character, and advancing by one retains overlaps.

Cost: O(n*m) time for text n and pattern m; O(1) extra space. Pitfall: Check empty input and bounds before indexing; valid indices end at size()-1.

### 10 remove adjacent duplicates

Keep a character only when it differs from the last retained character.

Trace: aaabbaa -> aba; separated occurrences are preserved. Exactly the first character of each adjacent run is retained.

Cost: O(n) time and O(n) output storage. Pitfall: Check empty input and bounds before indexing; valid indices end at size()-1.

### 11 decimal conversion

stoi accepts a prefix, so inspect its consumed-length result; catch invalid_argument and out_of_range.

Trace: 42x parses a prefix of length 2, but strict conversion rejects it. The consumed count reveals unparsed suffix text; distinct exceptions separate syntax and range failures.

Cost: O(n) conversion time, implementation-dependent conversion storage. Pitfall: This is a later bridge after pointers and exceptions; start with string streams in the parsing unit.


