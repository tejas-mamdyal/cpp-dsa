# Document search

The project is now a single file:main.cpp. Compile it directly like the other examples.

Input is a document count,that many text lines,a query count,and that many queries.
It finds documents containing every query word,ignoring ASCII letter case. Output uses
zero-based document IDs. Empty queries return NONE. Malformed input is rejected.

Study tokenization,posting lists and their intersection. Then add OR queries independently.

