# Study Notes: Linker Scripts and Memory Placement in Embedded C

## 1. Introduction to Linker Scripts
### Brief Explanation
A **Linker Script** is a plain text file that acts as a blueprint for the linker. It explains exactly how different parts of your compiled code (object files) should be combined and where they should be placed in the physical memory of your microcontroller. It is crucial because, without it, the linker wouldn't know the specific memory layout of your hardware.

### Key Points
*   It merges various sections of input object files into a single output file (usually an `.elf` file).
*   It assigns **unique absolute addresses** to different sections.
*   It contains information about the start addresses and sizes of code and data memory.
*   Written in **GNU Linker Command Language** with a `.ld` file extension.
*   Supplied to the linker during the linking phase using the `-T` option.

### Examples from the Video
*   **Command usage:** `arm-none-eabi-gcc -T linker_script.ld ...`.
*   **File creation:** The instructor creates a file named `stm32_ls.ld`.

### Real-World Example
Think of a linker script as an interior designer’s floor plan. The "object files" are the furniture, and the "linker script" tells you exactly which room (memory region) each piece of furniture belongs in so that the house (the final program) is functional.

### Common Mistakes / Important Notes
*   **Case Sensitivity:** Most linker commands like `ENTRY`, `MEMORY`, and `SECTIONS` are written in all capital letters.

### Summary
*   A text file with the `.ld` extension.
*   Defines how object file sections merge into an output file.
*   Assigns absolute memory addresses to code and data.
*   Essential for target-specific memory mapping.

---

## 2. The `ENTRY` Command
### Brief Explanation
The **`ENTRY` command** defines the first instruction to be executed when the processor starts. It populates the "Entry Point Address" information in the header of the generated ELF file.

### Key Points
*   It is used by debuggers (like GDB) to locate the starting point of the application.
*   Strictly speaking, it is not mandatory for the code to run on hardware, but it is **highly recommended for debugging**.
*   The **Reset Handler** is typically the entry point in embedded systems because it is the first code executed after a reset.

### Examples from the Video
*   **Syntax:** `ENTRY(symbol_name)`.
*   **Implementation:**
    ```ld
    ENTRY(Reset_Handler) /* Reset_Handler is the function name from the startup code */
    ```
    *Line explanation:* `ENTRY` tells the linker that `Reset_Handler` is the starting address of the application.

### Real-World Example
It’s like the "Start Here" sticker on a complex board game board. It doesn't change the game rules, but it tells the players exactly where to place their pieces to begin.

### Common Mistakes / Important Notes
*   **No Semicolons:** Do not use a semicolon at the end of the `ENTRY` command line.
*   **Symbol Accuracy:** Ensure the symbol name matches the function name in your startup assembly or C file exactly.

### Summary
*   Sets the entry point address in the ELF header.
*   Primarily used by debuggers.
*   Usually points to the `Reset_Handler`.

---

## 3. The `MEMORY` Command
### Brief Explanation
The **`MEMORY` command** describes the physical memory layout of the target microcontroller. It tells the linker how much Flash and RAM is available and where it starts.

### Key Points
*   Allows the linker to calculate if the code/data fits in the available space.
*   Throws an error if the application exceeds the memory limits.
*   Typically, a linker script contains only one `MEMORY` command.
*   **Syntax:** `NAME (attr) : ORIGIN = start_address, LENGTH = size`.

### Attributes Table
The instructor mentions that attributes define the permissions for a memory region:

| Attribute | Meaning |
| :--- | :--- |
| **R** | Read-only section |
| **W** | Read/Write section |
| **X** | Section containing executable code |
| **A** | Allocated section |
| **I** | Initialized section |

