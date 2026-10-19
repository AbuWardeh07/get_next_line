*This activity has been created as part of the 42 curriculum by aabuward.*

# get_next_line

## Description

```c
char *get_next_line(int fd);
```

**Goal of the project:** learn how to read from a file descriptor with
`read()`, how to manage memory by hand (`malloc` / `free`), and how to keep
state between function calls using a **static variable**.

### Behavior

- Returns the next line from `fd`, **including** the trailing `\n` .
- The last line may have no `\n` at the end of the file.
- Returns `NULL` when there is nothing more to read, or when an error occurs.
- Works with files, standard input, and any other valid file descriptor.
- The size of each `read()` call is set at compile time with `BUFFER_SIZE`.


### How it works

- line : is variable represent the static var;
`read()` returns a fixed number of bytes (`BUFFER_SIZE`), which almost never
matches the end of a line. So the function:

1. Keeps leftover data in a **static variable** (a "line") that survives between calls.
2. Reads `BUFFER_SIZE` bytes at a time and appends them to the line
   until the line contains a `\n` or the end of the file is reached.
3. Extracts everything up to and including the first `\n` and returns it as the line.
4. Keeps the rest in the line for the next call.
5. Frees the line and returns `NULL` when nothing is left.

## Instructions

### Files

| File | Role |
|---|---|
| `get_next_line.c` | main function |
| `get_next_line_utils.c` | helper functions |
| `get_next_line.h` | prototypes and `BUFFER_SIZE` default |

### Compilation

`BUFFER_SIZE` is passed with `-D`:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=7 get_next_line.c get_next_line_utils.c main.c
```

### Usage

Always `free` each returned line, and `close` the file when you are done.

### Testing tips

- Open the file with `O_RDONLY`.
- Test an empty file, a file with only `\n`, a file without a final `\n`,
  very long lines, and an invalid fd (such as `-1`).
- Check for leaks with `valgrind --leak-check=full ./a.out`.
- Try several `BUFFER_SIZE` values, including `1`.

## Resources

- [Static variables in C](https://en.wikipedia.org/wiki/Static_variable)
- [File descriptors](https://en.wikipedia.org/wiki/File_descriptor)
- [about open file](https://pubs.opengroup.org/onlinepubs/9699919799/functions/open.html)
- [GeeksforGeeks](https://www.geeksforgeeks.org/)
- [Stack Overflow](https://stackoverflow.com/)
- [W3Schools](https://www.w3schools.com/)


**AI usage:** AI was used to understand file descriptors,
(`O_RDONLY`), and to debug an unallocated buffer in a test `main`.
The implementation of `get_next_line` was written and tested by me, 
and to format this README file.
