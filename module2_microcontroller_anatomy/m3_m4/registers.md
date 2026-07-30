
# Cortex-M Register Family

```text
                    Cortex-M Registers

                           │
        ┌──────────────────┴──────────────────┐
        │                                     │
 General Registers                     Special Registers
        │                                     │
 R0-R15                          CONTROL, xPSR, PRIMASK,
                                 FAULTMASK, BASEPRI
```

---

# Part 1: General Registers (R0–R15)

These are the registers you use while writing programs.

| Register | Name                 | Purpose                                    |
| -------- | -------------------- | ------------------------------------------ |
| R0-R12   | General Purpose      | Store variables and calculations           |
| R13      | SP (Stack Pointer)   | Points to the top of the stack             |
| R14      | LR (Link Register)   | Stores the return address of a function    |
| R15      | PC (Program Counter) | Stores the address of the next instruction |

Think of these as your **working registers**.

Example:

```c
int a = 10;
int b = 20;
int c = a + b;
```

Internally the processor may use:

```text
R0 = 10
R1 = 20
R2 = 30
```

---

# R13 – Stack Pointer (SP)

Purpose:

```text
Points to the stack.
```

The Cortex-M has **two physical stack pointers**.

```text
          R13 (SP)

              │

      ┌───────┴────────┐

     MSP              PSP
```

---

## MSP (Main Stack Pointer)

Used by:

* After reset
* Handler Mode
* Simple applications

Think of it as

```text
Operating System Stack
```

---

## PSP (Process Stack Pointer)

Used by:

* Thread Mode
* RTOS tasks

Think of it as

```text
Application Stack
```

---

# R14 – Link Register

Purpose:

Stores

```text
Where should I return?
```

Example

```text
main()

↓

add()

↓

multiply()
```

When entering

```text
multiply()
```

LR stores

```text
Return Address
```

When

```text
BX LR
```

executes,

processor comes back.

---

# R15 – Program Counter

Purpose

```text
Which instruction should execute next?
```

Example

```text
Instruction 1

↓

Instruction 2

↓

Instruction 3
```

PC always points to

the next instruction.

---

# Part 2: Special Registers

These are **control registers**.

They don't store variables.

Instead,

they control

processor behaviour.

---

# Special Register Family

```text
Special Registers

│

├── xPSR

├── CONTROL

├── PRIMASK

├── FAULTMASK

└── BASEPRI
```

---

# xPSR

Think of xPSR as

```text
Processor Status Register
```

It answers questions like

```text
Did the result become zero?

Am I handling an interrupt?

Am I in Thumb state?
```

---

xPSR actually contains

```text
APSR

+

EPSR

+

IPSR
```

---

# APSR

Think

```text
ALU Result
```

Stores arithmetic flags.

| Flag | Meaning                       |
| ---- | ----------------------------- |
| N    | Negative                      |
| Z    | Zero                          |
| C    | Carry                         |
| V    | Overflow                      |
| Q    | Saturation (Cortex-M4)        |
| GE   | DSP compare flags (Cortex-M4) |

Example

```text
5-5=0

↓

Z=1
```

---

# IPSR

Think

```text
Current Exception
```

Example

```text
No Interrupt

↓

IPSR = Thread Mode
```

UART Interrupt

↓

IPSR contains

UART Exception Number.

---

# EPSR

Think

```text
Execution State
```

Stores

```text
Thumb State

ICI/IT bits
```

Important

```text
Thumb Bit

Always = 1
```

---

# CONTROL Register

Think of CONTROL as

```text
Processor Configuration Register
```

It decides

1.

```text
Privilege
```

2.

```text
Stack Pointer Selection
```

3.

```text
Floating Point Context
```

---

## CONTROL Layout

```text
Bit2 Bit1 Bit0

FPCA SPSEL nPRIV
```

---

## Bit 0

```text
nPRIV
```

Controls

```text
Privileged

or

Unprivileged
```

---

## Bit1

```text
SPSEL
```

Controls

```text
MSP

or

PSP
```

---

## Bit2

```text
FPCA
```

Only

Cortex-M4

with FPU.

Indicates whether floating-point registers are part of the current execution context.

---

# PRIMASK

Think

```text
Master Interrupt Switch
```

When

```text
0

↓

Interrupts Enabled
```

When

```text
1

↓

Disable almost everything
```

Except

```text
NMI

HardFault
```

---

# FAULTMASK

Think

```text
Super Interrupt Switch
```

Disables

everything

except

```text
NMI
```

Even

HardFault

is blocked.

Used mainly

inside fault handlers.

---

# BASEPRI

Think

```text
Priority Filter
```

Unlike PRIMASK,

it doesn't disable

everything.

Example

```text
BASEPRI = 4
```

Then

Priority

```text
0

1

2

3

↓

Allowed
```

Priority

```text
4

5

6

7

↓

Blocked
```

---

# Which Register Should I Remember?

Think of them like employees in a company.

