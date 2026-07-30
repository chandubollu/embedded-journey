Excellent! Now we are entering one of the most important chapters in ARM Cortex-M architecture:

> **4.4 Memory System**

Don't worry about the long list. **This section is mainly an overview**. The book is telling you **what features the Cortex-M memory system has**. Later sections explain each feature in detail.

Let's understand **every point** in simple language.

---

# 4.4 Memory System

## What is a Memory System?

A processor cannot work alone.

It needs memory to store:

* Program (instructions)
* Variables
* Stack
* Heap
* Peripheral registers

All these together form the **memory system**.

Think of a computer.

```text
             CPU
              │
      ┌───────┼────────┐
      │       │        │
   Flash     SRAM   Peripherals
```

The CPU communicates with all of them through the memory system.

---

# Feature 1: 4GB Linear Address Space

The book says

> With 32-bit addressing, ARM processors can access up to 4GB of memory.

Let's understand why.

---

## What is an Address?

Every memory location has an address.

Just like every house has a house number.

Example

```text
House Number

101

102

103
```

Memory works exactly the same.

```text
Address

0x00000000

0x00000001

0x00000002
```

The CPU accesses memory using these addresses.

---

## Why 4GB?

The Cortex-M uses

```text
32-bit Address Bus
```

A 32-bit address can represent

```text
2^32
```

different addresses.

That equals

```text
4,294,967,296 Bytes
```

which is approximately

```text
4 GB
```

Therefore

```text
32-bit Address

↓

4 GB Address Space
```

---

## Does Every Microcontroller Have 4GB RAM?

No.

The book clearly says

Most embedded systems

need

less than

```text
1 MB
```

For example

An STM32F103

might have

```text
64 KB Flash

20 KB SRAM
```

Yet

the processor **can still generate 4GB addresses**.

Most of the address space simply has no physical memory connected.

---

## Why Design It This Way?

The book gives the reason:

Future expansion.

If later

a microcontroller has

more RAM,

the processor design

does not need to change.

---

# AHB-LITE Bus

The book says

Cortex-M3/M4 uses

```text
AHB-LITE
```

What is that?

AHB means

> **Advanced High-performance Bus**

Think of it as

the highway

between

CPU

and

Memory.

```text
CPU

│

AHB-LITE Bus

│

Flash

SRAM

GPIO

UART
```

The processor sends

addresses

and

data

through this bus.

---

## Why Mention 8/16/32-bit Memory?

The book says

AHB-LITE

can connect to

```text
8-bit

16-bit

32-bit
```

memory devices

using suitable memory controllers.

Meaning

the processor is flexible.

It is not limited

to only

32-bit memory chips.

---

# Feature 2: Architecturally Defined Memory Map

This is one of the most important concepts.

The book says

The

4GB

address space

is divided into

different regions.

---

Think of a city.

```text
City

↓

Residential Area

Industrial Area

Hospital Area

School Area
```

Similarly

ARM divides memory.

```text
4GB Memory

↓

Code Region

SRAM Region

Peripheral Region

System Region
```

Every region

has a specific purpose.

---

## Why?

The book says

This improves performance.

---

### Example

Suppose

CPU

needs

instructions

from Flash

AND

data

from SRAM

at the same time.

Because

these are different regions,

the Cortex-M has multiple bus interfaces.

So

it can fetch

```text
Instruction

↓

Flash
```

while simultaneously reading

```text
Variable

↓

SRAM
```

This improves execution speed.

---

# Feature 3: Little Endian / Big Endian

This is another important topic.

First

what is Endian?

Endian means

> **How multi-byte data is stored in memory.**

Suppose

we store

```text
0x12345678
```

which occupies

4 bytes.

---

## Little Endian

Smallest byte

stored first.

Memory

```text
Address

100

101

102

103
```

Stores

```text
78

56

34

12
```

Least Significant Byte (LSB)

comes first.

---

## Big Endian

Largest byte

stored first.

Memory

```text
100

101

102

103
```

Stores

```text
12

34

56

78
```

Most Significant Byte (MSB)

comes first.

---

The book says

Cortex-M3/M4

supports

both.

But

a microcontroller

normally

uses

