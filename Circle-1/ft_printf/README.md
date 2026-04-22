# 🖨️ ft_printf

## 📍 Overview

**ft_printf** is a project in the 42 Cursus that involves recreating the `printf` function from the C standard library. It teaches parsing, variadic functions, and formatted output.

## 🎯 Objectives

- Understand and implement `printf` functionality
- Handle multiple format specifiers
- Master variadic functions in C
- Learn string parsing and formatting
- Handle edge cases and error management

## 🛠️ Features

- **Format Specifiers:**
  - `%c` - Character
  - `%s` - String
  - `%d` / `%i` - Integer
  - `%u` - Unsigned integer
  - `%x` / `%X` - Hexadecimal (lowercase/uppercase)
  - `%p` - Pointer address
  - `%%` - Percent sign

- **Flags and Modifiers:**
  - Width specifications
  - Precision
  - Left/right alignment
  - Zero padding

## 📦 Project Structure

```
ft_printf/
├── ft_printf.c       # Main printf function
├── ft_printf.h       # Header file
├── ft_basics.c       # Basic conversions (int, string, char)
├── ft_hexa.c         # Hexadecimal conversions
├── ft_puntero.c      # Pointer handling
└── Makefile
```

## 🚀 Usage

### Compilation

```bash
make
```

### Linking in other projects

```bash
gcc -o myprogram myprogram.c -L. -lftprintf
```

### Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you have %d points\n", "World", 42);
    return (0);
}
```

## 📋 Bonus Features (if applicable)

- `-` (left-align)
- `0` (zero-padding)
- `.precision`
- `#` (alternate form)

## 🔧 Compilation

```bash
make        # Compile library
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Recompile everything
```

## 📚 Learning Points

- Variadic functions (`va_list`, `va_arg`, etc.)
- String manipulation and formatting
- Character-by-character output handling
- Understanding printf's behavior and quirks

## 📝 Notes

- Function call: `int ft_printf(const char *format, ...)`
- Returns the number of characters printed
- Should handle edge cases and malformed format strings gracefully