| Register  | Think Like               | Job                                       |
| --------- | ------------------------ | ----------------------------------------- |
| R0-R12    | Workers                  | Store data                                |
| R13       | Stack Manager            | Points to the stack                       |
| R14       | Return Manager           | Knows where to return                     |
| R15       | Navigator                | Knows the next instruction                |
| APSR      | Result Checker           | Stores arithmetic flags                   |
| IPSR      | Interrupt Reporter       | Tells which exception is running          |
| EPSR      | Execution Reporter       | Stores execution state (Thumb, ICI/IT)    |
| CONTROL   | Configuration Manager    | Chooses privilege level and stack pointer |
| PRIMASK   | Main Security Guard      | Disables almost all interrupts            |
| FAULTMASK | Emergency Security Guard | Disables everything except NMI            |
| BASEPRI   | Smart Security Guard     | Blocks only low-priority interrupts       |

---

# One Easy Memory Trick

Instead of memorizing **11 different registers**, remember only these **five questions**:

### 1. Where is my data?

```text
R0–R12
```

---

### 2. Where is my stack?

```text
R13 (MSP / PSP)
```

---

### 3. What is happening right now?

```text
xPSR

↓

APSR

IPSR

EPSR
```

---

### 4. How should the processor behave?

```text
CONTROL
```

---

### 5. Which interrupts should be blocked?

```text
PRIMASK

FAULTMASK

BASEPRI
```

---

# Final Mind Map

```text
                    Cortex-M Registers

                        Registers
                            │
        ┌───────────────────┴───────────────────┐
        │                                       │
 General Registers                       Special Registers
        │                                       │
 R0-R12 → Data                          xPSR → Processor Status
 R13    → Stack Pointer                 │
 R14    → Return Address                ├─ APSR → Arithmetic Flags
 R15    → Next Instruction              ├─ IPSR → Current Exception
                                        └─ EPSR → Execution State

                                        CONTROL
                                        ├─ nPRIV → Privileged / Unprivileged
                                        ├─ SPSEL → MSP / PSP
                                        └─ FPCA → Floating-point context

                                        PRIMASK → Disable almost all interrupts
                                        FAULTMASK → Disable all except NMI
                                        BASEPRI → Disable selected priorities
```

## What you should memorize for interviews

Don't try to memorize every bit field. Memorize this:

* **R13 = Stack Pointer (MSP/PSP)**
* **R14 = Link Register**
* **R15 = Program Counter**
* **xPSR = Processor Status (APSR + IPSR + EPSR)**
* **CONTROL = Privilege + Stack Pointer Selection**
* **PRIMASK = Disable almost all interrupts**
* **FAULTMASK = Disable everything except NMI**
* **BASEPRI = Priority-based interrupt masking**

Excellent. Before we start, remember one important thing:

> **This entire section applies only to the Cortex-M4 that has a Floating Point Unit (FPU).**
>
> If your Cortex-M3 or Cortex-M4 **doesn't have an FPU**, these registers do not exist.

Also, your book itself says:

> **In normal applications there is no need to modify these settings.**

So don't panic. Most beginners never touch these registers.

Let's understand them one by one.

---

# What is the Floating Point Unit (FPU)?

Normally, the CPU performs operations like:

```c
10 + 20
50 - 15
8 * 9
```

These are **integer operations**.

But suppose your program contains

```c
float a = 3.14;
float b = 2.71;

float c = a + b;
```

Now the processor is dealing with **decimal numbers**.

These are called **floating-point numbers**.

Instead of making the CPU do all this work slowly,

Cortex-M4 has a separate hardware called the

## Floating Point Unit (FPU)

Think of it as

```text
CPU
│
├── Integer Calculator
│
└── Floating Point Calculator
```

The floating-point calculator performs decimal calculations much faster.

---

# What is FPSCR?

FPSCR means

> **Floating Point Status and Control Register**

Notice the name.

It has **two jobs**.

## 1. Status

It tells us

> What happened during floating-point calculations?

Example:

* Did overflow happen?
* Was the result zero?
* Was division by zero attempted?

---

## 2. Control

It tells the FPU

> How should floating-point calculations behave?

Example:

* How should numbers be rounded?
* Should special values (NaN) be propagated?
* Should tiny numbers become zero?

---

Think of FPSCR like this:

```text
FPSCR

│

├── Status
│      "What happened?"
│
└── Control
       "How should calculations work?"
```

---

# IEEE 754

The book says

> By default, the behaviour is compliant with IEEE 754.

What is IEEE 754?

It is simply

> **the international standard for floating-point arithmetic.**

It defines

* How decimal numbers are stored
* How rounding works
* How infinity works
* How NaN works

The Cortex-M4 follows this standard by default.

So normally

**you don't need to change anything.**

---

# FPSCR Flags

Let's understand every field.

---

# N Flag

Exactly like APSR.

Means

> Negative Result

Example

```c
float a = 2.0;
float b = 5.0;

float c = a - b;
```

Result

```text
-3.0
```

Processor sets

```text
N = 1
```

---

# Z Flag

Means

> Zero Result

Example

```c
5.5 - 5.5
```

Result

```text
0.0
```

Processor sets

```text
Z = 1
```

---

# C Flag

Carry/Borrow flag

Updated after floating-point comparison operations.

Just like APSR,

it helps the processor during comparisons.

---

# V Flag

Overflow Flag.

Suppose

the FPU tries to produce

a number larger than it can represent.

Example

```text
Very Very Very Huge Number
```

Overflow occurs.

Processor sets

```text
V = 1
```

---

# AHP

AHP means

