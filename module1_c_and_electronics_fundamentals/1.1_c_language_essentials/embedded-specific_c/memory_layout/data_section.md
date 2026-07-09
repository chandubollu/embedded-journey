In the memory layout of a C program, the **`.data` section** stores **global and static variables that are initialized with a non-zero value**.

### Definition

The **`.data` segment** contains variables:

* Declared **outside functions** (global variables), or
* Declared with the `static` keyword,
* And **assigned an initial value**.

### Example

```c
#include <stdio.h>

int global_var = 10;        // Stored in .data
static int static_var = 20; // Stored in .data

int main()
{
    static int count = 5;   // Stored in .data
    printf("%d %d %d\n", global_var, static_var, count);
    return 0;
}
```

### Where is `.data` stored?

* **In the executable file (Flash/ROM)**: the initial values (`10`, `20`, `5`) are stored.
* **At program startup**: these values are copied to **RAM**.
* During execution, the variables reside in **RAM** and can be modified.

### Characteristics

* ✅ Initialized global and static variables
* ✅ Occupies space in both **ROM/Flash** and **RAM**
* ✅ Values can be changed during program execution
* ✅ Exists for the entire lifetime of the program


**Remember:**

> **`.data` = Initialized global/static variables stored in Flash initially and copied to RAM before `main()` starts.**
