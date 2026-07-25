Excellent! Now we are entering **Section 2.2**, which is about **GPIO pins and alternate pin functions**. This is one of the most practical topics because every embedded project uses I/O pins.

I'll explain it from **scratch**, assuming you have never used a microcontroller before.

---

# Part 8: Texas Instruments LM3S and TM4C I/O Pins

---

# First Question

## What is an I/O Pin?

Imagine you are inside a house.

The house has doors and windows.

```text
        House

  +------------------+
  |                  |
  |                  |
  |                  |
  +------------------+
      Door
```

People enter and leave through the door.

Similarly,

a microcontroller communicates with the outside world using **pins**.

---

## Real-Life Example

Suppose you have an LED.

```text
Microcontroller -------- LED
```

The LED is outside the CPU.

The CPU needs a path to control it.

That path is called an

# I/O Pin

---

# What does I/O mean?

I/O stands for

```text
Input / Output
```

Input means

The microcontroller receives information.

Examples

* Push button
* Temperature sensor
* Light sensor
* Switch

---

Output means

The microcontroller sends information.

Examples

* LED
* Motor
* LCD
* Buzzer
* Relay

---

## Example

Suppose you press a button.

```text
Button

↓

GPIO Pin

↓

CPU
```

The button is an **input**.

---

Suppose CPU turns ON LED.

```text
CPU

↓

GPIO Pin

↓

LED
```

The LED is an **output**.

---

# GPIO

Most pins are called

```text
GPIO

General Purpose Input Output
```

These pins can be configured as either:

* Input
* Output

Example

```c
GPIOPin = INPUT;
```

or

```c
GPIOPin = OUTPUT;
```

---

# What does "General Purpose" mean?

General Purpose means

The pin is **not fixed**.

Today

```text
PA0

↓

Button
```

Tomorrow

```text
PA0

↓

LED
```

The same pin can perform different tasks depending on software configuration.

---

# Ports and Pins

Pins are grouped into

**Ports**.

Example

```text
Port A

PA0

PA1

PA2

PA3

PA4

PA5

PA6

PA7
```

Similarly

```text
Port B

PB0

PB1

PB2

PB3
...
```

Think of it like apartments.

```text
Apartment A

Room0

Room1

Room2
```

Port = Apartment

Pin = Room

---

# One Pin Can Do Many Jobs

This is the most important idea in this section.

A single physical pin can perform **multiple functions**.

Example

```text
PA0
```

Can become

* GPIO
* UART
* SSI (SPI)
* Timer
* ADC

depending on the microcontroller.

Only **one function can be active at a time**.

---

## Real-Life Example

Imagine one employee.

Morning

Teacher

Afternoon

Driver

Evening

Shopkeeper

Same person

Different jobs.

Similarly

One pin

Different functions.

---

# Example

The book says

```text
PA0

PA1
```

can become

UART pins.

Instead of

```text
GPIO
```

they become

```text
UART TX

UART RX
```

---

Suppose

```text
Laptop

↓

UART Cable

↓

TM4C
```

The communication happens through PA0 and PA1 (if configured for UART).

---

# What is an Alternate Function?

Normally

```text
PA0

↓

GPIO
```

But software can change it to

```text
PA0

↓

UART
```

This is called

**Alternate Function**

because the pin is performing something other than general-purpose I/O.

---

# JTAG

The next topic is

```text
JTAG
```

Students often confuse this.

Let's understand it.

---

# What is JTAG?

JTAG stands for

```text
Joint Test Action Group
```

It is a hardware interface used for

* Programming the microcontroller
* Debugging the program
* Reading registers
* Setting breakpoints
* Single-step execution

---

## Real-Life Example

Suppose a doctor checks your heartbeat using a medical instrument.

That instrument is connected to your body.

Similarly

The debugger connects to the microcontroller through JTAG.

---

# JTAG Connection

```text
PC

↓

Debugger

↓

JTAG

↓

TM4C
```