> Alternate Half Precision

The book says

```
0

↓

IEEE Half Precision
(Default)
```

```
1

↓

Alternative Half Precision
```

---

What is Half Precision?

Normally

```text
float

↓

32 bits
```

Half precision means

```text
16 bits
```

It uses

less memory

but

less accuracy.

The book doesn't explain it further here.

---

# DN

DN means

> Default NaN Mode

---

What is NaN?

NaN means

> Not a Number

Example

```text
0 ÷ 0
```

This is not

Infinity.

It is

undefined.

Processor produces

```text
NaN
```

---

The book says

If

```
DN = 0
```

NaN values

continue through later calculations.

Example

```text
NaN + 5

↓

NaN
```

---

If

```
DN = 1
```

Any calculation involving NaN

returns

the processor's **default NaN value**.

---

# FZ

FZ means

> Flush To Zero

---

Imagine

a calculation produces

an extremely tiny number.

Example

```text
0.00000000000000000000000001
```

Such numbers are called **very small (denormalized) values**.

---

The book says

```
FZ = 0
```

Normal IEEE behaviour.

Keep those tiny values.

(Default)

---

If

```
FZ = 1
```

Tiny numbers

become

```text
0
```

This makes calculations faster,

but less accurate.

---

# RMode

RMode means

> Rounding Mode

Suppose

the result is

```text
5.8
```

but

only an integer is needed.

How should it be rounded?

The FPSCR provides four choices.

---

## 00

Round to Nearest

(Default)

```
5.4 → 5

5.8 → 6
```

---

## 01

Round Towards Plus Infinity

Always round upward.

```
5.1 → 6

5.9 → 6
```

---

## 10

Round Towards Minus Infinity

Always round downward.

```
5.9 → 5
```

---

## 11

Round Towards Zero

Simply remove the decimal part.

```
5.9 → 5

-5.9 → -5
```

---

# Exception Bits

Now the book introduces several bits ending with

```text
C
```

These are called

**Cumulative Exception Bits.**

Think of them as

little warning lights.

Whenever a floating-point problem happens,

the corresponding light turns ON.

Software can later check these bits.

---

# IDC

Input Denormal Exception

Means

the input value

is extremely tiny

(not within the normalized range mentioned by the book).

Processor sets

```text
IDC = 1
```

---

# IXC

Inexact Result

Suppose

the exact answer is

```text
1.333333333333333...
```

Processor cannot store infinite decimal places.

It stores

```text
1.33333
```

Not exact.

Processor sets

```text
IXC = 1
```

---

# UFC

Underflow

Result became

too small

to represent normally.

Processor sets

```text
UFC = 1
```

---

# OFC

Overflow

Result became

too large

to represent.

Processor sets

```text
OFC = 1
```

---

# DZC

Division by Zero

Example

```text
10 ÷ 0
```

Processor sets

```text
DZC = 1
```

---

# IOC

Invalid Operation

Example

```text
0 ÷ 0
```

or another invalid floating-point operation.

Processor sets

```text
IOC = 1
```

---

# Important Note from the Book

The book says

These exception bits

can be checked

by software.

Meaning

your program can later ask

```text
Did overflow happen?

Did divide-by-zero happen?

Did underflow happen?
```

This helps detect floating-point errors.

The book also says that the detailed behaviour of these bits is explained later in **Chapter 13**.

---

# Memory-Mapped Floating Point Registers

Until now,

we studied

special registers

like

```
CONTROL

PRIMASK

BASEPRI
```

These are **not memory-mapped**.

But now,

the book says

the FPU also has

**memory-mapped registers**.

That means

they have

real memory addresses.

---

# CPACR

One important register is

> **CPACR**
>
> Coprocessor Access Control Register

Its job is very simple.

It controls

whether

the FPU

is

ON

or

OFF.

---

# Why Is FPU OFF by Default?

The book clearly says

> To reduce power consumption.

If your program

never uses

floating-point numbers,

keeping the FPU OFF

saves power.

---

# Before Using Floating Point

The book says

Before executing

floating-point instructions,

the FPU

must be enabled.

---

# CMSIS Code

The book gives

```c
SCB->CPACR |= 0xF << 20;
```

Let's understand it.

* **SCB** = System Control Block.
* **CPACR** = Coprocessor Access Control Register.
* `0xF << 20` sets the required access bits.

The effect is:

```text
Enable Full Access

↓

Floating Point Unit
```

After this,

floating-point instructions

can execute.

---

# Assembly Version

The book also gives assembly code.

Let's read it line by line.

### Step 1

```assembly
LDR R0, =0xE000ED88
```

Load the **address of CPACR** into `R0`.

---

### Step 2

```assembly
LDR R1, =0x00F00000
```

Load the bit pattern that enables the FPU into `R1`.

---

### Step 3

```assembly
LDR R2, [R0]
```

Read the current value of CPACR into `R2`.

---

### Step 4

```assembly
ORRS R2, R2, R1
```

Set the required enable bits without changing the other bits.

---

### Step 5

```assembly
STR R2, [R0]
```

Write the updated value back to CPACR.

The FPU is now enabled.

---

# Complete Summary

