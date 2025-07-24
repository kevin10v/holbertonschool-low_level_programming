# File I/O - Low-Level Programming in C

This project focuses on practicing file input and output operations using system calls in C.

## Learning Objectives

- How to create, open, close, read, and write files using `open`, `read`, `write`, and `close`
- File descriptors and their role in Unix/Linux systems
- Permissions and how to set them
- What is the difference between a function and a system call
- How to handle errors using appropriate return codes

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- All files compiled on Ubuntu 14.04 LTS using `gcc 4.8.4`
- Code must follow Betty coding style
- Use only system calls: `read`, `write`, `open`, `close`

## File Descriptions

| File | Description |
|------|-------------|
| `0-read_textfile.c` | Reads a text file and prints it to the POSIX standard output |
| `1-create_file.c` | Creates a file with specified content and permissions |
| `2-append_text_to_file.c` | Appends text to the end of an existing file |
| `3-cp.c` | Copies the content of one file to another |
| `main.h` | Header file containing all prototypes used |

## Usage

Compile the programs with:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 <file>.c -o <output>
