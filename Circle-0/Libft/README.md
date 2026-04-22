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
This will generate:

libft.a
📦 Usage

Include the header in your project:

#include "libft.h"

Compile with:

gcc main.c libft.a
📁 Project Structure
libft/
├── Makefile
├── libft.h
├── *.c
└── *.o
🧠 Key Concepts Learned
Memory allocation (malloc, free)
Pointer arithmetic
String manipulation
Data structures (linked lists)
Code modularity and reusability
⚠️ Notes
All functions are written in C
No use of external libraries allowed
Code follows 42 Norm (Norminette)
📌 Status

✅ Completed with bonus