only

one configuration,

chosen by the manufacturer.

---

# Feature 4: Bit Band Access (Optional)

This is a famous ARM feature.

The book says

If the vendor includes it,

two

1 MB

memory regions

become

bit addressable.

---

Normally

suppose

you have

```text
00010010
```

and

want to change

only

bit 3.

Normally

you must

```text
Read

↓

Modify

↓

Write
```

three steps.

---

Bit-band

lets you

access

a single bit

like a normal variable.

```text
Bit 5

↓

Address

↓

Write 1

or

Write 0
```

No read-modify-write sequence is needed.

---

The book says

this provides

**atomic access**

to a single bit.

That means

the bit update completes as one indivisible operation.

This is especially useful when interrupts or multiple pieces of code could otherwise interfere with a read-modify-write sequence.

---

# Feature 5: Write Buffer

Suppose

writing

to Flash

takes

many cycles.

Without

Write Buffer

```text
CPU

↓

Wait

Wait

Wait
```

Processor

cannot continue.

---

With

Write Buffer

```text
CPU

↓

Place Data

↓

Buffer

↓

Continue Executing
```

Meanwhile

the buffer

finishes

the write operation.

Result

↓

Higher speed.

Exactly what the book says.

---

# Feature 6: MPU (Memory Protection Unit)

The book says

MPU

is optional.

---

What does MPU do?

Imagine

a school.

Student

should not enter

Principal's Office.

Similarly

Task A

should not access

Task B's memory.

The MPU defines

which memory regions

can be accessed.

---

The book says

Cortex-M3/M4 MPU

supports

```text
8 Programmable Regions
```

Each region

can have

its own

access permissions.

This is why

RTOSes

often use

the MPU.

---

# Feature 7: Unaligned Transfer Support

This is another useful feature.

Normally

a

32-bit integer

is stored

at addresses like

```text
0

4

8

12
```

These are called

aligned addresses.

---

But suppose

someone stores

a 32-bit value

starting at

```text
Address

3
```

That is

not aligned.

Many processors

cannot read it directly.

---

The book says

ARMv7-M processors

including

Cortex-M3

and

Cortex-M4

support

unaligned transfers.

Meaning

they can still access

such data.

---

# Memory Types in a Microcontroller

The book finally says

Most microcontrollers contain

more than one memory.

Examples

## Flash

Stores

```text
Program Code
```

Example

```c
int main()
{
}
```

is stored

in Flash.

---

## SRAM

Stores

```text
Variables

Stack

Heap
```

Example

```c
int x = 10;
```

The variable

lives in SRAM while the program runs.

---

## EEPROM

Some microcontrollers

also contain

EEPROM.

Used for

storing

data that should remain

even after power is turned OFF.

---

The book says

these memories

are usually

on-chip,

and

software developers

do not need to know

the hardware interface details.

The memory controllers handle those details automatically.

---

# Complete Summary

| Feature                 | Simple Meaning                                                                                                           |
| ----------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| **4GB Address Space**   | A 32-bit address can represent up to 4GB of memory addresses, even if the microcontroller has much less physical memory. |
| **AHB-LITE Bus**        | The internal bus that connects the CPU to Flash, SRAM, and peripherals.                                                  |
| **Memory Map**          | The 4GB address space is divided into predefined regions such as code, SRAM, peripherals, and system memory.             |
| **Little/Big Endian**   | Defines the byte order used to store multi-byte values in memory.                                                        |
| **Bit-Band (Optional)** | Allows individual bits in certain 1MB memory regions to be accessed atomically through alias addresses.                  |
| **Write Buffer**        | Lets the CPU continue executing while slower memory writes complete in the background.                                   |
| **MPU (Optional)**      | Defines access permissions for memory regions to improve system robustness and security.                                 |
| **Unaligned Transfer**  | ARMv7-M processors can access data even when it is not aligned to its natural boundary.                                  |
| **Memory Types**        | Flash stores program code, SRAM stores runtime data, and some devices also include EEPROM for non-volatile data.         |

## Memory Trick

Remember these seven Cortex-M memory system features with the phrase:

