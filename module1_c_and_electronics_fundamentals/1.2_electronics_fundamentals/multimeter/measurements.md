The following information is a comprehensive summary of digital multimeter (DMM) operation and specific measurement procedures, drawn from the source "How to use a multimeter like a pro! The Ultimate guide."

### **1. General Multimeter Summary**
A digital multimeter is a precise, easy-to-use instrument used to measure electrical properties like voltage, current, and resistance. 
*   **Analog vs. Digital:** Digital multimeters are preferred over analog versions because they are more accurate and offer more functions.
*   **Manual vs. Auto Range:** An **Auto Range** meter automatically selects the correct scale for the measurement, while a **Manual Range** meter requires the user to select the next highest number on the dial compared to the expected value.
*   **Basic Terminals:** The black lead always goes into the **COM** (Common) terminal. The red lead is moved between terminals (V, $\Omega$, mA, or 10A) depending on the measurement.

---

### **2. Separate Measurement Guides**

#### **DC Voltage ($\bar{V}$)**
Used for batteries, solar panels, and electronic devices where electrons flow in one direction.
*   **Procedure:** Connect the red lead to the **V** terminal and the black lead to **COM**.
*   **Connection:** Connect probes in **parallel** across the component or battery.
*   **Note:** If the reading is negative, the probes are reversed. Use the "millivolt" (mV) setting for higher precision on tiny signals.

#### **AC Voltage ($\tilde{V}$)**
Measures the alternating current found in household sockets, represented by a sine wave symbol.
*   **Safety:** AC electricity is dangerous and can be fatal. Wear rubber boots, check lead insulation, and never use damaged cables.
*   **Procedure:** Black lead to **COM**, red to **V**. 
*   **Connection:** When testing sockets, always connect the black (neutral) probe first. If you connect the red (live) first, the black lead becomes electrified immediately.

#### **Resistance ($\Omega$)**
Measures how easily electricity flows through a component (unit: Ohms).
*   **Procedure:** Black lead to **COM**, red to **$\Omega$** terminal. 
*   **Critical Rule:** **Isolate components** before testing. If a resistor is measured while still in a circuit, it will be in parallel with other parts, giving a false lower reading.
*   **Letters to Watch:** 'k' means thousand ($\Omega$), and 'M' means mega/million ($\Omega$).

#### **Current (A)**
Measures the volume of electron flow in Amperes.
*   **Critical Rule:** The multimeter **must be in series** with the circuit. Current must flow *through* the meter. 
*   **Warning:** Never connect the meter in parallel with a load while in current mode; this causes a massive current flow that will damage the meter or blow its fuse.
*   **Terminals:** Use the **mA** port for small currents (up to ~400mA) and the **10A** port for high currents. Note that 10A measurements often have a time limit (e.g., 10 seconds every 15 minutes) to prevent overheating.

#### **Continuity**
Tests if two points in a circuit are electrically connected.
*   **Procedure:** If a continuous path exists (low resistance), the meter will emit a **beep** and show a value near zero ohms.
*   **Use Cases:** Testing for breaks in wires, checking if a fuse is blown, or verifying switch operation.

#### **Frequency (Hz)**
Measures how many times an AC signal repeats per second.
*   **Procedure:** Red lead in **V**, black in **COM**, and select the **Hz** setting. 
*   **Standard Values:** Typically 60Hz in North America and 50Hz in Europe.

#### **Diodes and LEDs**
Diodes allow current to flow in only one direction.
*   **Diode Test:** Forward bias should read **0.5V to 0.8V**; reverse bias should read **OL** (Open Loop).
*   **LEDs:** The diode setting can light up an LED. It will only light in one direction.

#### **Capacitance (F)**
Measures the storage capacity of a capacitor.
*   **Safety:** Capacitors can store high voltages even after power is removed. **Always discharge** the capacitor (e.g., with a high-wattage resistor) before touching or testing it.
*   **Procedure:** Connect the black probe to the negative side (if polarized) and the red probe to the positive.

#### **Transistors (hFE)**
Tests the current gain and functionality of NPN and PNP transistors.
*   **Procedure:** Use the **hFE** setting. Align the transistor legs (Emitter, Base, Collector) into the correct slots on the meter or adapter.
*   **Troubleshooting:** If the reading is "1" or out of the expected range, the transistor is faulty.

#### **Temperature (°C/°F)**
Uses a **thermocouple** probe to measure air or surface temperature.
*   **Note:** Do not use standard thermocouple probes in water.

#### **Battery Testing**
To accurately test a battery, you should measure it under a **load**.
*   **Procedure:** A battery might show 1.5V while idle but drop significantly when a 100-ohm resistor is placed across the probes. If the voltage drops sharply under load (e.g., to 0.86V), the battery is bad.
