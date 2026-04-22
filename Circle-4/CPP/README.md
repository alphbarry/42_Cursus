# 💻 CPP Modules (00-04)

## 📍 Overview

**CPP Modules 00-04** are beginner-level C++ projects in the 42 Cursus that cover fundamental object-oriented programming concepts. These modules teach basic C++ syntax, OOP principles, and standard library usage.

## 📚 Module Breakdown

### 🔷 CPP-00: Basics & I/O
- **Topics:** `std::cout`, input/output, basic types, functions
- **Concepts:** Stream objects, namespace, includes
- **Key Files:** `megaphone.cpp`

### 🔷 CPP-01: Memory Allocation & References
- **Topics:** `new`/`delete`, references vs pointers, memory management
- **Concepts:** Dynamic allocation, stack vs heap, reference semantics
- **Projects:** Memory allocation exercises

### 🔷 CPP-02: Ad-hoc Polymorphism & Fixed-Point Numbers
- **Topics:** Operator overloading, function overloading, fixed-point arithmetic
- **Concepts:** Overload operators, custom number types, type conversions
- **Key Classes:** Fixed-point number class

### 🔷 CPP-03: Inheritance & Polymorphism
- **Topics:** Class inheritance, protected members, virtual functions
- **Concepts:** Base/derived classes, method overriding, polymorphic behavior
- **Projects:** Inheritance hierarchies

### 🔷 CPP-04: Subtype Polymorphism & Abstract Classes
- **Topics:** Virtual functions, pure virtual functions, abstract classes
- **Concepts:** Polymorphic behavior, virtual destructors, interface design
- **Projects:** Complex inheritance structures

## 🎯 Learning Objectives

- **Object-Oriented Design:** Classes, inheritance, polymorphism
- **Memory Management:** Dynamic allocation, proper cleanup
- **Operator Overloading:** Customizing built-in operators
- **Type Conversion:** Implicit and explicit conversions
- **Encapsulation:** Public, protected, private access levels
- **STL Basics:** Standard containers and algorithms

## 📦 Project Structure

```
CPP/
├── CPP-00/
│   ├── ex00/
│   │   ├── Makefile
│   │   └── megaphone.cpp
│   ├── ex01/
│   │   ├── Makefile
│   │   ├── inc/
│   │   └── src/
│   └── ...
├── CPP-01/
│   ├── ex00/ - ex06/
│   │   ├── Makefile
│   │   ├── inc/          # Header files
│   │   └── src/          # Source files
│   └── ...
├── CPP-02/
│   ├── ex00/ - ex02/
│   └── ...
├── CPP-03/
│   ├── ex00/ - ex03/
│   └── ...
└── CPP-04/
    ├── ex00/ - ex03/
    └── ...
```

## 🚀 Compilation & Execution

### General Structure

Each exercise follows this pattern:

```bash
cd CPP-0X/exXX
make              # Compile
./program         # Run (executable name varies)
make clean        # Remove objects
make fclean       # Remove everything
make re           # Rebuild
```

### CPP-00 Example

```bash
cd CPP-00/ex00
make
./megaphone "hello world"
```

### CPP-01 Example

```bash
cd CPP-01/ex00
make
./memAllocation
```

## 🔑 Key C++ Concepts by Module

| Module | Main Concepts | Key Skills |
|--------|---------------|-----------|
| 00     | I/O, basics   | `cout`, `cin`, streams |
| 01     | Memory, refs  | `new/delete`, references |
| 02     | Overloading   | Operator overload, conversion |
| 03     | Inheritance   | Virtual functions, hierarchy |
| 04     | Polymorphism  | Abstract classes, pure virtual |

## 📝 Common Patterns

### Class Definition (CPP-01+)

```cpp
class MyClass {
private:
    int _value;

public:
    MyClass();                      // Constructor
    MyClass(const MyClass &obj);    // Copy constructor
    MyClass &operator=(const MyClass &obj);  // Assignment operator
    ~MyClass();                     // Destructor
    
    int getValue() const;           // Getter
    void setValue(int val);         // Setter
};
```

### Inheritance (CPP-03+)

```cpp
class Parent {
protected:
    int _protected_member;
public:
    virtual void method();
    virtual ~Parent();
};

class Child : public Parent {
public:
    virtual void method();
    ~Child();
};
```

### Operator Overloading (CPP-02+)

```cpp
class Fixed {
public:
    Fixed &operator++();            // Pre-increment
    Fixed operator++(int);          // Post-increment
    bool operator>(const Fixed &rhs) const;
    std::ostream &operator<<(std::ostream &out, const Fixed &obj);
};
```

## 📚 Standard Topics Covered

### CPP-00
- Streams and I/O
- Basic syntax and compilation
- Namespace usage

### CPP-01
- Pointers and references
- Memory allocation (`new`, `delete`)
- File I/O
- File pointers

### CPP-02
- Operator overloading (arithmetic, comparison, stream output)
- Fixed-point number class
- Type conversion (implicit/explicit)
- Increment operators

### CPP-03
- Inheritance basics
- Protected vs private inheritance
- Calling parent constructors
- Super class method calls

### CPP-04
- Virtual functions and methods
- Pure virtual functions (abstract classes)
- Virtual destructors
- Polymorphic behavior

## 🛡️ Coding Standards

- **Variable naming:** `_privateVar` format for private members
- **Efficient code:** Avoid unnecessary copies
- **Error handling:** Proper exceptions and validation
- **Memory safety:** No memory leaks, proper cleanup
- **Comments:** Clear documentation (French and English)

## 🧪 Testing

Each module includes multiple exercises with increasing complexity.

### Strategy
1. Start with basic concepts
2. Focus on understanding before optimization
3. Test edge cases
4. Review memory management carefully

## 🔧 Compilation Details

```bash
make              # Standard build
make clean        # Remove .o files
make fclean       # Remove all generated files (including executable)
make re           # Full rebuild
```

## 📝 Common Issues

- **Segmentation faults** - Usually memory management issues
- **Compilation errors** - Check const-correctness and signatures
- **Linking errors** - Ensure all source files are compiled
- **Runtime crashes** - Check virtual destructors in inheritance

## 💡 Best Practices

- Always write virtual destructors in polymorphic classes
- Use `const` for read-only methods
- Initialize all members in constructors
- Follow Orthodox Canonical Form (OCF) for classes
- Use `protected` for base class members accessed by derived classes
- Test with multiple compiler flags (`-Wall -Wextra -Werror`)

## 📖 Additional Resources

- C++ reference documentation
- Object-oriented design patterns
- Memory management best practices
- Operator overloading guidelines

## 📋 Exercise Checklist

- [ ] CPP-00: Basic I/O and functions
- [ ] CPP-01: Memory and references
- [ ] CPP-02: Operator overloading
- [ ] CPP-03: Inheritance
- [ ] CPP-04: Polymorphism and abstract classes

## 🎓 Next Steps

After completing these modules, progress to:
- **CPP-05:** Exceptions
- **CPP-06:** Type casting
- **CPP-07:** Templates
- **CPP-08:** Templated containers
- **CPP-09:** STL and algorithms
