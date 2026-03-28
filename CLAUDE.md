# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build & Run

This is a C++ LeetCode practice repo targeting **C++14** on macOS (Apple clang, arm64).

Compile and run a single file:
```bash
clang++ -std=c++14 -o solution 283.Move_Zeros.cpp && ./solution
```

## Code Structure

Each `.cpp` file is a self-contained LeetCode problem containing:
- A `Solution` class with the LeetCode problem method(s)
- A custom constructor that accepts an `initializer_list<int>` to populate `nums` directly
- A `vector_displayer` helper for printing the result
- A `main()` function with test cases

The `nums` vector is stored as a public member of `Solution` so `main()` can pass it by reference to `moveZeroes` and `vector_displayer`.
