# C++ and DSA, from the beginning

A C++17 learning repository for a student starting programming and progressing toward
interview preparation. It contains 1,086 source files,including lessons,supplements and ten
projects. File counts are not a measure of mastery;advanced topics are introductions.

Start with [setup and your first program](00-start-here/README.md),then follow the
[learning order](LEARNING_ORDER.md). Do not start by opening random files.

## Study route

|Order|Chapter|
|---|---|
|1|[Programming foundations](01-programming-foundations/README.md)|
|2|[Core C++](02-core-cpp/README.md)|
|3|[Standard library](03-standard-library/README.md)|
|4|[Problem-solving foundations](04-problem-solving-foundations/README.md)|
|5|[Linear data structures](05-linear-data-structures/README.md)|
|6|[Algorithm patterns](06-core-algorithm-patterns/README.md)|
|7|[Recursion and backtracking](07-recursion-and-backtracking/README.md)|
|8|[Trees,heaps and tries](08-trees-and-heaps/README.md)|
|9|[Graphs](09-graphs/README.md)|
|10|[Dynamic programming](10-dynamic-programming/README.md)|
|11|[Advanced topics](11-advanced-dsa/README.md)|
|12|[C++ engineering](12-cpp-engineering/README.md)|
|13|[Placement preparation](13-placement-preparation/README.md)|

## How to use a lesson

Read the notes,trace the example by hand,compile and run it,then rewrite it without looking.
Attempt practice before hints. Supplied assertions check examples;independent exercises
are where you find gaps in understanding.

## Build one example

Use a C++17 compiler. From the repository root:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic 01-programming-foundations/01-first-programs/01_hello.cpp -o hello
./hello
```

On Windows,use `-o hello.exe` and run `.\hello.exe`. Compile one source at a time;
most files define their own main. Do not link the entire repository together.
Input-driven examples wait for their documented input. Keep assertions enabled.

## Find your next activity

- [Study habits](STUDY_GUIDE.md)
- [Ten projects](14-projects/README.md)
- [Practice and timed rounds](practice/README.md)
- [Hints and worked solutions](solutions/README.md)
- [Contributing](CONTRIBUTING.md)

The repository is organized for study. It does not promise exhaustive C++ coverage or
that running the examples alone establishes interview readiness.

## Publish

The files are prepared for GitHub,but no remote has been created or pushed.
Choose a license if you want to offer reuse terms. Review the contents before the first commit.

