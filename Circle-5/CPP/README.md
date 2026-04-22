# 💻 CPP Modules (05-09)

## 📍 Overview

**CPP Modules 05-09** are intermediate to advanced C++ projects in the 42 Cursus that cover advanced object-oriented programming, templates, and the Standard Template Library (STL). These modules build upon the foundations from CPP-00 to CPP-04.

## 📚 Module Breakdown

### 🔶 CPP-05: Exceptions & Error Handling
- **Topics:** Try-catch blocks, custom exceptions, exception hierarchies
- **Concepts:** Exception safety, error handling, throwing and catching
- **Key Projects:** Form validation, exception classes, error scenarios

### 🔶 CPP-06: Type Casting & Type Safety
- **Topics:** `static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`
- **Concepts:** Compile-time vs runtime casting, type safety, scalar conversion
- **Key Projects:** Scalar type conversion, safe casting operations

### 🔶 CPP-07: Templates & Generic Programming
- **Topics:** Function templates, class templates, template specialization
- **Concepts:** Generic programming, template instantiation, compile-time polymorphism
- **Key Projects:** Template functions, template classes, container implementations

### 🔶 CPP-08: Templated Containers & Iterators
- **Topics:** Template containers, iterators, template methods
- **Concepts:** Container design, iterator patterns, range-based operations
- **Key Projects:** Stack, vector-like containers, template algorithms

### 🔶 CPP-09: STL, Algorithms & Best Practices
- **Topics:** STL containers, algorithms, functors, lambda functions (C++11)
- **Concepts:** Standard library mastery, functional programming, iterator patterns
- **Key Projects:** Sorting algorithms, RPN calculator, merge-insert sort optimization

## 🎯 Learning Objectives

- **Exception Handling:** Safe error management and recovery
- **Type Casting:** Safe and unsafe type conversions
- **Template Programming:** Generic and reusable code
- **STL Mastery:** Efficient use of containers and algorithms
- **Advanced OOP:** Complex design patterns and architectures
- **Performance Optimization:** Efficient template instantiation

## 📦 Project Structure

```
CPP/
├── CPP-05/
│   ├── ex00/         # Bureaucrat with exceptions
│   ├── ex01/         # (if bonus)
│   ├── ex02/         # Form system with validation
│   ├── ex03/         # Intern pattern
│   └── ...
├── CPP-06/
│   ├── ex00/         # Scalar Type Converter
│   ├── ex01/         # Identify real type
│   ├── ex02/         # Base conversion methods
│   └── ...
├── CPP-07/
│   ├── ex00/         # Function templates
│   ├── ex01/         # Template specialization
│   ├── ex02/         # Array templates
│   └── ...
├── CPP-08/
│   ├── ex00/         # Stack template
│   ├── ex01/         # Container with iterators
│   ├── ex02/         # MutantStack
│   └── ...
└── CPP-09/
    ├── ex00/         # RPN Calculator
    ├── ex01/         # Merge-Insert Sort (Ford-Johnson algorithm)
    ├── ex02/         # (if available)
    └── ...
```

## 🚀 Compilation & Execution

### General Pattern

```bash
cd CPP-0X/exXX
make              # Compile
./executable      # Run
make clean        # Remove objects
make fclean       # Remove all
make re           # Rebuild
```

### CPP-05 Example

```bash
cd CPP-05/ex02
make
./forms
```

### CPP-06 Example

```bash
cd CPP-06/ex00
make
./convert 42
./convert 42.5
./convert "hello"
```

### CPP-07 Example

```bash
cd CPP-07/ex00
make
./templates
```

### CPP-09 Example

```bash
cd CPP-09/ex00
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

## 🔑 Key C++ Concepts by Module

| Module | Main Concepts | Advanced Topics |
|--------|---------------|-----------------|
| 05     | Exceptions    | Error safety, custom exceptions |
| 06     | Type casting  | RTTI, safe conversions |
| 07     | Templates     | Generic programming, specialization |
| 08     | Containers    | Iterator patterns, template algorithms |
| 09     | STL/Algorithms| Functors, lambda, optimization |

## 📝 Code Patterns

### Exception Handling (CPP-05)

```cpp
try {
    if (invalid_condition)
        throw CustomException("Error message");
    // Normal code
} catch (const CustomException &e) {
    std::cerr << "Caught: " << e.what() << std::endl;
}
```

### Type Casting (CPP-06)

```cpp
// Safe downcast
Base *basePtr = new Derived();
Derived *derivedPtr = dynamic_cast<Derived*>(basePtr);
if (derivedPtr != nullptr) {
    // Safe to use
}

// Compile-time cast
int value = static_cast<int>(3.14);

// Const removal (careful!)
Type *ptr = const_cast<Type*>(constPtr);
```

### Function Templates (CPP-07)

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Usage
int max_int = max<int>(5, 3);
double max_double = max<double>(3.14, 2.71);
```

### Class Templates (CPP-07/08)

```cpp
template <typename T>
class Stack {
private:
    std::vector<T> _data;
public:
    void push(const T &value);
    T pop();
    bool isEmpty() const;
};

// Template specialization
template <>
class Stack<bool> {
    // Specialized implementation
};
```

