# 🖨️ ft_printf - Custom Printf Implementation

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Grade](https://img.shields.io/badge/Grade-100%2F100-green?style=for-the-badge)
![Norminette](https://img.shields.io/badge/Norminette-OK-green?style=for-the-badge)

*Recreating the versatile printf function*

</div>

## 📋 Table of Contents

- [About](#about)
- [Features](#features)
- [Supported Conversions](#supported-conversions)
- [Compilation](#compilation)
- [Usage](#usage)
- [Examples](#examples)
- [Testing](#testing)
- [Resources](#resources)

## 📖 About

**ft_printf** is a 42 School project that challenges students to recode the famous `printf` function from the C standard library. This project introduces variadic functions, format specifiers, and teaches how to handle different data types and formatting options.

### 🎯 Learning Objectives

- **Variadic Functions**: Understanding functions with variable arguments
- **Format Parsing**: Handling format specifiers and flags
- **Type Conversion**: Converting different data types to strings
- **Buffer Management**: Efficient output handling
- **Edge Cases**: Handling NULL pointers, overflow, and special cases

## ✨ Features

- ✅ **Multiple Format Specifiers**: c, s, p, d, i, u, x, X, %
- ✅ **Variadic Arguments**: Handles variable number of arguments
- ✅ **Memory Safe**: No memory leaks or segmentation faults
- ✅ **Norminette Compliant**: Follows 42's coding standards
- ✅ **Libft Integration**: Uses custom library functions

## 🔧 Supported Conversions

| Specifier | Type | Description | Example |
|-----------|------|-------------|---------|
| `%c` | char | Single character | `ft_printf("%c", 'A')` → `A` |
| `%s` | char* | String | `ft_printf("%s", "Hello")` → `Hello` |
| `%p` | void* | Pointer address | `ft_printf("%p", ptr)` → `0x7fff5fbff710` |
| `%d` | int | Signed decimal | `ft_printf("%d", 42)` → `42` |
| `%i` | int | Signed integer | `ft_printf("%i", -42)` → `-42` |
| `%u` | unsigned int | Unsigned decimal | `ft_printf("%u", 42u)` → `42` |
| `%x` | unsigned int | Lowercase hex | `ft_printf("%x", 255)` → `ff` |
| `%X` | unsigned int | Uppercase hex | `ft_printf("%X", 255)` → `FF` |
| `%%` | - | Literal % | `ft_printf("%%")` → `%` |

## 🔨 Compilation

```bash
# Compile the library
make

# Clean object files
make clean

# Full clean
make fclean

# Recompile
make re
```

## 🚀 Usage

### Function Prototype

```c
int ft_printf(const char *format, ...);
```

### Basic Usage

```c
#include "ft_printf.h"

int main(void)
{
    int count;
    
    // Basic usage
    count = ft_printf("Hello, World!\n");
    ft_printf("Characters printed: %d\n", count);
    
    return (0);
}
```

### Compilation with Your Project

```bash
# Compile your program with ft_printf
gcc -Wall -Wextra -Werror main.c -L. -lftprintf -o program
```

## 💡 Examples

### String and Character Output

```c
#include "ft_printf.h"

int main(void)
{
    char *name = "42 Student";
    char grade = 'A';
    
    ft_printf("Student: %s\n", name);           // Student: 42 Student
    ft_printf("Grade: %c\n", grade);            // Grade: A
    ft_printf("Literal: %%\n");                 // Literal: %
    
    return (0);
}
```

### Numeric Conversions

```c
#include "ft_printf.h"

int main(void)
{
    int number = 42;
    unsigned int positive = 42u;
    
    ft_printf("Decimal: %d\n", number);         // Decimal: 42
    ft_printf("Integer: %i\n", -number);        // Integer: -42
    ft_printf("Unsigned: %u\n", positive);      // Unsigned: 42
    ft_printf("Hex lower: %x\n", 255);          // Hex lower: ff
    ft_printf("Hex upper: %X\n", 255);          // Hex upper: FF
    
    return (0);
}
```

### Pointer Output

```c
#include "ft_printf.h"

int main(void)
{
    int value = 42;
    int *ptr = &value;
    char *str = "Hello";
    
    ft_printf("Pointer: %p\n", ptr);            // Pointer: 0x7fff5fbff710
    ft_printf("String pointer: %p\n", str);     // String pointer: 0x...
    ft_printf("NULL pointer: %p\n", NULL);      // NULL pointer: (nil)
    
    return (0);
}
```

### Mixed Format Usage

```c
#include "ft_printf.h"

int main(void)
{
    char *name = "Alice";
    int age = 25;
    unsigned int score = 98765;
    
    ft_printf("Player: %s, Age: %d, Score: %u (0x%X)\n", 
              name, age, score, score);
    // Output: Player: Alice, Age: 25, Score: 98765 (0x181CD)
    
    return (0);
}
```

## 🧪 Testing

### Manual Testing

```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ft_ret, std_ret;
    
    // Compare with standard printf
    ft_ret = ft_printf("ft_printf: %d %s %c\n", 42, "test", 'X');
    std_ret = printf("printf:    %d %s %c\n", 42, "test", 'X');
    
    ft_printf("ft_printf returned: %d\n", ft_ret);
    printf("printf returned: %d\n", std_ret);
    
    return (0);
}
```

### Edge Cases Testing

```c
#include "ft_printf.h"

int main(void)
{
    // NULL string
    ft_printf("NULL string: %s\n", NULL);       // NULL string: (null)
    
    // Zero values
    ft_printf("Zero: %d %u %x %X\n", 0, 0, 0, 0); // Zero: 0 0 0 0
    
    // Negative numbers
    ft_printf("Negative: %d\n", -2147483648);   // Negative: -2147483648
    
    // Large unsigned
    ft_printf("Max uint: %u\n", 4294967295u);   // Max uint: 4294967295
    
    return (0);
}
```

### External Testers

- [Tripouille/printfTester](https://github.com/Tripouille/printfTester)
- [paulo-santana/ft_printf_tester](https://github.com/paulo-santana/ft_printf_tester)
- [cacharle/ft_printf_test](https://github.com/cacharle/ft_printf_test)

## 🏗️ Implementation Details

### Project Structure

```
ft_printf/
├── ft_printf.c          # Main function
├── ft_printf.h          # Header file
├── Makefile            # Build configuration
└── fmt/                # Format handling functions
    ├── ft_format_char.c
    ├── ft_format_string.c
    ├── ft_format_pointer.c
    ├── ft_format_decimal.c
    ├── ft_format_unsigned.c
    └── ft_format_hex.c
```

### Key Functions

```c
// Main printf function
int ft_printf(const char *format, ...);

// Format handlers
int ft_format_char(va_list args);
int ft_format_string(va_list args);
int ft_format_pointer(va_list args);
int ft_format_decimal(va_list args);
int ft_format_unsigned(va_list args);
int ft_format_hex(va_list args, int uppercase);
```

## 📚 Resources

### Documentation
- [Variadic Functions in C](https://en.cppreference.com/w/c/variadic)
- [printf Format Specifiers](https://cplusplus.com/reference/cstdio/printf/)
- [stdarg.h Reference](https://en.cppreference.com/w/c/variadic)

### 42 Resources
- [ft_printf Subject PDF](https://cdn.intra.42.fr/pdf/pdf/960/ft_printf.en.pdf)
- [42 Norminette](https://github.com/42School/norminette)

## 🏆 Key Learnings

- **Variadic Functions**: Using va_start, va_arg, va_end
- **Format Parsing**: Analyzing format strings character by character
- **Type Safety**: Properly handling different data types
- **Memory Management**: Avoiding leaks in complex scenarios
- **Error Handling**: Managing edge cases and invalid inputs

## 🚧 Bonus Ideas

- Field width and precision handling
- Flag modifiers (-, +, #, 0, space)
- Additional conversion specifiers
- Color formatting support

---

<div align="center">

**Project completed as part of 42 School curriculum**

[![42](https://img.shields.io/badge/42-000000?style=flat-square&logo=42&logoColor=white)](https://www.42.fr/)

</div>
