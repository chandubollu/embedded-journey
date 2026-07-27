Excellent. This is the **foundation of the entire Cortex-M architecture**. If you understand this section deeply, everything in the following chapters becomes much easier.

I'll explain it **exactly as if you're learning computer architecture for the first time**, without skipping a single concept. I'll distinguish between **what the book says** and **additional background** only when necessary.

---

# CHAPTER 1

# 1.1 What are the ARM Cortex-M Processors?

Before understanding Cortex-M3 or Cortex-M4, we must answer three basic questions:

1. What is **ARM**?
2. What is a **processor**?
3. What is **Cortex-M**?

---

# 1. What is ARM?

The book says:

> **The Cortex-M3 and Cortex-M4 are processors designed by ARM.**

This single sentence contains several important ideas.

## ARM is a company

ARM is **not** a microcontroller manufacturer.

ARM designs:

* Processor architectures
* CPU cores
* Instruction sets

It **licenses** these designs to other companies.

Think of ARM as an architect.

```text
ARM
│
├── Designs processor
│
├── Creates instruction set
│
└── Licenses design
```

Companies such as

* STMicroelectronics
* NXP
* Texas Instruments
* Nordic
* Renesas
* Microchip

buy the licence and build complete microcontrollers.

---

## Example

Imagine a company designs a car engine.

Another company builds the complete car.

```text
ARM
↓

CPU Engine

↓

STMicroelectronics

↓

Complete STM32 Microcontroller
```

ARM designed the CPU.

ST designed the rest:

* Flash
* RAM
* GPIO
* UART
* Timers
* ADC
* SPI
* I2C
* CAN
* USB

and integrated them around the Cortex processor.

---

# 2. What is a Processor?

Many beginners confuse

Processor = Microcontroller

This is incorrect.

A processor only executes instructions.

It cannot directly blink an LED because it has no GPIO pins by itself.

Imagine the human body.

```text
Brain

↓

Makes decisions

↓

Hands

↓

Do work
```

Similarly,

```text
Processor

↓

Executes instructions

↓

Peripherals

↓

Interact with outside world
```

The Cortex-M processor is simply the "brain."

---

# 3. What is Cortex?

ARM has designed many processor families.

For example

```text
ARM7

ARM9

ARM11

↓

Cortex Family
```

The Cortex family is newer and more powerful.

Inside Cortex there are different families.

```text
Cortex

├── Cortex-A
│      Phones
│      Linux
│
├── Cortex-R
│      Real-time control
│
└── Cortex-M
       Microcontrollers
```

This book focuses on **Cortex-M**.

---

# Book says

> The Cortex-M3 processor was the first of the Cortex generation of processors, released by ARM in 2005 (silicon products released in 2006).

Let's understand every part.

---

## "First of the Cortex generation"

Before Cortex-M3,

ARM processors mainly used older architectures such as ARM7TDMI.

ARM wanted

* better performance
* lower power
* easier programming
* better interrupt handling

So ARM designed a completely new processor family called **Cortex**.

The first Cortex-M processor was Cortex-M3.

---

## Released by ARM in 2005

This means

ARM finished designing the processor in 2005.

That does **not** mean customers could buy microcontrollers immediately.

---

## Silicon products released in 2006

ARM only designs the CPU.

Semiconductor companies needed time to build chips around it.

Timeline

```text
2005

ARM designs Cortex-M3

↓

Companies obtain licence

↓

Design microcontroller

↓

Manufacture silicon

↓

2006

First Cortex-M3 chips available
```

---

# Book says

> The Cortex-M4 processor was released in 2010.

Cortex-M4 is basically an improved Cortex-M3.

ARM added extra hardware mainly for

* Digital Signal Processing (DSP)
* Faster multiplication
* Floating-point calculations

Most of the architecture stayed the same.

This is why software written for Cortex-M3 often works on Cortex-M4.

---

# Book says

> The Cortex-M3 and Cortex-M4 processors use a 32-bit architecture.

This sentence is extremely important.

People often misunderstand it.

---

## What does 32-bit architecture actually mean?

Many people think

32-bit processor

=

Can only process 32-bit numbers.

That is incomplete.

It actually means several parts of the processor are designed around 32-bit values.

The book immediately explains this.

---

# Book says

> Internal registers in the register bank, the data path, and the bus interfaces are all 32 bits wide.

Let's understand each one.

---

# Register Bank

Registers are extremely small memory locations inside the processor.

Think of them as the processor's working table.

```text
CPU

┌──────────────┐
│ R0           │
│ R1           │
│ R2           │
│ R3           │
│ ...          │
└──────────────┘
```

Each register stores

```text
□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□

32 bits
```

So every general-purpose register can directly hold a 32-bit value.

---

# Data Path

Suppose

```c
A = B + C;
```

The processor must move data

Register

↓

ALU

↓

Register

The path through which data travels is called the **data path**.

```text
Register

↓

ALU

↓

Register
```

Since the data path is 32 bits wide,

the processor can move 32 bits internally in one operation.

---

# Bus Interface

The processor communicates with Flash and SRAM using buses.

```text
CPU

⇄ Bus ⇄ Flash

⇄ Bus ⇄ SRAM
```

If the bus is 32 bits wide,

32 bits can be transferred in one bus transaction.

---

# Why is this useful?

Imagine transporting water.

One pipe carries

8 litres

Another pipe carries

32 litres.

Obviously,

the wider pipe transfers more water at a time.

A 32-bit bus is like the wider pipe—it can move more data per transfer than an 8-bit bus.

---

# Book says

> The Instruction Set Architecture (ISA) in the Cortex-M processors is called the Thumb ISA.

---

## What is ISA?

ISA means

**Instruction Set Architecture**

It defines

* instructions
* registers
* data types
* addressing modes
* execution behaviour

Think of it as the language spoken by the processor.

Example

```text
ADD

SUB

MOV

CMP

LDR

STR
```

These are instructions defined by the ISA.

---

# Thumb ISA

ARM processors originally supported a full ARM instruction set.

Cortex-M processors instead execute **Thumb instructions**.

The book states that Cortex-M uses the Thumb ISA based on Thumb-2 technology.

---

# Thumb-2 Technology

The book says

> supports a mixture of 16-bit and 32-bit instructions.

Why mix instruction sizes?

Imagine storing instructions in Flash.

If every instruction were 32 bits,

the program would consume more memory.

If many instructions can be encoded in 16 bits,

the same program occupies less Flash.

However,

some complex operations require more information.

Those use 32-bit instructions.

So Thumb-2 combines:

```text
16-bit instructions

+

32-bit instructions
```

This gives:

* Better code density (smaller programs)
* High performance
* Richer instruction set

---

# Cortex-M3 and Cortex-M4 Features

The book now lists the major architectural features. Each of these is important enough to deserve its own detailed lesson.

* **Three-stage pipeline design**: Improves performance by overlapping instruction fetch, decode, and execute.
* **Harvard bus architecture with unified memory space**: Separate instruction and data buses internally for higher throughput, while instructions and data share one address space from the programmer's perspective.
* **32-bit addressing (4 GB address space)**: The processor can generate 32-bit addresses, allowing access to (2^{32}) addressable locations (4 GB).
* **AMBA bus interfaces**: ARM's standard on-chip bus architecture enables efficient communication between the CPU, memory, and peripherals.
* **NVIC (Nested Vectored Interrupt Controller)**: Hardware that manages interrupts, supporting up to 240 external interrupt requests and 8–256 priority levels, depending on the microcontroller implementation.
* **Operating System support**: Includes features such as the **SysTick timer** and **shadowed stack pointer** to simplify RTOS implementation.
* **Sleep modes and low-power features**: Reduce power consumption when the processor is idle.
* **Optional MPU (Memory Protection Unit)**: Provides memory protection and access-permission control.
* **Bit-band support**: Allows efficient single-bit access in two specific memory regions.
* **Single-processor or multi-processor use**: The core can be integrated into systems with one or more processors.

