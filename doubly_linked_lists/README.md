# 📘 C - Doubly Linked Lists

This project focuses on implementing and manipulating **doubly linked lists** in the C programming language as part of the Holberton School low-level programming curriculum.

## 📌 Learning Objectives

- Understand how doubly linked lists work
- Learn how to traverse and manipulate them from both directions
- Practice dynamic memory management with `malloc` and `free`
- Handle insertion, deletion, and retrieval operations in linked structures

## 🧱 Data Structure Used

```c
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;