| Register/Field | Purpose                                     |
| -------------- | ------------------------------------------- |
| **FPSCR**      | Floating Point Status and Control Register  |
| **N**          | Negative result                             |
| **Z**          | Zero result                                 |
| **C**          | Carry/Borrow (comparison status)            |
| **V**          | Overflow status                             |
| **AHP**        | Selects half-precision format               |
| **DN**         | Controls NaN handling                       |
| **FZ**         | Flushes tiny values to zero when enabled    |
| **RMode**      | Selects the floating-point rounding mode    |
| **IDC**        | Input denormal exception                    |
| **IXC**        | Inexact result exception                    |
| **UFC**        | Underflow exception                         |
| **OFC**        | Overflow exception                          |
| **DZC**        | Divide-by-zero exception                    |
| **IOC**        | Invalid operation exception                 |
| **CPACR**      | Enables or disables the Floating Point Unit |

## What should you remember for now?

Since the book itself says **normal applications usually don't need to modify these settings**, you only need to remember these key points:

1. **FPSCR** = Floating Point **Status + Control** Register.
2. It contains **status flags** (N, Z, C, V) and **control settings** (AHP, DN, FZ, RMode).
3. It also contains **exception flags** (IDC, IXC, UFC, OFC, DZC, IOC) that software can check after floating-point operations.
4. The **FPU is disabled by default** to save power.
5. Before using floating-point instructions, the **CPACR** register must be configured to enable the FPU.
6. The detailed operation of these floating-point features is intentionally deferred by the book to **Chapter 13**, so there is no need to master every bit at this stage.
Excellent! This section is **one of the foundations of assembly programming**. Every time the CPU performs arithmetic like **ADD, SUB, CMP, ADC, SBC**, it updates four important flags in the **APSR (Application Program Status Register)**.

These four flags are:

* **N (Negative)**
* **Z (Zero)**
* **C (Carry)**
* **V (Overflow)**

These are collectively called the **NZCV flags**.

Let's understand every concept from your book **step by step without skipping anything**.

---

# 4.3.1 Integer Status Flags

The book says:

> The integer status flags are very similar to ALU status flags in many other processor architectures.

### What does this mean?

The **ALU (Arithmetic Logic Unit)** performs operations like:

* Addition
* Subtraction
* Multiplication
* Comparison
* Bitwise AND
* Bitwise OR

After every operation, the ALU tells the processor **what happened**.

Example:

```
10 + 20 = 30
```

Nothing special happened.

But consider

```
5 - 5 = 0
```

Now the processor wants to remember

> "The result became zero."

It stores this information in the **Z flag**.

---

# Why are these flags needed?

The book gives two reasons.

## 1. Conditional Branches

Example

```c
if(a==b)
{
   LED_ON();
}
```

How does the processor know

```
a == b ?
```

It compares

```
a

and

b
```

If they are equal

```
Z = 1
```

Then the processor jumps to

```
LED_ON()
```

without comparing again.

---

## 2. Conditional Execution

Some instructions execute only when certain flags satisfy a condition.

For example,

```
Execute this instruction

ONLY IF

Result is zero.
```

The processor checks the **Z flag**.

---

# The Four Integer Flags

The book lists four flags.

```
N
Z
C
V
```

Let's understand each one.

---

# 1. N Flag (Negative)

Book says

> Set to bit[31] of the result.

This sounds confusing.

Let's simplify it.

In Cortex-M,

numbers are stored in **32 bits**.

Example

```
00000000 00000000 00000000 00001010
```

The **leftmost bit** is **bit 31**.

```
Bit31

↓

Sign Bit
```

If

```
Bit31 = 0
```

the number is

```
Positive
```

If

```
Bit31 = 1
```

the number is

```
Negative
```

(when interpreted as a signed integer, exactly as the book states).

---

## Example

```
10 - 20

=

-10
```

Binary (simplified)

```
11111111........0110
```

Highest bit

```
1
```

Processor sets

```
N = 1
```

---

## Another Example

```
20 - 10

=

10
```

Highest bit

```
0
```

Processor sets

```
N = 0
```

---

# Remember

```
N = 1

↓

Negative Result
```

---

# 2. Z Flag (Zero)

Book says

> Set to 1 if the result is zero.

Simple.

---

## Example

```
15 - 15

=

0
```

Processor

```
Z = 1
```

---

## Another Example

```
20 - 15

=

5
```

Processor

```
Z = 0
```

---

## Compare Instruction

The book also says

Z becomes

1

after a compare instruction

if

both values are equal.

Example

```
CMP R0,R1
```

Suppose

```
R0 = 25

R1 = 25
```

Comparison

```
Equal
```

Processor

```
Z = 1
```

---

# Remember

```
Z = 1

↓

Result is Zero

or

Both operands are Equal
```

---

# 3. C Flag (Carry)

This is the flag that confuses almost everyone.

The book says

```
Carry flag
```

Let's separate

Addition

and

Subtraction.

---

# Carry in Addition

Imagine

only

4-bit arithmetic.

Largest number

```
1111

=

15
```

Now

```
1111

+

0001
```

Result

```
10000
```

But

processor has only

4 bits.

So it stores

```
0000
```

The extra

```
1
```

comes out.

That extra bit is called

```
Carry
```

Processor sets

```
C = 1
```

---

## Another Example

```
5 + 3

=

8
```

No extra bit.