> **Important:** The book only lists these features here. Their detailed operation is explained in later chapters, and we'll study each one thoroughly there.

---

# Instruction Set Features

The book then lists the capabilities of the Thumb instruction set used by Cortex-M3 and Cortex-M4.

It supports:

* General data processing instructions, including **hardware divide**.
* Memory access instructions for **8-bit, 16-bit, 32-bit, and 64-bit** data, including instructions that transfer multiple 32-bit registers at once.
* Bit-field manipulation instructions.
* **Multiply-Accumulate (MAC)** and **saturating arithmetic** instructions.
* Branches, conditional branches, and function calls.
* System-control and operating-system support instructions.

These categories tell you **what kinds of work the processor can perform**. Each instruction group is explained in detail later in the book.

---

# Additional Cortex-M4 Features

Compared with Cortex-M3, Cortex-M4 adds:

* **SIMD (Single Instruction Multiple Data)** operations.
* Additional fast multiply and MAC instructions.
* Saturating arithmetic instructions.
* An **optional single-precision Floating Point Unit (FPU)**.

These additions make Cortex-M4 much better suited for DSP workloads such as:

* Audio processing
* Digital filters
* Motor control
* Sensor fusion

---

# Where are these processors used?

The book says Cortex-M3 and Cortex-M4 are widely used in:

* Microcontrollers
* System-on-Chip (SoC) devices
* Application Specific Standard Products (ASSP)

This means the same CPU core can be embedded in many different types of chips, not just traditional microcontrollers.

---

# RISC vs CISC

The book describes Cortex-M processors as **RISC (Reduced Instruction Set Computing)** processors.

Historically:

* **RISC** processors used simpler instructions executed efficiently.
* **CISC (Complex Instruction Set Computing)** processors used more complex instructions.

The book also points out that modern processors blur this distinction. Cortex-M includes features such as a richer instruction set and mixed 16-bit/32-bit instructions, so the traditional boundary between RISC and CISC is no longer as clear as it once was.

---

# Cortex-M3 vs Cortex-M4

The book finishes by emphasising that:

* Both processors share the same overall programming model.
* Features such as the NVIC and MPU are programmed in essentially the same way.
* Cortex-M4 has internal architectural enhancements for DSP and floating-point operations.
* Because of these enhancements, **some instructions complete in fewer clock cycles on Cortex-M4**, giving higher performance for DSP-oriented applications.

---

# Summary

After studying this section, you should understand:

* ✅ What ARM is and what it designs.
* ✅ The difference between a **processor** and a **microcontroller**.
* ✅ Why Cortex-M3 and Cortex-M4 were introduced.
* ✅ What a **32-bit architecture** means.
* ✅ What **ISA**, **Thumb**, and **Thumb-2** are.
* ✅ The major architectural features of Cortex-M3/M4.
* ✅ The categories of instructions supported by the processor.
* ✅ The additional DSP and floating-point capabilities of Cortex-M4.
* ✅ Why Cortex-M processors are described as RISC and why that distinction has become less rigid.
* ✅ The similarities and key differences between Cortex-M3 and Cortex-M4.
Excellent. This section introduces the **entire Cortex-M family** and explains **why ARM created multiple Cortex-M processors instead of a single processor**. This is one of the most important concepts because it helps you choose the right processor for an application.

I'll explain **every sentence** and **every technical term** without skipping anything.

---

# 1.1.2 The Cortex-M Processor Family

---

## Book says

> **The Cortex-M3 and Cortex-M4 processors are two of the products in the ARM Cortex-M processor family.**

## Explanation

The Cortex-M3 and Cortex-M4 are **not the only Cortex-M processors**.

Think of Cortex-M as a family.

Just like a family has different members,

```text
Cortex-M Family

├── Cortex-M0
├── Cortex-M0+
├── Cortex-M1
├── Cortex-M3
├── Cortex-M4
├── Cortex-M7
├── Cortex-M23
├── Cortex-M33
├── Cortex-M35P
├── Cortex-M55
├── Cortex-M85
```

Each member is designed for a different purpose.

Some are:

* cheaper
* lower power
* faster
* better for DSP
* better for AI

The idea is exactly the same as buying different cars.

```text
Small Car

↓

Cheap
Low fuel

SUV

↓

More power

Sports Car

↓

High performance
```

You don't use a Formula 1 car to deliver groceries.

Similarly,

ARM doesn't expect one processor to fit every embedded application.

---

# Book says

> **The whole Cortex-M processor family is shown in Figure 1.1.**

The figure simply shows all the Cortex-M processors available at the time the book was written.

The main point is:

> Cortex-M3 and Cortex-M4 are only **members of a much larger family**.

---

# Book says

> **The Cortex-M3 and Cortex-M4 processors are based on ARMv7-M architecture.**

This sentence introduces an extremely important term:

## What is ARMv7-M?

Many beginners confuse:

* Cortex-M4
* ARMv7-M

They are **not the same thing**.

---

Think of building a house.

First,

an architect creates a blueprint.

```text
Blueprint

↓

House
```

The blueprint tells:

* room sizes
* wall locations
* electrical wiring

The blueprint itself is **not the house**.

---

Exactly the same idea.

```text
ARMv7-M

↓

Architecture

↓

Cortex-M3

↓

Actual Processor
```

ARMv7-M defines

* registers
* instruction set
* exception model
* memory model

Then ARM designs processors that obey that architecture.

---

### Architecture vs Processor

```text
Architecture

↓

Rules

↓

Processor

↓

Implementation
```

Example

ARMv7-M says

"There must be these registers."

Cortex-M3 implements them.

Cortex-M4 also implements them.

That is why they are very similar.

---

# Book says

> **Both are high-performance processors that are designed for microcontrollers.**

This means

ARM designed M3 and M4 specifically for

* embedded systems
* microcontrollers
* real-time applications

not for

* laptops
* desktop computers
* smartphones

---

## Why?

Microcontrollers need

* deterministic execution
* low power
* low cost
* fast interrupt response

Cortex-M processors are optimized for these goals.

---

# Book says

> **Because the Cortex-M4 processor has SIMD, fast MAC, and saturate arithmetic instructions...**

There are three new terms.

Let's study each.

---

# 1. SIMD

SIMD means

**Single Instruction Multiple Data**

Let's understand the name.

Single Instruction

↓

One instruction

Multiple Data

↓

Processes multiple values

---

Example

Suppose

```text
A = [1 2 3 4]

B = [5 6 7 8]
```

Normal processor

```text
1+5

↓

2+6

↓

3+7

↓

4+8
```

Four additions.

SIMD

```text
ADD ALL

↓

One instruction

↓

6 8 10 12
```

Very useful for

* audio
* image processing
* DSP

---

# 2. MAC

MAC means

**Multiply Accumulate**

Instead of

```text
Multiply

↓

Store

↓

Add
```

the processor does

```text
Multiply

+

Add

↓

Single instruction
```

Example

```text
Result

=

A×B+C
```

instead of

```text
A×B

↓

Temporary

↓

+C
```

This is extremely common in DSP.

---

# 3. Saturating Arithmetic

Suppose

8-bit number

Maximum

```text
255
```

Now

```text
250+20
```

Normal arithmetic

Overflow occurs.

Result wraps around.

Saturating arithmetic instead gives

```text
255
```

It "saturates" at the maximum value instead of wrapping.

This is very useful in

* image processing
* audio processing
* motor control

because wrap-around could produce incorrect results.

---

# Book says

> **it can also carry out some of the digital signal processing applications that traditionally have been carried out by a separate Digital Signal Processor (DSP).**

Before Cortex-M4,

many systems contained

