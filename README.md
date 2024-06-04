# 42_ft_printf

<p align="center">
    <img src="https://github.com/alx-sch/42_printf/assets/134595144/f0c52cd6-4282-4a69-9b03-5befc5335003" alt="libft" />
</p>

A custom implementation of a simplified printf() function, employing variadic macros to handle various format specifiers.

## Features

- **Variadic Format Handling:** Supports a variable number of arguments using variadic macros.
- **Format Specifiers:** Supports commonly used format specifiers for printf():
    - **%c:**        Character
    - **%s:**        String
    - **%p:**        Pointer
    - **%d, %i:**    Decimal (signed)
    - **%u:** Usigned Decimal
    - **%x, %X:** Hexadecimal
    - **%%:** Percentage Sign
 - **Inclusion of Libft:** Leverages existing libft functions to enhance code reusability, minimize redundancies, and ensure project coherence.
 - **Error Handling:** Manages invalid input formats in a controlled way.

## Variadic Functions
Variadic functions, also known as variable argument functions, allow users to pass different types and numbers of arguments to the function. Let's have a closer look at our variadic function ft_printf(), to understand this better:

- **Prototype:** `int ft_printf(const char *format, ...)`
    - `int`: The function's return type, representing the number of characters printed, including newline characters, excluding the NULL terminator (or '-1' in case of an error).
    - `const char *`: A pointer to the format string, which contains the content to be printed as well as format specifiers, working as placeholders.
    - `...`: The ellipsis (-> intentional omission of text) indicates that further arguments of any type and number can be accepted, also none. These arguments are expected to replace the format specifiers in the provided format string.
    - **Example Usage:**
      ```c
      int result = ft_printf("Hello, %s! You scored %d points.\n", "Betty", 42);
      // 'result' contains the number of characters printed by ft_printf() -> 36
      ```
        - In the printout, the variable arguments "Betty" (char *) and 42 (int) are formatted and replaced with the corresponding format specifiers %s and %d, respectively, in the provided format string.
- **Variadic Macros:**
    - `va_list`: A data type representing a list of arguments. The variable 'args' used below is declared of this type.
    - `va_start(args, format)`: Initializes the va_list 'args' to point to the first variable argument, which follows the 'format' string (in `int ft_printf(const char *format, ...)`, the first variable argument comes right after the 'format' parameter).
    - `va_arg(args, type)`: Retrieves the next argument from the va_list 'args' using the specified type. This macro allows you to iterate through the 'va_list' by calling it repeatedly, similar to the concept of iterating through lines with [get_next_line()](https://github.com/alx-sch/42_get_next_line).
    - `va_end(args)`: Cleans up the 'va_list' and should be called before the variadic function using va_start() returns.
 
## Error Handling 
It's important to recognize that the behavior of printf() may not be well-defined in certain edge cases, such as invalid format or argument inputs. Moreover, this behavior can vary depending on the platform of execution; I observed differences between Ubuntu and macOS in the following scenarios:

| Case | Command | Printout (Ubuntu) | Printout (macOS) |
| --- | --- | --- | --- |
| NULL pointer | `printf("->%p", (void*)ptr);`| `->(nil)` (Return: 7) | `->0x0` (Return: 5) |
| Invalid specifier | `printf("->%k", nbr);` | `->%k` (Return: 4) | `->k` (Return: 3) |
| % at EOF | `printf("->%");` | `->` (Return: -1) | `->` (Return: 2) |
| Space(s) between % and EOF | `printf("->%   ");` | `->` (Return: -1) | `->` (Return: 2) |
| Space(s) between % and invalid specifier | `printf("->%   k");` | `->% k` (Return: 5) | `->k` (Return: 3) |

**Specifications:**
- Ubuntu (v. 22.04) / x86_64
    ```bash
     gcc --version
     gcc (Ubuntu 10.5.0-1ubuntu1~22.04) 10.5.0
    ```
- macOS: Darwin (v. 23.3.0) / x86_64 (64-bit)
     ```bash
     gcc --version
     Apple clang version 15.0.0 (clang-1500.1.0.2.5)
    ```
     
In my project, I've implemented the error returns generated by printf() on Ubuntu. The function check_error() examines whether an encountered '%' in the format string is at the EOF or is exclusively followed by space characters. It stops printing and returns '-1' in such cases.

Regarding the representation of NULL pointers, I opted to print '(nil)'. Other edge cases resulting from unexpected user input were not explicitly considered.

## Testing
Several test cases, which compare the printout and return values of ft_printf() with those of the native printf(), are available in 'test_ft_printf.c'. After compiling the project's library, create the test program using the command `cc -o TEST test_ft_printf.c libftprintf.a`.

Note: The 'incomplete format specifier' warnings for printf() are expected as part of the testing process; please go ahead and ignore these.