### Examples from the Video
*   **Microcontroller Example:** STM32F4 (1MB Flash, 128KB RAM total).
*   **Code Implementation:**
    ```ld
    MEMORY
    {
        FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 1024K
        SRAM(rwx) : ORIGIN = 0x20000000, LENGTH = 128K
    }
    ```
    *Line-by-line explanation:*
    1. `MEMORY { ... }`: Defines the memory block.
    2. `FLASH(rx)`: A region named FLASH that is Readable and Executable.
    3. `ORIGIN = 0x08000000`: The physical start address of Flash.
    4. `LENGTH = 1024K`: The size of the Flash (1MB).
    5. `SRAM(rwx)`: A region named SRAM that is Readable, Writable, and Executable.
    6. `ORIGIN = 0x20000000`: The physical start address of RAM.
    7. `LENGTH = 128K`: The size of the combined SRAM1 and SRAM2.

### Real-World Example
This is like defining the boundaries of a plot of land. You specify where the "Code Garden" (Flash) is and where the "Work Shed" (RAM) is, and how many square feet each has.

### Common Mistakes / Important Notes
*   **Kilobyte Notation:** You can use `K` or `k` (e.g., `1024K`) which the linker expands to the correct byte count.
*   **Merging Regions:** If you don't need to treat SRAM1 and SRAM2 separately, you can club them into a single `SRAM` region for simplicity.

### Summary
*   Describes target memory start addresses and sizes.
*   Prevents memory overflow errors.
*   Uses attributes like `r`, `w`, and `x` to define permissions.

---

## 4. The `SECTIONS` Command
### Brief Explanation
The **`SECTIONS` command** is the most critical part of the script. it instructs the linker on how to merge input sections (from object files) into output sections and where to place them in the memory regions defined by the `MEMORY` command.

### Key Points
*   Controls the **order** in which sections appear in the final file.
*   **VMA (Virtual Memory Address):** The address the section will have when the program is running.
*   **LMA (Load Memory Address):** The address where the section is physically stored (loaded).
*   In Flash-based systems, for code, VMA and LMA are usually the same.

### Examples from the Video
*   **Syntax for a section:**
    ```ld
    SECTIONS
    {
        .text :
        {
            *(.isr_vector)
            *(.text)
            *(.rodata)
        } > FLASH
    }
    ```
    *Line-by-line explanation:*
    1. `SECTIONS { ... }`: Opens the sections block.
    2. `.text :`: Defines the name of the output section.
    3. `*(.isr_vector)`: Merges the interrupt vector table from all (`*`) input files first.
    4. `*(.text)`: Merges all code sections from all input files.
    5. `*(.rodata)`: Merges all constant/read-only data.
    6. `> FLASH`: Places this entire output section into the `FLASH` memory region defined earlier.

### Comparison Table: Input vs. Output Sections
| Aspect | Input Sections | Output Sections |
| :--- | :--- | :--- |
| **Origin** | Exist within individual object files (e.g., `main.o`, `startup.o`). | Created by the linker inside the ELF file. |
| **Examples** | `.text`, `.data`, `.bss`, `.rodata` from each file. | A combined `.text` or `.data` section. |
| **Management**| Managed by the compiler. | Defined and ordered by the `SECTIONS` command. |

### Real-World Example
Think of the `SECTIONS` command as a packing list for a moving truck. It says, "Take all the 'Kitchen' boxes (input sections) from every room and put them in the front of the truck (output section) in the 'Kitchen' area of the new house (Memory Region)."

### Common Mistakes / Important Notes
*   **Order Matters:** The order of sections inside the `SECTIONS` command determines their order in memory. For ARM Cortex-M, the `.isr_vector` **must** be at the very beginning of the Flash.
*   **Wildcards:** Use `*(.section_name)` to include that section from **all** input object files.

### Summary
*   Merges input sections into output sections.
*   Determines the order of sections in the ELF file.
*   Maps output sections to specific memory regions (e.g., `> FLASH`).

---

## 5. VMA and LMA (Relocation)
### Brief Explanation
In embedded systems, initialized data (`.data`) is stored in Flash (non-volatile) but must be copied to RAM (volatile) during startup so it can be modified. This creates a difference between where the data is "loaded" (LMA) and where it "runs" (VMA).