```text
Microcontroller

+

Separate DSP chip
```

because ordinary microcontrollers were slow for DSP work.

After Cortex-M4,

many DSP algorithms could run directly on the Cortex-M4.

This reduced

* cost
* PCB size
* power consumption

---

# What is DSP?

DSP means

Digital Signal Processing.

Examples

* Audio filtering
* Echo cancellation
* Motor control
* FFT
* FIR filters
* Noise removal

We will study DSP in detail later.

---

# Book says

> **The Cortex-M0, Cortex-M0+, and Cortex-M1 processors are based on ARMv6-M, which has a smaller instruction set.**

Notice something.

Earlier

M3

↓

ARMv7-M

Now

M0

↓

ARMv6-M

Different architecture.

---

## Why?

M0 is designed to be

* smaller
* cheaper
* lower power

Therefore

ARM removed some instructions.

Smaller instruction set

↓

Smaller processor

↓

Lower cost

---

# Book says

> **Both Cortex-M0 and Cortex-M0+ are very small size in terms of gate count.**

New term.

## What is Gate Count?

Inside every processor

there are millions of tiny logic circuits.

Each logic circuit is built using gates.

Example

```text
AND

OR

NOT

NAND

NOR

XOR
```

These are logic gates.

---

Imagine LEGO blocks.

Small toy

↓

100 blocks

Large toy

↓

5000 blocks

Processor

↓

Logic gates

More gates

↓

Bigger processor

Higher cost

More power

---

Book says

> about 12K gates

That means approximately

```text
12,000 logic gates
```

Very small.

---

# Why is small gate count important?

Smaller processor means

* cheaper silicon
* smaller chip
* lower leakage current
* lower power
* lower manufacturing cost

Perfect for

* toys
* sensors
* remote controls
* IoT

---

# Book says

> **The Cortex-M0+ processor has the most state-of-the-art low power optimizations.**

Meaning

ARM improved

* clock gating
* sleep modes
* power management

to reduce battery consumption.

Ideal for

* wearable devices
* battery sensors
* wireless nodes

---

# Book says

> **The Cortex-M1 processor is designed specifically for FPGA applications.**

New term.

## FPGA

FPGA means

**Field Programmable Gate Array**

Unlike a normal microcontroller,

an FPGA lets you build custom digital hardware.

Instead of buying a chip with a fixed CPU,

you can place the Cortex-M1 core **inside the FPGA**.

---

# Book says

> **It has Tightly Coupled Memory (TCM).**

TCM stands for

**Tightly Coupled Memory**.

This is a very fast memory connected directly to the processor core.

Think of two storage locations:

```text
Normal RAM

↓

Across the road

TCM

↓

Inside the CPU building
```

Because it is so close to the processor,

access is very fast and predictable.

This is useful in real-time systems where consistent timing matters.

---

# Book says

> **it can run at over 200 MHz in Altera Stratix III FPGA.**

This simply demonstrates that Cortex-M1 can operate at high clock frequencies when implemented in advanced FPGA devices.

The exact value depends on the FPGA and implementation.

---

# Book says

> **For general data processing and I/O control tasks, the Cortex-M0 and Cortex-M0+ processors have excellent energy efficiency due to the low gate count design.**

This means:

If your application mainly:

* reads sensors
* toggles GPIO pins
* communicates over UART, SPI, or I²C
* performs simple control

then Cortex-M0 or Cortex-M0+ is often enough.

Because the processor is simpler, it consumes less energy.

---

# Book says

> **But for applications with complex data processing requirements, they may take more instructions and clock cycles.**

This is a key trade-off.

Suppose you need to process audio samples.

A Cortex-M0 may need several instructions to perform an operation that Cortex-M4 can perform with one specialised instruction.

More instructions mean:

* more clock cycles
* more execution time
* higher energy consumption for that task

---

# Book says

> **In this case, the Cortex-M3 or Cortex-M4 processor would be more suitable...**

Why?

Because M3 and M4 include additional instructions and architectural features that allow many tasks to be completed with fewer instructions than on ARMv6-M (used by M0/M0+).

---

# Book says

> **As a result, we need different processors for different applications.**

This is the main conclusion of the section.

There is **no single "best" Cortex-M processor**.

The right choice depends on the application.

| Application             | Suitable Processor | Reason                                   |
| ----------------------- | ------------------ | ---------------------------------------- |
| Toy                     | Cortex-M0          | Low cost, low power                      |
| Temperature sensor      | Cortex-M0+         | Excellent battery life                   |
| Washing machine         | Cortex-M3          | More features and performance            |
| Drone flight controller | Cortex-M4          | DSP instructions help with sensor fusion |
| Audio processing        | Cortex-M4          | SIMD, MAC, optional FPU                  |
| FPGA-based design       | Cortex-M1          | Designed for FPGA implementation         |

---

# Book says

> **It is worthwhile to note that the Cortex-M processors are not the only ARM processors to be used in generic microcontroller products.**

This means Cortex-M was **not the first ARM processor used in microcontrollers**.

Before Cortex-M, many manufacturers used processors such as:

* ARM7TDMI
* ARM9

These were very successful in embedded systems.

---

# Book says

> **The ARM7 processor is the most widely used 32-bit embedded processor in history...**

The book highlights ARM7's historical importance.

Before Cortex-M became popular, ARM7TDMI-based microcontrollers were widely used by companies including NXP, Texas Instruments, Atmel, and others.

ARM7 laid much of the groundwork for modern ARM-based embedded systems, even though newer Cortex-M processors have largely replaced it in new designs.

---

# Summary

After this section, you should understand:

* ✅ Cortex-M is a **family** of processors, not a single processor.
* ✅ Cortex-M3 and Cortex-M4 are based on the **ARMv7-M architecture**, while Cortex-M0/M0+ use **ARMv6-M**.
* ✅ **Architecture** defines the rules; a **processor** is an implementation of those rules.
* ✅ Cortex-M4 adds **SIMD**, **fast MAC**, and **saturating arithmetic**, making it well suited for DSP tasks.
* ✅ Cortex-M0 and Cortex-M0+ prioritise **small size**, **low cost**, and **low power** through a low gate count.
* ✅ Cortex-M1 is intended for **FPGA implementations** and includes **Tightly Coupled Memory (TCM)**.
* ✅ Different Cortex-M processors exist because different embedded applications have different performance, power, and cost requirements.
* ✅ Before Cortex-M, **ARM7** and **ARM9** processors were widely used in microcontrollers and played an important role in ARM's success in embedded systems.
Excellent. This is one of the **most important sections in the entire book** because beginners often confuse a **processor (CPU)** with a **microcontroller (MCU)**.

The author is explaining **exactly what ARM sells** and **what companies like ST, NXP, TI, and Nordic actually manufacture**.

I'll explain **every sentence** without leaving any topic.

---

# 1.1.3 Differences Between a Processor and a Microcontroller

---

# Book says

> **ARM does not make microcontrollers.**

This is the first thing you should remember.

Many beginners think:

> "ARM makes STM32."

❌ **Wrong.**

ARM **never manufactures** STM32, LPC, Tiva, or Nordic chips.

ARM only designs the **CPU core**.

---

## Think of it like this

Suppose someone designs an engine.

Another company builds the complete car.

```text
Engine Designer
        │
        ▼
      Engine
        │
        ▼
 Car Manufacturer
        │
        ▼
 Complete Car
```

ARM is like the **engine designer**.

Companies like STMicroelectronics are the **car manufacturers**.

---

# Book says

> **ARM designs processors and various components that silicon designers need...**

Let's understand every word.

## Processor

We've already learned this.

A processor is the **CPU**.

It executes instructions.

Example:

```
ADD
SUB
MOV
LDR
STR
```

The CPU understands these instructions.

---

## Various Components

ARM doesn't only design CPUs.