```text
4 Great Architects Build Wonderful Modern Universities

4  → 4GB Address Space
G  → Generic AHB-LITE Bus
A  → Architecturally Defined Memory Map
B  → Bit-Band Access
W  → Write Buffer
M  → Memory Protection Unit (MPU)
U  → Unaligned Transfer Support
```

Excellent. This is **one of the most important topics in ARM Cortex-M architecture**. If you understand the **memory map**, then understanding STM32, NXP LPC, TI Tiva, Nordic, etc., becomes much easier because **all Cortex-M processors follow the same memory map**.

Let's understand it **exactly as your book explains**, without adding extra topics.

---

# 4.4.2 Memory Map

## What is a Memory Map?

Earlier we learned that the Cortex-M processor has

```text
4 GB Address Space
```

But is the entire 4 GB used for RAM?

**No.**

The processor divides the 4 GB address space into different regions.

Think of a city.

```
Whole City

↓

Residential Area

Commercial Area

Industrial Area

Hospital Area
```

Similarly,

ARM divides memory into different regions.

```
4 GB Address Space

↓

CODE Region

SRAM Region

Peripheral Region

External RAM

External Device

System Region
```

Each region has its own purpose.

---

# Complete Memory Map

The book gives this memory map.

```
Address Range                Region
------------------------------------------------
0x00000000 - 0x1FFFFFFF      CODE
0x20000000 - 0x3FFFFFFF      SRAM
0x40000000 - 0x5FFFFFFF      Peripherals
0x60000000 - 0x9FFFFFFF      External RAM
0xA0000000 - 0xDFFFFFFF      External Devices
0xE0000000 - 0xFFFFFFFF      System Region
```

This is the memory map that every Cortex-M processor understands.

---

# Region 1: CODE Region

Address

```
0x00000000

↓

0x1FFFFFFF
```

Size

```
512 MB
```

The book says

> Mainly used for program code.

That means your program is normally stored here.

Example

```c
int main()
{
    while(1)
    {

    }
}
```

This code is stored in

```
Flash Memory

↓

CODE Region
```

---

## Exception Vector Table

The book also says

This region is used for

```
Exception Vector Table
```

Remember

the vector table contains

```
Reset Handler

NMI Handler

HardFault Handler

UART ISR

Timer ISR
```

These addresses are normally placed at the beginning of the CODE region.

---

## Can SRAM Exist Here?

The book says

Yes.

Normally

this region stores

program code.

But

ARM allows flexibility.

A microcontroller vendor

may place

```
SRAM
```

inside the CODE region if desired.

---

# Region 2: SRAM Region

Address

```
0x20000000

↓

0x3FFFFFFF
```

Size

```
512 MB
```

The book says

> Mainly used for data memory.

What data?

Examples

```c
int x=10;

char name[20];

float temperature;
```

These variables are stored in SRAM.

Also

```
Stack

Heap

Global Variables

Local Variables
```

are normally stored in SRAM.

---

## Can Programs Run From SRAM?

The book says

Yes.

Programs can execute

from SRAM

as well.

Although the CODE region is mainly intended for program code, the architecture allows code execution from SRAM too.

---

# Region 3: Peripheral Region

Address

```
0x40000000

↓

0x5FFFFFFF
```

Size

```
512 MB
```

The book says

> Mainly used for peripherals.

Examples

```
GPIO

UART

SPI

I2C

ADC

Timers
```

Each peripheral has registers that appear in this address region.

Example

```
GPIO Register

↓

Memory Address

↓

CPU reads/writes it
```

Although these look like memory addresses,

they actually control hardware.

---

# Region 4: External RAM

Address

```
0x60000000

↓

0x9FFFFFFF
```

Size

```
1 GB
```

The book says

> Mainly used for external memory.

Some microcontrollers allow connecting extra RAM outside the chip.

Example

```
CPU

↓

External SRAM Chip
```

That external memory is usually mapped into this region.

Many small microcontrollers do not use this region.

---

# Region 5: External Device

Address

```
0xA0000000

↓

0xDFFFFFFF
```

Size

```
1 GB
```

The book says

> Mainly used for external peripherals.

Suppose

your board has

```
External LCD Controller

External FPGA

External Ethernet Chip
```

