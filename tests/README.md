# File-Based Database Engine

## Overview
This project simulates an in-memory storage engine for handling key-value pairs. It uses a B+ Tree indexing mechanism to optimize disk I/O and achieve sub-millisecond query lookups.

## Features
- Key-Value store
- B+ Tree indexing for efficient query lookups
- SQL-like command parser in C++
- Supports file-based data storage

## Setup
1. Clone the repository.
2. Navigate to the project directory and run `make` to compile.
3. Execute the program using `./dbengine`.

## Technologies
- C++
- B+ Tree data structure
- File I/O
