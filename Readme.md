# MiniVector – Custom std::vector Implementation in C++

## Overview
MiniVector is a simplified implementation of `std::vector<int>` written in modern C++.  
It demonstrates deep understanding of:

- Dynamic memory management
- Rule of 5
- Move semantics
- Capacity growth strategy
- Iterator support
- STL-style API design

## Features
- Dynamic resizing with amortized O(1) `push_back`
- Copy & move constructors
- Copy & move assignment operators
- `reserve`, `shrink_to_fit`, `clear`
- Safe access using `at()`
- Fast access using `operator[]`
- Iterator support (`begin`, `end`)
- Range-based for loop compatibility

## Why this project?
This project was built to understand how `std::vector` works internally and to gain
system-level C++ experience useful for performance-critical software.

## Build & Run
```bash
g++ .\main.cpp .\minivector.cpp -o a.exe
.\a.exe
