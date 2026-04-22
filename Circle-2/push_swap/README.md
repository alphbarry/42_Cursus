# 🔄 Push_Swap

## 📍 Overview

**Push_Swap** is a project in the 42 Cursus that involves sorting a stack of integers using a limited set of operations. It teaches algorithms, optimization, and data structure manipulation.

## 🎯 Objectives

- Sort a list of integers using two stacks
- Minimize the number of operations
- Implement efficient sorting algorithms
- Optimize for different input sizes
- Understand complexity analysis

## 🛠️ Features

- **Two Stacks (A and B):**
  - Stack A contains the unsorted numbers
  - Stack B is initially empty (auxiliary)
  - Goal: sort stack A in ascending order

- **Allowed Operations:**
  - `sa` - Swap top 2 elements of stack A
  - `sb` - Swap top 2 elements of stack B
  - `ss` - Swap top 2 of both stacks
  - `pa` - Push top of B to A
  - `pb` - Push top of A to B
  - `ra` - Rotate stack A up
  - `rb` - Rotate stack B up
  - `rr` - Rotate both stacks up
  - `rra` - Rotate stack A down
  - `rrb` - Rotate stack B down
  - `rrr` - Rotate both stacks down

- **Output:**
  - List of operations performed
  - Minimal operation count (optimized)

## 📦 Project Structure

```
push_swap/
├── Makefile
├── src/              # Source files
├── inc/              # Header files
└── libft/            # Custom C library
```

## 🚀 Compilation & Execution

### Compilation

```bash
make
```

Creates executable: `push_swap`

### Usage

```bash
./push_swap <number1> <number2> <number3> ...
```

### Examples

```bash
# Sort 3 numbers
./push_swap 3 2 1

# Sort 5 numbers
./push_swap 5 1 3 2 4

# Already sorted
./push_swap 1 2 3 4 5

# Reverse sorted
./push_swap 5 4 3 2 1
```

## 🧪 Testing

### Checker Program (if available)

```bash
# Generate random numbers
ARG=$(seq 1 100 | shuf | head -n 100 | tr '\n' ' ')

# Run push_swap
./push_swap $ARG | ./checker $ARG

# Should output "OK" if sorting is correct
```

## ⚙️ Algorithm Complexity

- **Small list (≤ 3 elements):** Direct solution
- **Medium list (5-100 elements):** Optimized algorithm (target: < 5500 ops for 100 elements)
- **Large list (> 100 elements):** Efficient sorting (target: < 11500 ops for 500 elements)

## 🔑 Key Concepts

- **Stack Operations** - LIFO (Last In First Out)
- **Algorithm Optimization** - Minimize total operations
- **Problem Decomposition** - Break into manageable chunks
- **Heuristic Approaches** - Use intelligent placement
- **Sorting Algorithms** - Adapted for stack constraints

## 📚 Sorting Strategies

- **Bubble Sort** - Simple but inefficient for large lists
- **Insertion Sort** - Better for partially sorted data
- **Quick Sort** - Efficient average case
- **Merge Sort** - Predictable performance
- **Radix Sort** - Good for large sequences

## 🛡️ Input Validation

```bash
# Handles:
- Positive and negative numbers
- Prevents duplicates
- Validates integer range
- Detects invalid arguments
```

## 🔧 Compilation Details

```bash
make        # Build executable
make clean  # Remove object files
make fclean # Remove executable and objects
make re     # Clean and rebuild
```

## 📝 Error Handling

```bash
# Invalid arguments
./push_swap abc

# Duplicate numbers
./push_swap 1 2 1

# Non-integer input
./push_swap 1.5 2 3

# Out of range
./push_swap 2147483648 1 2
```

## 💡 Optimization Tips

- Minimize rotations (most expensive operation)
- Use stack B strategically
- Group numbers efficiently
- Reduce redundant operations
- Consider median positioning

## 📊 Performance Goals

| Input Size | Operation Limit | Difficulty |
|------------|-----------------|------------|
| 3          | 3               | Easy       |
| 5          | 12              | Medium     |
| 100        | 5500            | Hard       |
| 500        | 11500           | Very Hard  |

## 📝 Notes

- Numbers must be unique
- Negative numbers are allowed
- Very large lists require smart algorithms
- Visualizers available for testing