```
C = 0
```

---

# Carry in Subtraction

The book says

For subtraction,

Carry means

```
NOT Borrow
```

This is ARM terminology.

---

Example

```
10 - 5
```

Can be done normally.

No borrow needed.

Processor

```
C = 1
```

---

Example

```
5 - 10
```

Borrow required.

Processor

```
C = 0
```

---

This is why beginners often get confused.

For subtraction

```
Borrow

↓

Carry becomes 0
```

No borrow

↓

Carry becomes 1

Exactly as the book states.

---

# Carry in Shift Operations

The book also says

Carry is updated

during

```
Shift

Rotate
```

operations.

Example

```
10010000

>>

1
```

The last bit shifted out

goes into

Carry.

The book does not explain this further here, so we'll stop at that point.

---

# Remember

```
Addition

Extra Bit

↓

Carry = 1
```

```
Subtraction

No Borrow

↓

Carry = 1
```

---

# 4. V Flag (Overflow)

Overflow

is

NOT

Carry.

This is another important point.

Carry works mainly for **unsigned arithmetic**.

Overflow works for **signed arithmetic**.

---

Imagine

8-bit signed numbers.

Range

```
-128

to

127
```

Now calculate

```
100

+

100
```

Actual answer

```
200
```

But

200

cannot be represented

in signed 8-bit.

Overflow occurs.

Processor

```
V = 1
```

---

Another Example

```
20

+

10

=

30
```

Fits perfectly.

```
V = 0
```

---

# Remember

```
Signed Result

Too Big

or

Too Small

↓

Overflow
```

---

# Summary of Four Flags

| Flag | Meaning  | Set When                                      |
| ---- | -------- | --------------------------------------------- |
| N    | Negative | Result is negative (bit 31 = 1)               |
| Z    | Zero     | Result equals zero                            |
| C    | Carry    | Carry in addition or no borrow in subtraction |
| V    | Overflow | Signed arithmetic overflow                    |

---

# Which Instructions Update These Flags?

The book says

Most

16-bit instructions

update

the flags automatically.

---

For

32-bit instructions,

the instruction encoding usually contains a bit that decides

```
Update Flags?

Yes

or

No
```

---

# Example

The book gives

```
MULS
```

Multiply.

It updates

```
N

Z
```

But

does

NOT

update

```
V

C
```

Exactly as the book states.

---

# Understanding Table 4.7

Let's look at a few examples from the book.

---

## Example 1

```
0x70000000

+

0x70000000
```

Book says

```
Result

=

0xE0000000

N = 1

Z = 0

C = 0

V = 1
```

Why?

* Highest bit is 1 → **N = 1**
* Result is not zero → **Z = 0**
* No carry out of the most significant bit → **C = 0**
* As signed numbers, the addition overflowed → **V = 1**

---

## Example 2

```
0x80000000

+

0x80000000
```

Book result

```
0x00000000

N = 0

Z = 1

C = 1

V = 1
```

Explanation

* Result wrapped around to zero → **Z = 1**
* Carry out occurred → **C = 1**
* Signed overflow occurred → **V = 1**
* Result bit 31 is 0 → **N = 0**

---

## Example 3

```
0x00001234

-

0x00001000
```

Book result

```
0x00000234

N = 0

Z = 0

C = 1

V = 0
```

Explanation

* Positive result → **N = 0**
* Not zero → **Z = 0**
* No borrow needed → **C = 1**
* No signed overflow → **V = 0**

---

## Example 4

```
0x00000004

-

0x00000005
```

Book result

```
0xFFFFFFFF

N = 1

Z = 0

C = 0

V = 0
```

Explanation

* Result is -1 in two's complement → **N = 1**
* Not zero → **Z = 0**
* Borrow required → **C = 0**
* No signed overflow → **V = 0**

---

# Carry in 64-bit Addition

The book gives a very important example.

Suppose we want to add two **64-bit numbers**.

The Cortex-M is a **32-bit processor**, so it cannot add all 64 bits at once.

It splits the operation into two 32-bit additions.

Suppose

```
X = High32 | Low32

Y = High32 | Low32
```

### Step 1

Add the lower 32 bits.

```
Low Result

=

LowX

+

LowY
```

If this addition produces a carry,

the **C flag** becomes 1.

---

### Step 2

Now add the upper 32 bits.

But don't forget the carry from Step 1.

So the processor effectively performs

```
Upper Result

=

UpperX

+

UpperY

+

Carry
```

This is exactly what the book shows:

```c
Z[31:0]  = X[31:0]  + Y[31:0];      // Lower 32-bit addition
// Carry flag is updated here

Z[63:32] = X[63:32] + Y[63:32] + Carry;
```

Without the carry from the lower half, the final 64-bit result could be incorrect.

---

# Complete Memory Trick

Think of the APSR flags as four questions the processor asks after every arithmetic operation:

| Question                                        | Flag  |
| ----------------------------------------------- | ----- |
| **Is the result negative?**                     | **N** |
| **Is the result zero?**                         | **Z** |
| **Did an unsigned carry (or no borrow) occur?** | **C** |
| **Did a signed overflow occur?**                | **V** |

