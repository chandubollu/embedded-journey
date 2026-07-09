##### memory layout
- why should we care about how the memory is layed out?
- what pieces of our program  go where?
the critical reason is if we know that 
- our program is layed out on a layer of os what will happen?
- if a program is running on a bare metal what is happen?
basically we have 4 sections to care about in terms of memory layout
1. bss
2. data section
3. text section
4. stack
we are talking about stack we also think of heap .but in typical embedded program what happens is you generally don't rely on dynamic allocation.because the behaviour of dynamic allocation is unpredictable.
let's say if you have code which is running on very
limmited resource which is typically the case with embedded systems.
if you allow dynamic memory allocation there you might run into a situation where the heap is sort of running out of memory and you might run into very weird scenarios which puts the system generally.
- in order to avoid it.what programmers typically do is pre-calculate how much memory the program is going to need and it's fairly easy todo you have some tools which ae part of gcc tools available to do that.
- once you know the maximum amount of memory the program is going to use,you preallocate in the ram
itself.
- you never bothered about dynamically getting the memory and hence ou don't need the heap and another advantage is because you naver going to need the heap.you can remove that dynamic allocation code or the heap management libraries from your gcc .and save space there.
##### example1
```c
#include<stdio.h>
int x=11;
int y;
int main()
{
    static m=100;
    int a=10;
    printf("%d\n",x);
    int b;
    return a+b;
}
```
- here x is initialed with 11 in the global scope.
- here y is not initialized in the global scope.
- here a is initialized with 10 in the local scope.
- here b is not initialized in the local scope.
- c standsrds suggest thst any non-initialized globals are default initialized to zero.
- lets think of your code executing the first line inside the main function.
- int a=10;
-at any point within the main program if you choose to use or print x ,the answer will be printed as 11.
- who initializes the x memory location to 11,because our code is not doing that?
- where is this x=11 is stored?
- if you are running on top of an os which is user space code which generally you know
- if c code is running on an os environment it is called the hosted environment.
- and the baremetal environment is called free standing environment.
- in hosted environment os loads it.
- in freestanding environment hardware programmers put the compiled binary code into memory.
- the 11 goes and takes place in the data section.
- in data section : initialized globals,static variables with in the body of the function.
This is one of the **most important concepts** in Embedded C. If you understand **`.data`, `.bss`, ROM, and RAM**, you'll understand what happens before `main()` starts.

---

# Step 1: ROM vs RAM

Every microcontroller has two main types of memory.

```text
                 Microcontroller

      +-------------------------------+
      |             CPU               |
      +-------------------------------+

      ROM (Flash)               RAM (SRAM)
+--------------------+     +--------------------+
| Program Code       |     | .data             |
| Initial Values     |     | .bss              |
| const Data         |     | Heap              |
| String Literals    |     | Stack             |
+--------------------+     +--------------------+
```

## ROM (Flash)

* Permanent memory
* Stores your program
* Stores initial values of global variables
* Stores constants (`const`)
* Keeps data even after power OFF

Example:

```c
const int max = 100;
```

`max` stays in Flash.

---

## RAM (SRAM)

* Temporary memory
* Used while the program runs
* Loses contents after power OFF

RAM contains:

* `.data`
* `.bss`
* Heap
* Stack

---

# Step 2: What is `.data`?

`.data` stores **initialized global and static variables**.

Example:

```c
int x = 10;
static int y = 20;
```

Both have initial values.

During execution:

```text
RAM

.data
---------
x = 10
y = 20
```

---

## But where are these values before the program starts?

Initially, they are stored in Flash.

```text
Flash

Initial values
--------------
x = 10
y = 20
```

During startup,

the startup code copies them into RAM.

```text
Flash                     RAM

x =10  ------------->   x =10
y =20                 y =20
```

Why?

Because your program needs to modify them.

Example:

```c
x++;
```

Flash cannot be written like normal RAM during program execution, so writable variables must live in RAM.

---

# Step 3: What is `.bss`?

`.bss` stores **uninitialized global and static variables**.

Example:

```c
int count;
static int flag;
```

You didn't give any value.

C automatically initializes them to zero.

Equivalent to

```c
int count = 0;
```

Memory after startup:

```text
RAM

.bss
--------
count =0
flag =0
```

---