These devices can be mapped here.

Again,

many microcontrollers leave this region unused.

---

# Region 6: System Region

Address

```
0xE0000000

↓

0xFFFFFFFF
```

This is one of the most important regions.

It contains

```
Processor Control Registers

Interrupt Controller

Debug Hardware
```

These are **not ordinary peripherals** like GPIO or UART.

They belong to the processor itself.

---

# Private Peripheral Bus (PPB)

Inside the System Region,

the book shows a smaller area.

```
0xE0000000

↓

0xE00FFFFF
```

called

```
PPB

Private Peripheral Bus
```

Think of PPB as

```
Processor's Private Area
```

Only the processor's own hardware lives here.

---

# System Control Space (SCS)

Inside the PPB,

the book shows another smaller region.

```
0xE000E000

↓

0xE000EFFF
```

This is called

```
System Control Space (SCS)
```

It contains important processor control registers.

---

# What is Inside the SCS?

The book specifically mentions

### NVIC

```
Nested Vectored Interrupt Controller
```

This manages interrupts.

---

### Processor Configuration Registers

Examples include processor control registers discussed earlier (such as CONTROL and other system control registers).

---

### Debug Components

These are used by debuggers.

For example,

```
Breakpoints

Single Step

Watchpoints
```

The book groups these as debug components.

---

# Why Is This Memory Map Important?

The book gives a very important reason.

Every Cortex-M processor

uses

the same memory arrangement.

That means

```
CODE Region

↓

Always starts

at

0x00000000
```

SRAM

always starts at

```
0x20000000
```

Peripherals

always start at

```
0x40000000
```

PPB

always starts at

```
0xE0000000
```

No matter

whether it is

```
STM32

NXP

TI

Nordic
```

the processor understands these regions the same way.

---

# Does Every Microcontroller Use All These Regions?

The book clearly says

No.

Example

Suppose

a microcontroller has

```
64 KB Flash

20 KB SRAM
```

Then

only a tiny portion of

```
CODE Region
```

is actually used.

Similarly,

only part of the SRAM region is occupied.

The remaining addresses simply have no implemented memory behind them.

---

# Where Do We Find the Exact Addresses?

The book says

Every vendor provides

```
User Manual

or

Datasheet
```

These documents tell you

* Flash size
* SRAM size
* Peripheral addresses

for that specific microcontroller.

---

# Why Is a Common Memory Map Useful?

The book gives two reasons.

## 1. Software Portability

Suppose

you write software

for one Cortex-M device.

Since

processor registers

are always in the same system region,

moving the software to another Cortex-M device becomes easier.

---

## 2. Debug Tools

The debugger

always knows

where processor debug registers are located.

Therefore,

debug tools

work similarly

across Cortex-M processors.

---

# Complete Memory Map Diagram

```
4 GB Address Space
──────────────────────────────────────────────

0x00000000 ──────────────────────────────
            CODE Region (512 MB)
            • Program Code
            • Exception Vector Table

0x20000000 ──────────────────────────────
            SRAM Region (512 MB)
            • Variables
            • Stack
            • Heap

0x40000000 ──────────────────────────────
            Peripheral Region (512 MB)
            • GPIO
            • UART
            • SPI
            • Timers
            • ADC

0x60000000 ──────────────────────────────
            External RAM (1 GB)

0xA0000000 ──────────────────────────────
            External Devices (1 GB)

0xE0000000 ──────────────────────────────
            System Region
            │
            ├── PPB
            │
            └── SCS
                 • NVIC
                 • Processor Configuration Registers
                 • Debug Components

0xFFFFFFFF ──────────────────────────────
```

---

# Complete Summary