ARM also designs other reusable hardware blocks.

For example

* Cortex CPU
* NVIC
* Debug interface
* Bus interfaces
* TrustZone (newer processors)
* Memory Protection Unit (MPU)

These hardware blocks can be reused in many chips.

---

## Silicon Designers

Who are silicon designers?

These are semiconductor companies such as

* STMicroelectronics
* NXP
* Texas Instruments
* Renesas
* Nordic
* Silicon Labs
* Microchip

They design integrated circuits (ICs).

---

# Book says

> **licenses these designs to various silicon design companies including microcontroller vendors.**

Now we come to ARM's business model.

ARM creates the design.

Instead of manufacturing chips,

it **licenses** the design.

---

Imagine this.

You write software.

Instead of selling your computer,

you sell the software licence.

Exactly the same thing happens here.

```text
ARM

↓

Designs Cortex-M4

↓

Licenses design

↓

ST buys licence

↓

ST manufactures STM32
```

ARM earns money from licensing.

ST earns money by selling microcontrollers.

---

# Book says

> **Typically we call these designs "Intellectual Property (IP)."**

New term:

## What is Intellectual Property (IP)?

IP means

**a valuable design created by a company.**

In electronics,

IP is usually

* CPU designs
* Memory controller
* USB controller
* Ethernet controller
* DSP block

These are reusable hardware designs.

Instead of redesigning everything,

companies buy the IP.

---

### Example

Suppose you invent

an amazing calculator.

Instead of selling calculators,

you sell the design.

Many companies manufacture calculators using your design.

Your design

=

Intellectual Property.

---

# Book says

> **The business model is called IP licensing.**

Business model simply means

**how ARM earns money.**

ARM generally does **not** manufacture chips.

Instead,

```text
ARM

↓

Design CPU

↓

Licence CPU

↓

Receive royalty
```

Microcontroller company

↓

Manufactures chip

↓

Sells chip

↓

Receives product revenue

---

# Book says

> **In a typical microcontroller design, the processor takes only a small part of the silicon area.**

This surprises many beginners.

People imagine

```text
Microcontroller

↓

Mostly CPU
```

Actually,

the CPU occupies only a small part.

---

Imagine opening an STM32 chip.

Inside,

you would see something like

```text
+--------------------------------------+
|                                      |
| Flash Memory                         |
|                                      |
|----------------------|---------------|
| SRAM                 | Peripherals   |
|                      | UART          |
|                      | SPI           |
|                      | I2C           |
|                      | ADC           |
|                      | Timers        |
|                      | USB           |
|----------------------|---------------|
| CPU (Cortex-M4)      | Clock System  |
+--------------------------------------+
```

Notice

CPU

↓

Very small

Most of the chip is occupied by

* Flash
* SRAM
* peripherals
* buses
* clock system

---

# What is Silicon Area?

Silicon is the material from which chips are manufactured.

The inside of the chip is called the **silicon die**.

Imagine a small square.

```text
 _______________________

|                       |

|        CHIP           |

|_______________________|
```

Everything must fit inside this square.

Each block occupies some area.

CPU

↓

Small

Flash memory

↓

Very large

---

# Book says

> **The other areas are taken up by memories...**

Let's study each block.

---

# 1. Memories

Every microcontroller contains memory.

Mainly

```text
Flash

↓

Program storage

SRAM

↓

Variables
```

Without memory,

the processor cannot execute programs.

---

# 2. Clock Generation

Book says

> PLL

PLL means

**Phase Locked Loop**

Very important component.

Suppose crystal frequency is

```
8 MHz
```

Processor needs

```
72 MHz
```

PLL multiplies the frequency.

```text
Crystal

8 MHz

↓

PLL

↓

72 MHz
```

We'll study PLL in detail later.

---

# 3. Clock Distribution Logic

Generating the clock is only the first step.

The clock must reach

* CPU
* UART
* SPI
* ADC
* Timers

This distribution network is called the **clock tree**.

```text
PLL

↓

Clock Tree

├── CPU

├── UART

├── SPI

├── ADC

└── Timer
```

---

# 4. System Bus

A bus is like a highway.

Everything communicates over the bus.

```text
CPU

↓

Bus

↓

Flash

↓

SRAM

↓

GPIO

↓

UART
```

Without buses,

nothing inside the chip can communicate.

---

# 5. Peripherals

Peripherals are hardware blocks that perform specific tasks.

Examples

| Peripheral | Purpose                             |
| ---------- | ----------------------------------- |
| GPIO       | Read buttons, drive LEDs            |
| UART       | Serial communication                |
| SPI        | High-speed communication            |
| I²C        | Sensor communication                |
| ADC        | Convert analogue voltage to digital |
| DAC        | Convert digital value to analogue   |
| Timer      | Measure time, generate delays       |
| PWM        | Motor control, LED brightness       |

These are dedicated hardware circuits that save the CPU from doing everything in software.

---

# Book says

> **Although many microcontroller vendors use ARM Cortex-M processors as their choice of CPU...**

This means

many companies

use exactly the same Cortex processor.

For example

```text
STM32

↓

Cortex-M4

LPC

↓

Cortex-M4

TM4C

↓

Cortex-M4
```

Same CPU.

Different microcontrollers.

---

# Book says

> **the memory system, memory map, peripherals, and operation characteristics can be completely different from one product to another.**

This is extremely important.

Although the CPU is identical,

everything around it can change.

Let's see.

---

## Memory

STM32

```
Flash = 512 KB
```

Another MCU

```
Flash = 2 MB
```

Different.

---

## SRAM

One MCU

```
64 KB
```

Another

```
512 KB
```

Different.

---

## Peripherals

One microcontroller

```
3 UARTs
```

Another

```
8 UARTs
```

Different.

---

## Clock Speed

One MCU

```
48 MHz
```

Another

```
480 MHz
```

Different.

---

## Operating Voltage

One MCU

```
1.8 V
```

Another

```
3.3 V
```

Different.

---

So even though both use Cortex-M4,

they behave differently because the surrounding hardware is different.

---

# Book says

> **This allows microcontroller manufacturers to add additional features in their products and differentiate their products from others on the market.**

This is the reason companies buy ARM IP.

ARM provides the CPU.

Each manufacturer builds a unique product around it.

Example

```text
STM32

↓

USB

↓

CAN

↓

Ethernet

↓

LCD Controller

↓

Crypto Engine
```

Another company may choose a completely different set of peripherals.

This lets manufacturers create products for different markets.

---

# Book says

> **This book is focused on the Cortex-M3 and Cortex-M4 processors.**

This is telling you the scope of the book.

The book explains

* CPU
* registers
* exceptions
* NVIC
* instruction set
* memory system

It does **not** explain every peripheral of every microcontroller.

---

# Book says

> **For details of the complete microcontroller system design... you still need to read the reference manuals provided by the microcontroller vendor.**

This is one of the most practical lessons in the chapter.

To use a specific microcontroller, you need **two kinds of documentation**.

### 1. ARM Cortex-M Processor Documentation

Explains things common to all Cortex-M3/M4 processors:

* Registers
* Thumb instruction set
* NVIC
* Exceptions
* MPU
* Core architecture

### 2. Microcontroller Vendor Reference Manual

Explains device-specific features, such as:

* Memory map
* GPIO registers
* UART configuration
* ADC
* Timers
* Clock tree
* Pin assignments

For example, if you use an STM32F407, you would read:

* **ARM Cortex-M4 Technical Reference** → to understand the CPU core.
* **STM32F407 Reference Manual** → to understand STM32-specific peripherals and memory map.

---

# Complete Flow

```text
                 ARM
                  │
     Designs Cortex-M CPU
                  │
        Licenses CPU IP
                  │
                  ▼
        STMicroelectronics
                  │
   Adds Flash, SRAM, GPIO,
 UART, SPI, ADC, Timers, PLL
                  │
                  ▼
      STM32 Microcontroller
                  │
                  ▼
      Programmer writes code
```