## Why aren't zeros stored in Flash?

Suppose you have

```c
int bigArray[1000];
```

This is about **4000 bytes**.

If Flash stored 4000 bytes of zeros, it would waste Flash space.

Instead, the startup code simply clears the `.bss` section in RAM.

```text
RAM

Before startup

??????
??????

↓

Startup clears memory

000000
000000
```

This is much more efficient.

---

# Step 4: Startup Process

Suppose your program is

```c
#include <stdio.h>

int x = 10;
int y;
const int z = 50;

int main()
{
    int a = 20;
}
```

---

## Before Power ON

Flash contains

```text
Flash

Program Code

x initial value =10

z =50
```

RAM

```text
??????????
```

Nothing useful yet.

---

## After Reset

The microcontroller executes startup code (before `main()`).

### Step 1

Copy `.data`

```text
Flash                  RAM

x=10 -------------> x=10
```

---

### Step 2

Clear `.bss`

```text
RAM

y=0
```

---

### Step 3

Initialize Stack Pointer

```text
RAM

Top of RAM

↓

Stack Pointer
```

---

### Step 4

Call `main()`

Now

```c
int a=20;
```

is created on the stack.

---

# Complete Memory Diagram

```text
                 FLASH (ROM)

+--------------------------------+
| Program Instructions           |
|                                |
| const variables                |
| String literals                |
| Initial value of x =10         |
+--------------------------------+


              |
              | Copy .data
              |
              V


                 RAM (SRAM)

+--------------------------------+
| .data                          |
| x =10                          |
+--------------------------------+

| .bss                           |
| y =0                           |
+--------------------------------+

| Heap                           |
|                                |
| Free Memory                    |
|                                |
| Stack                          |
| a=20                           |
+--------------------------------+
```

---

# Why `.data` Needs Flash and RAM

Example:

```c
int counter = 5;
```

When the chip is powered off:

* RAM loses everything.
* Flash still remembers the initial value (`5`).

Every reset:

```text
Flash

counter=5

↓

Copy

↓

RAM

counter=5
```

Then your program can do:

```c
counter++;
```

Now RAM contains

```text
counter=6
```

Flash still contains

```text
counter=5
```

until you explicitly reprogram the Flash.

---

# Why `.bss` Exists

Example:

```c
int buffer[10000];
```

If Flash stored 10,000 zeros:

```text
000000000000000000...
```

it would waste Flash memory.

Instead,

Flash stores **nothing** for `buffer`.

At startup:

```text
RAM

??????????

↓

Startup clears memory

000000000
```

This saves Flash space and speeds up program loading.

---

# Interview Question

### Where is this variable stored?

```c
int x = 10;
```

**Answer:**

* Initial value (`10`) is stored in **Flash (ROM)**.
* During startup, it is copied to the **`.data` section in RAM**.
* The program accesses and modifies the RAM copy.

---

### Where is this stored?

```c
int y;
```

**Answer:**

* It is allocated in the **`.bss` section of RAM**.
* Startup code initializes it to `0`.
* No storage is required in Flash for its initial value.

---

# Summary

| Memory/Section  | Contents                                                                | Located In | Initialized By                        |
| --------------- | ----------------------------------------------------------------------- | ---------- | ------------------------------------- |
| **Flash (ROM)** | Program code, `const` data, string literals, initial values for `.data` | ROM        | Programmer (during flashing)          |
| **`.data`**     | Initialized global/static variables                                     | RAM        | Startup code copies values from Flash |
| **`.bss`**      | Uninitialized global/static variables (become `0`)                      | RAM        | Startup code clears to zero           |
| **Heap**        | Dynamic memory (`malloc`)                                               | RAM        | Runtime                               |
| **Stack**       | Local variables, function parameters, return addresses                  | RAM        | Runtime                               |

### Key idea to remember

```text
Flash (ROM)
----------------------------
Program code
const data
Initial values of .data
----------------------------
           |
           |  Startup code
           |  (before main())
           V
RAM (SRAM)
----------------------------
.data  ← initialized globals/statics
.bss   ← zero-initialized globals/statics
Heap
Stack
----------------------------
```

This startup sequence—**copy `.data` from Flash to RAM, clear `.bss` to zero, set up the stack, then call `main()`**—is fundamental to how almost every embedded C program begins execution.


