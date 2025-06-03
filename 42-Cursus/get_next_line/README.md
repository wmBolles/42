# 📖 get_next_line - File Reading Line by Line

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Grade](https://img.shields.io/badge/Grade-125%2F100-brightgreen?style=for-the-badge)
![Norminette](https://img.shields.io/badge/Norminette-OK-green?style=for-the-badge)

*Reading files efficiently, one line at a time*

</div>

## 📋 Table of Contents

- [About](#about)
- [Features](#features)
- [Function Prototype](#function-prototype)
- [Compilation](#compilation)
- [Usage](#usage)
- [Examples](#examples)
- [Buffer Size](#buffer-size)
- [Testing](#testing)
- [Resources](#resources)

## 📖 About

**get_next_line** is a 42 School project that teaches file handling and static variables in C. The goal is to create a function that reads a file line by line, regardless of the file size or line length, using a fixed buffer size.

### 🎯 Learning Objectives

- **Static Variables**: Understanding persistent variables between function calls
- **File Descriptors**: Working with file input/output operations
- **Memory Management**: Efficient buffer handling and memory allocation
- **Edge Cases**: Handling EOF, empty lines, and multiple file descriptors
- **Buffer Management**: Reading files with a configurable buffer size

## ✨ Features

- ✅ **Line-by-line Reading**: Reads one line at a time from any file
- ✅ **Multiple File Descriptors**: Can handle multiple files simultaneously
- ✅ **Configurable Buffer**: BUFFER_SIZE can be modified at compile time
- ✅ **Memory Efficient**: Minimal memory usage with proper cleanup
- ✅ **Edge Case Handling**: Manages EOF, empty files, and large files
- ✅ **Bonus Version**: Supports multiple file descriptors concurrently

## 🔧 Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters
- `fd`: File descriptor to read from

### Return Value
- **Success**: Returns the line read (including `\n` if present)
- **EOF**: Returns `NULL` when end of file is reached
- **Error**: Returns `NULL` on error (invalid fd, malloc failure, etc.)

## 🔨 Compilation

```bash
# Compile with default buffer size (usually 1024)
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

# Compile with custom buffer size
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c

# Compile bonus version (multiple file descriptors)
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

## 🚀 Usage

### Basic Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);
        
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}
```

### Reading Standard Input

```c
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char *line;
    
    printf("Enter lines (Ctrl+D to end):\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("You entered: %s", line);
        free(line);
    }
    
    return (0);
}
```

## 💡 Examples

### Reading a Complete File

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int fd;
    char *line;
    int line_count = 0;
    
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }
    
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    
    while ((line = get_next_line(fd)) != NULL)
    {
        line_count++;
        printf("Line %d: %s", line_count, line);
        free(line);
    }
    
    printf("\nTotal lines: %d\n", line_count);
    close(fd);
    return (0);
}
```

### Multiple File Descriptors (Bonus)

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1, fd2;
    char *line1, *line2;
    
    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    
    if (fd1 == -1 || fd2 == -1)
        return (1);
    
    // Read alternately from both files
    while (1)
    {
        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);
        
        if (!line1 && !line2)
            break;
            
        if (line1)
        {
            printf("File1: %s", line1);
            free(line1);
        }
        
        if (line2)
        {
            printf("File2: %s", line2);
            free(line2);
        }
    }
    
    close(fd1);
    close(fd2);
    return (0);
}
```

### Error Handling

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main(void)
{
    int fd;
    char *line;
    
    // Try to read from invalid file descriptor
    line = get_next_line(-1);
    if (!line)
        printf("Invalid file descriptor handled correctly\n");
    
    // Try to open non-existent file
    fd = open("nonexistent.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("File doesn't exist: %s\n", strerror(errno));
        return (1);
    }
    
    return (0);
}
```

## ⚙️ Buffer Size

The `BUFFER_SIZE` defines how many bytes are read from the file at once:

```bash
# Small buffer (byte by byte) - slower but memory efficient
gcc -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c

# Medium buffer - balanced performance
gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

# Large buffer - faster but uses more memory
gcc -D BUFFER_SIZE=8192 get_next_line.c get_next_line_utils.c
```

### Buffer Size Impact

| Buffer Size | Performance | Memory Usage | Use Case |
|-------------|-------------|--------------|----------|
| 1 | Slow | Minimal | Testing edge cases |
| 42 | Moderate | Low | Small files |
| 1024 | Good | Medium | General purpose |
| 8192+ | Fast | High | Large files |

## 🧪 Testing

### Basic Testing

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include <assert.h>

void test_basic_functionality(void)
{
    int fd;
    char *line;
    
    // Create test file
    fd = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    write(fd, "Line 1\nLine 2\nLine 3", 20);
    close(fd);
    
    // Test reading
    fd = open("test.txt", O_RDONLY);
    
    line = get_next_line(fd);
    assert(strcmp(line, "Line 1\n") == 0);
    free(line);
    
    line = get_next_line(fd);
    assert(strcmp(line, "Line 2\n") == 0);
    free(line);
    
    line = get_next_line(fd);
    assert(strcmp(line, "Line 3") == 0);
    free(line);
    
    line = get_next_line(fd);
    assert(line == NULL);
    
    close(fd);
}
```

### Edge Cases Testing

```c
void test_edge_cases(void)
{
    int fd;
    char *line;
    
    // Test empty file
    fd = open("empty.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    close(fd);
    
    fd = open("empty.txt", O_RDONLY);
    line = get_next_line(fd);
    assert(line == NULL);
    close(fd);
    
    // Test file with only newlines
    fd = open("newlines.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    write(fd, "\n\n\n", 3);
    close(fd);
    
    fd = open("newlines.txt", O_RDONLY);
    line = get_next_line(fd);
    assert(strcmp(line, "\n") == 0);
    free(line);
    close(fd);
}
```

### External Testers

- [Tripouille/get_next_lineTester](https://github.com/Tripouille/get_next_lineTester)
- [xicodomingues/francinette](https://github.com/xicodomingues/francinette)
- [harm-smits/gnl_tester](https://github.com/harm-smits/gnl_tester)

## 🏗️ Implementation Details

### Project Structure

```
get_next_line/
├── get_next_line.c          # Main function
├── get_next_line.h          # Header file
├── get_next_line_utils.c    # Helper functions
├── get_next_line_bonus.c    # Bonus: multiple fd support
├── get_next_line_bonus.h    # Bonus header
└── get_next_line_utils_bonus.c  # Bonus utilities
```

### Key Concepts

- **Static Variables**: Persist data between function calls
- **Buffer Management**: Efficiently handle partial reads
- **String Manipulation**: Join and split buffer contents
- **Memory Safety**: Prevent leaks and handle edge cases

## 📚 Resources

### Documentation
- [File Descriptors in Linux](https://www.tutorialspoint.com/unix/unix-file-management.htm)
- [Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/)
- [File I/O System Calls](https://man7.org/linux/man-pages/man2/read.2.html)

### 42 Resources
- [get_next_line Subject PDF](https://cdn.intra.42.fr/pdf/pdf/960/get_next_line.en.pdf)
- [42 Norminette](https://github.com/42School/norminette)

## 🏆 Key Learnings

- **Static Variables**: Understanding scope and lifetime
- **File I/O**: Low-level file operations in C
- **Buffer Management**: Efficient memory usage patterns
- **String Processing**: Advanced string manipulation techniques
- **Edge Case Handling**: Robust error management

## 🚧 Common Pitfalls

- **Memory Leaks**: Always free returned lines
- **Buffer Overflow**: Properly handle buffer boundaries
- **Static Variable Cleanup**: Manage memory in static variables
- **File Descriptor Validation**: Check for invalid fd values
- **EOF Handling**: Correctly detect end of file

---

<div align="center">

**Project completed as part of 42 School curriculum**

[![42](https://img.shields.io/badge/42-000000?style=flat-square&logo=42&logoColor=white)](https://www.42.fr/)

</div>
