![Introduction](images/intro.jpg)
![Introduction](images/intro.jpg)
![Introduction](images/intro.jpg)
---

# Part 1: Memory Fundamentals (From Scratch)

---

# What is Memory?

Imagine you have a study table.

On your table, you have:

* 📚 Books
* 📝 Notebook
* 🖊️ Pen
* 📱 Calculator

When solving a problem, you:

1. Read the question from the book.
2. Write calculations on the notebook.
3. Use the calculator.
4. Write the final answer.

A microcontroller works in almost the same way.

It has:

* CPU (the brain)
* Memory (to store programs and data)
* Peripherals (GPIO, UART, Timers, ADC, etc.)

Without memory, the CPU has **nothing to execute**.

---

# Why does a microcontroller need memory?

Suppose you write this program:

```c
int a = 10;
int b = 20;
int c;

c = a + b;
```

Where should the microcontroller keep:

* the program itself?
* the values of `a`, `b`, and `c`?
* intermediate results?

It needs memory.

---

# Types of Memory

In Cortex-M microcontrollers, there are two main memories.

```
Memory
│
├── Flash ROM
│
└── SRAM
```

These memories have different purposes.

---

# Flash Memory (Program Memory)

Flash stores your program permanently.

Think of it as a **library**.

```
Flash

main()

↓

GPIO_Init()

↓

while(1)

↓

LED_ON()

↓

delay()

↓

LED_OFF()
```

Even if power is removed,

the program stays there.

---

## Real-life example

Imagine a cookbook.

```
Recipe

↓

Take vegetables

↓

Wash

↓

Cut

↓

Cook

↓

Serve
```

Even if the chef goes home,

the recipe remains.

Flash memory is exactly like that cookbook.

It permanently stores instructions.

---

# SRAM (Data Memory)

SRAM stores

* variables
* arrays
* stack
* temporary calculations

Example

```c
int temperature = 30;
```

The value

```
30
```

is stored inside SRAM.

---

## Real-life example

Imagine a whiteboard.

During class,

the teacher writes

```
5+10=15
```

At the end,

the board is erased.

Tomorrow,

it is empty again.

SRAM behaves like the whiteboard.

When power goes OFF,

everything disappears.

---

# Flash vs SRAM

| Flash                            | SRAM                             |
| -------------------------------- | -------------------------------- |
| Stores program                   | Stores data                      |
| Permanent                        | Temporary                        |
| Slower                           | Faster                           |
| Large capacity                   | Smaller capacity                 |
| Does not lose data without power | Loses data when power is removed |

---

# Example

Suppose your LED blink program is

```c
int delay = 500;

int main()
{
    while(1)
    {
        LED_ON();
        wait(delay);
        LED_OFF();
        wait(delay);
    }
}
```

Where are these stored?

Program:

```c
main()

LED_ON()

LED_OFF()

wait()
```

↓

Flash

Variable

```c
delay = 500
```

↓

SRAM

---

# Real-Life Analogy

Imagine you are preparing for an exam.

### Flash

Your textbook.

It always remains.

---

### SRAM

Your rough notebook.

You solve problems there.

Tomorrow,

you erase it.

---

# Why can't everything be Flash?

Suppose you write

```c
temperature = temperature + 1;
```

This changes every second.

If stored in Flash,

the CPU would constantly rewrite Flash.

Flash has limited write cycles and is slower.

Instead,

variables go into SRAM.

---

# Why can't everything be SRAM?

Suppose power goes OFF.

Everything disappears.

When power comes back,

the CPU would not know

* where your program is
* what to execute

Therefore,

the program must be in Flash.

---

# How does the CPU use both?

Suppose you press the reset button.

Step 1

CPU starts.

↓

Step 2

Reads the program from Flash.

↓

Step 3

Copies initialized variables into SRAM.

↓

Step 4

Starts executing instructions.

---

# Real-Time Example

Imagine your washing machine.

Its software is permanently stored.

```
Wash

↓

Rinse

↓

Spin

↓

Finish
```

That software is in Flash.

During washing,

it stores

* remaining time
* water level
* temperature
* selected mode

These values change continuously.

They are stored in SRAM.

---

# Memory Capacity

The table in your book lists different microcontrollers.

For example:

| MCU           |    RAM |   Flash |
| ------------- | -----: | ------: |
| LM3S811       |   8 KB |   64 KB |
| TM4C123GH6PM  |  32 KB |  256 KB |
| TM4C1294NCPDT | 256 KB | 1024 KB |

Notice that all of them use the **same Cortex-M processor architecture**, but they differ in:

* Flash size
* SRAM size
* Number of GPIO pins
* Available peripherals (USB, CAN, Ethernet, PWM, DMA, etc.)

This is similar to buying laptops:

* One model has **8 GB RAM, 256 GB SSD**
* Another has **16 GB RAM, 512 GB SSD**

The CPU family may be the same, but the memory and features differ.

---

# What does "32 KB RAM" mean?

It means the microcontroller can store up to approximately **32 × 1024 bytes** of runtime data (variables, stack, buffers, etc.) in SRAM.

Similarly,

**256 KB Flash** means it can store about **256 × 1024 bytes** of program code and constants.

---

# Summary

```
                ARM Cortex-M MCU
        +----------------------------+
        |            CPU             |
        +-------------+--------------+
                      |
          -------------------------
          |                       |
          |                       |
     Flash Memory             SRAM
     (Program)               (Data)
          |                       |
  Permanent storage       Temporary storage
  main()                  Variables
  Functions               Stack
  Constants               Heap (if used)
```

---

## Key Points to Remember

* **Memory** stores both programs and data.
* **Flash** is non-volatile and stores your program permanently.
* **SRAM** is volatile and stores variables while the program is running.
* The CPU fetches instructions from **Flash** and reads/writes data in **SRAM**.
* Different Cortex-M microcontrollers mainly differ in **Flash size**, **RAM size**, and **available peripherals**, while sharing the same basic architecture.

---

# Part 2: ARM Cortex-M Memory Map (Figure 2.4)

---

# What is a Memory Map?

Imagine you live in a city.

The city has different areas.

```text
City

Residential Area
Commercial Area
Hospital Area
School Area
Airport
```

Every area has its own address.

For example

```text
House
↓

12 Gandhi Road
```

Hospital

```text
102 Hospital Road
```

Airport

```text
Airport Road
```

Every building has an address.

---

A microcontroller works exactly the same way.

Everything inside it has an address.

For example

```text
Flash

↓

0x00000000
```

RAM

↓

```text
0x20000000
```

GPIO

↓

```text
0x40000000
```

NVIC

↓

```text
0xE0000000
```

This complete address layout is called the

# Memory Map

---

# Why does everything need an address?

Suppose the CPU wants to

* read a variable
* turn ON an LED
* receive UART data

How does it know where these things are?

Answer:

By using addresses.

---

Real-life example

Imagine calling a friend.

You don't say

```text
Call someone.
```

You dial

```text
9876543210
```

That number identifies exactly one person.

Similarly,

The CPU identifies every memory location by its address.

---

