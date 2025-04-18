# Push_swap Test Script Documentation

This document provides information about the `test_push_swap.sh` script that automates testing for the 42 Push_swap project.

## Overview

The test script is designed to verify that your Push_swap implementation meets all the mandatory requirements for the 42 project evaluation. It runs a series of tests from basic error handling to advanced sorting algorithms performance.

## Prerequisites

- A compiled `push_swap` executable in the current directory
- Bash shell environment
- For memory leak tests: `valgrind` (Linux) or `leaks` (macOS)
- For random number tests: `shuf` command (included in most Linux distributions)
- For checker tests: `checker_OS` executable (or checker_linux/checker_Mac/checker in PATH)

## Running the Tests

1. Make sure your Push_swap project is compiled:
   ```
   make
   ```

2. Make the test script executable (if not already):
   ```
   chmod +x test_push_swap.sh
   ```

3. Run the script:
   ```
   ./test_push_swap.sh
   ```

## Test Categories

The script performs the following test categories:

### 1. Memory Leak Tests
- Validates that your program doesn't leak memory when sorting simple inputs
- Uses Valgrind on Linux or leaks on macOS

### 2. Error Management Tests
- Tests handling of non-numeric arguments (should print "Error")
- Tests handling of duplicate numbers (should print "Error")
- Tests handling of integer overflow (values > INT_MAX or < INT_MIN)
- Tests with no arguments (should print nothing)

### 3. Identity Tests (Already Sorted)
- Tests with a single number (should output nothing)
- Tests with pairs like "2 3" (already sorted)
- Tests with longer sorted sequences

### 4. Simple Version Tests (3 Numbers)
- Tests sorting 3 numbers (e.g., "2 1 0")
- Verifies sorting works with ≤3 instructions
- Uses checker to verify the solution is correct

### 5. Simple Version Tests (5 Numbers)
- Tests sorting 5 numbers (e.g., "1 5 2 4 3")
- Verifies sorting works with ≤12 instructions
- Uses both specific test cases and random number sequences

### 6. Middle Version Tests (100 Numbers)
- Tests sorting 100 random numbers
- Rates performance based on instruction count:
  - <700 = 5/5
  - <900 = 4/5
  - <1100 = 3/5
  - <1300 = 2/5
  - <1500 = 1/5

### 7. Advanced Version Tests (500 Numbers)
- Tests sorting 500 random numbers
- Rates performance based on instruction count:
  - <5500 = 5/5
  - <7000 = 4/5
  - <8500 = 3/5
  - <10000 = 2/5
  - <11500 = 1/5

## Understanding Output

The script uses color-coded output to make results easy to understand:
- 🟢 Green: Passed tests and good performance
- 🟡 Yellow: Test information and medium performance
- 🔴 Red: Failed tests and poor performance

At the end of the test run, you'll get a summary of passed tests and an overall evaluation.

## Test Results Interpretation

- For sorting algorithm tests, the instruction count is the key metric
- A lower instruction count means a more efficient algorithm
- The script shows both the raw count and a rating based on the project requirements
- All checker tests should return "OK" to verify that the sorting is correct

## Troubleshooting

If you encounter issues:

1. **Missing checker_OS**: The script will still run most tests but won't verify that the sorting is correct. Try to obtain the checker from the intra resources.

2. **Missing valgrind/leaks**: Memory leak tests will be skipped.

3. **Missing shuf command**: Random number tests will be skipped. Install coreutils package on your system.

## Note

This test script is designed to help prepare for evaluation and doesn't guarantee a specific grade. The actual evaluation may have additional or slightly different criteria.

Use this script as a tool to verify your implementation meets the minimum requirements and to identify areas for improvement.