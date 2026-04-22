# 📚 Libft

## 📍 Overview

**Libft** is the first project of the 42 Cursus. Its objective is to recreate a set of standard C library functions, along with additional utility functions, to build a solid foundation in low-level programming.

This library will be reused throughout the cursus in more complex projects.

## 🎯 Objectives

- Understand and reimplement core C standard library functions  
- Master memory management and pointer manipulation  
- Work with strings, arrays, and linked lists  
- Write clean, modular, and reusable code  
- Follow strict coding standards (Norminette)

## 🛠️ Implemented Functions

### 🔤 Libc Functions
Reimplemented standard functions such as:

- `ft_strlen`
- `ft_strchr`
- `ft_strrchr`
- `ft_strncmp`
- `ft_memset`
- `ft_memcpy`
- `ft_memmove`
- `ft_memchr`
- `ft_memcmp`
- `ft_bzero`
- `ft_calloc`
- `ft_strdup`

### 🔍 Additional Functions

- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_itoa`
- `ft_strmapi`
- `ft_striteri`
- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

### 🔗 Bonus (Linked Lists)

- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`

## ⚙️ Compilation

To compile the library:

```bash
make
```

This will generate:
- `libft.a` - Static library archive

### Compilation Commands

```bash
make        # Compile library
make clean  # Remove object files (.o)
make fclean # Remove all generated files (objects + libft.a)
make re     # Full rebuild (fclean + make)
```

## 📦 Usage

### Include in Your Project

```c
#include "libft.h"
```

### Compile with Library

```bash
gcc main.c libft.a -o myprogram
```

Or with custom flags:

```bash
gcc -Wall -Wextra -Werror main.c libft.a -o myprogram
```

## 📁 Project Structure

```
libft/
├── Makefile          # Build automation
├── libft.h           # Header file with function declarations
├── ft_*.c            # Source files for each function
└── objects/ (generated)
    └── *.o           # Object files
```

## 🧠 Key Concepts Learned

- **Memory allocation** - `malloc()`, `free()`, avoiding memory leaks
- **Pointer arithmetic** - Address manipulation and dereferencing
- **String manipulation** - Character arrays, null termination
- **Data structures** - Linked list implementation
- **Code modularity** - Reusable, organized functions
- **Function declarations** - Header files and function prototypes
- **Static libraries** - Creating and linking `.a` files

## 📚 Example Usage

### Using String Functions

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char    str[] = "Hello World";
    size_t  len;
    char    *dup;

    len = ft_strlen(str);           // Get length: 11
    dup = ft_strdup(str);           // Duplicate string
    ft_putstr_fd(dup, 1);           // Print to stdout
    free(dup);                       // Free allocated memory
    return (0);
}
```

### Using Linked Lists (Bonus)

```c
#include "libft.h"

int main(void)
{
    t_list  *head;
    t_list  *new_node;

    head = NULL;
    new_node = ft_lstnew("Hello");       // Create new node
    ft_lstadd_front(&head, new_node);   // Add to front
    new_node = ft_lstnew("World");
    ft_lstadd_back(&head, new_node);    // Add to back
    
    ft_lstiter(head, print_function);   // Iterate through list
    ft_lstclear(&head, free);           // Clear entire list
    return (0);
}
```

## ⚠️ Notes

- ✅ All functions written in standard C (C89/C99)
- ✅ No external libraries allowed
- ✅ Code follows 42 Norm (Norminette strict style)
- ✅ Handles edge cases properly
- ✅ Memory-safe implementations
- ⚠️ Must manually manage all allocated memory with `free()`

## 📋 Function Categories

| Category | Count | Type |
|----------|-------|------|
| Libc functions | 13 | Mandatory |
| Additional functions | 11 | Mandatory |
| Linked lists | 9 | Bonus |
| **Total** | **33** | - |

## 🎓 Learning Outcomes

After completing this project, you will understand:
- How C standard library functions work internally
- Memory management and the heap
- Pointer usage and arithmetic
- Creating and using static libraries
- Building reusable code components
- Following strict coding conventions

## 📌 Status

✅ **Completed with bonus** - All mandatory and bonus functions implemented