# Memory Map of ARM Cortex-M

Your figure shows

```text
0x00000000
│
│ Flash ROM
│
0x0003FFFF
```

↓

```text
0x20000000
│
│ SRAM
│
0x20007FFF
```

↓

```text
0x40000000
│
│ GPIO
│ UART
│ Timers
│ ADC
│ SPI
│ I²C
│ PWM
│
0x400FFFFF
```

↓

```text
0xE0000000
│
│ NVIC
│ SysTick
│ SCB
│
0xE0041FFF
```

Think of this like different departments in a company.

---

# Region 1: Flash ROM

Starts at

```text
0x00000000
```

This stores

* Program
* Functions
* Constant data

Example

```c
int main()
{
    while(1)
    {
    }
}
```

The machine code for this program is stored here.

---

Real-life example

Think of Flash as

📚 Library

Books stay there permanently.

You read them.

You don't constantly rewrite them.

---

# Region 2: SRAM

Starts at

```text
0x20000000
```

Stores

* Variables
* Arrays
* Stack
* Temporary calculations

Example

```c
int temperature=25;
```

The value

```text
25
```

is stored inside SRAM.

---

Real-life example

Think of SRAM as

📝 Notebook

You write.

You erase.

You write again.

---

# Region 3: Peripheral Space

Starts at

```text
0x40000000
```

This is one of the biggest ideas in embedded systems.

Notice

GPIO

is NOT RAM.

UART

is NOT RAM.

Timer

is NOT RAM.

ADC

is NOT RAM.

But

the CPU accesses them

AS IF THEY WERE MEMORY.

This is called

# Memory-Mapped I/O

---

# What is Memory-Mapped I/O?

Suppose you want to turn ON an LED.

You might think

```text
CPU

↓

Send command to LED
```

Actually,

the CPU simply writes to a memory address.

Example

```text
Address

0x40025038
```

The CPU thinks

"I'm writing data to memory."

But

that address belongs to GPIO hardware.

So the LED turns ON.

---

Real-life example

Imagine your house.

Address

```text
House No. 10
```

belongs to

your home.

House

```text
No. 20
```

belongs to

a hospital.

The postman only knows addresses.

He doesn't care what building is there.

Similarly,

the CPU only knows addresses.

It doesn't know whether the address belongs to

* RAM
* Flash
* GPIO
* UART

The hardware decides.

---

# Example

Suppose

```c
GPIO_PORTF_DATA_R = 0x02;
```

What actually happens?

CPU writes

```text
0x02
```

to

```text
0x400253FC
```

That address belongs to

GPIO Port F.

LED becomes ON.

---

Notice

CPU never says

```text
Turn ON LED.
```

It only says

```text
Write 0x02 to address 0x400253FC.
```

---

# Region 4: PPB (Private Peripheral Bus)

Starts at

```text
0xE0000000
```

Contains

* NVIC
* SysTick
* SCB

These are

CPU-related peripherals.

---

Example

NVIC

handles interrupts.

SysTick

creates delays.

SCB

controls the processor.

---

Real-life example

Think of

PPB

as

Manager's office.

Ordinary employees

cannot access it directly.

Only important CPU functions use it.

---

# Why does RAM start at 0x20000000?

Students often ask

Why not

```text
0x00000001
```

or

```text
0x10000000
```

The answer is

ARM reserved different address ranges for different purposes.

| Address Range | Purpose            |
| ------------- | ------------------ |
| 0x00000000    | Flash              |
| 0x20000000    | SRAM               |
| 0x40000000    | Peripherals        |
| 0xE0000000    | System peripherals |

Because every Cortex-M follows this standard,

software becomes portable.

---

# What happens when CPU reads an address?

Suppose

```c
temperature++;
```

CPU wants

```text
temperature
```

Address

```text
0x20000010
```

CPU sees

```text
0x20000010
```

Since it begins with

```text
0x2
```

the hardware knows

"This is RAM."

---

Suppose

```text
0x40025038
```

CPU sees

```text
0x4
```

Hardware says

"This is GPIO."

---

Suppose

```text
0x00001000
```

Hardware says

"This is Flash."

---

So

The CPU doesn't manually decide.

The **memory map hardware** automatically routes each address to the correct destination.

---

# How the CPU Uses the Memory Map

Suppose your LED blink program runs.

```c
while(1)
{
    LED_ON();
}
```

The CPU performs these steps:

```text
Step 1

Read instruction

↓

Flash
```

↓

```text
Step 2

Read variable

↓

RAM
```

↓

```text
Step 3

Write GPIO register

↓

Peripheral Space
```

↓

```text
LED turns ON
```

Notice that in a single program, the CPU is accessing three different regions of the memory map.

---

# Why Different Buses? (Introduction)

Your book mentions:

* ICode Bus
* DCode Bus
* System Bus
* PPB
* AHB

Think of them as **different roads** in a city.

If every vehicle used one road, there would be traffic.

Instead:

* One road carries **instructions** (ICode).
* One road carries **constant data from Flash** (DCode).
* One road carries **RAM and peripheral accesses** (System Bus).
* One road carries **CPU control peripherals** (PPB).
* One high-speed road serves **fast peripherals** (AHB).

This allows multiple transfers to happen efficiently. We'll study each bus in detail in the next part.

---

# Complete Memory Map

```text
                ARM Cortex-M

 0x00000000
 +----------------------------+
 | Flash ROM                  |
 | Program                    |
 | Functions                  |
 | Constants                  |
 +----------------------------+

 0x20000000
 +----------------------------+
 | SRAM                       |
 | Variables                  |
 | Stack                      |
 | Arrays                     |
 +----------------------------+

 0x40000000
 +----------------------------+
 | GPIO                       |
 | UART                       |
 | SPI                        |
 | I²C                        |
 | Timers                     |
 | ADC                        |
 | PWM                        |
 +----------------------------+

 0xE0000000
 +----------------------------+
 | NVIC                       |
 | SysTick                    |
 | SCB                        |
 +----------------------------+
```

---

# Key Points to Remember

* Every memory location in a Cortex-M has a **unique address**.
* The **memory map** divides the address space into regions for Flash, SRAM, peripherals, and system peripherals.
* **Flash** stores program code and constants.
* **SRAM** stores variables, the stack, and temporary data.
* **Peripherals are memory-mapped**: the CPU controls hardware by reading from and writing to specific addresses.
* The CPU does not need separate instructions for GPIO, UART, or timers—it simply accesses their mapped addresses.

---



# Part 3: ARM Cortex-M Buses (ICode, DCode, System Bus, PPB, AHB)

Now we're going to answer an important question:

> **How does the CPU communicate with Flash, SRAM, GPIO, UART, and other peripherals?**

The answer is:

**Using buses.**

---

# What is a Bus?

A **bus** is a communication pathway that carries information between different parts of a computer or microcontroller.

Think of a bus as a **road**.

Just as roads carry vehicles, buses carry:

* Instructions
* Data
* Addresses
* Control signals

---

## Real-Life Example

Imagine a city.

```text
          Library
             |
             |
 School ---- Road ---- Hospital
             |
             |
          Railway Station
```