Whenever you see `ADD`, `SUB`, `CMP`, `MULS`, or similar instructions, remember that the processor may update these four flags. Later instructions, especially conditional branches, use these flags to decide what to do next. This is why the NZCV flags are so fundamental in ARM programming.
Excellent! This section is actually much easier than it looks. The whole section is about **one flag only**:

> **Q Flag (Saturation Flag)**

If you understand **what saturation means**, then you'll understand the entire section.

Let's go through it **line by line**, exactly following the book.

---

# 4.3.2 Q Status Flag

Earlier we learned the APSR contains

```text
N
Z
C
V
```

But in **ARMv7-M (Cortex-M3/M4)** there is one more flag:

```text
Q
```

The book calls it the

> **Q Status Flag**

---

# What is the Q Flag?

The book says:

> The Q is used to indicate an occurrence of saturation during saturation arithmetic operations.

Let's simplify that.

The Q flag simply answers one question:

> **"Did saturation happen?"**

If yes,

```text
Q = 1
```

If no,

Q remains unchanged.

---

# First, What is Saturation?

This is the most important concept.

Normally, when a calculation produces a value that is **too large** to fit into the destination register, **overflow** occurs.

Example (using an 8-bit signed number for simplicity):

An 8-bit signed integer can store only:

```text
-128  to  +127
```

Now suppose you calculate

```text
100 + 50 = 150
```

But

```text
150
```

cannot be stored in an 8-bit signed register.

---

# Normal Arithmetic

In normal arithmetic,

the extra bits are lost.

The value "wraps around."

Example

```text
100 + 50

↓

150

↓

Overflow

↓

Wrong Result
```

The processor simply stores whatever fits into the register.

This can produce a completely incorrect value.

---

# Why Is That a Problem?

Imagine you are processing audio.

Speaker samples are

```text
-32768

to

32767
```

Now suppose

after processing

the result becomes

```text
45000
```

Normal overflow

may produce

something like

```text
-20536
```

Instead of a loud sound,

you suddenly get

a completely wrong signal.

This causes

**signal distortion**.

Exactly what the book mentions.

---

# Saturation Arithmetic

Instead of allowing overflow,

the processor says

> "I can't represent this value."

So it stores

the **largest possible value**.

Example

Maximum value

```text
127
```

Suppose calculation gives

```text
150
```

Instead of wrapping around,

processor stores

```text
127
```

This is called

**Saturation**.

---

# Example

Normal arithmetic

```text
120 + 20

↓

140

↓

Overflow

↓

Wrong Value
```

---

Saturation arithmetic

```text
120 + 20

↓

140

↓

Maximum Allowed

↓

127
```

Much safer.

---

# Underflow

The same idea applies

to numbers that are

too small.

Suppose

minimum value is

```text
-128
```

Calculation

```text
-120 - 20

↓

-140
```

Cannot be represented.

Instead of wrapping around,

processor stores

```text
-128
```

---

# Signed Saturation

Figure 4.16 shows

Signed Saturation.

Imagine this graph.

```text
               Maximum

                 +127
                  ▲
                  │
                  │
                  │
                  │
------------------┼----------------
                  │
                  │
                  │
                  ▼
                -128
               Minimum
```

If the result tries to go

above

```text
127
```

processor stores

```text
127
```

If the result tries to go

below

```text
-128
```

processor stores

```text
-128
```

And

```text
Q = 1
```

---

# Unsigned Saturation

Unsigned numbers

cannot become negative.

Suppose

8-bit unsigned

stores

```text
0

to

255
```

Now

```text
250 + 20

↓

270
```

Too large.

Processor stores

```text
255
```

If calculation goes below

```text
0
```

processor stores

```text
0
```

Again

```text
Q = 1
```

---

# What Does the Q Flag Do?

The book says

Whenever

saturation occurs

```text
Q = 1
```

That's all.

Think of Q as a warning light.

```text
Saturation Happened?

↓

YES

↓

Q = 1
```

---

# Very Important Property of Q

The book says

> After this bit is set, it remains set until software clears it.

This is different from

N

Z

C

V.

Those flags

change

after almost every arithmetic instruction.

But

Q behaves differently.

---

Suppose

you execute

```text
Operation 1

↓

Saturation

↓

Q = 1
```

Now execute

```text
Operation 2

↓

No Saturation
```

What happens?

The book says

```text
Q

Still = 1
```

It **does not clear automatically.**

---

# Why?

Imagine a car dashboard.

Suppose

the engine overheats.

The warning light turns ON.

Even if

temperature becomes normal,

the light

stays ON

until someone resets it.

Exactly the same idea.

---

# Why Is This Useful?

Suppose

your DSP algorithm performs

100 additions.

```text
Step1

↓

Step2

↓

Step3

↓

...

↓

Step100
```

Checking after every step

would be slow.

Instead,

at the end

you simply ask

```text
Is Q = 1 ?
```

If yes,

at least one operation

saturated.

Very convenient.

This is exactly what the book means when it says:

> You can determine whether saturation occurred at the end of a sequence of operations without checking each step.

---

# Which Instructions Set Q?

The book says

Most saturation instructions

start with

```text
Q
```

Example

```text
QADD16
```

Read the name carefully.

```text
Q

↓

Saturation
```

So whenever you see

```text
QADD

QSUB

QADD16
```

you should think

```text
Saturation Arithmetic
```

