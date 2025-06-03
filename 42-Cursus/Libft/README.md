# 🔧 Libft - Custom C Library

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Grade](https://img.shields.io/badge/Grade-125%2F100-brightgreen?style=for-the-badge)
![Norminette](https://img.shields.io/badge/Norminette-OK-green?style=for-the-badge)

*Building the foundation of C programming*

</div>

## 📋 Table of Contents

- [About](#about)
- [Functions Implemented](#functions-implemented)
- [Compilation](#compilation)
- [Usage](#usage)
- [Testing](#testing)
- [Resources](#resources)

## 📖 About

**Libft** is the first project in the 42 curriculum that involves recreating essential C standard library functions from scratch. This project serves as the foundation for all future C projects at 42, teaching fundamental programming concepts like memory management, string manipulation, and linked lists.

### 🎯 Learning Objectives

- **Memory Management**: Understanding malloc, free, and memory allocation
- **String Manipulation**: Working with C strings and character arrays
- **Function Implementation**: Recreating standard library functions
- **Makefile**: Learning build automation
- **Code Standards**: Following 42's Norminette coding standard

## ⚙️ Functions Implemented

### Part 1 - Libc Functions

| Function | Description |
|----------|-------------|
| `ft_atoi` | Convert string to integer |
| `ft_bzero` | Zero out memory |
| `ft_calloc` | Allocate and zero memory |
| `ft_isalnum` | Check if alphanumeric |
| `ft_isalpha` | Check if alphabetic |
| `ft_isascii` | Check if ASCII |
| `ft_isdigit` | Check if digit |
| `ft_isprint` | Check if printable |
| `ft_memchr` | Locate byte in memory |
| `ft_memcmp` | Compare memory areas |
| `ft_memcpy` | Copy memory area |
| `ft_memmove` | Move memory area |
| `ft_memset` | Fill memory with byte |
| `ft_strchr` | Locate character in string |
| `ft_strdup` | Duplicate string |
| `ft_strlcat` | Concatenate strings |
| `ft_strlcpy` | Copy string |
| `ft_strlen` | Calculate string length |
| `ft_strncmp` | Compare strings |
| `ft_strnstr` | Locate substring |
| `ft_strrchr` | Locate character from end |
| `ft_tolower` | Convert to lowercase |
| `ft_toupper` | Convert to uppercase |

### Part 2 - Additional Functions

| Function | Description |
|----------|-------------|
| `ft_itoa` | Convert integer to string |
| `ft_putchar_fd` | Output character to fd |
| `ft_putendl_fd` | Output string + newline to fd |
| `ft_putnbr_fd` | Output number to fd |
| `ft_putstr_fd` | Output string to fd |
| `ft_split` | Split string by delimiter |
| `ft_striteri` | Apply function to each char |
| `ft_strjoin` | Join two strings |
| `ft_strmapi` | Apply function to string |
| `ft_strtrim` | Trim characters from string |
| `ft_substr` | Extract substring |

### Bonus Part - Linked Lists

| Function | Description |
|----------|-------------|
| `ft_lstadd_back` | Add element to end of list |
| `ft_lstadd_front` | Add element to front of list |
| `ft_lstclear` | Delete and free list |
| `ft_lstdelone` | Delete one element |
| `ft_lstiter` | Apply function to each element |
| `ft_lstlast` | Get last element |
| `ft_lstmap` | Apply function and create new list |
| `ft_lstnew` | Create new element |
| `ft_lstsize` | Count elements in list |

## 🔨 Compilation

```bash
# Compile the library
make

# Compile with bonus functions
make bonus

# Clean object files
make clean

# Full clean (remove libft.a)
make fclean

# Full recompilation
make re
```

## 🚀 Usage

### Basic Usage

```c
#include "libft.h"

int main(void)
{
    char *str = "Hello, 42!";
    char *dup = ft_strdup(str);
    
    ft_putstr_fd(dup, 1);
    ft_putchar_fd('\n', 1);
    
    free(dup);
    return (0);
}
```

### Compilation with Your Project

```bash
# Compile your program with libft
gcc -Wall -Wextra -Werror main.c -L. -lft -o program
```

### Advanced Example - Linked Lists

```c
#include "libft.h"

int main(void)
{
    t_list *list = NULL;
    
    // Create and add elements
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("First")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Second")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Third")));
    
    // Print list size
    ft_putnbr_fd(ft_lstsize(list), 1);
    ft_putchar_fd('\n', 1);
    
    // Clean up
    ft_lstclear(&list, free);
    return (0);
}
```

## 🧪 Testing

### Manual Testing

```c
// Test ft_strlen
assert(ft_strlen("Hello") == 5);
assert(ft_strlen("") == 0);

// Test ft_atoi
assert(ft_atoi("42") == 42);
assert(ft_atoi("-42") == -42);

// Test ft_split
char **result = ft_split("Hello,World,42", ',');
assert(strcmp(result[0], "Hello") == 0);
assert(strcmp(result[1], "World") == 0);
assert(strcmp(result[2], "42") == 0);
```

### External Testers

- [libft-unit-test](https://github.com/alelievr/libft-unit-test)
- [Tripouille/libftTester](https://github.com/Tripouille/libftTester)
- [jtoty/libftest](https://github.com/jtoty/libftest)

## 📚 Resources

### Documentation
- [C Standard Library Reference](https://en.cppreference.com/w/c)
- [Memory Management in C](https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm)

### 42 Resources
- [42 Norminette](https://github.com/42School/norminette)
- [Libft Subject PDF](https://cdn.intra.42.fr/pdf/pdf/960/libft.en.pdf)

## 🏆 Key Learnings

- **Memory Safety**: Proper allocation and deallocation
- **String Handling**: Safe string manipulation in C
- **Data Structures**: Understanding and implementing linked lists
- **Code Quality**: Writing clean, maintainable code following standards
- **Build Systems**: Using Makefiles effectively

---

<div align="center">

**Project completed as part of 42 School curriculum**

[![42](https://img.shields.io/badge/42-000000?style=flat-square&logo=42&logoColor=white)](https://www.42.fr/)

</div>