This is how Code Composer Studio or Keil downloads your program.

---

# Why Doesn't the Book Recommend Using JTAG Pins?

The JTAG pins are ordinary physical pins.

Technically,

you can configure them as GPIO.

Example

Instead of

```text
JTAG
```

you use them for

```text
LED
```

or

```text
Button
```

But then

your debugger loses communication.

You may no longer be able to download or debug your program.

Therefore,

during development,

leave the JTAG pins dedicated to debugging.

---

# Alternative Functions

The book lists many alternate functions.

Let's understand each one.

---

# 1. UART

UART means

**Universal Asynchronous Receiver Transmitter**

Purpose

Serial communication.

Example

```text
Laptop

↓

UART

↓

TM4C
```

Used for

* Debug messages
* GPS
* Bluetooth
* ESP8266
* ESP32
* Serial Monitor

---

## Real-Life Example

WhatsApp chat.

One person sends.

Another receives.

UART does the same electronically.

---

# 2. SSI (SPI)

SSI means

**Synchronous Serial Interface**

Another name

```text
SPI
```

Purpose

Fast communication.

Used with

* LCD
* OLED
* SD Card
* DAC
* Flash Memory

Example

```text
TM4C

↓

SPI

↓

OLED Display
```

---

# 3. I²C

Full name

```text
Inter-Integrated Circuit
```

Purpose

Connect many slow devices.

Example

```text
Temperature Sensor

RTC

EEPROM

OLED

IMU
```

All can share the same two wires.

---

## Real-Life Example

A classroom.

One teacher

Many students.

Same communication bus.

---

# 4. I²S

Used for

Audio.

Example

```text
Microphone

↓

I²S

↓

TM4C

↓

Speaker
```

---

# 5. Timer

Timer measures time.

Example

Blink LED every

```text
500 ms
```

Or measure

* Pulse width
* Frequency
* Period

---

# 6. PWM

PWM means

```text
Pulse Width Modulation
```

Instead of

```text
ON

OFF
```

PWM changes

the ON time and OFF time.

Used for

* Motor speed
* LED brightness
* Servo motors

---

## Example

Motor

```text
10%

↓

Slow
```

Motor

```text
90%

↓

Fast
```

---

# 7. ADC

ADC means

```text
Analog to Digital Converter
```

Real world

Temperature

```text
28.6°C
```

Light

```text
2.4 V
```

Battery

```text
3.72 V
```

These are analog signals.

ADC converts them into digital numbers the CPU can process.

---

# 8. Analog Comparator

Suppose

```text
Voltage1 = 3V

Voltage2 = 2V
```

Comparator answers

```text
YES

3V > 2V
```

Only comparison.

No conversion.

---

# 9. QEI

QEI means

Quadrature Encoder Interface.

Used for

Rotary encoders.

Example

Robot wheel.

Motor shaft.

Industrial automation.

It measures

* Position
* Direction
* Speed

---

# 10. USB

Universal Serial Bus.

Same USB you use on a computer.

Allows

```text
Computer

↓

USB

↓

TM4C
```

---

# 11. Ethernet

Used for networking.

Example

```text
TM4C

↓

Ethernet Cable

↓

Router

↓

Internet
```

Applications

* IoT
* Industrial automation
* Data logging

---

# 12. CAN

CAN means

Controller Area Network.

Very common in

🚗 Cars.

Example

```text
Engine ECU

↓

CAN Bus

↓

ABS

↓

Airbag

↓

Dashboard

↓

Transmission
```

All these controllers communicate using CAN.

---

# Complete Pin Multiplexing Concept

Imagine one pin.

```text
               PA0

                  │
     ┌────────────┼────────────┐
     │            │            │
   GPIO         UART         Timer
     │            │            │
   Button      TX/RX      Capture
```

Software selects **one** of these functions at a time.

This feature is called **pin multiplexing (pin mux)**.

---

# Summary Table