### Key Points
*   **LMA:** The "Load" address (Flash).
*   **VMA:** The "Virtual" or "Run" address (RAM).
*   The **Startup Code** is responsible for copying the `.data` section from LMA to VMA.

### Examples from the Video
*   **Placing `.data` section:**
    ```ld
    .data :
    {
        *(.data)
    } > SRAM AT > FLASH
    ```
    *Line-by-line explanation:*
    1. `.data :`: Creates the output data section.
    2. `*(.data)`: Merges all data sections from input files.
    3. `> SRAM`: Sets the **VMA** to SRAM (where it will be accessed during runtime).
    4. `AT > FLASH`: Sets the **LMA** to FLASH (where it is physically stored until the startup code copies it).

*   **Placing `.bss` section:**
    ```ld
    .bss :
    {
        *(.bss)
    } > SRAM
    ```
    *Note:* `.bss` (uninitialized data) is not stored in Flash, so it only has a VMA in SRAM.

### Summary
*   **LMA:** Storage address (Flash).
*   **VMA:** Runtime address (SRAM).
*   `.data` sections use both LMA and VMA for relocation.

---

## 6. The Location Counter (`.`)
### Brief Explanation
The **Location Counter**, represented by a **dot (`.`)**, is a special linker variable that tracks the current address the linker is working on within the `SECTIONS` command.

### Key Points
*   The linker automatically updates it as it adds sections.
*   It can only be used **inside** the `SECTIONS` command.
*   It always tracks the **VMA** (Virtual Memory Address), not the LMA.
*   It is used to define boundaries (start/end addresses) of sections.

### Examples from the Video
*   **Boundary Tracking:**
    ```ld
    .text :
    {
        *(.text)
        _etext = .;  /* _etext now holds the address where .text ends */
    } > FLASH
    ```
    *Logic:* Initially, `.` is the start of the section. After `*(.text)`, the linker increments `.` by the size of all merged text sections. Assigning `_etext = .` captures that final address.

### Summary
*   Represented by a dot (`.`).
*   Tracks the current VMA automatically.
*   Essential for finding the start and end of memory sections.

---

## 7. Linker Script Symbols
### Brief Explanation
**Linker Script Symbols** are names given to specific memory addresses. They allow you to "export" address information from the linker script into your C program.

### Key Points
*   **Not the same as C variables:** A C variable stores a *value* at an address; a linker symbol *is* the address.
*   Used to provide the startup code with the source (Flash) and destination (RAM) addresses for copying data.
*   Follow the same naming rules as C variables.

### Comparison Table: C Variables vs. Linker Symbols
| Feature | C Variable | Linker Script Symbol |
| :--- | :--- | :--- |
| **Defined in** | `.c` or `.h` files. | `.ld` files. |
| **Content** | Holds data (e.g., `int x = 100`). | Holds a memory address. |
| **Handled by** | Compiler. | Linker. |
| **Visible in** | Symbol Table (as a name with an address). | Symbol Table (as a name with an address). |

### Examples from the Video
*   **Creating symbols for relocation:**
    ```ld
    _etext = .;           /* End of text (code) in Flash */
    _sdata = .;           /* Start of data in RAM (VMA) */
    .data : AT(_etext)    /* Load data right after code in Flash */
    {
        _sdata = .;       /* Start of data section */
        *(.data)
        _edata = .;       /* End of data section */
    } > SRAM
    ```
    *Instructor's Reasoning:* The startup code needs `_etext` (source), `_sdata` (destination), and the size (calculated via `_edata - _sdata`) to successfully move data from Flash to RAM.

### Real-World Example
A linker symbol is like a GPS coordinate. In C, you might have a "Building" (variable) that contains "People" (data). The linker symbol is just the latitude and longitude of where that building is located on the map.

### Summary
*   Symbols represent addresses, not variable values.
*   Linker adds these symbols to the final executable's symbol table.
*   Used to pass boundary information to C startup code.
