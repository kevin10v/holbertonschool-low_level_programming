# C - Doubly Linked Lists

This project is part of the Holberton School's Low-Level Programming curriculum. It focuses on implementing and understanding **doubly linked lists** in C.

---

## 📚 Learning Objectives

By the end of this project, I am expected to be able to explain to anyone, **without using Google**:

- What is a doubly linked list
- How to use doubly linked lists
- How to navigate and manipulate a doubly linked list (both forward and backward)
- How to insert and delete nodes in a doubly linked list
- How to manage memory in linked lists

---

## ⚙️ Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- OS: Ubuntu 20.04 LTS
- Compilation: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- No use of global variables
- Max 5 functions per file
- Allowed functions: `malloc`, `free`, `printf`, `exit`
- All `.c` files should end with a new line
- Must follow [Betty style](https://github.com/holbertonschool/Betty) (coding and documentation)
- All function prototypes must be in the header file `lists.h`
- All header files must be include guarded

---

## 🧠 Data Structure Used

```c
/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;
📂 Project Structure
File	Description
0-print_dlistint.c	Prints all elements of a doubly linked list
1-dlistint_len.c	Returns the number of elements in the list
2-add_dnodeint.c	Adds a node at the beginning of the list
3-add_dnodeint_end.c	Adds a node at the end of the list
4-free_dlistint.c	Frees a doubly linked list
5-get_dnodeint.c	Gets the nth node of the list
6-sum_dlistint.c	Returns the sum of all elements in the list
7-insert_dnodeint.c	Inserts a node at a specific index
8-delete_dnodeint.c	Deletes a node at a specific index
lists.h	Header file with function prototypes and struct

🧪 Compilation Example

gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-print_dlistint.c -o a
./a

🔁 Author
Project provided by Holberton School. Exercises and testing managed by Julien Barbier.
