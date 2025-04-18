# Push_swap

## Overview
Push_swap is a 42 School algorithm project focused on sorting data efficiently. The goal is to sort a set of integers using two stacks and a specific set of operations, optimizing for the minimum number of moves.

## Project Description
This program takes a set of integers as arguments, sorts them using two stacks (Stack A and Stack B), and outputs the sequence of operations used to sort the data.

### The Rules
- You have two stacks: Stack A and Stack B.
- At the start, Stack A contains the input integers (in random order) and Stack B is empty.
- The goal is to sort all integers in Stack A in ascending order.
- You can only use the following operations:
  - `sa`: Swap the first two elements at the top of Stack A
  - `ra`: Rotate Stack A (move the first element to the bottom)
  - `rra`: Reverse rotate Stack A (move the last element to the top)
  - `pa`: Push the top element from Stack B to Stack A
  - `pb`: Push the top element from Stack A to Stack B

## Implementation Details

### Data Structures
- `t_stack`: A structure containing an integer array and a top index pointer

### Main Components
- **Input Validation**: Checks for valid numbers, duplicates, and already sorted sequences
- **Stack Initialization**: Sets up the stacks based on input
- **Stack Operations**: Implements the required stack manipulation operations
- **Sorting Algorithms**:
  - Simple algorithms for handling 2, 3, or 5 elements
  - A more sophisticated algorithm for larger sequences

### Error Handling
The program detects and handles various error cases:
- Invalid arguments (non-integers, overflows)
- Duplicate values
- Memory allocation failures

## Usage

```bash
# Compile the program
make

# Run with arguments
./push_swap 4 67 3 87 23

# Test with the checker (if available)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## Performance
- For 3 numbers: Maximum 2-3 operations
- For 5 numbers: Maximum 12 operations
- For 100 numbers: Around 700 operations (based on algorithm implementation)
- For 500 numbers: Around 5500 operations (based on algorithm implementation)

## Author
- isel-bar (isel-bar@student.42.fr)