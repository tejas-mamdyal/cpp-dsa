# Start here: your first programming course

No experience is needed. Follow the numbered chapters.

## What you are learning

A computer executes instructions on stored data. An algorithm is a finite sequence
of unambiguous steps; a program expresses those steps in a language. Input supplies
data, processing transforms it and output presents a result. Write the steps in
ordinary words before translating them into C++.

You will learn to read and change a program, trace its state, debug failures,
create your own functions and finish three projects. Progress by understanding;
the semester timeline in the repository plan is a suggestion, not a deadline.

## Prepare your tools

Use an editor, a terminal and a C++17 compiler. The examples below assume g++ is
installed and on PATH. Check `g++ --version` in PowerShell. If it is not recognized,
finish compiler installation/PATH setup and restart the terminal before studying
the code. An editor alone is not a compiler. The existing toolchain in this workspace
can compile the course; a fresh machine must provide its own compiler.

From the repository root:

```powershell
New-Item -ItemType Directory -Force build | Out-Null
g++ -std=c++17 -Wall -Wextra -pedantic 01-programming-foundations/01-first-programs/01_hello.cpp -o build/hello.exe
./build/hello.exe
```

Expected output: `Hello, programmer!`. To run another lesson replace the source
path. For an input lesson, run the executable, type the documented values and
press Enter. Programs print results without prompts; their comments describe input.
Do not paste JSON test syntax into the executable: the input values are plain text.

## Understand what happens

1. Edit source (`.cpp`): text written for the compiler and human readers.
2. Compile: the compiler checks language rules and translates the source.
3. Link: referenced definitions and runtime support are connected into an executable.
4. Run (`.exe`): execute the translated instructions.
5. Change source and compile again. An old executable does not update itself.

A syntax/type error prevents compilation. A missing definition may fail linking.
Invalid operations can fail at runtime. A logic error may run and print a wrong
answer. Read the first diagnostic and locate the indicated source statement.

## Your first session

Run hello, change its message, rebuild and run again. Explain every symbol using
its source comments. Continue through [the Phase1 units](../01-programming-foundations/README.md)
in order. Read a note, trace a tiny input, run it, then reproduce it without looking.
Try an independent exercise before opening hints. Keep a notebook of misconceptions
and counterexamples; revisit a lesson a day later and again a week later.

## When something goes wrong

- Command not recognized: check compiler installation/PATH or the executable path.
- Source file not found: open PowerShell in this repository root and verify the path.
- Compilation fails: read the first diagnostic; check spelling, braces and semicolons.
- Program appears idle: it may be waiting for its documented input.
- Output is stale: rebuild the source you edited and run the newly created executable.
- Wrong result: predict a tiny case, trace variables and find the first wrong state.

For a debugger session, compile with `-g -O0` using the same source path. In a
debugger configured for your compiler, set a breakpoint on a processing statement,
run, inspect locals, step over an update, and compare with your paper trace. Step
into enters a helper; the call stack shows which function called it. Breakpoints
and stepping require the executable built from the current source with debug info.

## Finish line for Phase1

Complete the eight checkpoints, calculator, number toolkit and grade analyzer;
then take the final assessment. You should be able to explain, independently write
and debug a small input-driven program using conditions, loops and functions.
After that, Phase2 introduces collections and deeper C++ concepts.