The road allows people to travel between places.

Similarly,

```text
Flash
   |
RAM ---- Bus ---- CPU ---- GPIO
   |
UART
```

The bus allows information to travel.

---

# Why Not Connect Everything Directly?

Suppose a microcontroller has

* Flash
* SRAM
* GPIO
* UART
* SPI
* ADC
* Timers
* PWM

If the CPU had separate wires to every peripheral,

```text
CPU
├── Flash
├── SRAM
├── GPIO
├── UART
├── ADC
├── Timer
├── SPI
├── I2C
├── PWM
├── CAN
├── USB
```

it would require a huge number of connections.

Instead,

everything communicates through buses.

---

# What Does a Bus Carry?

Every bus usually carries three kinds of information.

## 1. Address Bus

Tells **where** the CPU wants to access.

Example

```text
0x20000020
```

means

Read data from RAM address `0x20000020`.

---

## 2. Data Bus

Carries the actual data.

Example

```text
55
```

or

```text
0xABCD1234
```

---

## 3. Control Bus

Carries control signals such as

* Read
* Write
* Reset
* Interrupt acknowledge

These signals tell the hardware **what operation** the CPU wants to perform.

---

# Why Does Cortex-M Have Multiple Buses?

Students often ask:

> "Why not use one big bus?"

Imagine a city with only one road.

```text
School Bus

Ambulance

Fire Truck

Cars

Motorcycles

Lorries
```

All using the same road.

Result:

🚗 Traffic jam.

---

ARM avoids this by providing **multiple buses**.

Each bus has a specific job.

This improves speed because different transfers can occur without blocking each other.

---

# Cortex-M Bus Architecture

```text
                    +----------------+
                    |     CPU        |
                    +--------+-------+
                             |
        -------------------------------------------------
        |          |             |              |
     ICode      DCode       System Bus        PPB
        |          |             |              |
     Flash      Flash      RAM & Peripherals   NVIC
```

Each bus serves a different purpose.

---

# 1. ICode Bus (Instruction Bus)

ICode means

**Instruction Code Bus**

Its job is simple:

Fetch program instructions from Flash.

Example

```c
int main()
{
    LED_ON();
}
```

The instruction

```text
LED_ON()
```

is stored in Flash.

The CPU fetches it through the **ICode Bus**.

---

## Real-Life Example

Imagine reading a recipe.

```text
Recipe Book

↓

Read next instruction

↓

Cook
```

The recipe book is Flash.

Reading each step is the ICode Bus.

---

# What Travels on the ICode Bus?

Only **program instructions**.

Example

```text
MOV

ADD

SUB

LDR

STR

BL
```

These are ARM machine instructions.

The ICode Bus is **not** used for variables.

---

# 2. DCode Bus (Data Code Bus)

Students often ask:

"If ICode reads Flash, why do we need DCode?"

Because programs also store **constant data** in Flash.

Example

```c
const int table[4]={10,20,30,40};
```

The array

```text
10 20 30 40
```

is stored in Flash.

When the CPU reads it,

it uses the **DCode Bus**.

---

## Real-Life Example

Recipe book.

One page says

```text
Step 1

Boil water.
```

Another page says

```text
Ingredients

Salt

Oil

Rice
```

Instructions are read through the ICode Bus.

Constant data (ingredients) is read through the DCode Bus.

---

# Difference Between ICode and DCode

| ICode              | DCode                                   |
| ------------------ | --------------------------------------- |
| Reads instructions | Reads constant data                     |
| Flash              | Flash                                   |
| Executes program   | Reads lookup tables, constants, strings |

---

# Example

```c
const char name[]="ARM";
```

The CPU accesses

```text
ARM
```

using the DCode Bus.

---

# 3. System Bus

This is the busiest bus.

It connects the CPU to

* SRAM
* GPIO
* UART
* SPI
* ADC
* Timers
* DMA
* Most peripherals

Whenever the CPU accesses RAM or peripherals, it uses the **System Bus**.

---

## Example 1: Reading a Variable

```c
temperature++;
```

Suppose

```text
temperature
```

is stored at

```text
0x20000010
```

The CPU reads it through the **System Bus**.

---

## Example 2: Turning ON an LED

```c
GPIO_DATA = 0x01;
```

The GPIO register is in peripheral space (`0x40000000` onwards).

The CPU writes to it through the **System Bus**.

---

## Real-Life Example

Think of the System Bus as the **main highway** used by most traffic in a city.

---

# 4. PPB (Private Peripheral Bus)

PPB stands for

**Private Peripheral Bus**

It connects the CPU to internal system peripherals such as:

* NVIC (Nested Vectored Interrupt Controller)
* SysTick Timer
* SCB (System Control Block)
* Debug components

These are not ordinary peripherals.

They directly control CPU operation.

---

## Example

When an interrupt occurs:

```text
Button Press

↓

NVIC

↓

CPU jumps to Interrupt Service Routine
```

The CPU communicates with the NVIC through the PPB.

---

## Real-Life Example

Think of the PPB as the **manager's private office**.

Employees (GPIO, UART, Timers) work in the factory.

The manager communicates through a separate, private corridor.

---

# 5. AHB (Advanced High-performance Bus)

AHB stands for

**Advanced High-performance Bus**

It is a high-speed bus used for fast communication.

Many Cortex-M microcontrollers connect high-performance peripherals through the AHB, such as:

* High-speed GPIO
* DMA
* USB
* Ethernet
* External memory interfaces

Not every Cortex-M uses the AHB in exactly the same way; the exact implementation depends on the microcontroller manufacturer (such as STMicroelectronics, Texas Instruments, NXP, or Microchip).

---

## Why AHB?

Imagine copying a 1 MB file.

A slow road takes longer.

A highway moves traffic much faster.

Similarly,

AHB provides higher bandwidth for peripherals that need fast data transfer.

---

# How All the Buses Work Together

Suppose your program is:

```c
const int limit = 100;

int counter = 0;

int main()
{
    while (1)
    {
        if (counter < limit)
        {
            GPIO_DATA = 1;
            counter++;
        }
    }
}
```

### Step 1

CPU fetches

```text
while(1)
```

from Flash.

↓

**ICode Bus**

---

### Step 2

Reads

```text
limit
```

from Flash.

↓

**DCode Bus**

---

### Step 3

Reads

```text
counter
```

from SRAM.

↓

**System Bus**

---

### Step 4

Writes

```text
GPIO_DATA = 1;
```

to the GPIO register.

↓

**System Bus**

---

### Step 5

If a button interrupt occurs,

the CPU communicates with the NVIC.

↓

**PPB**

---

# Complete Data Flow

```text
                     +----------------+
                     |      CPU       |
                     +--------+-------+
                              |
        -------------------------------------------------
        |          |              |                 |
     ICode      DCode        System Bus           PPB
        |          |              |                 |
     Flash      Flash      RAM & GPIO         NVIC
 Instructions  Constants    UART Timer        SysTick
                           SPI ADC PWM        SCB
```

---

# Summary Table

