# 🍽️ Philosophers

## 📍 Overview

**Philosophers** is a project in the 42 Cursus that implements the classic **Dining Philosophers Problem** using multithreading and synchronization. It teaches concurrent programming, mutex usage, deadlock prevention, and thread management in C.

## 🎯 Objectives

- Implement multithreading with POSIX threads (`pthread`)
- Master mutex locks for resource synchronization
- Prevent deadlocks and race conditions
- Manage philosopher lifecycle and states
- Handle timing and thread scheduling
- Implement thread-safe data structures

## 🧩 The Dining Philosophers Problem

### Problem Description

**Scenario:**
- `n` philosophers sit around a circular table
- Each philosopher has a fork on each side
- To eat, a philosopher needs **both forks** (left and right)
- Philosophers are in one of three states:
  - 🍽️ **Eating** - Has both forks
  - 😴 **Sleeping** - Thinking and resting
  - 🤔 **Thinking** - Waiting for forks

### Critical Issues

1. **Deadlock** - All philosophers hold one fork and wait for the other
2. **Starvation** - Some philosophers never get to eat
3. **Race Conditions** - Data races when accessing shared forks

### Solution

Using `pthread_mutex` to synchronize access to forks and careful state management.

## ⚙️ Key Features

### Core Features

- **Concurrency:** Utilizes POSIX threads (`pthread`) to simulate each philosopher
- **Synchronization:** Employs mutexes to manage access to shared resources (forks)
- **Deadlock Prevention:** Ensures all philosophers can eat without deadlock/starvation
- **Timing:** Monitors eating, sleeping, and death times accurately
- **Lifecycle Management:** Tracks philosopher states and death detection
- **Thread-Safe Logging:** Coordinates output from multiple threads

## 📦 Project Structure

```
Philosophers/
├── Makefile          # Build automation
├── README.md         # This file
├── inc/
│   └── philo.h       # Main header file with data structures
└── src/
    ├── main.c        # Entry point and main loop
    ├── inits.c       # Initialization (philosophers, mutexes, etc.)
    ├── threads.c     # Thread creation and management
    ├── forks.c       # Fork acquisition and release logic
    ├── death.c       # Death detection and monitoring
    └── utils.c       # Utility functions (time, output, etc.)
```

## 🚀 Compilation & Execution

### Compilation

```bash
make              # Compile the project
make clean        # Remove object files
make fclean       # Remove all generated files
make re           # Full rebuild
```

Creates executable: `philo`

### Usage

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [times_each_must_eat]
```

### Parameters

| Parameter | Type | Description |
|-----------|------|-------------|
| `number_of_philosophers` | int | Number of philosophers (1-200) |
| `time_to_die` | int | Time in ms before philosopher dies if not eating |
| `time_to_eat` | int | Time in ms to eat |
| `time_to_sleep` | int | Time in ms to sleep |
| `times_each_must_eat` | int | (Optional) Times each philosopher must eat; if 0/omitted, runs indefinitely |

### Examples

```bash
# 5 philosophers, must die if not eating in 800ms, eat for 200ms, sleep 200ms
# Each must eat 5 times before success
./philo 5 800 200 200 5

# 4 philosophers, 410ms to die, 200ms to eat, 200ms to sleep
# Runs until deadlock/starvation (no limit on meals)
./philo 4 410 200 200

# Classic test case
./philo 1 800 200 200
# Philosopher dies (only 1 fork available)

# Large number
./philo 200 800 200 200 2
```

## 🔄 Philosopher States

```
┌─────────────┐
│   THINKING  │ (Waiting for forks)
└──────┬──────┘
       │ (Acquires left fork)
       ▼
┌─────────────┐
│    EATING   │ (Has 2 forks)
└──────┬──────┘
       │ (Releases forks, time_to_eat elapsed)
       ▼
┌─────────────┐
│   SLEEPING  │ (Resting)
└──────┬──────┘
       │ (time_to_sleep elapsed)
       ▼
   (Back to THINKING)