| Peripheral | Full Form                                   | Typical Use                                    |
| ---------- | ------------------------------------------- | ---------------------------------------------- |
| GPIO       | General Purpose Input Output                | LED, Button                                    |
| UART       | Universal Asynchronous Receiver Transmitter | PC communication, Bluetooth, GPS               |
| SSI (SPI)  | Synchronous Serial Interface                | OLED, SD Card, DAC, Flash                      |
| I²C        | Inter-Integrated Circuit                    | Sensors, EEPROM, RTC                           |
| I²S        | Inter-IC Sound                              | Audio devices                                  |
| Timer      | Timer/Counter                               | Delays, pulse measurement, periodic interrupts |
| PWM        | Pulse Width Modulation                      | Motor control, LED brightness, Servo           |
| ADC        | Analog-to-Digital Converter                 | Read analog sensors                            |
| Comparator | Analog Comparator                           | Compare two analog voltages                    |
| QEI        | Quadrature Encoder Interface                | Motor position and speed                       |
| USB        | Universal Serial Bus                        | PC communication                               |
| Ethernet   | Ethernet Network                            | Internet/LAN communication                     |
| CAN        | Controller Area Network                     | Automotive and industrial networks             |
| JTAG       | Joint Test Action Group                     | Programming and debugging                      |

---

# Key Points to Remember

* A microcontroller communicates with the outside world through **I/O pins**.
* Most pins are **GPIO** by default but can be switched to **alternate functions**.
* **Only one function can be active on a pin at a time**.
* This ability to choose different functions for the same pin is called **pin multiplexing**.
* **JTAG pins** are primarily intended for programming and debugging and are usually left dedicated during development.
* Interfaces like **UART, SPI, I²C, PWM, ADC, USB, Ethernet, and CAN** all use specific I/O pins configured for those alternate functions.

---

Excellent! This section is about the **actual pins available on the Texas Instruments LM3S811 microcontroller**. The previous section explained **what UART, SPI, I²C, PWM, ADC, etc. are**. This section explains **which physical pins can perform those functions**.

Let's study it from scratch.

---

# Part 9: Texas Instruments LM3S811 I/O Pins

---

# Before We Start

Suppose someone asks you:

> **How does a microcontroller communicate with the outside world?**

Answer:

Through its **I/O pins**.

But another question is:

> **Can every pin do every job?**

No.

Each pin has **specific capabilities**.

---

# What is the LM3S811?

The **LM3S811** is a microcontroller made by **Texas Instruments**.

It contains:

* ARM Cortex-M3 CPU
* Flash Memory
* SRAM
* GPIO Ports
* Timers
* UART
* SPI (SSI)
* I²C
* ADC
* PWM
* Comparator

Think of it as a **small computer on a single chip**.

---

# Physical Pins

Imagine the microcontroller package.

```text
        LM3S811

      +----------------+
 PA0  |                | PE0
 PA1  |                | PE1
 PA2  |                | PD7
 ...  |                | ...
      +----------------+
```

Each metal leg is called a **pin**.

Each pin connects the CPU to external devices.

---

# Ports

Pins are grouped into **ports**.

For LM3S811:

```text
Port A
PA0
PA1
PA2
PA3
PA4
PA5
```

```text
Port B
PB0
PB1
PB2
PB3
PB4
PB5
PB6
PB7
```

```text
Port C
PC0
PC1
PC2
PC3
PC4
PC5
PC6
PC7
```

```text
Port D
PD0
PD1
PD2
PD3
PD4
PD5
PD6
PD7
```

```text
Port E
PE0
PE1
```

Together, the LM3S811 has **32 digital I/O pins**.

---

# Digital I/O Lines

The book says:

> **32 digital I/O lines**

What does that mean?

A digital pin has only **two possible states**.

```text
0

or

1
```

or

```text
LOW

HIGH
```

Example

An LED.

```text
HIGH

↓

LED ON
```

```text
LOW

↓

LED OFF
```

---

# ADC Inputs