---

# Key Takeaways

* **Processor (CPU)** executes instructions; it is only one part of a chip.
* **Microcontroller (MCU)** is a complete system containing the CPU, memory, buses, clock circuitry, and peripherals.
* ARM designs and licenses **processor IP**; it does not manufacture microcontrollers.
* **IP (Intellectual Property)** refers to reusable hardware designs such as CPU cores and controllers.
* In a microcontroller, the CPU occupies only a small portion of the silicon area; memories and peripherals take much more space.
* Two microcontrollers can use the **same Cortex-M processor** but have completely different memory sizes, peripherals, clock speeds, voltages, and pin configurations.
* To program a specific MCU, you need both the **ARM Cortex-M documentation** and the **vendor's reference manual**.
Excellent. This section explains **how a Cortex-M processor becomes a real microcontroller**. It describes the relationship between **ARM** and **microcontroller vendors**, what ARM provides, what the vendors add, and how software development works.

I'll explain every sentence and every technical term.

---

# 1.1.4 ARM and the Microcontroller Vendors

---

# Book says

> **Currently there are more than 15 silicon vendors using ARM Cortex-M3 or Cortex-M4 processors in microcontroller products.**

## Explanation

A **silicon vendor** is a company that designs and sells semiconductor chips such as microcontrollers.

The book lists examples including:

* Analog Devices
* Atmel
* Cypress
* Freescale
* Fujitsu
* Holtek
* Infineon
* NXP
* Samsung
* Silicon Laboratories
* STMicroelectronics
* Texas Instruments
* Toshiba

These companies **do not design the Cortex-M3 or Cortex-M4 CPU from scratch**. Instead, they **license** the Cortex-M processor from ARM and build their own microcontrollers around it.

---

## Real-world Example

Think of Android smartphones.

Google develops Android.

Different companies such as Samsung, Xiaomi, and OnePlus build different phones using Android.

```text
Google
      │
      ▼
 Android Operating System
      │
 ┌────┴───────────────┐
 ▼                    ▼
Samsung           Xiaomi
 ▼                    ▼
Different Phones
```

Similarly,

```text
ARM
      │
      ▼
 Cortex-M Processor
      │
 ┌────┴───────────────┐
 ▼                    ▼
ST               NXP
 ▼                    ▼
STM32            LPC
```

ARM provides the CPU design.

The vendors build different products.

---

# Book says

> **There are also some other companies that use Cortex-M3 or Cortex-M4 for SoC designs, other companies that use only Cortex-M0 or Cortex-M0+ processors.**

## Explanation

Not every company builds a normal microcontroller.

Some companies build a **System-on-Chip (SoC)**.

### What is an SoC?

A **System-on-Chip** integrates many components onto one chip.

Example:

```text
+--------------------------------------+
|               SoC                    |
|--------------------------------------|
| Cortex-M CPU                         |
| RAM                                  |
| Flash                                |
| GPU                                  |
| Communication Blocks                 |
| Hardware Accelerators                |
| Security Modules                     |
+--------------------------------------+
```

An SoC is generally more complex than a traditional microcontroller.

---

Some companies only need simple processors.

For example,

* battery-powered sensors
* smart switches
* IoT nodes

For these applications,

Cortex-M0 or Cortex-M0+ is sufficient because they consume less power and occupy less silicon area.

---

# Book says

> **After a company licenses the Cortex-M processor design, ARM provides the design source code of the processor in a language called Verilog-HDL (Hardware Description Language).**

This sentence introduces a very important concept.

---

# What is Verilog-HDL?

Most programmers write software in languages such as

```c
int a = 5;
```

or

```cpp
printf("Hello");
```

These languages describe **software**.

Verilog-HDL is different.

It describes **hardware**.

---

Imagine you want to build an AND gate.

Instead of drawing it,

you write something like

```verilog
assign Y = A & B;
```

This tells the computer:

> Build an AND gate.

So Verilog is **not programming the processor**.

It is **describing the processor's hardware**.

---

## What does ARM provide?

ARM gives the vendor the Verilog description of the Cortex-M processor.

```text
ARM
     │
     ▼
Verilog HDL Source
     │
     ▼
Microcontroller Vendor
```

The vendor now has the CPU design in hardware description form.

---

# What is HDL?

HDL stands for **Hardware Description Language**.

Unlike C, which tells a processor what to do,

HDL tells electronic design tools **what hardware to create**.

---

# Book says

> **The design engineers in these companies then add their own design blocks like peripherals and memories...**

Once the vendor receives the Cortex-M CPU,

it begins building the rest of the chip.

Example:

```text
Cortex-M CPU
      │
      ▼
+--------------------------+
| Vendor Adds              |
|--------------------------|
| Flash Memory             |
| SRAM                     |
| GPIO                     |
| UART                     |
| SPI                      |
| I²C                      |
| ADC                      |
| DAC                      |
| Timers                   |
| USB                      |
| CAN                      |
| Ethernet                 |
+--------------------------+
```

Every vendor chooses different peripherals.

This is why different microcontrollers have different capabilities even if they use the same Cortex-M core.

---

# Book says

> **use various EDA tools to convert the whole design from Verilog-HDL and various other forms into a transistor level chip layout.**

This describes how a chip is physically created.

---

# What are EDA Tools?

EDA means

**Electronic Design Automation**

These are specialised software tools used to design integrated circuits.

They convert the HDL description into a real chip layout.

---

## Simplified Design Flow

```text
Verilog HDL

↓

Logic Gates

↓

Transistors

↓

Physical Layout

↓

Manufacturing
```

The final output is a layout that semiconductor fabrication plants can manufacture.

---

# What is a Transistor-Level Layout?

A processor ultimately consists of millions (or billions) of transistors.

The EDA tools decide:

* where each transistor is placed,
* how they are connected,
* how signals travel,
* how power is distributed.

The result is the actual blueprint used to fabricate the silicon chip.

---

# Book says

> **ARM also provides other Intellectual Property (IP) products...**

ARM does not only sell processor cores.

It also provides many reusable hardware blocks.

These are also called **IP (Intellectual Property)**.

---

The book lists three examples.

---

# 1. Physical IP

The book says:

> **Design of the cell libraries such as logic gates and memories**

## What is Physical IP?

Physical IP consists of ready-made hardware building blocks.

Examples include:

* NAND gates
* NOR gates
* Flip-flops
* SRAM cells

Instead of designing these from scratch,

vendors can license ARM's optimised implementations.

---

# 2. CMSDK and CoreLink

The book says:

> **Peripherals and AMBA infrastructure components**

### CMSDK

CMSDK stands for

**Cortex-M System Design Kit**

It includes:

* example systems,
* baseline peripherals,
* AMBA bus infrastructure,
* example software.

Think of it as a starter kit that helps vendors begin building a Cortex-M-based chip quickly.

---

### CoreLink

CoreLink provides interconnection hardware.

Imagine a city.

Roads connect:

* houses,
* offices,
* hospitals.

Similarly,

CoreLink connects:

```text
CPU

↓

Memory

↓

Peripherals

↓

DMA
```

It provides the "roads" inside the chip.

---

# 3. CoreSight

The book says:

> **Additional debug components...**

CoreSight is ARM's debugging infrastructure.

It provides hardware support for:

* breakpoints,
* watchpoints,
* tracing,
* debugging,
* multi-processor debugging.

When you debug code in an IDE, CoreSight hardware helps the debugger communicate with the processor.

---

# Book says

> **ARM provides a product called the Cortex-M System Design Kit (CMSDK)...**

The purpose of CMSDK is to make chip development easier.

Instead of building every bus, peripheral, and example design from scratch,

vendors reuse ARM's IP.

