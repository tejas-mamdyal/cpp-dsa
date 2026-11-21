# File streams before persistence

Use [the expanded files unit](practice/README.md) before the persistence project.

Prerequisites: strings, RAII and exceptions. Read [the file/organization example](01_files_and_program_organization.cpp)
before contact-manager persistence. ofstream writes and ifstream reads; their
lifetimes close the owned files. Check open/write success and define overwrite
behavior. Create build/ using the compile instructions before running the example; keep generated files there. Larger build-system work remains later.

