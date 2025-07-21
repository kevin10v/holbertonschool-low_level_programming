# 📘 C - Singly Linked Lists

This project is part of the **Holberton School Low-Level Programming** curriculum. It focuses on the implementation and manipulation of **singly linked lists** in C.

## 📂 Project Structure

Directory: `singly_linked_lists`  
Repository: `holbertonschool-low_level_programming`

## ✅ Learning Objectives

- Understand what a linked list is
- Know how to build and traverse a singly linked list
- Handle dynamic memory allocation using `malloc` and `free`
- Use `struct`, `typedef`, and pointers effectively

## 🔧 Functions Implemented

### `0-print_list.c`
> Prints all elements of a `list_t` list  
**Prototype:** `size_t print_list(const list_t *h);`  
- Prints `[0] (nil)` if the string is `NULL`

### `1-list_len.c`
> Returns the number of elements in a `list_t` list  
**Prototype:** `size_t list_len(const list_t *h);`

### `2-add_node.c`
> Adds a new node at the beginning of a list  
**Prototype:** `list_t *add_node(list_t **head, const char *str);`

### `3-add_node_end.c`
> Adds a new node at the end of a list  
**Prototype:** `list_t *add_node_end(list_t **head, const char *str);`

### `4-free_list.c`
> Frees a `list_t` list  
**Prototype:** `void free_list(list_t *head);`

## 🧪 Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 <main_file.c> <source_file.c> -o <output_name>