| Bus            | Purpose                                       | Example                                                            |
| -------------- | --------------------------------------------- | ------------------------------------------------------------------ |
| **ICode Bus**  | Fetches program instructions from Flash       | `while(1)`, `ADD`, `MOV`                                           |
| **DCode Bus**  | Reads constant data stored in Flash           | `const` arrays, lookup tables, strings                             |
| **System Bus** | Accesses SRAM and most peripherals            | Variables, GPIO, UART, ADC, Timers                                 |
| **PPB**        | Connects CPU to internal system peripherals   | NVIC, SysTick, SCB                                                 |
| **AHB**        | High-speed bus for high-bandwidth peripherals | DMA, USB, Ethernet, high-speed GPIO (implementation varies by MCU) |

---

# Key Points to Remember

* A **bus** is a communication path between the CPU and other parts of the microcontroller.
* The **ICode Bus** fetches program instructions from Flash.
* The **DCode Bus** reads constant data stored in Flash.
* The **System Bus** is used for RAM and most peripherals.
* The **PPB** connects the CPU to system control components like the NVIC and SysTick.
* The **AHB** provides a high-speed communication path for peripherals that require high bandwidth.

---

# Part 4: Bit-Banding (Table 2.2) – From Scratch

This is one of the most interesting features in ARM Cortex-M3 and Cortex-M4 processors.

Many beginners find it confusing because of the name. By the end of this chapter, you'll understand:

* What bit-banding is
* Why ARM introduced it
* How it works
* How to calculate bit-band addresses
* Real-time examples with GPIO
* Its advantages and limitations

> **Note:** Bit-banding is available on many Cortex-M3 and Cortex-M4 devices, but **not on Cortex-M0/M0+**, and it is **optional or absent on many newer Cortex-M families**. Always check your microcontroller's reference manual.

---

# Why Do We Need Bit Manipulation?

Suppose an LED is connected to **bit 3** of a GPIO register.

Example register:

```text
GPIO_DATA Register

Bit:

7 6 5 4 3 2 1 0

0 0 0 0 0 0 0 0
```

To turn ON the LED,

we need to make

```text
Bit 3 = 1
```

Result:

```text
7 6 5 4 3 2 1 0

0 0 0 0 1 0 0 0
```

Only one bit changes.

---

# The Traditional Method

Normally we write

```c
GPIO_DATA |= (1 << 3);
```

The processor performs several operations:

### Step 1

Read the register.

```text
00000000
```

↓

### Step 2

Modify one bit.

```text
00001000
```

↓

### Step 3

Write it back.

Three operations are required:

```text
Read

↓

Modify

↓

Write
```

This is called a **Read-Modify-Write** sequence.

---

# What Problem Can Occur?

Imagine two people sharing a whiteboard.

Person A:

```text
Changes Bit 3
```

Person B:

```text
Changes Bit 5
```

If both work at the same time,

one person's changes may overwrite the other's.

The same thing can happen if an interrupt occurs between the read and write operations.

---

# Example

Suppose the register initially contains:

```text
00000000
```

Main program wants:

```text
Bit 3 = 1
```

Interrupt wants:

```text
Bit 5 = 1
```

Sequence:

```text
Main reads

00000000
```

↓

Interrupt changes register

```text
00100000
```

↓

Main writes back

```text
00001000
```

Oops!

Bit 5 has been lost.

This is called a **race condition**.

---

# ARM's Solution: Bit-Banding

Instead of reading the whole register,

ARM creates a **special address** for **every single bit**.

Instead of:

```text
32-bit register
```

you can directly access

```text
Bit 0

Bit 1

Bit 2

Bit 3

...

Bit 31
```

Each bit behaves like its own 32-bit word.

---

# Real-Life Example

Imagine a building with 32 rooms.

Normally,

you open the main door,

walk inside,

go to Room 18,

and switch on the light.

With bit-banding,

every room has its own outside door.

You go directly to Room 18.

No one else is disturbed.

---

# How Bit-Banding Works

ARM reserves two special regions.

## Bit-band Region

Contains the actual memory.

For SRAM:

```text
0x20000000
↓

0x200FFFFF
```

(1 MB region)

---

## Alias Region

Contains the alias addresses.

```text
0x22000000
↓

0x23FFFFFF
```

(32 MB region)

---

Relationship:

```text
Real Memory

↓

One Bit

↓

Alias Address

↓

Write 0 or 1
```

Writing to the alias address automatically changes exactly one bit in the real memory.

---

# Example

Suppose

```text
Address

0x20000000
```

contains

```text
00000000
```

Suppose we want

```text
Bit 3 = 1
```

Instead of

```c
variable |= (1<<3);
```

we write

```text
*(alias address)=1;
```

Hardware automatically updates only Bit 3.

Result

```text
00001000
```

---

# Why Is It Safe?

The CPU performs

one write

instead of

```text
Read

↓

Modify

↓

Write
```

No race condition.

No interrupt problem.

Only one bit changes.

This is called an **atomic operation**.

---

# What Does "Atomic" Mean?

An atomic operation is one that:

* cannot be interrupted halfway,
* appears as a single, indivisible action to the rest of the system.

Think of pressing a lift button. You either press it or you don't—there is no "half-pressed" state visible to the controller.

---

# Memory Layout

```text
SRAM Bit-Band Region

0x20000000

↓

Actual Data

↓

1 MB
```

↓

```text
Alias Region

0x22000000

↓

32 MB
```

Every bit in the 1 MB region has its own alias word in the 32 MB alias region.

---

# Why Is the Alias Region 32 Times Larger?

One word (32 bits) is used to represent **one bit**.

Suppose SRAM has

```text
1 Byte

↓

8 Bits
```

Each bit gets

```text
1 Word

↓

4 Bytes
```

Therefore,

```text
8 Bits

↓

8 × 4

↓

32 Bytes
```

This is why the alias region is much larger.

---

# Bit-Band Formula

ARM defines the alias address as:

```text
Alias Address =
Alias Base
+
(Byte Offset × 32)
+
(Bit Number × 4)
```

Where:

* **Alias Base** = `0x22000000` (for SRAM)
* **Byte Offset** = Address − `0x20000000`
* **Bit Number** = 0–7 (for a byte) or the desired bit within the addressed word

This is the formula shown in many Cortex-M reference manuals.

---

# Example Calculation

Suppose:

```text
Real Address

0x20000000
```

We want

```text
Bit 3
```

### Step 1

Byte Offset

```text
0
```

---

### Step 2

Multiply by 32

```text
0
```

---

### Step 3

Bit Number × 4

```text
3 × 4

↓

12
```

---

### Step 4

Add Alias Base

```text
0x22000000

+

12

=

0x2200000C
```

So:

```text
Alias Address

0x2200000C
```

Writing:

```c
*(volatile uint32_t *)0x2200000C = 1;
```

sets bit 3 of the byte at `0x20000000`.

Writing:

```c
*(volatile uint32_t *)0x2200000C = 0;
```

clears bit 3.

---

# GPIO Example

Suppose LED is connected to

```text
Bit 1
```

Instead of

