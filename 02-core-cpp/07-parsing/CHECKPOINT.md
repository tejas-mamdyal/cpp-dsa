# Parsing checkpoint (20 points)

1. Choose >>, getline or istringstream for a fixed numeric pair, a full name and
   a line of unknown-count numbers. Explain each boundary policy. (4)
2. Implement a standalone pipe-separated integer parser, including blank fields,
   trailing separators, overflow and12abc. No project header or raw pointer. (6)
3. Read a quoted name and age, then reject incomplete quotes and extra fields. (4)
4. Trace how EOF differs from a malformed final number; explain why an int may
   read the prefix of12abc successfully. (3)
5. Reimplement the count-prefixed or matrix example without consulting its source,
   then test missing values and an invalid count/dimension. (3)

Target16/20, including at least4/6 on the independent delimited parser. Record a
failed case and its fix. Read std::quoted and stream-state notes before attempting
those tasks; the examples introduce their small APIs before using them.