This reduces development time.

---

# Book says

> **reduces the total chip development effort with reusable IP.**

This is the main advantage of reusable IP.

Without reusable IP:

```text
Design Everything

↓

Several Years
```

With reusable IP:

```text
Reuse Existing Blocks

↓

Much Faster Development
```

---

# Book says

> **But of course, there is still a lot of work for the microcontroller chip designers to do.**

Receiving the Cortex-M CPU is only the beginning.

The vendor still needs to design:

* new peripherals,
* memory systems,
* clock systems,
* low-power features,
* packaging,
* testing,
* documentation.

---

# Book says

> **working hard to develop better peripherals, lower power memories...**

This is how companies compete.

Although many use the same Cortex-M processor,

they differentiate their products through:

* faster ADCs,
* better timers,
* lower power consumption,
* more communication interfaces,
* improved security,
* unique peripherals.

For example, two Cortex-M4 microcontrollers may differ significantly in their available peripherals and power characteristics.

---

# Book says

> **they also need to develop example software and support materials...**

Hardware alone is not enough.

Vendors also provide:

* Software Development Kits (SDKs),
* HAL (Hardware Abstraction Layer) libraries,
* example projects,
* application notes,
* reference manuals,
* tutorials.

These resources help engineers use the chip effectively.

---

# Book says

> **On the software side, ARM has various software development platforms such as the Keil Microcontroller Development Kit (MDK-ARM) and ARM Development Studio 5 (DS-5).**

ARM also develops software tools.

The book mentions:

### Keil MDK-ARM

A widely used embedded development environment.

It includes:

* C/C++ compiler,
* assembler,
* linker,
* debugger,
* project management tools.

---

### ARM Development Studio 5 (DS-5)

Another ARM development environment aimed at more advanced ARM systems.

---

# Book says

> **These software development suites contain compilers, debuggers, and instruction set simulators.**

Let's briefly define each.

* **Compiler**: Converts C/C++ source code into machine code.
* **Debugger**: Allows you to pause execution, inspect variables, and step through code.
* **Instruction Set Simulator**: Simulates the processor in software so code can be tested without physical hardware.

---

# Book says

> **Designers can also use other third-party software development tools if they prefer.**

You are **not limited** to ARM's tools.

Many developers use:

* IAR Embedded Workbench,
* GCC-based toolchains,
* PlatformIO,
* STM32CubeIDE,
* VS Code with appropriate extensions.

The processor remains the same.

---

# Book says

> **Since all of the Cortex-M microcontrollers have the same processor cores, the embedded product designers can use the same development suite for a massive range of microcontrollers from different vendors.**

This is one of the biggest advantages of the Cortex-M ecosystem.

Because the CPU core is common, many development tools support multiple vendors.

For example:

```text
Keil MDK

        │
        ▼

  Cortex-M3/M4

 ┌──────┼──────────────┐
 ▼      ▼              ▼
STM32   LPC        Tiva C
```

Although each microcontroller has different peripherals, the **core architecture**, instruction set, exception model, and debugging interface are shared. This makes it easier for engineers to move between different Cortex-M-based devices while using familiar tools.

---

# Summary

By the end of this section, you should understand:

* ✅ Many semiconductor companies license Cortex-M processors from ARM.
* ✅ ARM supplies the processor as **Verilog-HDL**, a hardware description of the CPU.
* ✅ Vendors add memories, buses, peripherals, and other hardware to create complete microcontrollers or SoCs.
* ✅ **EDA tools** convert the HDL design into a transistor-level chip layout ready for manufacturing.
* ✅ ARM also provides additional IP such as **Physical IP**, **CMSDK**, **CoreLink**, and **CoreSight**.
* ✅ Microcontroller vendors compete by adding unique peripherals, improving power efficiency, and providing software support.
* ✅ ARM offers development tools such as **Keil MDK-ARM** and **DS-5**, but third-party tools can also be used.
* ✅ A common Cortex-M core allows developers to use similar development environments across many vendors' microcontrollers.
# Summary: 1.1.5 Selecting Cortex-M3/M4 Microcontrollers

There is **no single "best" Cortex-M microcontroller**. The right choice depends entirely on the application's requirements. When selecting a microcontroller, consider:

* **Peripherals and interfaces** (UART, SPI, I²C, ADC, etc.)
* **Memory size** (Flash and SRAM)
* **Power consumption**
* **Performance and maximum clock frequency**
* **Package type**
* **Operating conditions** (voltage, temperature, EMI)
* **Cost and availability**
* **Development tool support**
* **Future upgrade options**
* **Firmware/security features**
* **Availability of application notes, examples, and documentation** 

**Recommendation:** Start with the vendor's documentation, application notes, development kits, and reference designs. When designing a PCB, bring out the standard debug connector to simplify debugging. 

---

# Summary: 1.2 Advantages of Cortex-M Processors

The book highlights the major advantages of the Cortex-M family:

### 1. Low Power

* Small processor design.
* Optimized for low power consumption.
* Supports sleep modes and ultra-low-power technologies.
* Suitable for battery-powered devices. 

### 2. High Performance

* Cortex-M3/M4 provide high performance (over **3 CoreMark/MHz** and **1.25 DMIPS/MHz**).
* Can execute demanding applications or run at lower clock speeds to save power. 

### 3. Energy Efficiency

* Combines low power with high performance.
* Completes work quickly and returns to sleep sooner, extending battery life. 

### 4. Excellent Code Density

* Thumb ISA produces compact programs.
* Smaller code requires less Flash memory, reducing chip size and cost. 

### 5. Powerful Interrupt System

* Supports up to **240 vectored interrupts**.
* **8–256 priority levels**.
* Hardware interrupt nesting.
* Very low interrupt latency (12 clock cycles with zero wait-state memory).
* Ideal for real-time applications. 

### 6. Easy to Program (C Friendly)

* Simple linear memory map.
* No complex memory banking.
* Most software, including interrupt handlers, can be written in standard C. 

### 7. Scalability

* Family ranges from inexpensive microcontrollers to high-performance and multiprocessor devices.
* Same architecture allows reuse of software and development tools. 

### 8. Rich Debug Features

* Supports breakpoints, single stepping, program trace, data trace, and profiling.
* Debug systems can be linked in multiprocessor designs. 

### 9. Operating System Support

* Includes hardware features that simplify RTOS implementation.
* Supports many embedded operating systems. 

### 10. Versatile System Features

* Includes **Bit-Band** memory support.
* Optional **Memory Protection Unit (MPU)**. 

### 11. Software Portability

* Standard ANSI C support.
* CMSIS provides common headers and APIs, making software reusable across Cortex-M devices. 

### 12. Large Ecosystem

* Thousands of Cortex-M devices.
* Wide choice of IDEs, debuggers, RTOSs, middleware, and software tools. 

---

# Summary: 1.3 Applications of Cortex-M Processors

The Cortex-M3 and Cortex-M4 processors are used in many embedded applications because of their performance, low power, and flexibility.

### Main application areas:

* **Microcontrollers:** Consumer electronics, household appliances, IT equipment, industrial systems, and medical devices.
* **Automotive:** Real-time control systems and automotive ASSPs requiring fast interrupts and memory protection.
* **Data Communications:** Bluetooth, ZigBee, and other communication systems.
* **Industrial Control:** Factory automation, motor control, and other deterministic real-time systems.
* **Consumer Products:** Devices with displays, graphical user interfaces, and communication features.
* **System-on-Chip (SoC):** Audio processing, power management, I/O control, and subsystem management.
* **Mixed-Signal ICs:** Smart sensors, PMICs, MEMS devices, and analog chips that integrate a Cortex-M processor for additional intelligence. 

---

# Complete Chapter Review (Sections 1.1–1.3)

After studying these sections, you should understand:

* ✅ What ARM is and its IP licensing model.
* ✅ The difference between a **processor (CPU)** and a **microcontroller (MCU)**.
* ✅ The Cortex-M family and the differences between Cortex-M0, M0+, M1, M3, and M4.
* ✅ How ARM processors become complete microcontrollers through vendor integration.
* ✅ How to choose an appropriate Cortex-M microcontroller for a design.
* ✅ The major advantages of Cortex-M processors: low power, high performance, compact code, efficient interrupts, scalability, debugging support, RTOS support, and software portability.
* ✅ The wide range of applications where Cortex-M processors are used, from simple IoT nodes to automotive, industrial control, communication systems, SoCs, and mixed-signal integrated circuits. 
Absolutely. This section is **not about the Cortex-M architecture itself**. Instead, it teaches you **where to find the correct documentation** when you're developing with ARM Cortex-M processors or ARM-based microcontrollers.

Let's learn it **from absolute scratch**.

---

# 1.4 Resources for Using ARM Processors and ARM Microcontrollers

---

# Before we begin...

Imagine you buy an **STM32F407 Discovery Board**.

You now want to:

* Blink an LED
* Configure UART
* Use ADC
* Learn the Cortex-M4 CPU
* Debug faults
* Write assembly
* Understand interrupts

Where will you find all this information?

Will one book contain everything?

**No.**

There are **many documents**, each serving a different purpose.

This section explains **which document to read for which purpose**.

---

# Big Picture

When working with an ARM microcontroller, documentation comes from **two sources**.

```text
                 Documentation

              ┌───────────────┐
              │               │
              ▼               ▼

        ARM Documentation    Vendor Documentation

       (CPU/Core)            (Microcontroller)
```

---

# ARM Documentation

ARM provides documentation about

* CPU
* Architecture
* Instruction Set
* NVIC
* MPU
* Exceptions

ARM **does NOT** explain

* GPIO
* UART
* ADC
* Timers
* Pins

Why?

Because ARM didn't design them.

---

# Vendor Documentation

The vendor

(ST, NXP, TI...)

explains

* GPIO
* UART
* SPI
* I²C
* ADC
* Clock Tree
* Pin Configuration
* Registers

because **they designed those parts**.

---

# Example

Suppose you're using

STM32F407.

To understand

Interrupts

↓

Read ARM documentation.

To understand

GPIOA MODER register

↓

Read STM32 Reference Manual.

---

# 1.4.1 What can you find on the ARM website?

The book says:

> ARM does not manufacture Cortex-M3 or Cortex-M4 microcontrollers.

We already learned this.

ARM only designs

* CPU
* Architecture

Therefore,

their website mainly contains documentation about

the **processor itself**.

---

# ARM Infocenter

The book mentions

```
http://infocenter.arm.com
```

At the time the book was written, ARM stored documentation there.

Today ARM provides documentation through its **developer documentation portal**, but the book refers to the older Infocenter.

The purpose is the same:

A place where you can download ARM manuals.

---

# What documents are available?

The book lists several important documents.

Let's understand every one.

---

# 1. ARMv7-M Architecture Reference Manual

This is one of the most important ARM books.

Think of it as

the **constitution** of ARMv7-M.

It defines

* Architecture
* Registers
* Instruction Set
* Exception model
* Memory model

It explains

**what every ARMv7-M processor must follow.**

---

## Example

Suppose ARM says

Register R0

must behave like this.

Every ARMv7-M processor

must follow that rule.

---

This document is mainly useful when you want to understand

how Cortex-M works internally.

---

# 2. Cortex-M3 Devices Generic User Guide

Think of this as

the **programmer's manual**.

It explains

* Registers

* NVIC

* SysTick

* MPU

* Exception handling

* Instruction overview

Unlike the Architecture Manual,

this guide is easier for software developers.

---

# 3. Cortex-M4 Devices Generic User Guide

Almost the same as above,

but

includes

Cortex-M4 specific features

such as

* DSP instructions

* Floating Point Unit (FPU)

---

# 4. Cortex-M3 Technical Reference Manual (TRM)

Now we move deeper.

This document is mostly useful for

* silicon designers
* advanced developers

It explains

* Internal implementation
* Instruction timing
* Bus interfaces
* Processor internals

---

## Difference

Architecture Manual

↓

Defines rules

Technical Reference Manual

↓

Shows how Cortex-M3 implements those rules.

---

# 5. Cortex-M4 Technical Reference Manual

Same idea,

but for Cortex-M4.

It contains

* DSP implementation
* FPU implementation
* Timing information

---

# 6. Procedure Call Standard (AAPCS)

New topic.

Suppose

Function A

calls

Function B.

How should parameters be passed?

Should they use

Registers?

Stack?

Which register stores return values?

Who saves registers?

All these rules are defined in the

Procedure Call Standard.

Example

```c
sum(10,20);
```

The compiler knows

which register holds

10

which holds

20

because of this standard.

---

# ARM Application Notes

The book lists

Application Notes.

---

## What is an Application Note?

Think of it as

a tutorial.

Instead of

explaining theory,

it explains

how to do a specific task.

---

Example

Application Note

↓

Running FreeRTOS

Instead of explaining

what FreeRTOS is,

it explains

how to run it.

---

Examples mentioned by the book

* Embedded software development

* FreeRTOS

* Migrating from PIC

* Migrating from 8051

* Cortex-M4 Lazy Stacking

* Memory Barrier Instructions

Each note focuses on a specific practical topic. 

---

# Software Manuals

ARM also provides manuals for

software tools.

Example

Keil

Compiler

Linker

Debugger

If you use Keil,

these manuals explain

how to use the tools.

---

# SoC / FPGA Documents

These are mainly for

chip designers,

not normal embedded programmers.

The book lists:

---

## AMBA AHB-Lite

AHB means

Advanced High-performance Bus.

Think of it as

the main highway

inside a chip.

CPU

↓

AHB

↓

Flash

↓

RAM

↓

DMA

---

## APB

APB means

Advanced Peripheral Bus.

It is a simpler bus.

Usually connects

UART

SPI

GPIO

Timers

ADC

to the main system.

---

## CoreSight Guide

CoreSight

is ARM's debugging architecture.

It explains

* breakpoints

* trace

* debug connections

* debug components

---

# 1.4.2 Documentation from the Microcontroller Vendors

Now we move from ARM

to

ST

NXP

TI

etc.

---

## Why do we need vendor documentation?

ARM explains

CPU.

Vendor explains

everything else.

---

# First document

Reference Manual

This is

the most important document

after the Cortex manual.

It explains

* GPIO

* UART

* SPI

* ADC

* Timers

* RCC

* DMA

* Registers

Suppose you want to configure UART.

You must read

Reference Manual.

---

# Second document

Datasheet

Many beginners confuse

Reference Manual

Datasheet.

They are different.

---

## Datasheet

Contains

* Pin diagram

* Voltage

* Maximum current

* Package

* Temperature

* Electrical characteristics

Used mainly during

hardware design.

---

## Example

You want to know

Maximum GPIO current.

Read

Datasheet.

You want to know

Which register enables UART?

Read

Reference Manual.

---

# Third document

Application Notes

Again,

vendor application notes

teach

how to perform

specific tasks.

Examples

* Flash Programming

* Bootloader

* USB

* CAN

* ADC calibration

---

# Development Kits

Example

STM32 Discovery

Nucleo

LaunchPad

These kits contain

example projects.

---

# Firmware Libraries

Instead of writing

everything yourself,

vendors provide

software libraries.

Example

STM32Cube HAL

CMSIS

Driver libraries

---

# Book's Advice

The author says

When starting a project,

begin with

Vendor

↓

Example Projects

↓

Reference Manual

↓

Application Notes

because they are the fastest way to learn how to use a specific microcontroller. 

---

# Summary Table