The LM3S811 also has **4 ADC inputs**.

Unlike digital pins, these measure **analog voltages**.

Example:

```text
Battery

↓

3.15V
```

or

```text
Temperature Sensor

↓

1.82V
```

The ADC converts these voltages into numbers.

---

# ADC Resolution

The book says:

> **10-bit ADC**

What does that mean?

A 10-bit ADC can represent

[
2^{10} = 1024
]

different values.

So the output ranges from:

```text
0

↓

1023
```

---

## Example

If the ADC reference voltage is **3.3 V**:

| Input Voltage | ADC Value |
| ------------- | --------: |
| 0 V           |         0 |
| 1.65 V        |      ≈512 |
| 3.3 V         |      1023 |

So an analog voltage becomes a digital number the CPU can process.

---

# Sampling Rate

The book says:

> **500k samples per second**

Meaning:

The ADC can take up to **500,000 measurements every second**.

Example applications:

* Audio recording
* Voltage measurement
* Sensor reading

---

# Why Do Pins Have Two Names?

This is one of the most important concepts.

Example:

```text
PA0
```

also has the name

```text
U0RX
```

Why?

Because the same physical pin can perform different jobs.

---

## Example

Normally

```text
PA0

↓

GPIO
```

After configuration

```text
PA0

↓

UART Receive
```

The pin hasn't changed.

Only its function has changed.

---

# Pin Multiplexing

This ability is called

**Pin Multiplexing**.

One pin

↓

Many possible functions

↓

Software selects one.

Example:

```text
                PA0

                  │
      ┌───────────┴───────────┐
      │                       │
    GPIO                  UART RX
```

Only **one function** is active at a time.

---

# Understanding Table 2.3

Let's look at each entry.

---

# 1. PA0 – PA1

Alternate names:

```text
PA0 → U0RX

PA1 → U0TX
```

Meaning:

These two pins can become **UART0**.

UART requires two lines:

* RX (Receive)
* TX (Transmit)

Example:

```text
PC

↓

UART Cable

↓

PA0 ← Receive

PA1 → Transmit
```

Used for:

* Serial Monitor
* Debugging
* Bluetooth
* GPS

---

# 2. PA2 – PA5

These become **SSI0 (SPI)**.

| Pin | Function           |
| --- | ------------------ |
| PA2 | Clock (SCLK)       |
| PA3 | Chip Select (SFSS) |
| PA4 | MISO (SRX)         |
| PA5 | MOSI (STX)         |

Example:

```text
LM3S811

↓

SPI

↓

OLED Display
```

---

# 3. PB2 – PB3

These become **I²C**.

```text
PB2

↓

SCL
```

Clock line.

```text
PB3

↓

SDA
```

Data line.

Used with:

* EEPROM
* RTC
* Temperature sensors
* OLED displays

---

# 4. PWM Pins

Examples:

```text
PB0

↓

PWM2
```

```text
PB1

↓

PWM3
```

```text
PD0

↓

PWM0
```

```text
PD1

↓

PWM1
```

```text
PE0

↓

PWM4
```

```text
PE1

↓

PWM5
```

These generate PWM signals.

Applications:

* Motor speed control
* LED brightness
* Servo motors

---

# 5. Timer Pins

Examples:

```text
PD4

↓

Timer0A
```

```text
PC5

↓

Timer0B
```

Used for:

* Measuring pulse width
* Frequency measurement
* Generating periodic interrupts

---

# 6. Analog Comparator

Pins:

```text
PB4

↓

Comparator Input
```

```text
PB6

↓

Comparator Input
```

Comparator compares two analog voltages.

Example:

```text
Voltage1 = 2V

Voltage2 = 1V

↓

Output = HIGH
```

---

# 7. JTAG Pins

Pins:

```text
PC0

PC1

PC2

PC3

PB7
```

Used for:

* Programming
* Debugging
* Breakpoints
* Downloading code

The book recommends:

**Do not use these as GPIO while developing**, because the debugger relies on them.

