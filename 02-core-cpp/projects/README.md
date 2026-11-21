# Phase2 projects

Complete the unit checkpoints before using these as reference solutions. Write your
own version from each contract before reading its implementation. Both programs
separate command handling, model rules and processing; neither needs a custom header.

## Persistent contacts

[01_contact_manager.cpp](01_contact_manager.cpp) supports ADD, UPDATE, FIND, DELETE,
LIST, SAVE, LOAD and QUIT, one command per line. IDs1..1000000 are unique; at most
1000 contacts. Name length1..80 and phone length1..32; phone is text so leading
zeros survive. Quote fields containing spaces or quotes; single words may be unquoted.
The source comment defines failure status and output. Earlier successful output may
precede a later error.

```text
ADD 2 "Ada Lovelace" "01234"
SAVE
DELETE 2
LOAD
FIND 2
QUIT
```

Expected output:

```text
ADDED
SAVED
DELETED
LOADED
2 "Ada Lovelace" "01234"
```

Storage is `build/contacts.txt`, containing one quoted record per line in ascending
ID order. Empty file is a valid empty collection. LOAD rejects missing files,
malformed fields, duplicate IDs and excess records. It commits only a completely
valid temporary map. SAVE checks writing and close; it overwrites directly and is
not crash-atomic. Keep your personal data outside this teaching scratch path.

## Student records

[02_student_record_manager.cpp](02_student_record_manager.cpp) supports ADD id name
count marks..., UPDATE id count marks..., REMOVE id, FIND id, REPORT, FILTER threshold
and QUIT. Count1..10; marks0..100; thresholds0..100; at most1000 students. IDs/names
use the contact limits. REPORT sorts by descending average then ascending ID; FILTER
uses the same order. Names/marks are stored; averages are derived so updates cannot
leave a stale cached summary. Output uses two decimal places.

```text
ADD 2 "Grace" 2 80 100
ADD 1 "Ada" 2 90 90
REPORT
UPDATE 2 1 100
FILTER 95
QUIT
```

Expected output:

```text
ADDED
ADDED
1 "Ada" 90.00
2 "Grace" 90.00
UPDATED
2 "Grace" 100.00
```

## Build and check only the projects

From the repository root:

CRUD, ordering/ties, empty collections, boundaries, missing/malformed/duplicate
files, failed extraction, invalid marks, partial records and extra tokens. File I/O
checks never need your personal contacts file.

## Assessment

20 points per project: data/model invariants4, complete operations4, input/error
handling4, persistence round trip or sorting/filtering4, and clear decomposition/
independent boundary tests4. Aim for16/20 each. Explain ownership and cost as well
as passing sample sessions. Extensions: atomic save, versioned format, duplicate
phone policy, name search, median summaries and import/export.

