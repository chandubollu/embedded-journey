If you want to understand the **memory layout of a C program** (`.text`, `.data`, `.bss`, stack, and heap), use the following demo program. It contains examples of every memory section.

```c
#include <stdio.h>
#include <stdlib.h>

/* .data section (initialized global variables) */
int global_init = 100;
static int static_init = 200;

/* .bss section (uninitialized global variables) */
int global_uninit;
static int static_uninit;

/* .text section (functions) */
void display(void)
{
    printf("\nInside display() function\n");
}

int main(void)
{
    /* stack section (local variables) */
    int local_var = 10;
    char ch = 'A';

    /* heap section (dynamic memory allocation) */
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 500;

    printf("=== Memory Layout Demo ===\n\n");

    printf(".data section:\n");
    printf("global_init      = %d, Address = %p\n",
           global_init, (void *)&global_init);
    printf("static_init      = %d, Address = %p\n",
           static_init, (void *)&static_init);

    printf("\n.bss section:\n");
    printf("global_uninit    = %d, Address = %p\n",
           global_uninit, (void *)&global_uninit);
    printf("static_uninit    = %d, Address = %p\n",
           static_uninit, (void *)&static_uninit);

    printf("\nStack section:\n");
    printf("local_var        = %d, Address = %p\n",
           local_var, (void *)&local_var);
    printf("ch               = %c, Address = %p\n",
           ch, (void *)&ch);

    printf("\nHeap section:\n");
    printf("*ptr             = %d, Address = %p\n",
           *ptr, (void *)ptr);

    printf("\n.text section:\n");
    printf("main() address   = %p\n", (void *)main);
    printf("display() address= %p\n", (void *)display);

    display();

    free(ptr);

    return 0;
}
```

### Example Output

(The addresses will be different on your system.)

```text
=== Memory Layout Demo ===

.data section:
global_init      = 100, Address = 0x601040
static_init      = 200, Address = 0x601044

.bss section:
global_uninit    = 0, Address = 0x601050
static_uninit    = 0, Address = 0x601054

Stack section:
local_var        = 10, Address = 0x7ffce1a1234c
ch               = A, Address = 0x7ffce1a1234b

Heap section:
*ptr             = 500, Address = 0x55f2b7d882a0

.text section:
main() address   = 0x401176
display() address= 0x401146
```

### Which variable goes where?

| Variable/Function | Memory Section | Reason                        |
| ----------------- | -------------- | ----------------------------- |
| `global_init`     | `.data`        | Global initialized variable   |
| `static_init`     | `.data`        | Static initialized variable   |
| `global_uninit`   | `.bss`         | Global uninitialized variable |
| `static_uninit`   | `.bss`         | Static uninitialized variable |
| `main()`          | `.text`        | Executable code               |
| `display()`       | `.text`        | Executable code               |
| `local_var`       | Stack          | Local variable                |
| `ch`              | Stack          | Local variable                |
| `ptr`             | Stack          | Pointer variable itself       |
| `*ptr` data       | Heap           | Dynamically allocated memory  |

### Typical Memory Layout

```text
High Address
+------------------+
|      Stack       |  ← local variables
|       ↓          |
+------------------+
|                  |
|                  |
+------------------+
|       Heap       |  ← malloc()
|       ↑          |
+------------------+
|      .bss        |  ← uninitialized globals/statics
+------------------+
|      .data       |  ← initialized globals/statics
+------------------+
|      .text       |  ← program instructions
+------------------+
Low Address
```

This single program demonstrates almost all important memory sections that an embedded C programmer needs to understand.