```c
GPIO_DATA |= (1<<1);
```

Bit-banding allows a direct write to the corresponding alias address:

```text
Alias Address

↓

Write 1
```

↓

Hardware automatically changes only **Bit 1**.

No masking required.

No read-modify-write sequence.

---

# Advantages

* Very easy single-bit access.
* Atomic bit updates.
* No race conditions during single-bit writes.
* Faster than a read-modify-write sequence in many situations.
* Simplifies embedded code.

---

# Limitations

* Available only for specific memory regions.
* Not supported by Cortex-M0/M0+.
* Not implemented on many newer Cortex-M devices.
* Code using bit-banding is less portable because not every Cortex-M microcontroller supports it.

---

# Summary Diagram

```text
            Real SRAM
        +-----------------+
        | 0x20000000      |
        |                 |
        | Bit 0           |
        | Bit 1           |
        | Bit 2           |
        | Bit 3           |
        | ...             |
        +-----------------+
                |
                | Bit-band hardware
                |
                v
        +-----------------+
        | Alias Region    |
        | 0x22000000      |
        | One word/bit    |
        +-----------------+
```

---

# Key Points to Remember

* **Bit-banding** provides a separate alias address for each individual bit in specific SRAM and peripheral regions.
* It allows **atomic** setting or clearing of a single bit with one write.
* It avoids the problems associated with **read-modify-write** operations.
* The alias address is calculated using the ARM-defined bit-band formula.
* Always verify whether your Cortex-M microcontroller supports bit-banding before using it.

---

# Part 5: Checkpoint 2.1, Memory Access, and Complete Cortex-M Memory Architecture

So far you've learned:

* ✅ Registers
* ✅ Flash vs SRAM
* ✅ Memory Map
* ✅ Buses
* ✅ Bit-Banding

Now we'll connect everything together and see **how the CPU actually executes a program**.

---

# The Big Picture

Imagine you press the **Reset** button on an STM32 or TM4C microcontroller.

What happens?

Does the CPU immediately blink an LED?

No.

The CPU follows a sequence.

```text
Power ON

↓

CPU Reset

↓

Read Reset Vector

↓

Load Stack Pointer

↓

Start main()

↓

Execute Program
```

Let's understand every step.

---

# Step 1: Power ON

When power is applied,

all circuits become active.

```text
CPU

Flash

RAM

GPIO

UART

ADC

Clock
```

Everything is powered.

But nothing has started executing yet.

---

# Step 2: CPU Looks at Address 0x00000000

Remember our memory map?

```text
0x00000000

↓

Flash
```

The Cortex-M architecture defines that **the beginning of the address space contains startup information**.

The CPU reads from Flash immediately after reset.

---

## What is Stored There?

The first few words of Flash contain:

```text
Address

0x00000000

↓

Initial Stack Pointer
```

Next word

```text
0x00000004

↓

Reset Handler Address
```

---

# What is the Reset Handler?

The Reset Handler is the **first function executed after reset**.

It is not `main()`.

Typical sequence:

```text
Reset

↓

Reset_Handler()

↓

System Initialization

↓

main()
```

---

# Why Doesn't the CPU Jump Directly to `main()`?

Because before `main()` runs, several things must be prepared.

For example:

* Stack pointer
* Clock configuration
* Copying initialized variables from Flash to RAM
* Clearing the `.bss` section
* Initializing the C runtime

Only after that is `main()` called.

---

# Step 3: Stack Pointer is Loaded

Suppose Flash contains:

```text
0x00000000

↓

0x20008000
```

This value becomes

```text
SP = 0x20008000
```

The CPU now knows where the stack begins.

---

## Real-Life Example

Imagine opening a notebook.

Before solving problems,

you first decide

"Start writing from this page."

That page is like the Stack Pointer.

---

# Step 4: Reset Handler Executes

The CPU fetches instructions through the **ICode Bus**.

Example:

```c
Reset_Handler()
{
    SystemInit();
    __libc_init_array();
    main();
}
```

Notice:

The CPU is already reading instructions from Flash.

---

# Step 5: Variables are Prepared

Suppose your program contains:

```c
int count = 5;
```

Although `count = 5` is stored in Flash,

the variable must exist in RAM while the program runs.

The Reset Handler copies it.

```text
Flash

count = 5

↓

Copy

↓

RAM

count = 5
```

---

# Another Example

```c
int a = 10;
int b = 20;
```

Stored permanently:

```text
Flash
```

Copied at startup:

```text
RAM
```

Now the CPU uses the RAM copies.

---

# Step 6: Uninitialized Variables

Suppose

```c
int temperature;
```

No initial value is given.

The compiler places it in the **.bss** section.

During startup,

the Reset Handler clears it.

```text
RAM

temperature = 0
```

---

# Step 7: `main()` Starts

Finally,

```c
int main()
{
    while(1)
    {
    }
}
```

begins executing.

Only now does your application actually start.

---

# Complete Startup Flow

```text
Power ON

↓

CPU Reset

↓

Read Flash

↓

Load Stack Pointer

↓

Reset Handler

↓

Copy Variables

↓

Clear BSS

↓

Initialize Clock

↓

main()
```

This entire sequence usually happens in **milliseconds**.

---

# How Does the CPU Decide Which Memory to Access?

Suppose the CPU wants to read

```c
temperature
```

Address:

```text
0x20000020
```

The CPU places this address on the **address bus**.

The hardware checks:

```text
Starts with 0x2

↓

SRAM
```

So the request goes to SRAM.

---

Suppose the CPU wants

```text
0x00002000
```

Hardware checks:

```text
Starts with 0x0

↓

Flash
```

---

Suppose

```text
0x40004000
```

Hardware says:

```text
Peripheral
```

Maybe GPIO,

UART,

SPI,

Timer,

or ADC.

---

Suppose

```text
0xE000E100
```

Hardware says:

```text
NVIC
```

---

# The CPU Doesn't Know the Device

This is an important concept.

The CPU **does not know**:

* "This is GPIO."
* "This is UART."

The CPU only knows:

```text
Read address

Write address
```

The **memory system** routes the access to the correct hardware.

---

# Real-Time Example

Imagine a courier company.

Courier receives:

```text
Address:

12 Park Road
```

The courier doesn't know whether it is

* House
* School
* Office
* Hospital

The address determines the destination.

The CPU works exactly the same way.

---

# Complete Memory Architecture

```text
                   +----------------------+
                   |       Cortex-M CPU   |
                   +----------+-----------+
                              |
         ------------------------------------------------
         |             |             |                  |
      ICode         DCode       System Bus           PPB
         |             |             |                  |
      Flash         Flash     RAM & Peripherals       NVIC
 Instructions     Constants   GPIO UART SPI ADC      SysTick
                               Timers PWM DMA        SCB
```

Everything is connected through buses.

---

# Complete Program Execution Example

Program:

```c
const int LIMIT = 100;

int count = 0;

int main()
{
    while(1)
    {
        if(count < LIMIT)
        {
            GPIO_DATA = 1;
            count++;
        }
    }
}
```

### CPU Execution

---

### Instruction Fetch

