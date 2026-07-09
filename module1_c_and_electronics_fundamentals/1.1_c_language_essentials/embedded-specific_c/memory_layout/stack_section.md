Here's a document-style explanation of the **Stack Section** that you can directly add to your notes or GitHub repository.

# Stack Section in Memory Layout

## Introduction

The **stack** is a region of **RAM** used by the program during execution to manage **function calls**, **local variables**, **function parameters**, and **temporary data**. The stack is automatically managed by the CPU and compiler and follows the **Last In, First Out (LIFO)** principle.

Unlike the `.text`, `.data`, and `.bss` sections, the stack is dynamic and changes continuously during program execution.

---

## What is Stored in the Stack?

The stack typically stores:

* Local variables
* Function parameters
* Return addresses
* Saved CPU registers
* Temporary variables

---

## Basic Example

```c
#include <stdio.h>

void fun()
{
    int x = 10;    // Stored in stack
    printf("x = %d\n", x);
}

int main()
{
    int y = 20;    // Stored in stack
    fun();
    return 0;
}
```

### Stack Operation

When `main()` executes:

```
Stack
-----
y = 20
```

When `fun()` is called:

```
Stack
-----
x = 10
-----
y = 20
```

After `fun()` returns:

```
Stack
-----
y = 20
```

The memory occupied by `x` is automatically released.

---

## Function Parameters on Stack

```c
#include <stdio.h>

void add(int a, int b)
{
    int sum = a + b;
    printf("%d\n", sum);
}

int main()
{
    add(10,20);
    return 0;
}
```

The stack contains:

```
Stack Frame of add()
--------------------
sum = 30
b = 20
a = 10
return address
--------------------
```

After `add()` returns, the entire stack frame is removed.

---

## Nested Function Calls

```c
void C()
{
    int c = 30;
}

void B()
{
    int b = 20;
    C();
}

void A()
{
    int a = 10;
    B();
}

int main()
{
    A();
}
```

When `C()` executes:

```
Top of Stack
-------------
c = 30
-------------
b = 20
-------------
a = 10
-------------
return addresses
-------------
```

When `C()` returns, its stack frame is removed. Then `B()` returns, and its stack frame is removed.

---

## Recursive Function Example

```c
void fun(int n)
{
    if(n == 0)
        return;

    printf("%d\n", n);
    fun(n-1);
}
```

Calling:

```c
fun(3);
```

Creates stack frames:

```
fun(3)
fun(2)
fun(1)
fun(0)
```

Each function call creates a new stack frame.

---

## Stack Overflow Example

```c
void fun()
{
    int arr[100000];
    fun();
}
```

Since each recursive call allocates more stack memory, eventually the stack becomes full, resulting in a **stack overflow**.

---

## Characteristics of the Stack

| Property     | Description            |
| ------------ | ---------------------- |
| Memory Type  | RAM                    |
| Allocation   | Automatic              |
| Lifetime     | Until function returns |
| Growth       | Usually downward       |
| Access Speed | Very fast              |
| Managed By   | CPU and compiler       |

---

## Memory Layout

```
High Address
----------------
|    Stack     |  ↓ grows
----------------
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

## Advantages of Stack

* Fast memory allocation and deallocation
* Automatically managed
* Efficient function call handling
* No memory leaks

---

## Limitations of Stack

* Limited size
* Stack overflow can occur
* Data exists only during function execution

---

## Summary

* The stack is a region of RAM used for function execution.
* It stores local variables, function parameters, return addresses, and temporary data.
* It follows the Last In, First Out (LIFO) principle.
* The stack grows when functions are called and shrinks when they return.
* Excessive recursion or large local variables can cause stack overflow.

### One-line Definition

> The stack is a dynamic RAM region used to store local variables, function parameters, return addresses, and temporary data during program execution.


