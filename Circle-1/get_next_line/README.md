# 📖 get_next_line

## 📍 Overview

**get_next_line** is a project in the 42 Cursus that requires implementing a function to read a file line by line. This project teaches file I/O, buffer management, and dynamic memory allocation.

## 🎯 Objectives

- Read files line by line efficiently
- Manage static variables and buffers
- Handle multiple file descriptors simultaneously
- Learn file descriptor operations
- Implement memory-safe practices

## 🛠️ Features

- **Read lines from a file descriptor**
- **Handle multiple file descriptors** (static buffer per FD)
- **Configurable buffer size** (via `BUFFER_SIZE`)
- **Dynamic memory allocation** for lines of any length
- **Proper newline handling** (include `\n` in return value)
- **EOF and error handling**

## 📦 Project Structure

```
get_next_line/
├── get_next_line.c       # Main function implementation
├── get_next_line_utils.c # Helper functions
├── get_next_line.h       # Header file
└── Makefile (optional)
```

## 🚀 Usage

### Compilation

```bash
gcc -D BUFFER_SIZE=42 your_program.c get_next_line.c get_next_line_utils.c
```

### Function Signature

```c
char *get_next_line(int fd);
```

**Returns:**
- A string representing the next line from file descriptor `fd`
- `NULL` if EOF is reached or an error occurs
- Includes the newline character (`\n`) if present

### Example

```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## ⚙️ Configuration

- **BUFFER_SIZE:** Define buffer size at compile time
  - Default: 42 bytes
  - Can be changed: `-D BUFFER_SIZE=4096`
  - Affects performance and memory usage

## 🔑 Key Concepts

- **Static variables** - Retain buffer between function calls
- **File descriptors** - Manage multiple open files
- **Dynamic allocation** - Resize as needed for longer lines
- **Memory leaks** - Careful management and cleanup
- **Edge cases** - Empty files, no newline at EOF, etc.

## 📝 Notes

- Must handle `BUFFER_SIZE` as small as 1 byte
- Works with `/dev/urandom` (binary data)
- Should not allocate entire file into memory
- Each file descriptor maintains its own buffer state

## 🔧 Bonus Features (if applicable)

- Compile without `BUFFER_SIZE` defined (use default)
- Handle standard input (`fd = 0`)
- Work efficiently with large files