```text
Flash

↓

ICode Bus

↓

CPU
```

Instruction:

```text
if(count < LIMIT)
```

---

### Read Constant

```text
LIMIT

↓

Flash

↓

DCode Bus

↓

CPU
```

---

### Read Variable

```text
count

↓

RAM

↓

System Bus

↓

CPU
```

---

### Write GPIO

```text
GPIO_DATA = 1;

↓

Peripheral

↓

LED ON
```

---

### Interrupt Occurs

Button pressed.

```text
Button

↓

NVIC

↓

PPB

↓

CPU

↓

Interrupt Service Routine
```

---

# Checkpoint 2.1 Practice Questions

Here are questions similar to what your textbook expects.

### Question 1

Where is the program stored?

**Answer:**

Flash memory.

---

### Question 2

Where are variables stored during execution?

**Answer:**

SRAM.

---

### Question 3

Which bus fetches instructions?

**Answer:**

ICode Bus.

---

### Question 4

Which bus reads constant data from Flash?

**Answer:**

DCode Bus.

---

### Question 5

Which bus accesses GPIO?

**Answer:**

System Bus.

---

### Question 6

Which bus connects the CPU to the NVIC?

**Answer:**

PPB.

---

### Question 7

Where does the CPU start after reset?

**Answer:**

It begins by reading the startup information from **Flash at address `0x00000000`**, loading the initial Stack Pointer and Reset Handler.

---

### Question 8

Why is SRAM volatile?

**Answer:**

Because its contents are lost when power is removed.

---

### Question 9

Why is Flash non-volatile?

**Answer:**

Because it retains data even without power.

---

### Question 10

What is memory-mapped I/O?

**Answer:**

A technique where peripherals are assigned memory addresses, allowing the CPU to control hardware using ordinary memory read and write operations.

---

# Interview Questions

1. What is the difference between Flash and SRAM?
2. Why does Cortex-M use a Harvard architecture?
3. Explain the memory map of Cortex-M.
4. What is memory-mapped I/O?
5. Why are there separate ICode and DCode buses?
6. What is the purpose of the System Bus?
7. What happens immediately after a Cortex-M reset?
8. What is the Reset Handler?
9. Why must initialized variables be copied from Flash to RAM?
10. What is the role of the Stack Pointer during startup?

---

# Complete Chapter Summary

```text
                 Cortex-M Memory System

          +-------------------------------+
          |            CPU                |
          +---------------+---------------+
                          |
      -------------------------------------------------
      |              |              |                 |
   ICode         DCode         System Bus          PPB
      |              |              |                 |
   Flash         Flash         SRAM              NVIC
 Instructions    Constants     GPIO              SysTick
                               UART              SCB
                               SPI
                               ADC
                               Timers
                               PWM

Memory Map

0x00000000 → Flash
0x20000000 → SRAM
0x40000000 → Peripherals
0xE0000000 → System Peripherals
```

---

Excellent! This is one of the **most important topics** in embedded systems. Every function call, interrupt, RTOS task, and local variable uses the **stack**. I'll explain it from **scratch** with simple examples and diagrams.

---

# Part 6: Stack (ARM Cortex-M)

---

# What is a Stack?

A **stack** is a special area of **RAM** used to temporarily store data.

It follows a rule called

> **LIFO (Last In, First Out)**

Meaning

> **The last item placed on the stack is the first one removed.**

---

## Real-Life Example 1: Stack of Plates 🍽️

Imagine plates stacked in a restaurant.

```
      Top
    +-------+
    | Plate3|
    +-------+
    | Plate2|
    +-------+
    | Plate1|
    +-------+
```

Suppose you add plates one by one.

```
Add Plate1

↓

Add Plate2

↓

Add Plate3
```

Now if you remove a plate,

which comes first?

```
Plate3
```

Then

```
Plate2
```

Then

```
Plate1
```

This is exactly how a stack works.

---

# Why Does a CPU Need a Stack?

Suppose you write

```c
int add(int a,int b)
{
    int c;

    c=a+b;

    return c;
}
```

While this function executes,

the CPU must temporarily store

* local variables
* return address
* registers
* function parameters (sometimes)
* interrupt information

Where should these be stored?

Answer:

**Stack**

---

# Where is the Stack Stored?

The stack is **not a separate memory chip**.

It is simply a reserved area inside **SRAM**.

```
SRAM

+----------------------+
| Global Variables     |
+----------------------+
| Heap (optional)      |
+----------------------+
|                      |
| Free Memory          |
|                      |
+----------------------+
| Stack                |
+----------------------+
```

The stack uses normal RAM.

---

# What is the Stack Pointer (SP)?

The CPU must know

> "Where is the top of the stack?"

It stores this address inside a register called

```
SP
```

(Stack Pointer)

Example

```
SP = 0x20007FF0
```

means

```
Top of Stack

↓

0x20007FF0
```

---

# Why is it Called "Pointer"?

Because

it **points** to memory.

Think of a bookmark inside a book.

```
Book

↓

Bookmark

↓

Current Page
```

SP is the bookmark.

---

# ARM Stack Grows Downward

This surprises almost every beginner.

The stack grows

**from higher addresses toward lower addresses.**

Example

```
Higher Address

0x20008000

↓

0x20007FFC

↓

0x20007FF8

↓

0x20007FF4

↓

Lower Address
```

Notice

addresses become **smaller**.

---

## Why Downward?

ARM designers reserved the top of RAM for the stack so it can grow downward while global variables typically occupy lower addresses. This lets the two areas use RAM efficiently.

---

# Example

Suppose

```
SP = 0x20008000
```

Stack is empty.

```
Address

0x20008000  ← SP
```

---

# PUSH Operation

Suppose

```
R0 = 100
```

Now execute

```asm
PUSH {R0}
```

---

## Step 1

Decrease SP

```
SP

0x20008000

↓

0x20007FFC
```

Why?

Because ARM stores 32-bit data.

```
32 bits

=

4 bytes
```

So SP moves by **4 bytes**.

---

## Step 2

Store the data

```
Address          Data

0x20007FFC  →   100
```

Now

```
SP

↓

0x20007FFC
```

The stack looks like

```
Top

100
```

---

# Another PUSH

Suppose

```
R1 = 200
```

Execute

```asm
PUSH {R1}
```

SP becomes

```
0x20007FF8
```

Memory

```
0x20007FF8 → 200

0x20007FFC → 100
```

Stack

```
Top

200

100
```

---

# Another PUSH

```
R2 = 300
```

Execute

```asm
PUSH {R2}
```

Memory

```
0x20007FF4 → 300

0x20007FF8 → 200

0x20007FFC → 100
```

Stack

```
Top

300

200

100
```

Notice

The newest value is always on top.

---

# POP Operation

Suppose

```asm
POP {R3}
```

The CPU performs two steps.

---

## Step 1

Read memory.

```
R3

↓

300
```

---

## Step 2

Increase SP.

```
0x20007FF4

↓

0x20007FF8
```

Now

Top becomes

```
200
```

---

# Continue

```
POP {R4}
```

R4

↓