```

## 🔑 Key Concepts

### Threading
- **pthread_create()** - Create new thread for each philosopher
- **pthread_join()** - Wait for thread completion
- **pthread_detach()** - Threads run independently

### Synchronization
- **pthread_mutex_t** - Mutex for fork protection
- **pthread_mutex_lock()** - Acquire fork
- **pthread_mutex_unlock()** - Release fork
- **pthread_mutex_init()** - Initialize mutex

### Timing
- **gettimeofday()** - Get current time
- **usleep()** - Sleep for microseconds
- **Timestamp tracking** - Monitor eating/death times

### Deadlock Prevention

**Common strategies:**
1. **Timeouts** - Set time limit for holding forks
2. **Ordering** - Always acquire forks in same order
3. **Resource hierarchy** - Lower-numbered forks first
4. **Monitor thread** - Separate thread checks for deaths

## 📚 Data Structures

### Philosopher State

```c
typedef struct s_philo
{
    int             id;              // Philosopher ID (0 to n-1)
    pthread_t       thread;          // Thread associated
    pthread_mutex_t left_fork;       // Left fork mutex
    pthread_mutex_t *right_fork;     // Right fork (philosopher to right)
    long            meals_eaten;     // Number of meals completed
    long            last_meal_time;  // Timestamp of last meal
    int             is_eating;       // Currently eating flag
    struct s_data   *data;           // Reference to global data
}   t_philo;
```

### Global Data

```c
typedef struct s_data
{
    int             num_philo;       // Number of philosophers
    long            time_to_die;     // Time before death (ms)
    long            time_to_eat;     // Duration of eating (ms)
    long            time_to_sleep;   // Duration of sleeping (ms)
    int             meals_required;  // Required meals per philosopher (-1 = infinite)
    long            start_time;      // Program start timestamp
    int             simulation_stop;  // Flag to stop simulation
    pthread_mutex_t print_mutex;     // Synchronize output
    pthread_mutex_t data_mutex;      // Protect shared data
    t_philo         *philosophers;   // Array of philosophers
}   t_data;
```

## 🧪 Testing

### Test Cases

```bash
# Basic 5 philosophers - classical test
./philo 5 800 200 200

# One philosopher - should die (no second fork)
./philo 1 800 200 200

# Limited meals - should terminate cleanly
./philo 5 800 200 200 3

# Tight timing - test deadlock prevention
./philo 3 100 50 50

# Single meal - quick test
./philo 4 410 200 200 1

# Large group
./philo 100 800 200 200 500
```

### Expected Output Format

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

## 🛡️ Race Conditions Prevented

1. **Fork access** - Mutex protects each fork
2. **Philosopher state** - Mutex protects state updates
3. **Output** - Print mutex prevents interleaved messages
4. **Death detection** - Monitored safely with timestamps

## 📊 Common Issues & Solutions

| Issue | Cause | Solution |
|-------|-------|----------|
| Quick starvation | Philosophers prioritized unfairly | Randomize fork acquisition |
| All philosophers die | Timing too tight | Increase time_to_die |
| Program hangs | Deadlock occurred | Implement lock ordering |
| Race conditions | Unsynchronized access | Use mutexes properly |
| High CPU usage | Busy-waiting | Use usleep() between checks |

## 💡 Implementation Tips

### Deadlock Prevention Strategies

```c
// Strategy 1: Resource Ordering (always pick lower fork first)
if (left_fork_id < right_fork_id)
    acquire(left_fork);  // Lower ID first
else
    acquire(right_fork);

// Strategy 2: Timeout on fork acquisition
if (pthread_mutex_timedlock(&fork, &timeout) == ETIMEDOUT)
    release_held_forks();

// Strategy 3: Even philosophers act differently
if (philosopher_id % 2 == 0)
    sleep(1);  // Stagger odd philosophers
```

### Efficient Timing

```c
// Get current time in milliseconds
long get_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

// Calculate elapsed time
long elapsed = get_time() - start_time;
if (elapsed > time_to_die)
    philosopher_died();
```

## 📝 Notes

- All code follows 42 Norm standards
- Must handle up to 200 philosophers
- Timing accuracy is critical (±10ms tolerance common)
- No data races or undefined behavior allowed
- Proper cleanup of mutexes and threads required
- Output must be chronological and consistent

## 🔧 Compilation Details

```bash
make              # Standard compilation
make clean        # Remove .o files
make fclean       # Remove executable and objects
make re           # Clean and rebuild
```

### Typical Compilation Command

```bash
gcc -Wall -Wextra -Werror -pthread -I./inc src/*.c -o philo
```

## 🎓 Learning Outcomes

After completing this project, you will understand:

- Multithreading fundamentals with pthreads
- Mutex locks and synchronization primitives
- Deadlock concepts and prevention techniques
- Race condition detection and prevention
- Process lifecycle and timing
- Concurrent programming challenges
- System-level debugging with threads

## 📈 Performance Considerations

- **Lock contention** - Many philosophers competing for forks
- **Context switching** - OS overhead with many threads
- **Cache locality** - Shared data access patterns
- **Scalability** - Maximum philosopher count

## 📚 Related Concepts

- **Semaphores** - Alternative synchronization primitive
- **Condition variables** - Wait for specific conditions
- **Reader-writer locks** - For different access patterns
- **Lock-free programming** - Atomic operations without locks

## ⚠️ Common Mistakes to Avoid

- Forgetting to initialize/destroy mutexes
- Holding locks too long
- Not releasing locks on all code paths
- Race conditions in philosopher state
- Inefficient polling instead of event-driven design
- Incorrect timestamp comparison

## 📌 Status

✅ **Completed** - Full implementation with deadlock prevention and all philosophers active
