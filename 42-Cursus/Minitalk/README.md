# 📡 Minitalk - Client-Server Communication

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Grade](https://img.shields.io/badge/Grade-125%2F100-brightgreen?style=for-the-badge)
![UNIX](https://img.shields.io/badge/UNIX-Signals-orange?style=for-the-badge)

*Inter-process communication using UNIX signals*

</div>

## 📋 Table of Contents

- [About](#about)
- [Features](#features)
- [How It Works](#how-it-works)
- [Compilation](#compilation)
- [Usage](#usage)
- [Examples](#examples)
- [Signal Handling](#signal-handling)
- [Testing](#testing)
- [Resources](#resources)

## 📖 About

**Minitalk** is a 42 School project that demonstrates inter-process communication (IPC) using UNIX signals. The project consists of a server that receives messages and a client that sends messages, communicating entirely through `SIGUSR1` and `SIGUSR2` signals.

### 🎯 Learning Objectives

- **UNIX Signals**: Understanding signal handling and inter-process communication
- **Process Management**: Working with process IDs (PIDs)
- **Binary Communication**: Converting characters to binary representation
- **Asynchronous Programming**: Handling asynchronous signal events
- **System Programming**: Low-level system calls and signal safety

## ✨ Features

- ✅ **Signal-Based Communication**: Uses only SIGUSR1 and SIGUSR2
- ✅ **Binary Transmission**: Sends characters bit by bit
- ✅ **Process Identification**: Server displays its PID for client connection
- ✅ **String Transmission**: Send complete strings between processes
- ✅ **Unicode Support**: Handles extended ASCII and Unicode characters
- ✅ **Acknowledgment System**: Server confirms message reception (bonus)
- ✅ **Multiple Clients**: Server can handle sequential client connections

## 🔧 How It Works

### Signal Mapping
- **SIGUSR1**: Represents binary `0`
- **SIGUSR2**: Represents binary `1`

### Communication Process
1. **Server startup**: Server starts and displays its PID
2. **Client connection**: Client connects using server's PID
3. **Character encoding**: Each character is converted to 8-bit binary
4. **Bit transmission**: Each bit is sent as a signal (SIGUSR1 or SIGUSR2)
5. **Character reconstruction**: Server rebuilds characters from received bits
6. **Message display**: Server displays the reconstructed message

### Binary Representation Example
```
Character 'A' (ASCII 65):
Binary: 01000001
Signals: SIGUSR1 SIGUSR2 SIGUSR1 SIGUSR1 SIGUSR1 SIGUSR1 SIGUSR1 SIGUSR2
```

## 🔨 Compilation

```bash
# Compile both server and client
make

# Compile only server
make server

# Compile only client
make client

# Compile bonus version
make bonus

# Clean object files
make clean

# Full clean
make fclean
```

## 🚀 Usage

### Basic Usage

```bash
# Terminal 1: Start the server
./server
# Output: Server PID: 12345

# Terminal 2: Send a message
./client 12345 "Hello, 42!"
```

### Bonus Usage (with acknowledgment)

```bash
# Terminal 1: Start the bonus server
./server_bonus
# Output: Server PID: 12345

# Terminal 2: Send a message with confirmation
./client_bonus 12345 "Hello, World!"
# Output: Message sent successfully!
```

## 💡 Examples

### Simple Message

```bash
# Start server
./server
Server PID: 1234
Waiting for messages...

# Send message from client
./client 1234 "42 School"

# Server output:
Received: 42 School
```

### Long Message

```bash
# Send a longer message
./client 1234 "This is a longer message to test the communication system."

# Server output:
Received: This is a longer message to test the communication system.
```

### Special Characters

```bash
# Send message with special characters
./client 1234 "Hello! 🚀 42 École #@$%"

# Server output:
Received: Hello! 🚀 42 École #@$%
```

### Multiple Messages

```bash
# Send multiple messages sequentially
./client 1234 "First message"
./client 1234 "Second message"
./client 1234 "Third message"

# Server output:
Received: First message
Received: Second message
Received: Third message
```

## ⚡ Signal Handling

### Server Signal Handler

```c
void signal_handler(int signal, siginfo_t *info, void *context)
{
    static int bit_count = 0;
    static unsigned char current_char = 0;
    
    (void)context;
    
    if (signal == SIGUSR2)
        current_char |= (1 << (7 - bit_count));
    
    bit_count++;
    
    if (bit_count == 8)
    {
        if (current_char == '\0')
        {
            write(1, "\n", 1);
            // Send acknowledgment (bonus)
            kill(info->si_pid, SIGUSR1);
        }
        else
        {
            write(1, &current_char, 1);
            // Send acknowledgment (bonus)
            kill(info->si_pid, SIGUSR2);
        }
        bit_count = 0;
        current_char = 0;
    }
}
```

### Client Signal Sending

```c
void send_char(pid_t server_pid, unsigned char c)
{
    int bit;
    
    for (bit = 7; bit >= 0; bit--)
    {
        if (c & (1 << bit))
            kill(server_pid, SIGUSR2);  // Send 1
        else
            kill(server_pid, SIGUSR1);  // Send 0
            
        usleep(100);  // Small delay to ensure signal delivery
    }
}

void send_string(pid_t server_pid, char *str)
{
    while (*str)
    {
        send_char(server_pid, *str);
        str++;
    }
    send_char(server_pid, '\0');  // Send null terminator
}
```

## 🧪 Testing

### Basic Functionality Test

```bash
#!/bin/bash

# Start server in background
./server &
SERVER_PID=$!

# Wait for server to start
sleep 1

# Get server PID from output
MINITALK_PID=$(ps aux | grep "./server" | grep -v grep | awk '{print $2}' | head -1)

# Test basic message
./client $MINITALK_PID "Test message"

# Test empty message
./client $MINITALK_PID ""

# Test special characters
./client $MINITALK_PID "!@#$%^&*()"

# Clean up
kill $SERVER_PID
```

### Performance Test

```bash
#!/bin/bash

# Test with large message
./server &
SERVER_PID=$!
sleep 1

MINITALK_PID=$(ps aux | grep "./server" | grep -v grep | awk '{print $2}' | head -1)

# Generate long message
LONG_MESSAGE=$(python3 -c "print('A' * 1000)")
time ./client $MINITALK_PID "$LONG_MESSAGE"

kill $SERVER_PID
```

### Signal Safety Test

```c
// Test signal handling edge cases
#include <signal.h>
#include <sys/wait.h>

void test_signal_safety(void)
{
    pid_t server_pid, client_pid;
    
    // Fork server process
    server_pid = fork();
    if (server_pid == 0)
    {
        execl("./server", "./server", NULL);
        exit(1);
    }
    
    sleep(1);  // Let server start
    
    // Fork multiple clients
    for (int i = 0; i < 5; i++)
    {
        client_pid = fork();
        if (client_pid == 0)
        {
            char message[100];
            sprintf(message, "Message from client %d", i);
            execl("./client", "./client", "server_pid", message, NULL);
            exit(1);
        }
    }
    
    // Wait for all clients
    for (int i = 0; i < 5; i++)
        wait(NULL);
        
    kill(server_pid, SIGTERM);
    wait(NULL);
}
```

## 🏗️ Implementation Details

### Project Structure

```
minitalk/
├── Makefile
├── server.c             # Server implementation
├── client.c             # Client implementation
├── minitalk.h           # Header file
├── server_bonus.c       # Bonus server with acknowledgment
├── client_bonus.c       # Bonus client with acknowledgment
└── minitalk_bonus.h     # Bonus header file
```

### Key Functions

```c
// Server functions
void setup_signal_handlers(void);
void signal_handler(int signal, siginfo_t *info, void *context);

// Client functions
void send_char(pid_t server_pid, unsigned char c);
void send_string(pid_t server_pid, char *str);
void acknowledgment_handler(int signal);  // Bonus

// Utility functions
int ft_atoi(char *str);
void ft_putstr(char *str);
void ft_putnbr(int n);
```

## 📚 Resources

### Documentation
- [UNIX Signals](https://man7.org/linux/man-pages/man7/signal.7.html)
- [Signal Handling](https://www.gnu.org/software/libc/manual/html_node/Signal-Handling.html)
- [Process Communication](https://www.tutorialspoint.com/inter_process_communication/index.htm)

### System Calls
- [`kill()`](https://man7.org/linux/man-pages/man2/kill.2.html) - Send signal to process
- [`signal()`](https://man7.org/linux/man-pages/man2/signal.2.html) - Set signal handler
- [`sigaction()`](https://man7.org/linux/man-pages/man2/sigaction.2.html) - Advanced signal handling
- [`getpid()`](https://man7.org/linux/man-pages/man2/getpid.2.html) - Get process ID

### 42 Resources
- [Minitalk Subject PDF](https://cdn.intra.42.fr/pdf/pdf/960/minitalk.en.pdf)
- [42 Norminette](https://github.com/42School/norminette)

## 🏆 Key Learnings

- **Signal Programming**: Mastering UNIX signal handling
- **Inter-Process Communication**: Understanding IPC mechanisms
- **Binary Operations**: Working with bitwise operations
- **Asynchronous Programming**: Handling non-blocking operations
- **Process Management**: Working with process IDs and signal delivery

## 🚧 Common Challenges

- **Signal Timing**: Ensuring proper signal delivery timing
- **Race Conditions**: Avoiding signal loss or corruption
- **Signal Safety**: Writing signal-safe code
- **Process Synchronization**: Coordinating client-server communication
- **Error Handling**: Managing invalid PIDs and signal failures

## 🎯 Bonus Features

- **Acknowledgment System**: Server confirms message reception
- **Unicode Support**: Handle extended character sets
- **Multiple Client Support**: Server can handle multiple clients
- **Error Reporting**: Client receives delivery confirmation

---

<div align="center">

**Project completed as part of 42 School curriculum**

[![42](https://img.shields.io/badge/42-000000?style=flat-square&logo=42&logoColor=white)](https://www.42.fr/)

</div>
