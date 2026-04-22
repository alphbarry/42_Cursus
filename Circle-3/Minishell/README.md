# 🐚 Minishell

## 📍 Overview

**Minishell** is a project in the 42 Cursus that involves implementing a simplified version of the UNIX shell (bash/sh). It teaches process management, file I/O redirection, command parsing, and system-level programming.

## 🎯 Objectives

- Implement a functional shell interpreter
- Parse and execute user commands
- Handle process creation and management (`fork`, `execve`)
- Implement I/O redirection (`>`, `>>`, `<`, `<<`)
- Parse command pipelines (`|`)
- Implement built-in shell commands
- Handle environment variables
- Manage signals properly

## 🛠️ Features

### Core Shell Features

- **Command Execution:**
  - Parse and execute external commands
  - Search for executables in `$PATH`
  - Handle arguments and quotes
  - Support for absolute and relative paths

- **Built-in Commands:**
  - `echo` - Print text with optional `-n` flag
  - `cd` - Change directory with support for `-`, old `$PWD`
  - `pwd` - Print working directory
  - `export` - Set environment variables
  - `unset` - Remove environment variables
  - `env` - Display environment variables
  - `exit` - Exit the shell with optional status code

- **I/O Redirection:**
  - `>` - Output redirection (truncate file)
  - `>>` - Output redirection (append to file)
  - `<` - Input redirection (read from file)
  - `<<` - Here-document (heredoc) support

- **Piping:**
  - `|` - Connect command output to next command input
  - Support for multiple pipes

- **Variable Expansion:**
  - `$VAR` - Expand environment variables
  - `$?` - Last command exit status
  - `${VAR}` - Extended variable syntax
  - Quote handling (`'`, `"`)

- **Signal Handling:**
  - `Ctrl+C` - Interrupt command (SIGINT)
  - `Ctrl+D` - Exit shell (EOF)
  - `Ctrl+\` - Quit (SIGQUIT)

## 📦 Project Structure

```
minishell/
├── Makefile              # Build automation
├── README.md
├── inc/
│   ├── minishell.h       # Main header file
│   └── structs.h         # Data structure definitions
├── src/
│   ├── main.c            # Entry point
│   ├── builtins/         # Built-in command implementations
│   │   ├── echo.c
│   │   ├── cd.c
│   │   ├── pwd.c
│   │   ├── export.c
│   │   ├── unset.c
│   │   ├── env.c
│   │   ├── exit.c
│   │   └── built_utils.c
│   ├── cmd/              # Command parsing and management
│   │   ├── cmd.c
│   │   ├── cmd_filler.c
│   │   ├── cmd_utils.c
│   │   └── cmd_exec_utils.c
│   ├── exec/             # Command execution
│   │   ├── cmd_exec.c
│   │   ├── exec_shell.c
│   │   └── tokens_exec.c
│   ├── expand/           # Variable and token expansion
│   │   ├── dollar_expand.c
│   │   ├── token_expand.c
│   │   ├── split_token.c
│   │   └── *_utils.c
│   ├── heredocs/         # Here-document handling
│   │   ├── heredocs.c
│   │   ├── get_hdocs.c
│   │   └── *_utils.c
│   ├── redirs/           # I/O redirection
│   │   ├── io_redirs.c
│   │   ├── hdoc_handling.c
│   │   └── *_utils.c
│   ├── tokens/           # Tokenization/parsing
│   │   ├── tokenize.c
│   │   ├── token_list.c
│   │   ├── tokens_error.c
│   │   └── *_utils.c
│   ├── signals/          # Signal handling
│   │   └── signals.c
│   └── utils/            # Utility functions
│       ├── env.c         # Environment management
│       ├── error.c       # Error handling
│       ├── clean.c       # Memory cleanup
│       └── *_utils.c
├── libs/                 # External libraries
│   ├── libft/            # Custom C library
│   ├── gnl/              # Get next line
│   └── Makefile
└── objects/              # Compiled object files (generated)
```

## 🚀 Compilation & Execution

### Compilation

```bash
make              # Compile the shell
make clean        # Remove object files
make fclean       # Remove all generated files
make re           # Full rebuild
```

Creates executable: `minishell`

### Running the Shell

```bash
./minishell
```

The shell prompt will appear and wait for commands.

### Examples

```bash
$ echo "Hello World"
Hello World

$ pwd
/home/user/minishell