| Resource                                | Provided By | Purpose                                          |
| --------------------------------------- | ----------- | ------------------------------------------------ |
| ARMv7-M Architecture Reference Manual   | ARM         | CPU architecture, instruction set, exceptions    |
| Cortex-M3/M4 Generic User Guide         | ARM         | Programming model, NVIC, SysTick, MPU            |
| Cortex-M3/M4 Technical Reference Manual | ARM         | Internal processor implementation and timing     |
| Procedure Call Standard                 | ARM         | Rules for function calls and register usage      |
| ARM Application Notes                   | ARM         | Tutorials on specific ARM topics                 |
| Reference Manual                        | Vendor      | Peripherals, registers, memory map               |
| Datasheet                               | Vendor      | Pins, electrical specifications, package         |
| Vendor Application Notes                | Vendor      | Practical examples (UART, ADC, Flash, USB, etc.) |
| Development Kits                        | Vendor      | Example hardware and sample projects             |
| Firmware Libraries                      | Vendor      | Ready-to-use software drivers                    |

---

# Which document should you read?

| If you want to learn...    | Read...                               |
| -------------------------- | ------------------------------------- |
| Cortex-M CPU architecture  | ARMv7-M Architecture Reference Manual |
| Registers, NVIC, SysTick   | Cortex-M Generic User Guide           |
| CPU implementation details | Cortex-M Technical Reference Manual   |
| GPIO, UART, ADC, Timers    | Vendor Reference Manual               |
| Pinout and voltage ratings | Vendor Datasheet                      |
| Example peripheral usage   | Vendor Application Notes              |
| Embedded software examples | Vendor SDK / Firmware Libraries       |

---

# Key Takeaways

* **ARM documentation** explains the **CPU core** (architecture, instruction set, exceptions, NVIC, MPU, etc.).
* **Vendor documentation** explains the **specific microcontroller** (GPIO, UART, ADC, timers, pinout, electrical characteristics, and memory map).
* The most important ARM documents are the **ARMv7-M Architecture Reference Manual**, **Cortex-M3/M4 Generic User Guides**, **Technical Reference Manuals**, and the **Procedure Call Standard**.
* The most important vendor documents are the **Reference Manual**, **Datasheet**, and **Application Notes**.
* For practical development, you typically use **both** ARM documentation and vendor documentation together. This organization and the listed resources come directly from the book. 
This section is mainly **history and background**. The exam importance is lower than CPU architecture or interrupts, but it helps you understand **why Cortex processors exist** and **how ARM evolved**.

Here is a concise summary.

---

# 1.5.1 A Brief History of ARM

### 1. ARM was founded in 1990

* ARM originally stood for **Advanced RISC Machines Ltd.**
* It was a joint venture between:

  * Apple Computers
  * Acorn Computer Group
  * VLSI Technology

---

### 2. ARM6 Processor (1991)

* ARM introduced the **ARM6** processor family.
* It was used in the **Apple Newton PDA**.
* VLSI became the first company to license ARM processors.

---

### 3. ARM Licensing Model

Instead of manufacturing chips, ARM:

* Designs processor cores
* Licenses the designs to semiconductor companies

Companies such as:

* Texas Instruments
* NEC
* Sharp
* STMicroelectronics

built their own chips using ARM processors.

This business model is called **IP (Intellectual Property) Licensing**.

---

### 4. ARM's Growth

ARM processors became popular because they are:

* Low power
* Low cost
* High performance

They are used in:

* Mobile phones
* Hard drives
* PDAs
* Home entertainment devices
* Consumer electronics

---

### 5. ARM Provides More Than CPUs

Besides processor cores, ARM also provides:

* Memory controllers
* Peripherals
* System IP
* Development tools
* Software support

This helps chip manufacturers develop products more quickly.

---

# 1.5.2 ARM Processor Evolution

Before Cortex processors, ARM already had several successful processor families.

---

## ARM7TDMI

One of ARM's most successful processors.

Features:

* Used in many 32-bit microcontrollers
* Supports **two instruction sets**:

  * ARM (32-bit instructions)
  * Thumb (16-bit instructions)

Advantages:

* Better code density
* Smaller program memory
* Low power consumption

This made ARM processors popular in portable devices.

---

## ARM9

Designed for:

* Higher-performance microcontrollers
* Embedded applications requiring more processing power.

---

## ARM11

Designed mainly for:

* Mobile phones
* More advanced embedded systems.

---

# Why Cortex Was Introduced

ARM realised that different applications need different kinds of processors.

For example:

* A smartphone needs very high performance.
* A washing machine needs low cost and low power.
* A hard disk controller needs deterministic real-time behaviour.

Instead of using one processor family for everything, ARM created the **Cortex family**.

---

# Cortex Processor Family

ARM divided Cortex processors into **three profiles**.

## 1. Cortex-A (Application Profile)

Designed for:

* Smartphones
* Tablets
* TVs
* Linux
* Android
* iOS
* Windows

Characteristics:

* Highest performance
* Supports MMU
* Runs full operating systems

Examples:

* Cortex-A5
* Cortex-A7
* Cortex-A8
* Cortex-A9
* Cortex-A15
* Cortex-A53
* Cortex-A57

---

## 2. Cortex-R (Real-Time Profile)

Designed for:

* Automotive systems
* Hard disk controllers
* Mobile baseband processors
* Industrial real-time systems

Characteristics:

* High performance
* Deterministic execution
* Low latency
* High reliability

Examples:

* Cortex-R4
* Cortex-R5
* Cortex-R7

---

## 3. Cortex-M (Microcontroller Profile)

Designed for:

* Microcontrollers
* IoT devices
* Consumer electronics
* Mixed-signal chips

Characteristics:

* Low power
* Low cost
* Energy efficient
* Fast interrupt response
* Easy to program
* Deterministic behaviour

Examples:

* Cortex-M0
* Cortex-M0+
* Cortex-M1
* Cortex-M3
* Cortex-M4

---

# ARMv7 Architecture

The Cortex family was the first processor family based on **ARM Architecture Version 7 (ARMv7).**

For Cortex-M processors:

* **ARMv7-M** is the architecture specification.
* **Cortex-M3** is an implementation of ARMv7-M.
* **Cortex-M4** is also based on ARMv7-M, with additional DSP and optional floating-point features.

---

# Processor Evolution Timeline

```text
ARM6 (1991)
      │
      ▼
ARM7TDMI
      │
      ▼
ARM9
      │
      ▼
ARM11
      │
      ▼
Cortex Family
      │
 ┌────┼────┐
 ▼    ▼    ▼
A    R    M
```

---

# Cortex Family Comparison

| Profile  | Purpose                                 | Examples                            |
| -------- | --------------------------------------- | ----------------------------------- |
| Cortex-A | High-performance application processors | Smartphones, tablets, Linux systems |
| Cortex-R | Real-time, high-reliability processors  | Automotive, HDD controllers         |
| Cortex-M | Low-power microcontrollers              | STM32, NXP LPC, TM4C, Nordic nRF    |

---

# Key Takeaways

* ARM was founded in **1990** as **Advanced RISC Machines Ltd.**
* ARM introduced the **ARM6** processor in **1991**.
* ARM follows an **IP licensing** business model rather than manufacturing chips.
* Before Cortex, ARM developed **ARM7TDMI**, **ARM9**, and **ARM11** processor families.
* **ARM7TDMI** introduced support for both **ARM (32-bit)** and **Thumb (16-bit)** instruction sets, improving code density.
* ARM created the **Cortex family** to serve different markets:

  * **Cortex-A** → High-performance application processors.
  * **Cortex-R** → Real-time processors.
  * **Cortex-M** → Low-power microcontrollers.
* The **Cortex family** was the first based on **ARMv7 architecture**, and the **Cortex-M3/M4** processors implement the **ARMv7-M** profile.