| Region              | Address Range             | Main Purpose                                       |
| ------------------- | ------------------------- | -------------------------------------------------- |
| **CODE**            | `0x00000000 – 0x1FFFFFFF` | Mainly program code and exception vector table     |
| **SRAM**            | `0x20000000 – 0x3FFFFFFF` | Mainly data memory (variables, stack, heap)        |
| **Peripherals**     | `0x40000000 – 0x5FFFFFFF` | Peripheral registers (GPIO, UART, SPI, ADC, etc.)  |
| **External RAM**    | `0x60000000 – 0x9FFFFFFF` | Mainly external memory                             |
| **External Device** | `0xA0000000 – 0xDFFFFFFF` | Mainly external peripherals/devices                |
| **System Region**   | `0xE0000000 – 0xFFFFFFFF` | Processor control and debug components             |
| **PPB**             | `0xE0000000 – 0xE00FFFFF` | Private Peripheral Bus for processor internals     |
| **SCS**             | `0xE000E000 – 0xE000EFFF` | NVIC, processor configuration, and debug registers |

## Memory Trick

To remember the order of the regions from low to high addresses:

```text
CODE
   ↓
SRAM
   ↓
PERIPHERALS
   ↓
EXTERNAL RAM
   ↓
EXTERNAL DEVICES
   ↓
SYSTEM
```

Or simply:

**"Code Stores Programs, External Systems"**

* **Code** → CODE region
* **Stores** → SRAM
* **Programs** → Peripherals
* **External** → External RAM + External Devices
* **Systems** → System region

Excellent. This is **one of the most important sections in ARM Cortex-M architecture** because **every C function, interrupt, RTOS, and operating system uses the stack**.

The good news is that the concepts are not difficult once you understand them. Let's follow the book **section by section** without skipping anything.

---

# 4.4.3 Stack Memory

## What is Stack Memory?

The book starts by saying:

> As in almost all processor architectures, the Cortex-M processors need stack memory to operate.

This means **every Cortex-M processor requires a stack**.

---

## What is a Stack?

The book defines the stack as:

> A Last-In-First-Out (LIFO) data storage buffer.

### What is LIFO?

LIFO means

> **Last In, First Out**

Imagine a stack of books.

```
        +--------+
        | Book C | ← Last placed
        +--------+
        | Book B |
        +--------+
        | Book A |
        +--------+
```

If you remove a book,

which one comes out first?

```
Book C
```

The last book placed is the first one removed.

This is exactly how stack memory works.

---

# Where is Stack Stored?

The book says

ARM processors

use

```
Main System Memory
```

for the stack.

Usually this is SRAM.

The processor does **not** have a separate hardware stack memory.

---

# Stack Pointer (SP)

The stack needs someone to keep track of its top.

That is

```
SP

(Stack Pointer)

R13
```

Earlier we learned

```
R13

↓

Stack Pointer
```

SP always points to the **current top of the stack**.

---

# PUSH Instruction

The book says

```
PUSH
```

stores data

into

the stack.

Example

Suppose

```
R4 = 25
```

Execute

```assembly
PUSH {R4}
```

Now

```
R4 value

↓

Stored in Stack Memory
```

The stack becomes

```
+---------+
|   25    | ← SP
+---------+
```

---

# POP Instruction

The opposite operation is

```
POP
```

Example

```assembly
POP {R4}
```

Now

```
25

↓

Copied back

↓

R4
```

The stack becomes empty again.

---

# SP Automatically Changes

The book says

The current stack pointer is

**automatically adjusted**

during PUSH and POP.

That means

you never write

```assembly
SP = SP - 4
```

The processor does that automatically.

---

# Why Do We Need Stack?

The book gives four reasons.

Let's understand each.

---

# 1. Saving Registers

Imagine

Main Program

```
R4 = 100
```

Now

you call

```
function1()
```

Inside

function1

you also need

```
R4
```

If

function1

changes

```
R4
```

then

Main Program

loses

its value.

---

Solution

```
Before using R4

↓

PUSH R4
```

Now

modify R4 freely.

At the end

```
POP R4
```

Original value

returns.

Exactly what the book says.

---

# 2. Passing Parameters

The book says

Stack

can also

pass information

to functions.

Example

```
main()

↓

Calls

↓

sum()
```

Arguments

may be placed

on the stack.

---

# 3. Local Variables

Suppose

```c
void test()
{
    int x;
}
```

The local variable

```
x
```

exists

only

inside

the function.

The stack is commonly used to hold such local variables.

---

# 4. Interrupts

The book says

Stack stores

processor status

and register values

during

interrupts.

Later

these values

are restored.

This allows the interrupted program to continue correctly.

---

