## `.bss` Section — Summary

* **`.bss`** stores **uninitialized** or **zero-initialized** global and static variables.

```c id="k4bgrk"
int x;          // .bss
static int y;   // .bss
int z = 0;      // .bss
```

* **`.bss` is not stored in ROM/Flash** because storing zeros wastes memory.
* Instead, the executable stores only the **size of the `.bss` section**.
* During startup, the system **allocates space in RAM** and **sets all `.bss` variables to zero** before `main()` starts.

### Example

```c id="ln9ex1"
char buffer[100000];   // .bss
```

Instead of storing **100,000 zeros in ROM**, the startup code simply does:

```text id="m4zw40"
Reserve 100000 bytes in RAM
Fill them with 0
```

### Comparison

| Section | Variables                                         | ROM | RAM |
| ------- | ------------------------------------------------- | --- | --- |
| `.data` | Initialized globals/statics                       | Yes | Yes |
| `.bss`  | Uninitialized or zero-initialized globals/statics | No  | Yes |

### Key Point

> **`.bss` saves ROM space by not storing zeros; the startup code clears the `.bss` section to zero in RAM before `main()` executes.**