$ ls -la | grep minishell
-rwxr-xr-x  user  group  minishell

$ cat < input.txt > output.txt

$ export MY_VAR=42
$ echo $MY_VAR
42

$ cd ..
$ pwd
/home/user

$ exit 0
```

## ⌨️ Command Examples

### Basic Commands

```bash
# Echo command
$ echo hello world
hello world

# With -n flag (no newline)
$ echo -n "no newline" && echo "next"
no newlinenext

# List files
$ ls -la

# Print working directory
$ pwd
```

### Environment Variables

```bash
# View all environment variables
$ env

# Set a variable
$ export PATH=/usr/bin:/bin

# Use a variable
$ echo $PATH

# Remove a variable
$ unset MY_VAR

# Check last command status
$ echo $?
0
```

### I/O Redirection

```bash
# Redirect output to file (truncate)
$ echo "hello" > file.txt

# Append to file
$ echo "world" >> file.txt

# Read from file
$ cat < file.txt

# Here-document
$ cat << EOF
This is a
multi-line
input
EOF
```

### Piping

```bash
# Simple pipe
$ ls -l | grep ".c"

# Multiple pipes
$ cat file.txt | grep "pattern" | wc -l

# Redirect at the end
$ ps aux | grep minishell > processes.txt
```

## 🔑 Key Concepts

### Process Management
- **fork()** - Create child process
- **execve()** - Execute command
- **wait()** / **waitpid()** - Wait for child process
- **exit()** - Terminate process

### File I/O
- **open()** - Open file descriptor
- **close()** - Close file descriptor
- **dup2()** - Redirect file descriptors
- **read()** / **write()** - File operations

### Signal Handling
- **signal()** / **sigaction()** - Set signal handlers
- **SIGINT** - Ctrl+C interrupt
- **SIGQUIT** - Ctrl+\ quit
- **SIGCHLD** - Child process termination

### Tokenization & Parsing
- **Lexical analysis** - Break input into tokens
- **Syntax analysis** - Validate command structure
- **Quote handling** - Single and double quotes
- **Variable expansion** - $VAR substitution

### Shell Features
- **Built-in commands** - Implemented internally
- **External commands** - Executed via execve
- **Redirections** - Input/output redirection
- **Pipes** - Inter-process communication

## 📚 Learning Points

- Understanding the Unix shell design
- Process creation and management
- File descriptor manipulation
- Signal handling and interrupts
- Parsing and tokenization
- Environment variable management
- Standard I/O redirection
- Command pipeline architecture

## 🛡️ Error Handling

The shell handles:
- Invalid commands with appropriate error messages
- File not found errors
- Permission denied errors
- Invalid redirections
- Broken pipes
- Syntax errors

## 🧪 Testing

### Test Various Features

```bash
# Test redirections
./minishell
$ echo "test" > file.txt
$ cat file.txt

# Test pipes
$ echo "hello world" | wc -w

# Test built-ins
$ export TEST=42
$ echo $TEST
$ unset TEST

# Test heredoc
$ cat << EOL
> multiple
> lines
> EOL

# Test directory navigation
$ cd ..
$ pwd
$ cd -
```

## ⚠️ Notes

- Implements a subset of bash functionality
- All code follows 42 Norm standards
- Proper memory management required
- Handles edge cases and error conditions
- Supports both interactive and non-interactive modes

## 🔧 Compilation Details

```bash
make              # Standard compilation
make clean        # Remove .o files
make fclean       # Remove executables and objects
make re           # Clean and rebuild all
```

### Compiler Flags

Usually compiled with:
```bash
gcc -Wall -Wextra -Werror -I./inc src/*.c libs/libft/libft.a -lreadline -o minishell
```

## 📊 Main Components

| Component | Files | Purpose |
|-----------|-------|---------|
| Tokenization | `tokens/` | Parse input into tokens |
| Expansion | `expand/` | Variable and token expansion |
| Redirection | `redirs/` | Handle I/O redirection |
| Execution | `exec/` | Execute parsed commands |
| Built-ins | `builtins/` | Implement shell built-ins |
| Utilities | `utils/` | Helper functions & env mgmt |

## 📝 Next Steps

After completing Minishell, explore:
- Full bash implementation
- Advanced shell features
- Job control
- Command history
- Terminal emulation

## 📌 Status

✅ **Completed** - Full shell implementation with all required features