# Full Descending Stack

The book now introduces an important term.

```
Full Descending Stack
```

Let's understand the name.

---

## Descending

Stack grows

toward

lower addresses.

Suppose

top of stack

starts at

```
0x20001000
```

After one PUSH

```
SP

↓

0x20000FFC
```

Another PUSH

```
SP

↓

0x20000FF8
```

Notice

addresses are

getting smaller.

Hence

```
Descending
```

---

## Full

The book says

SP points to

the memory location

containing

the last pushed data.

That is why

it is called

```
Full
```

---

# PUSH Operation

The book explains

PUSH

in two steps.

Step 1

```
Decrease SP
```

Step 2

```
Store Data
```

Diagram

```
SP

↓

Decrease

↓

Store Data
```

---

Example

Initially

```
SP

=

0x20001000
```

PUSH

```
R4
```

Processor first

```
SP

↓

0x20000FFC
```

Then

stores

```
R4
```

at

```
0x20000FFC
```

---

# POP Operation

POP is the reverse.

Step 1

Read

the value

pointed by

SP.

Step 2

Increase SP.

Example

```
Read

↓

0x20000FFC
```

Then

```
SP

↓

0x20001000
```

---

# PUSH/POP in Functions

The book gives

Figure 4.20.

Main program

calls

```
function1()
```

Suppose

function1

uses

```
R4

R5

R6
```

These registers

already contain

important values.

Therefore

the function begins

```assembly
PUSH {R4,R5,R6}
```

Now

function1

can freely change them.

Before returning

```assembly
POP {R4,R5,R6}
```

Original values

come back.

Main program

never notices

the changes.

---

# Rule

The book says

Every

```
PUSH
```

must have

a matching

```
POP
```

Otherwise

stack becomes

corrupted.

---

# Multiple Register PUSH

The book says

PUSH

can save

multiple registers

at once.

Example

```assembly
PUSH {R4,R5,R6}
```

Instead of

three instructions

only

one

instruction

is required.

---

POP

also works

the same way.

```assembly
POP {R4,R5,R6}
```

---

# Stack Alignment

Registers are

32 bits.

Therefore

every PUSH

stores

```
4 Bytes
```

The book states

SP is always aligned

to

```
4-byte boundary
```

Meaning

the lowest two bits

of SP

are always

```
00
```

---

# Combining POP and Return

The book introduces a clever trick.

Normally

```
POP Registers

↓

Return
```

Two operations.

Instead

save

```
LR
```

onto

the stack.

At the end

POP

directly into

```
PC
```

The processor then

returns

automatically.

This combines

restoring the return address

and

returning from the function.

---

# Two Stack Pointers

Earlier

we learned

```
R13

↓

Stack Pointer
```

The book now explains

physically

there are

**two stack pointers**.

---

## 1. MSP

```
Main Stack Pointer
```

Book says

* Default after reset
* Used for all exception handlers

---

## 2. PSP

```
Process Stack Pointer
```

Book says

* Only used in Thread Mode
* Usually used for application tasks running under an embedded OS

---

# Which One is Used?

The book refers to

```
CONTROL Register

↓

SPSEL
```

We studied this earlier.

---

## SPSEL = 0

Thread Mode

↓

Uses

```
MSP
```

Handler Mode

↓

Uses

```
MSP
```

Exactly like Figure 4.23.

```
Thread Mode

↓

Interrupt

↓

Handler Mode

↓

Return

↓

Thread Mode

(All use MSP)
```

---

## SPSEL = 1

Thread Mode

↓

Uses

```
PSP
```

Handler Mode

↓

Uses

```
MSP
```

Exactly like Figure 4.24.

```
Application

↓

PSP

↓

Interrupt

↓

MSP

↓

Return

↓

PSP
```

---

# Stacking

The book introduces a new term.

```
Stacking
```

During an interrupt,

the processor automatically pushes

a number of registers

onto the current stack.

This automatic saving of the processor state is called

```
Stacking
```

---

# Unstacking

When the interrupt finishes,

the processor automatically restores those registers.

This restoration is called

```
Unstacking
```

---

# Why Use Two Stacks?

The book gives two reasons.

Suppose

an application

