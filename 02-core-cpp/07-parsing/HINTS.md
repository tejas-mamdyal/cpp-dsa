# Parsing hints

Try PRACTICE.md first. These give the first step, then the key validation detail.

| Task | First hint | Validation/next step |
|---|---|---|
|1 Pipe list|Use getline with '\|'|Read one integer per field and reject leftovers|
|2 Decimal mean|Use istringstream and double|Check finite/range values; count before division|
|3 Full names|Consume the numeric line's remainder|Then use plain getline exactly n times; do not skip blanks|
|4 Name:score|Split exactly once at ':'|Check the numeric part consumes the entire field|
|5 Test lists|Outer test loop, inner element loop|Reset the sum per case and validate each n|
|6 Coordinate|Read a punctuation char, int, char, int, char|Compare all punctuation before printing; reject leftovers|
|7 Optional comma|Make the final-empty-field rule explicit|Allow only the final delimiter, never an interior empty field|
|8 Blank terminator|Compare the whole line with empty text|Whitespace-only lines are not equal to empty text|
|9 Text setting|find the first '=' and take the suffix|Do not extract the suffix with >> if spaces matter|
|10 Quoted name|Use std::quoted with a string stream|Inspect stream failure and reject trailing unexpected text|
|11 Column total|Read/retain the matrix before the column|Validate0<=column<columns before indexing|
|12 Policy comparison|Track the stream position after each extraction|An int extraction can succeed before the trailing junk|