---

# Does Every Cortex-M Support Q?

The book clearly states:

### ARMv7-M

Examples

```text
Cortex-M3

Cortex-M4
```

Supports

```text
Q Flag
```

---

### ARMv6-M

Example

```text
Cortex-M0
```

Does

NOT

support

```text
Q
```

---

# Cortex-M3 vs Cortex-M4

The book makes one more comparison.

## Cortex-M3

Provides

only

a few

**Saturation Adjustment Instructions**.

---

## Cortex-M4

Provides

* Full Saturation Arithmetic Instructions
* Saturation Adjustment Instructions

So

the Cortex-M4 has more DSP capabilities than the Cortex-M3.

---

# Complete Example

Let's use an 8-bit signed register for illustration.

Maximum

```text
+127
```

Minimum

```text
-128
```

---

### Example 1

Normal Arithmetic

```text
100 + 50

↓

150

↓

Overflow

↓

Wrong Result
```

Q

```text
Not Used
```

---

### Example 2

Saturation Arithmetic

```text
100 + 50

↓

150

↓

Store

127

↓

Q = 1
```

---

### Example 3

Next Instruction

```text
20 + 10

↓

30
```

No saturation.

But

```text
Q

Still = 1
```

because software has not cleared it.

---

# Memory Trick

Think of the Q flag as a **"Saturation Warning Light."**

```text
Calculation

↓

Too Big ?

↓

Store Maximum

↓

Q = 1
```

```text
Calculation

↓

Too Small ?

↓

Store Minimum

↓

Q = 1
```

Unlike the N, Z, C, and V flags, the **Q flag is sticky**:

```text
Saturation occurs

↓

Q becomes 1

↓

Q stays 1

↓

Software clears it
```

---

# Complete Summary

| Topic                    | Meaning                                                                                              |
| ------------------------ | ---------------------------------------------------------------------------------------------------- |
| **Q Flag**               | Indicates that a saturation operation occurred                                                       |
| **Available In**         | ARMv7-M (Cortex-M3, Cortex-M4)                                                                       |
| **Not Available In**     | ARMv6-M (Cortex-M0)                                                                                  |
| **Saturation**           | Clamp the result to the maximum or minimum representable value instead of letting it wrap around     |
| **Overflow Saturation**  | Store the maximum value                                                                              |
| **Underflow Saturation** | Store the minimum value                                                                              |
| **Sticky Behavior**      | Once Q becomes 1, it remains 1 until software clears it                                              |
| **Why Useful?**          | Lets software detect whether any saturation occurred across a sequence of saturation operations      |
| **Typical Instructions** | Usually have mnemonics beginning with **Q** (for example, `QADD16`)                                  |
| **Main Use**             | Digital Signal Processing (DSP), where wrapping around would introduce significant signal distortion |

The **one sentence** you should remember is:

> **The Q flag is a sticky saturation flag. Whenever a saturation arithmetic instruction clamps a result to its maximum or minimum value instead of allowing overflow or underflow, the processor sets Q to 1, and it stays set until software explicitly clears it.**
Excellent. This is actually **one of the hardest topics in Chapter 4**. The good news is:

> **For beginners, you do NOT need to memorize all the instructions in Table 4.8.**

The book itself says that **SIMD and SEL instructions are explained in Chapter 5**. So here, you only need to understand **what the GE bits are and why they exist**.

Let's learn it from scratch.

---

# 4.3.3 GE Bits

Earlier we studied APSR.

```text
APSR

├── N
├── Z
├── C
├── V
├── Q
└── GE
```

Now we are studying

```text
GE
```

GE means

> **Greater Equal**

---

# Which Processor Has GE?

The book clearly says

| Processor | GE Available? |
| --------- | ------------- |
| Cortex-M0 | ❌ No          |
| Cortex-M3 | ❌ No          |
| Cortex-M4 | ✅ Yes         |

So,

GE exists **only in Cortex-M4**.

---

# Why Was GE Introduced?

The answer is

```text
SIMD Instructions
```

GE is **not** used by normal ADD or SUB instructions.

It is used only with

```text
SIMD Instructions
```

---

# What is SIMD?

SIMD means

> **Single Instruction Multiple Data**

Normally,

suppose you want to add

```text
1 + 2

3 + 4

5 + 6

7 + 8
```

A normal processor executes

```text
ADD

ADD

ADD

ADD
```

Four instructions.

---

A SIMD instruction can do

all four additions

at once.

Think of it like

```text
Normal CPU

1+2

↓

3+4

↓

5+6

↓

7+8
```

One after another.

---

SIMD

```text
1+2

3+4

5+6

7+8

↓

ALL TOGETHER
```

One instruction.

That is why SIMD is very fast.

---

# Why Does Cortex-M4 Need GE?

Suppose

one SIMD instruction

adds

4 bytes simultaneously.

Example

Register A

```text
10

20

30

40
```

Register B

```text
5

25

35

10
```

SIMD ADD

produces

```text
15

45

65

50
```

Now

the processor wants to know

which byte

gave a positive result,

or

which byte overflowed.

One flag

is not enough.

We need

4 flags.

Therefore

ARM created

```text
GE[3]

GE[2]

GE[1]

GE[0]
```

Together

they are called

```text
GE Bits
```

