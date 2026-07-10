## Microcontroller Boards & Embedded Platforms — Summary Table

| Board / Device                            | Type                                | Main Processor                         | Built-in Connectivity                        | Best Used For                                       | Real-Life Example                                            | Think of it as               |
| ----------------------------------------- | ----------------------------------- | -------------------------------------- | -------------------------------------------- | --------------------------------------------------- | ------------------------------------------------------------ | ---------------------------- |
| **ESP32 DevKit-C (ESP32-WROOM-32)**       | Microcontroller Development Board   | Dual-Core Xtensa LX6 (240 MHz)         | ✅ Wi-Fi, ✅ Bluetooth                         | IoT, Home Automation, Robotics, Sensor Projects     | Smart home lighting, weather station, Wi-Fi-controlled robot | �� Smartphone                |
| **STM32 Nucleo-F401RE**                   | Microcontroller Development Board   | ARM Cortex-M4 (84 MHz)                 | ❌ No Wi-Fi/Bluetooth                         | Industrial Control, Motor Control, Embedded Systems | Washing machine controller, industrial automation            | 🏭 Factory Controller        |
| **Blue Pill (STM32F103C8T6)**             | Low-Cost Microcontroller Board      | ARM Cortex-M3 (72 MHz)                 | ❌ No Wi-Fi/Bluetooth                         | Learning STM32, Robotics, DIY Projects              | Digital voltmeter, electronic door lock                      | 🛵 Scooter                   |
| **ST-Link V2**                            | Programmer & Debugger               | —                                      | USB                                          | Programming and debugging STM32 boards              | Uploading firmware to a Blue Pill                            | 🔌 USB Installer             |
| **Nordic nRF52840 DK**                    | Wireless Development Board          | ARM Cortex-M4F (64 MHz)                | ✅ Bluetooth LE, ✅ Thread, ✅ Zigbee, ✅ Matter | BLE Devices, Smart Home, Wearables                  | Smartwatch, fitness tracker, smart lock                      | ⌚ Smartwatch                 |
| **Nordic nRF5340 DK**                     | Advanced Wireless Development Board | Dual ARM Cortex-M33 (128 MHz + 64 MHz) | ✅ Bluetooth LE, ✅ Thread, ✅ Zigbee, ✅ Matter | Advanced IoT, Matter Devices, Industrial Wireless   | Smart home hub, advanced IoT gateway                         | �� Luxury Electric Car       |
| **Neoway N58 / N720**                     | Cellular Communication Module       | Embedded Cellular Modem                | ✅ 4G/LTE Cellular                            | Remote Monitoring, GPS Tracking, Smart Meters       | Vehicle tracker with SIM card                                | 📱 Mobile Phone              |
| **GL.iNet GL-MT300N-V2 (OpenWRT Router)** | Programmable Router                 | MIPS/ARM SoC (varies)                  | ✅ Wi-Fi, Ethernet                            | Networking, VPN, IoT Gateway                        | Home Wi-Fi router with custom features                       | 🚦 Traffic Police            |
| **Raspberry Pi 4**                        | Single Board Computer (SBC)         | Quad-Core ARM Cortex-A72               | Wi-Fi, Bluetooth, Ethernet                   | Embedded Linux, AI, Robotics, Servers               | Mini desktop computer, home server                           | 🖥 Mini Computer             |
| **BeagleBone Black**                      | Single Board Computer (SBC)         | ARM Cortex-A8 (1 GHz)                  | Ethernet (Wi-Fi via add-on)                  | Industrial Embedded Linux, Real-Time Control        | Factory automation system                                    | 🏭 Industrial Computer       |
| **i.MX6ULL Development Board**            | Embedded Linux SBC                  | ARM Cortex-A7                          | Ethernet (board dependent)                   | Commercial Embedded Linux Products                  | ATM, barcode scanner, medical device                         | �� Industrial Linux Computer |

---

## Quick Comparison

| If you want to learn...                  | Recommended Board      |
| ---------------------------------------- | ---------------------- |
| Embedded C Programming                   | STM32 Nucleo-F401RE    |
| IoT (Wi-Fi)                              | ESP32 DevKit-C         |
| Bluetooth Low Energy (BLE)               | nRF52840 DK            |
| Matter & Thread                          | nRF5340 DK             |
| STM32 Programming on a Budget            | Blue Pill + ST-Link V2 |
| Cellular IoT (SIM-based Communication)   | Neoway N58/N720        |
| Computer Networking & OpenWRT            | GL.iNet GL-MT300N-V2   |
| Embedded Linux                           | Raspberry Pi 4         |
| Industrial Embedded Linux                | BeagleBone Black       |
| Commercial Linux-Based Embedded Products | i.MX6ULL Board         |

---

## Easy Way to Remember

| Device               | Remember It As                                      |
| -------------------- | --------------------------------------------------- |
| **ESP32**            | 🌐 Internet-enabled microcontroller                 |
| **STM32**            | ⚙️ Precision embedded controller                    |
| **Blue Pill**        | 💰 Budget STM32 board                               |
| **ST-Link**          | 🔧 STM32 programmer/debugger                        |
| **nRF52840**         | 📶 Bluetooth specialist                             |
| **nRF5340**          | 🚀 Next-generation wireless platform                |
| **Neoway Module**    | 📡 Cellular modem for IoT                           |
| **OpenWRT Router**   | 🌍 Smart network gateway                            |
| **Raspberry Pi**     | 💻 Small Linux computer                             |
| **BeagleBone Black** | 🏭 Industrial Linux controller                      |
| **i.MX6ULL**         | 🖥 Embedded Linux processor for commercial products |
