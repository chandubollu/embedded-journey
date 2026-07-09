Here's a document-style explanation of the **Heap Section** that you can add to your notes.

# Heap Section in Memory Layout

## Introduction

The **heap** is a region of **RAM** used for **dynamic memory allocation**. Unlike the stack, where memory is allocated and deallocated automatically, memory in the heap is allocated and freed manually by the programmer.

The heap is used when the size of data is not known at compile time or when data needs to exist beyond the lifetime of a function.

---

## What is Stored in the Heap?

The heap stores:

* Dynamically allocated variables
* Arrays with runtime-determined size
* Structures allocated using dynamic memory functions
* Objects created during program execution

---

## Dynamic Memory Functions

In C, heap memory is managed using functions from `<stdlib.h>`:

```c id="1qnn83"
malloc()   // Allocate memory
calloc()   // Allocate and initialize memory to zero
realloc()  // Resize allocated memory
free()     // Release memory
```

---

## Basic Example

```c id="0mw1cr"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;

    ptr = (int *)malloc(sizeof(int));

    *ptr = 100;

    printf("%d\n", *ptr);

    free(ptr);

    return 0;
}
```

### Memory Allocation

```id="a8uh7o"
Stack                    Heap
-----                    -----
ptr  ------------------> 100
```

The pointer `ptr` is stored on the stack, while the actual integer value `100` is stored on the heap.

---

## Dynamic Array Example

```c id="smgz2r"
#include <stdlib.h>

int *arr;

arr = (int *)malloc(5 * sizeof(int));
```

Memory allocated:

```id="m27vgq"
Heap
----------------
arr[0]
arr[1]
arr[2]
arr[3]
arr[4]
----------------
```

---

## Structure Example

```c id="ctf9l2"
struct Student
{
    int id;
    float marks;
};

struct Student *s;

s = (struct Student *)malloc(sizeof(struct Student));
```

The structure object is stored in the heap.

---

## Memory Leak Example

```c id="cmujpw"
void fun()
{
    int *ptr;

    ptr = malloc(sizeof(int));

    *ptr = 10;

    // free(ptr); missing
}
```

Here, memory is allocated but never released, causing a **memory leak**.

---

## Characteristics of Heap

| Property    | Description              |
| ----------- | ------------------------ |
| Memory Type | RAM                      |
| Allocation  | Manual                   |
| Lifetime    | Until `free()` is called |
| Growth      | Usually upward           |
| Speed       | Slower than stack        |
| Managed By  | Programmer               |

---

## Heap vs Stack

| Feature     | Stack              | Heap        |
| ----------- | ------------------ | ----------- |
| Allocation  | Automatic          | Manual      |
| Speed       | Fast               | Slower      |
| Lifetime    | Function execution | Until freed |
| Size        | Limited            | Larger      |
| Memory Leak | Impossible         | Possible    |

---

## Memory Layout

```id="eei2yj"
High Address
----------------
|    Stack     |  ↓ grows
----------------
|              |
|              |
|    Heap      |  ↑ grows
----------------
|    .bss      |
----------------
|    .data     |
----------------
|    .text     |
----------------
Low Address
```

---

## Advantages of Heap

* Dynamic memory allocation
* Flexible memory usage
* Data can persist beyond function calls
* Useful for linked lists, trees, queues, and buffers

---

## Disadvantages of Heap

* Slower than stack
* Can cause memory leaks
* Can cause memory fragmentation
* Requires manual memory management

---

## Embedded Systems Note

In many microcontrollers, dynamic memory allocation (`malloc`, `free`) is avoided because:

* RAM is very limited
* Heap fragmentation can occur
* Memory leaks can crash the system
* Predictable memory usage is preferred

---

## Summary

* The heap is a region of RAM used for dynamic memory allocation.
* Memory is allocated using `malloc()`, `calloc()`, or `realloc()`.
* Memory remains allocated until `free()` is called.
* The heap provides flexibility but requires careful memory management.

### One-line Definition

> The heap is a RAM area used for dynamic memory allocation, where memory is manually allocated and released by the programmer.