### STL Algorithms (CPP-09)

```cpp
#include <algorithm>

std::vector<int> vec = {3, 1, 4, 1, 5};

// Sorting
std::sort(vec.begin(), vec.end());

// Finding
auto it = std::find(vec.begin(), vec.end(), 4);

// Transforming
std::transform(vec.begin(), vec.end(), vec.begin(),
               [](int x) { return x * 2; });

// Reduced
auto sum = std::reduce(vec.begin(), vec.end(), 0,
                       [](int a, int b) { return a + b; });
```

## 🛡️ Advanced Topics

### Exception Safety (CPP-05)
- **No-throw guarantee:** Function never throws
- **Strong guarantee:** All-or-nothing: either succeeds or leaves state unchanged
- **Basic guarantee:** On failure, valid but unspecified state
- **No guarantee:** Undefined behavior on failure

### Template Instantiation (CPP-07)
- **Explicit instantiation:** Manually instantiate templates
- **Implicit instantiation:** Compiler generates code
- **Template specialization:** Override for specific types
- **Partial specialization:** Override for partial constraints

### Iterator Categories (CPP-08)
- **Input iterators** - Read-only, single pass
- **Output iterators** - Write-only, single pass
- **Forward iterators** - Read/write, multiple passes
- **Bidirectional iterators** - Forward + backward
- **Random access iterators** - Random access capability

## 📚 Standard Library Components

### CPP-05
- `std::exception` - Base exception class
- Custom exception hierarchies
- Exception constructor/what() method

### CPP-06
- `static_cast<>()` - Compile-time safe cast
- `dynamic_cast<>()` - Runtime polymorphic cast
- `const_cast<>()` - Remove const qualifier
- `reinterpret_cast<>()` - Reinterpret bits

### CPP-07/08/09
- `std::vector<T>` - Dynamic array
- `std::list<T>` - Doubly-linked list
- `std::stack<T>` - LIFO container
- `std::queue<T>` - FIFO container
- `std::map<K, V>` - Key-value pairs
- `std::set<T>` - Unique sorted values
- `std::algorithm` - Algorithms (sort, find, transform, etc.)
- `std::functional` - Functors and function objects

## 🧪 Testing

### CPP-06 Test Examples

```bash
./convert 0
./convert -42
./convert 3.14
./convert "42"
./convert "inf"
./convert "nan"
```

### CPP-09 Algorithm Testing

```bash
./RPN "1 2 + 3 *"      # Output: 9
./RPN "5 1 2 + 4 * + 3 -"  # Complex RPN
```

## 💡 Best Practices

- **Exceptions:** Use for exceptional conditions, not control flow
- **Templates:** Prefer templates over macros or virtual functions
- **STL:** Use standard containers instead of custom implementations
- **Const-correctness:** Mark methods `const` when appropriate
- **Move semantics:** Implement move constructors for efficiency (C++11+)
- **RAII:** Resource acquisition is initialization principle

## 📊 Performance Optimization (CPP-09)

### Ford-Johnson Algorithm (Merge-Insert Sort)
- Optimal for large datasets with minimal comparisons
- Used in CPP-09 ex01
- Better average-case than quicksort, better worst-case than heapsort

### Algorithm Comparison

| Algorithm | Best | Average | Worst | Space |
|-----------|------|---------|-------|-------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Ford-Johnson | - | O(n log n) | O(n log n) | O(n) |

## 📝 Common Pitfalls

- **Memory leaks** - Forgetting to delete dynamically allocated objects
- **Exception safety** - Not properly handling exceptions
- **Template bloat** - Instantiating too many versions
- **Const-correctness** - Modifying const arguments
- **Iterator invalidation** - Using invalidated iterators after modifications

## 🎓 Progression Path

1. **CPP-05:** Learn exception handling for error management
2. **CPP-06:** Master type system and safe casting
3. **CPP-07:** Understand generic programming basics
4. **CPP-08:** Build advanced container abstractions
5. **CPP-09:** Leverage STL for optimization

## 📖 Key Algorithms (CPP-09)

- **RPN Evaluation:** Stack-based expression parsing
- **Merge-Insert Sort:** Optimal sorting algorithm
- **Dijkstra's Algorithm:** Shortest path (if available)
- **Binary Search:** Efficient searching

## 🔧 Compilation Tips

```bash
# Compile with maximum warnings
g++ -Wall -Wextra -Werror -std=c++98

# Or modern C++ (if allowed)
g++ -Wall -Wextra -Werror -std=c++11
```

## 📋 Module Checklist

- [ ] CPP-05: Exception handling and custom exceptions
- [ ] CPP-06: Type casting and RTTI
- [ ] CPP-07: Function and class templates
- [ ] CPP-08: Template containers and iterators
- [ ] CPP-09: STL mastery and algorithm optimization

## ✅ Completion Criteria

- All exercises compile without errors/warnings
- Code follows 42 norm standards
- Proper memory management (no leaks)
- Exception safety implemented
- All test cases pass