```
200
```

SP

↓

```
0x20007FFC
```

---

Next

```
POP {R5}
```

R5

↓

```
100
```

SP

↓

```
0x20008000
```

Stack is empty again.

---

# What Happened in Your Book?

Initially

```
R0 = 1

R1 = 2

R2 = 3
```

Program

```asm
PUSH {R0}

PUSH {R1}

PUSH {R2}

POP {R3}

POP {R4}

POP {R5}
```

Final result

```
R3 = 3

R4 = 2

R5 = 1
```

Exactly because

**Last In → First Out**

---

# Why Does PUSH Decrement SP First?

ARM uses a **full descending stack**.

That means:

1. Move SP to the next free location.
2. Store the value there.

Example

```
Old SP

↓

0x20008000

↓

Subtract 4

↓

0x20007FFC

↓

Store data
```

---

# Why Does POP Read First?

Because SP already points to valid data.

So

```
Read

↓

Increase SP
```

---

# Stack Rules

Your book lists five important rules.

## Rule 1

Every PUSH should have a matching POP.

Example

```asm
PUSH {R0}

PUSH {R1}

POP {R1}

POP {R0}
```

Balanced.

---

## Rule 2

Never go outside the allocated stack.

If stack size is

```
4 KB
```

Don't push beyond it.

---

## Rule 3

Don't write into unused stack space manually.

Interrupts and function calls may use it later, leading to corruption.

---

## Rule 4

PUSH

```
Decrease SP

↓

Store Data
```

---

## Rule 5

POP

```
Read Data

↓

Increase SP
```

---

# What is Stack Overflow?

Suppose stack size

```
4 KB
```

But program pushes

```
6 KB
```

The stack grows beyond its reserved region.

```
Allocated Stack

+----------------+
|                |
|                |
+----------------+

↓

More PUSH

↓

Outside Stack
```

This is

**Stack Overflow**

---

## Real-Life Example

Imagine a cupboard with space for **100 plates**.

You keep adding more plates.

Eventually,

plates fall into the next cupboard.

Similarly,

a stack overflow overwrites neighbouring memory.

---

# What is Stack Underflow?

Suppose

```asm
POP
```

is executed

without a previous

```asm
PUSH
```

The CPU tries to remove data that isn't there.

This is called

**Stack Underflow**

---

## Real-Life Example

Trying to remove a plate from an empty stack.

Nothing is there.

---

# Why Interrupts Use the Stack

Suppose CPU is running

```c
while(1)
{
}
```

Suddenly,

a button is pressed.

The CPU must remember where it was before jumping to the interrupt.

So it automatically pushes information such as:

* Program Counter (PC)
* Link Register (LR)
* xPSR
* R0–R3, R12 (on exception entry)

onto the stack before executing the Interrupt Service Routine (ISR).

After the ISR finishes, the CPU pops this information and resumes the interrupted program.

---

# Why the Initial SP is Set to the Top of RAM

Suppose RAM is

```
0x20000000

↓

0x20007FFF
```

The stack usually starts at

```
0x20008000
```

(the first address above the RAM region).

Initially,

```
SP

↓

0x20008000
```

As data is pushed,

the stack grows downward into valid RAM.

---

# Summary Diagram

```
                RAM

High Address
0x20008000
+----------------------+
|      Empty           | ← Initial SP
+----------------------+
|                      |
|      Stack           |
|                      |
|   PUSH ↓             |
|                      |
+----------------------+
|   Free Memory        |
+----------------------+
| Global Variables     |
+----------------------+
| Static Variables     |
+----------------------+
0x20000000
Low Address
```

---

# Key Points to Remember

* A **stack** is a temporary storage area in **SRAM**.
* It follows the **LIFO (Last In, First Out)** principle.
* The **Stack Pointer (SP)** always points to the **top of the stack**.
* On ARM Cortex-M, the stack **grows downward**, so pushing data **decrements** the SP by 4 bytes, and popping data **increments** it by 4 bytes.
* Every `PUSH` should have a corresponding `POP`.
* **Stack overflow** occurs when the stack grows beyond its allocated region.
* **Stack underflow** occurs when data is popped from an empty stack.
* Function calls and interrupts rely heavily on the stack to save temporary state and return correctly.

Excellent! These sections (**2.1.4 Operating Modes** and **2.1.5 Reset**) are fundamental to understanding how a Cortex-M processor runs programs and handles interrupts. Let's study them from the beginning with simple examples.

---

# Part 7: Operating Modes (ARM Cortex-M)

Before learning operating modes, let's answer a simple question.

> **Who is controlling the microcontroller?**

Sometimes it's:

* Your main program (`main()`)
* An interrupt (button press, timer interrupt, UART receive, etc.)
* An operating system (FreeRTOS, Zephyr, etc.)

ARM provides different operating modes to manage these safely.

---

# What is an Operating Mode?

An operating mode tells the CPU:

* Who is currently running?
* What permissions does the code have?
* Which stack should be used?

Think of it like different roles in a company.

---

## Real-Life Example

Imagine a company.

There are two types of employees.

### Employee

Can

* Read files
* Write reports

Cannot

* Change company rules
* Hire employees
* Access the server room

---

### Manager

Can do everything.

* Access server room
* Change policies
* Hire employees
* Reset systems

ARM works exactly the same way.

---

# ARM Has Two Privilege Levels

## 1. Privileged Mode

This is the administrator mode.

Code running here can

* Configure clocks
* Configure NVIC
* Access SysTick
* Change system registers
* Change privilege levels

Everything is allowed.

---

## 2. Unprivileged Mode

This is the user mode.

Restrictions include access to

* NVIC
* SysTick
* Certain system control registers

This prevents user programs from accidentally damaging the system.

---

# Why Do We Need Two Levels?

Imagine you're writing a calculator application.

Should it be able to disable all interrupts?

No.

Only the operating system should have that permission.

That's why ARM separates user code from system code.

---

# CONTROL Register

ARM stores these settings inside the **CONTROL register**.

The two important bits are:

| Bit   | Name                           | Purpose                                |
| ----- | ------------------------------ | -------------------------------------- |
| Bit 0 | Thread Privilege Level (nPRIV) | Privileged or Unprivileged Thread mode |
| Bit 1 | SPSEL (ASPSEL in some texts)   | Selects PSP or MSP in Thread mode      |

> **Note:** Modern ARM documentation usually calls bit 0 **nPRIV** and bit 1 **SPSEL**.

---

# Bit 0: Privilege Level

```text
CONTROL Register

Bit0
```

If

```text
0
```

Thread mode runs as **Privileged**.

If

```text
1
```

Thread mode runs as **Unprivileged**.

> Your textbook reverses this description. According to the ARM Cortex-M architecture, **nPRIV = 0 means Privileged** and **nPRIV = 1 means Unprivileged**.

---

## Example

Suppose

```text
CONTROL = 0
```

The CPU has full permission.

---

Suppose

```text
CONTROL = 1
```

The CPU becomes an ordinary user.

---

# Bit 1: Stack Selection

ARM Cortex-M has **two stack pointers**.