---

# GE is 4 Bits

Unlike

```text
N

Z

C

V

Q
```

which are

only

1 bit,

GE is

```text
4 bits
```

Diagram

```text
GE

+---+---+---+---+
|3  |2  |1  |0  |
+---+---+---+---+
```

---

# What Does Each Bit Represent?

The book says

For most SIMD instructions,

each GE bit

corresponds to

one byte.

Imagine

32-bit register.

```text
+--------+--------+--------+--------+

 Byte3     Byte2     Byte1     Byte0

+--------+--------+--------+--------+
```

Now

GE

looks like

```text
GE3

↓

Byte3

GE2

↓

Byte2

GE1

↓

Byte1

GE0

↓

Byte0
```

Each byte

gets

its own flag.

---

# Example

Suppose SIMD adds

four bytes.

Result

```text
Byte0

Positive
```

Processor

```text
GE0 = 1
```

---

Result

```text
Byte1

Negative
```

Processor

```text
GE1 = 0
```

---

Result

```text
Byte2

Positive
```

Processor

```text
GE2 = 1
```

---

Result

```text
Byte3

Positive
```

Processor

```text
GE3 = 1
```

Final

```text
GE

=

1101
```

---

# Half-Word Operations

The book also talks about

16-bit SIMD instructions.

Remember

32 bits

can also be divided into

```text
+----------------+----------------+

 Upper Half        Lower Half

 16 bits            16 bits

+----------------+----------------+
```

Now

instead of

4 bytes,

processor works on

2 half-words.

---

The book says

```text
Lower Half

↓

GE1

GE0
```

Upper Half

↓

```text
GE3

GE2
```

If

Lower Half

result

is positive,

processor sets

```text
GE1 = 1

GE0 = 1
```

Otherwise

```text
GE1 = 0

GE0 = 0
```

Similarly

Upper Half

controls

```text
GE2

GE3
```

---

# What Does Table 4.8 Mean?

Don't worry about remembering every instruction name.

The table simply tells us

which SIMD instruction

updates

GE bits

and

how.

For example,

the first row says

If

Lower Half

result

is

greater than or equal to

0

then

```text
GE1 GE0

=

11
```

Otherwise

```text
GE1 GE0

=

00
```

Similarly,

Upper Half

controls

```text
GE3 GE2
```

---

# Byte Operations

For

8-bit SIMD instructions,

each byte

gets

one GE bit.

Example

```text
Byte0

↓

GE0
```

Positive?

↓

```text
GE0 = 1
```

Negative?

↓

```text
GE0 = 0
```

The same rule applies to

Byte1, Byte2, and Byte3.

---

# What Is the SEL Instruction?

Now the book introduces

```text
SEL
```

Don't panic.

The book says

GE bits

are used by

SEL.

Think of SEL as

a **selector**.

It chooses

between two registers.

Example

Register A

```text
10

20

30

40
```

Register B

```text
100

200

300

400
```

Suppose

```text
GE

=

1010
```

Then

SEL

might choose

```text
Byte3

↓

A
```

```text
Byte2

↓

B
```

```text
Byte1

↓

A
```

```text
Byte0

↓

B
```

The exact behavior of the SEL instruction is explained later in **Chapter 5**. At this point, the important idea from the book is simply that **SEL uses the GE bits to decide which byte to select from each source register**.

---

# Reading GE

The book also says

GE bits

can be read

by reading

```text
APSR
```

using

```assembly
MRS R0, APSR
```

Then

software

can examine

the GE bits

if additional processing is needed.

---

# Why Is This Useful?

Suppose

you are processing

an image.

Each pixel

has

4 bytes.

SIMD processes

all four pixels

together.

GE immediately tells

which pixel

satisfied the condition.

No need

to check

every pixel

individually.

This makes DSP and multimedia processing much faster.

---

# Should You Memorize Table 4.8?

**No.**

The book itself says

> More details of the SIMD and SEL instructions are given in **Chapter 5**.

For now,

just understand

the concept.

---

# Complete Summary

| Topic                | Explanation                                                                  |
| -------------------- | ---------------------------------------------------------------------------- |
| **GE**               | Greater-Equal bits                                                           |
| **Width**            | 4 bits                                                                       |
| **Available In**     | Cortex-M4 only                                                               |
| **Not Available In** | Cortex-M3 and Cortex-M0                                                      |
| **Used By**          | SIMD instructions                                                            |
| **Purpose**          | Stores per-byte or per-half-word results of SIMD operations                  |
| **8-bit SIMD**       | Each GE bit corresponds to one byte                                          |
| **16-bit SIMD**      | GE[1:0] correspond to the lower half-word and GE[3:2] to the upper half-word |
| **SEL Instruction**  | Uses the GE bits to choose bytes from two source registers                   |
| **Can Be Read?**     | Yes, by reading the APSR                                                     |

## What you should remember for interviews

You only need these four points:

1. **GE (Greater-Equal) is a 4-bit field in the APSR.**
2. **It is available only on the Cortex-M4** (not on Cortex-M3 or Cortex-M0).
3. **It is updated by SIMD instructions** to record results for individual bytes or half-words.
4. **The SEL instruction uses the GE bits** to perform conditional byte selection, with the detailed behavior covered later in Chapter 5.