accidentally corrupts

its stack.

If the operating system

used the same stack,

it would also be damaged.

Instead

```
Application

↓

PSP
```

Operating System

↓

```
MSP
```

Now

application bugs

cannot directly damage

the kernel stack.

The book also says

this simplifies OS design

and allows

faster context switching.

---

# CMSIS Functions

The book provides CMSIS APIs.

Read MSP

```c
x = __get_MSP();
```

Write MSP

```c
__set_MSP(x);
```

Read PSP

```c
x = __get_PSP();
```

Write PSP

```c
__set_PSP(x);
```

The book warns:

> It is generally **not recommended** to change the currently selected stack pointer from a C function because that stack may already be holding local variables or other data.

---

# Assembly Instructions

The same operations

can be done

using

```
MRS

MSR
```

Examples from the book:

```assembly
MRS R0, MSP   ; Read Main Stack Pointer into R0
MSR MSP, R0   ; Write R0 to Main Stack Pointer

MRS R0, PSP   ; Read Process Stack Pointer into R0
MSR PSP, R0   ; Write R0 to Process Stack Pointer
```

---

# Who Uses MSP and PSP?

The book says

Most applications

never access them directly.

Embedded operating systems

do.

For example,

during a context switch,

the OS updates the

```
PSP
```

to switch between tasks.

---

# Initialization

The book finishes with an important point.

### MSP

After power-up,

hardware automatically initializes

```
MSP
```

by reading the

```
Vector Table
```

---

### PSP

The processor

does **not**

initialize

```
PSP
```

Software

must initialize it

before it is used.

---

# 4.4.4 Memory Protection Unit (MPU)

The book then gives a short introduction to the MPU.

## Is MPU Always Present?

No.

The book clearly states:

> The MPU is **optional** in Cortex-M3 and Cortex-M4 processors.

So not every microcontroller includes one.

---

## Why Use an MPU?

Most applications do not need it and can ignore it.

For systems that require **high reliability**, the MPU protects memory by defining access permissions for different memory regions and for privileged versus unprivileged access.

---

## Programmable Regions

The MPU in Cortex-M3 and Cortex-M4 supports

```
8 programmable regions.
```

---

## How Can It Be Used?

The book gives two examples:

1. An embedded OS configures memory permissions separately for each task.
2. A specific memory range is made **read-only** to prevent accidental modification.

---

## More Details

The book explicitly says that

> More information about the MPU is covered in **Chapter 11**.

So at this point, you only need to know its purpose and basic capabilities.

---

# Complete Summary

| Topic                          | Key Idea                                                                                                                       |
| ------------------------------ | ------------------------------------------------------------------------------------------------------------------------------ |
| **Stack**                      | A Last-In-First-Out (LIFO) memory area used by the processor.                                                                  |
| **Stack Pointer (SP/R13)**     | Points to the current top of the stack.                                                                                        |
| **PUSH**                       | Decrements SP first, then stores data.                                                                                         |
| **POP**                        | Reads data from SP, then increments SP.                                                                                        |
| **Stack Type**                 | Full-descending stack.                                                                                                         |
| **Uses of Stack**              | Save registers, pass information to functions, store local variables, save processor state during exceptions.                  |
| **Multiple Register PUSH/POP** | One instruction can transfer several 32-bit registers.                                                                         |
| **Alignment**                  | Stack transfers are word-sized (4 bytes), and SP is always 4-byte aligned.                                                     |
| **MSP**                        | Default after reset; always used in Handler Mode.                                                                              |
| **PSP**                        | Alternate stack pointer for Thread Mode, typically used by application tasks in an embedded OS.                                |
| **SPSEL**                      | Selects MSP or PSP for Thread Mode.                                                                                            |
| **Stacking**                   | Automatic register saving on exception entry.                                                                                  |
| **Unstacking**                 | Automatic register restoration on exception return.                                                                            |
| **MSP Initialization**         | Done automatically by hardware from the vector table after reset.                                                              |
| **PSP Initialization**         | Must be performed by software before use.                                                                                      |
| **MPU**                        | Optional feature with eight programmable regions for memory protection; mainly used in reliable systems and RTOS environments. |
