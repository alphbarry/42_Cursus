# 📡 Minitalk

## 📍 Overview

**Minitalk** is a project in the 42 Cursus that implements inter-process communication (IPC) using UNIX signals. It teaches signal handling, bit manipulation, and client-server architecture.

## 🎯 Objectives

- Implement signal-based communication between processes
- Master signal handling (`SIGUSR1` and `SIGUSR2`)
- Transmit data bit-by-bit over signals
- Handle asynchronous communication
- Understand process IDs and signal masking

## 🛠️ Features

- **Server:**
  - Listens for incoming signals
  - Reconstructs messages from bit sequences
  - Displays received messages
  - Runs indefinitely

- **Client:**
  - Sends messages to server via signals
  - Transmits data bit-by-bit
  - Verifies message delivery
  - Handles server communication

- **Communication Mechanism:**
  - Uses `SIGUSR1` for bit 0
  - Uses `SIGUSR2` for bit 1
  - Builds characters from 8 bits
  - Confirms receipt with signals

## 📦 Project Structure

```
minitalk/
├── server.c       # Server program
├── client.c       # Client program
├── Makefile
└── libft/         # Custom C library functions
```

## 🚀 Compilation & Execution

### Compilation

```bash
make
```

This creates two executables: `server` and `client`

### Running

**Terminal 1 - Start Server:**

```bash
./server
```

Output: Server PID (e.g., `12345`)

**Terminal 2 - Send Message:**

```bash
./client 12345 "Hello from minitalk!"
```

## ⚙️ Protocol

1. Client gets server PID
2. Client converts each character to binary (8 bits)
3. For each bit:
   - Sends `SIGUSR1` if bit is 0
   - Sends `SIGUSR2` if bit is 1
   - Waits for server acknowledgment
4. Sends null terminator (special sequence)
5. Server reconstructs and displays message

## 🔑 Key Concepts

- **Signal Handling** - `sigaction()` for reliable signal handling
- **Bit Manipulation** - Extract and send individual bits
- **Process Communication** - PID-based targeting
- **Acknowledgment Protocol** - Ensures reliable delivery
- **Blocking/Non-blocking** - Signal handling patterns

## 📝 Signal Reference

- `SIGUSR1` - User-defined signal 1 (bit = 0)
- `SIGUSR2` - User-defined signal 2 (bit = 1)
- `SIGCHLD` - Child signal (optional, for confirmation)

## 🛡️ Edge Cases

- Handles very long messages
- Works with special characters
- Manages rapid signal sequences
- Handles multiple clients
- Prevents signal loss

## 🧪 Testing

```bash
# Test basic message
./client <PID> "Hello"

# Test with special characters
./client <PID> "!@#$%^&*()"

# Test with numbers
./client <PID> "42 is the answer"

# Test with empty string behavior
./client <PID> ""
```

## 📚 Learning Points

- Unix signals and signal handlers
- Bit-level data transmission
- Process synchronization
- Asynchronous programming
- Low-level system programming

## 🔧 Compilation Details

```bash
make        # Build both server and client
make clean  # Remove object files
make fclean # Remove executables and objects
make re     # Clean and rebuild
```

## 📝 Notes

- Server must be running before client sends messages
- Server PID is displayed when starting
- Message transmission is slow (bit-by-bit)
- Suitable for small messages (not for large data)
- Demonstrates fundamental IPC concepts