---

# 8. PD6 – Fault Pin

This is a **PWM Fault** input.

Suppose a motor controller detects an emergency, such as:

* Overcurrent
* Motor jam
* Overheating

The fault pin can immediately force all PWM outputs into a safe state, stopping the motor.

---

# PC4 Has No Alternate Function

Unlike most pins,

```text
PC4
```

can only be used as

```text
GPIO
```

It cannot become:

* UART
* SPI
* I²C
* Timer
* PWM

---

# Evaluation Kit (Development Board)

The book now talks about the **LM3S811 Evaluation Kit**.

Remember:

* **LM3S811** → the microcontroller chip.
* **Evaluation Kit (Eval Board)** → a PCB containing the chip plus useful hardware.

Think of it like this:

```text
Microcontroller Chip
        │
        ▼
+--------------------------+
| LM3S811 Evaluation Board |
|                          |
| LED                      |
| Push Button              |
| USB                      |
| Debugger                 |
| Power                    |
+--------------------------+
```

The board lets you experiment without wiring everything yourself.

---

# Devices Already Connected on the Board

The evaluation board has components already wired to certain pins.

Examples:

| Pin | Connected Device  |
| --- | ----------------- |
| PA0 | Virtual COM RX    |
| PA1 | Virtual COM TX    |
| PB2 | OLED Display SCL  |
| PB3 | OLED Display SDA  |
| PC4 | User Push Button  |
| PC5 | User LED          |
| PD7 | OLED Power Enable |

---

## Example

The user LED is connected to:

```text
PC5
```

If you configure PC5 as an output:

```c
PC5 = 1;
```

the LED turns ON.

If:

```c
PC5 = 0;
```

the LED turns OFF.

---

# Jumpers

The board includes **jumpers**.

A jumper is a small removable connector that links a pin to an onboard device.

Example:

```text
PC5 ───── Jumper ───── LED
```

If you remove the jumper:

```text
PC5      LED

(No connection)
```

Now PC5 is free to connect to your own circuit instead of the onboard LED.

---

# Complete Overview

```text
                LM3S811

          +-------------------+
          |                   |
          | ARM Cortex-M3 CPU |
          |                   |
          +---------+---------+
                    |
              GPIO Pins
                    |
     ---------------------------------
     |        |       |      |        |
    UART     SPI     I²C    PWM     ADC
     |        |       |      |        |
 Serial    Display  Sensor  Motor  Voltage
```

---

# Summary Table

| Topic                   | Explanation                                                 |
| ----------------------- | ----------------------------------------------------------- |
| **32 Digital I/O Pins** | Can be used as GPIO or alternate functions                  |
| **4 ADC Inputs**        | Measure analog voltages                                     |
| **10-bit ADC**          | Produces values from 0 to 1023                              |
| **500 kS/s ADC**        | Up to 500,000 conversions per second                        |
| **Pin Multiplexing**    | One physical pin can perform different functions            |
| **UART Pins**           | Serial communication                                        |
| **SPI (SSI) Pins**      | Fast communication with displays, SD cards, etc.            |
| **I²C Pins**            | Two-wire interface for sensors and EEPROMs                  |
| **PWM Pins**            | Control motors and LED brightness                           |
| **Timer Pins**          | Generate interrupts and measure signals                     |
| **JTAG Pins**           | Used for programming and debugging                          |
| **Evaluation Board**    | Development board with LEDs, buttons, debugger, and jumpers |

---

## Key Points to Remember

* The **LM3S811** provides **32 digital GPIO pins** and **4 analog input pins**.
* Many pins have **alternate functions**, such as UART, SPI, I²C, PWM, timers, or comparators.
* A single pin can perform **only one function at a time**; software selects which function is active.
* The evaluation board connects some pins to onboard hardware like LEDs, buttons, and an OLED display through removable jumpers.
* During development, avoid reconfiguring the **JTAG** pins because they are needed for programming and debugging.