Earlier we studied:

* MSP
* PSP

Now we'll understand why.

---

# MSP (Main Stack Pointer)

Used by

* Startup code
* Reset
* Interrupts
* Operating system kernel

Think of it as

**System Stack**

---

# PSP (Process Stack Pointer)

Used by

* User programs
* Tasks
* Threads

Think of it as

**Application Stack**

---

## Real-Life Example

Imagine a hospital.

There are

### Doctors

Have their own workspace.

↓

PSP

---

### Emergency Team

Has its own emergency room.

↓

MSP

The two groups don't interfere with each other.

---

# Which Stack is Used?

If

```text
SPSEL = 0
```

Use

```text
MSP
```

---

If

```text
SPSEL = 1
```

Use

```text
PSP
```

---

# Why Two Stacks?

Imagine an operating system.

Application

↓

```text
Play Music
```

Interrupt occurs

↓

```text
UART Interrupt
```

Should the interrupt use the application's stack?

No.

Interrupts use the MSP.

This keeps interrupt handling reliable.

---

# Thread Mode vs Handler Mode

ARM defines **how** the CPU is currently running.

There are two execution modes.

---

# Thread Mode

Thread Mode means

Normal program execution.

Example

```c
int main()
{
    while(1)
    {
    }
}
```

This runs in

```text
Thread Mode
```

---

# Handler Mode

Handler Mode means

The CPU is executing an **Interrupt Service Routine (ISR)**.

Example

```c
void GPIO_Handler()
{
}
```

This executes in

```text
Handler Mode
```

---

# Real-Life Example

Imagine a teacher teaching a class.

Normal teaching

↓

Thread Mode

Suddenly

Fire alarm rings.

Teacher immediately handles the emergency.

↓

Handler Mode

Emergency finishes.

Teacher returns to the lesson.

↓

Thread Mode

---

# Switching Between Modes

Suppose

```c
while(1)
{
}
```

CPU is running.

↓

Thread Mode

Now

Timer interrupt occurs.

↓

CPU automatically switches to

```text
Handler Mode
```

After ISR finishes

↓

CPU returns to

```text
Thread Mode
```

All of this happens automatically.

---

# ISR_NUMBER

ARM uses a field called

```text
ISR_NUMBER
```

to identify which interrupt is currently active.

When

```text
ISR_NUMBER = 0
```

No interrupt.

CPU is in Thread Mode.

---

Suppose

UART interrupt.

```text
ISR_NUMBER = 21
```

The CPU knows

"I'm servicing UART."

---

# Important Point

All interrupt service routines

always use

```text
MSP
```

Never PSP.

---

# Complete Mode Diagram

```text
               CPU

        +-----------------+
        | Thread Mode     |
        | main()          |
        +--------+--------+
                 |
         Interrupt occurs
                 |
                 v
        +-----------------+
        | Handler Mode    |
        | ISR             |
        +--------+--------+
                 |
        ISR completes
                 |
                 v
        +-----------------+
        | Thread Mode     |
        +-----------------+
```

---

# Part 8: Reset

Now let's understand what happens when power is applied.

---

# What is Reset?

Reset means

Start the processor from the beginning.

It occurs when

* Power is applied
* Reset button is pressed
* Software requests a reset
* Watchdog timer expires (depending on configuration)

---

## Real-Life Example

Restarting your laptop.

Everything starts from the beginning.

---

# After Reset

ARM Cortex-M always starts in

Thread Mode

↓

Privileged

↓

Using MSP

Exactly as your book states.

---

# Step 1

CPU reads

```text
Flash Address

0x00000000
```

This location contains

Initial Stack Pointer.

Example

```text
0x20008000
```

The CPU loads

```text
SP = 0x20008000
```

---

# Step 2

CPU reads

```text
Flash Address

0x00000004
```

This contains

Reset Vector.

Example

```text
Reset_Handler()
```

The CPU loads this address into the Program Counter (PC).

---

# What is the Reset Vector?

The reset vector is simply the **address of the Reset Handler**.

The CPU jumps there immediately after reset.

---

# Why Doesn't It Jump to `main()`?

Because the system must first:

* Set up the stack
* Initialize memory
* Configure the clock
* Initialize the C runtime

Only then does it call

```c
main();
```

---

# Word Alignment

Your book says

> Stack accesses are word aligned.

A Cortex-M word is

```text
32 bits

=

4 bytes
```

Therefore,

valid stack addresses are multiples of 4.

Examples

```text
0x20008000

✓
```

```text
0x20008004

✓
```

```text
0x20008008

✓
```

Invalid

```text
0x20008002

✗
```

because it is not 4-byte aligned.

---

# Halfword Alignment

Instructions are fetched in **16-bit (halfword)** units because Cortex-M executes the **Thumb instruction set**.

A halfword is

```text
16 bits

=

2 bytes
```

Instruction addresses must therefore be aligned on 2-byte boundaries.

---

# Thumb State (T Bit)

ARM Cortex-M processors execute **only Thumb instructions**.

The processor status register (xPSR) contains the **T bit**.

```text
T = 1
```

means

Thumb mode.

On Cortex-M,

this bit is always set.

Unlike older ARM processors, Cortex-M does **not** execute classic 32-bit ARM instruction mode.

---

# Link Register After Reset

Your book says

```text
LR = 0xFFFFFFFF
```

Why?

Because there is **no function to return to** after reset.

The CPU has just started.

---

# Complete Reset Sequence

```text
Power ON

↓

Reset

↓

Thread Mode

↓

Privileged

↓

MSP Selected

↓

Read SP from Flash[0]

↓

Read Reset Vector from Flash[4]

↓

Jump to Reset_Handler()

↓

Initialize Memory

↓

main()
```

---

# Summary

| Topic                 | Meaning                                                                   |
| --------------------- | ------------------------------------------------------------------------- |
| **Privileged Mode**   | Full access to system resources                                           |
| **Unprivileged Mode** | Restricted access for user applications                                   |
| **Thread Mode**       | Normal program execution (`main()`)                                       |
| **Handler Mode**      | Interrupt Service Routine execution                                       |
| **MSP**               | Main Stack Pointer, used after reset and during interrupts                |
| **PSP**               | Process Stack Pointer, typically used by applications/tasks under an RTOS |
| **Reset Vector**      | Address of the `Reset_Handler()` stored at Flash address `0x00000004`     |
| **Initial SP**        | Loaded from Flash address `0x00000000`                                    |
| **Thumb State**       | Cortex-M always executes Thumb instructions (`T = 1`)                     |

---

## Key Points to Remember

* After a reset, the Cortex-M starts in **Thread Mode**, **Privileged**, using the **MSP**.
* The CPU first loads the **initial Stack Pointer** from address `0x00000000`.
* It then loads the **Reset Handler address** (reset vector) from address `0x00000004` and begins execution there.
* An interrupt automatically switches the processor from **Thread Mode** to **Handler Mode** and uses the **MSP**.
* In systems with an RTOS, user tasks commonly run in **Thread Mode** using the **PSP**, while the kernel and interrupts use the **MSP**.
