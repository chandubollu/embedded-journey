# Sensors and Peripherals Explained (Like a 10th Standard Student)

Think of a **microcontroller** (ESP32 or STM32) as the **brain** of a human.

The brain cannot see, hear, or feel by itself. It needs **eyes, ears, nose, and skin** to collect information.

Similarly, a microcontroller needs **sensors** to collect data and **displays** to show information.

---

# 1. DHT22 (Temperature & Humidity Sensor)

![Image](https://images.openai.com/static-rsc-4/tuRgZSh0OYgQuyyhvUg4eLLx7ghLFktUPSZEttjRLsIC1B_KWyr-O3AIaUd1JPNtQg5Ong-Uk1XgtECUIaK6jJC_J4hluX9KeMYBW0ueVNQQe3QrO2PMHLVQxathq8ahowWtQzEBBA3Cyo3Aglk2vJa526fqSvuWLxz7noxQ2lc-RnxRqkEe1ESiNrsJ7CO6?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/aZca860rScCOFdE6MyljwBzDJj9XP-EnjVaVoiu9vjPnxKCx5mUYbZ3dQVMfXlZMZQXWA3WxYN-HBSnWcJIIFf57f1ShpeRnr1VMo7lcVrJOBEJYqOLOuedL9EMD248tjUmjfKiUfTwUp7SGr_uh7aNswbbBgYGBt6831T_Saztm6LdEmSdB8QDW3poJNk4C?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/tUhwuXP5HrvS0Ji7ZaNl6KpzirP4AhJqVCT6eHAxmdMqZJh2RNW9ac5zWj5msSWCY7GeN3GeCgZTJYIIHrexOuZ2GhyxWENUoRoMFFsxzwcAre_AzfW2GThkibW8QnMKCfDGgYlW6KZtqVU1GpAna99i3OzScxQ0lzCvjuUvBFm_0NOZqzCVojYHrr61WnRS?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/89ufdR4brw_bzjFIyFuS8-uE3_mn-tpqRl6cZfdMwhy7qRaHV0rpBaDt-FedKQ8A62oebDdD-otMYXUN4zE6sRs0SjOKIsThqXSQG0zaMDpgWeA7xbmdX1eIRmnE6z8REeLihpZ8xV3cgFhp67PmoFXiuNpA25RBDOjRZtUSb3VqQ5cmriVT9lkRdgoLtGKk?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/argznNJU2jsPYRd2rAwGeIq4_vnoEBiRQb1uwxuu7xaDqp7fLipuRyugRUzMhRtoUODIPATQOFyD9DpB3zokCSB_auLF9S7nDnTwSYYrE_ZiIj0Z_TWX4te4qJSkXSTojMQyzdRqgErqrOL1R6QO1IiifBpkRoL9yN6Mvvx_MopmUTCMG19idzZHxmqT60gs?purpose=fullsize)

## What is it?

The **DHT22** measures:

* 🌡 Temperature
* 💧 Humidity (moisture in the air)

It sends this information to the microcontroller.

### Real-Life Example

Imagine your classroom.

You want to know:

* Is it hot?
* Is it cold?
* Is the air humid?

The DHT22 tells the microcontroller these values.

### Common Applications

* Weather Station
* Smart Fan
* Greenhouse
* Air Quality Monitor

### Think of it as

🌡 A digital thermometer.

---

# 2. BME280

![Image](https://images.openai.com/static-rsc-4/ZphnKys_TKwvexVyqU7e8vOjjJC0FJ6-bBsNu42fVPCLHlDt7NJOpLeT3vTI4nycLtQSCf9hdQLTAsOOvT55zUXeGSMqlL-rEslJ5ypDEcbIlLaEiW5Vr1Z-34s25VCcEdHdLuDOLs-qGH38hqIJAZ73rDarOLuJCz7FZZJ9KChKS-E7OJxWiE-zQt9_287F?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/NkYVQP3MbTfaeXKZwgffnBaGjtZpou4eKBlnGaUIn4E2vfTjYyaZQVSQQL8lYa5tHXYSl5A1DyDmSwz-CZMfpbEnRJemN8AxNA_Azo-UY1hy8GjP8nv_0RNJEHOfnEimylxgHy_-YidFifFz8XCGKDVJPc0HCV2LwjDKsSZoAPbXiy9oJ1yzbTaUTX8Suqh9?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/RF-VCNwxiSkZEyzGHwR3Ztw8l2GbAxSI2vqXYjBOyVGzGUG1KhqT7rBHo_YhAWHswKC49_rp4-Pwgd1M3uNSpTz_xjF-8x9YVvTOdTP6B8yhHhgSwqxNL0M-8etC6ZuVVtxpZEL6UR7n6xmW-JBDkob0cyLekofpWh1z8ahgHAlsnYJhELuZn55Bz3Ebh8Dp?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/YzBCMimGuGDQyqAB0GrUwliBka-1e5I4fYX6lEGJr7rhvcTHXu-zk_MmtM3Vcwk2rP7M4nO_Kc6vFnnj7cAKF52J_mfcc2W0O8ZQQlNktmNdFoCPx1WCKmWvnGq38fe6Z5FxBXHONufSm0FDh1yskAqOK9SbiUBsEv0ZSLWA9BYVpnCJA8098runEk8LFJ5t?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/3ClX2g90htUKk2LJWkhWLzNfbJbJ6y_Va0PNMsHlOK1nFyrcjtAMyLhlNwixcYj7x-YRdmBHKIVqQSeKGV0SKAC1QEPfl9M-Y-nLc9tz2QpTjdwT6ZXLdznPpM7NPzikpnOyNWz5SBfi0PIziUkWRVfSsdjhtAvOYl4wAbkPUWl06fcsm2B4KVCHUS79jjKQ?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/OkFyQob4Owirkj04JD_IEHcuZ0VldHI0TpVeDxJcuJubjlA5cjeEl5kFonPGaKA_x6F1RWSEH5_odCMw_--MZybMQIz3KLvsCldQK_HV9yfgsT3O-3LWJmeLKnedTl0lW_t9p5xbLpFBqyIYf8kp5qd3y4TAQGS8pLRlOYFgvHhC9yKiY9tmQJq_BnRrz6Bs?purpose=fullsize)

## What is it?

The **BME280** is an upgraded environmental sensor.

It measures:

* 🌡 Temperature
* 💧 Humidity
* 🌬 Air Pressure

Because it measures pressure, it can also estimate altitude.

### Real-Life Example

Weather stations use air pressure to predict rain or storms.

### Common Applications

* Weather Monitoring
* Drone Altitude Measurement
* Smart Agriculture
* Indoor Climate Monitoring

### Think of it as

🌤 A mini weather station.

---

# 3. MPU6050

![Image](https://images.openai.com/static-rsc-4/7D3bjqXF7F2cRP6mXUdqfMlPO8eYVq2mwr5YJHR4JOGBTyRqEJOWpkhGoCulfxbqDjkrtfk1WYyYPqcbmjyvoEm5AtD-TnS-RONv0YTIevZSp6TFUHwJ2LHLIUg2g6kUoJYctmhSAFJrJTRcJFTEyDpeYdyE2NXUJIdt5M0XwtTGHDiBODYi87rzC_DEl9oR?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/TcJOkIGfaUH79v-6V_sPi3BnrmOuD9QdgYWPnEq8vjb-hc9P6XKpYLlhCods--SJrzuP2SdwpYCEg3336cg5TS1foheg7aj_HduSVBz0xj8HHIqWDDQgGABv2jAsizXsJkN3KiN3n7lcK8_FetZ_j9FpGR3Ee38ZYoGCcQDGZ8EtciHLTSBR6odmabCTCjyt?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/90QPJ40gHXh6LU5hKnPE2TzFxBkFQlRIb-aco896Y6uxE_A5hJ4T4WfcfUhXB2osRwd1Yy7zsOpjYb2lOpAFpHAMxnGyTkhLPYGjIi6VS77_8YJLCpMYFySUNNaYhbpN9GKPeaOYL6H-mVMnWLUe4jv5Ke1u8PJjMzw3B9H3T3kghaY3dDxOjVkc42xazUbY?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/oPunDUaaB8jMXcs4SjnHS-ceWV6XHaDHU7TFq1oYb7dtz758ddIIUJSAEim_X1lZqLKeez9GCmf6C4bA84vKWPVTkXIUoOQO7E_zNhinmBUafN6pgdVQm9bguXpxAJ1VMEhZ6FAem4l9LuJUJt-3aBcw22mqxRhQg2SvCV48iLLLqoLD5WEtizwjsnLOfvg8?purpose=fullsize)

## What is it?

The **MPU6050** is a motion sensor.

It contains:

* Accelerometer
* Gyroscope

### Accelerometer measures

* Movement
* Tilt
* Acceleration

### Gyroscope measures

* Rotation
* Angular speed

Communication: **I²C**

---

### Real-Life Example

When you rotate your smartphone,

the screen automatically rotates.

That happens because of sensors like MPU6050.

---

### Common Applications

* Self-balancing Robot
* Drone
* Gesture Control
* Gaming Controller

---

### Think of it as

👂 The body's balance sensor (inner ear).

---

# 4. SSD1306 OLED Display

![Image](https://images.openai.com/static-rsc-4/noBCto7uYPiBxyae7nMujaqxovuuLj0Qec7A8siKePuOPC3iKM__Y0F0duDEJj_t89u3wDt3NwBUJVufWpwABgzY5uVlIF7v1X6gWLpQBOCdixIAAo6Pm3yEENdcw8j2ADcjOkX4XkQ3-rBVCyQKIqonS4v1qXkhbHX1iYBV_ZGfZhnfDXk68u3QdxJ7XelQ?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/7b94EnTgkMN5Fs4T4aDWRakrpAab6Th8t9TaaNRdR_eKPlJDQ48nk_YrAdxkIy16EYFJkR5VlnuTIAMepGXGvR6S6SYt-oUTIbSGSUquB5UPCeNmyEaRl9lDXtJ8pkGlJC-YDm8f-J5zXeodXxo11H4oBmsBtNPDO7CbVK-aF6SW3Ff2v28Z9rgIxhIfzF99?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/pZfD8rbijL5VKwMmjXPhLUAVFKx67PJioqfhBxkq3sbgGk8kPVFship94gzTY8nUbxz8hKUO2GZhvlI10ldN-XDK6XoCIMWB1-EOnHYfOEJALEpiHogU5xpCZnQCzSN2CY6iGWeO0M9s3kTi3CmbPnii4giz7WXi_p1rRtY2VpXPYYjjXz_cUfCdBJuPMgub?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/BZPfdMpyBeiFsX0bAggWNgkyzHqhq8avuyYA_jDbE7E-WBqGMJHqt0gCw23fPpjoM4SA4W9h7w_HA47b_PeWxfbI5aKREOhr2AErD8RZFJT_THWFr0Ueiz7OgBSk9hQSygTpaclr2QeucjNA4bT2eMi5Rdq1fLrIZPG0onWv7FXInIW-CJqy1Ae8-z6fB_bu?purpose=fullsize)

## What is it?

A small display that shows:

* Numbers
* Text
* Graphics

Communication: **I²C**

Typical size:

0.96 inch

Resolution:

128 × 64 pixels

---

### Real-Life Example

Like the small display on a fitness band or smartwatch.

It can show:

```
Temperature : 30°C

Humidity : 60%

Wi-Fi Connected
```

---

### Common Applications

* Weather Station
* Battery Meter
* IoT Display
* Sensor Data Display

---

### Think of it as

📺 A tiny TV screen.

---

# 5. ST7789 IPS LCD

![Image](https://images.openai.com/static-rsc-4/8f84MbwrAlTRkv7xL51xKVBvofKEmTzIxR18cSVcl4rG8vPJXBkPRFTaHLLPw_ulzsCsvFji5YL0JIViDYcBJRSo2krHj_ht6_oi3SbqGvsD_W7-UbsSxxLUCCiZJ2BQfLU8BZM979X9LYp_3rrtbZoPNbjcFS_PIWUI2h5LUCUBUVyudkeQYWgv7ByQxrXM?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/7GC67TgGKTpgL0_uACb5VCIaf0ZWBhbMzJVwfB5LcJ-Ee4L-pQHG-5Y7FEy35AjI495lSJqXpiB-8opqMURjnPfHp-QT308rczC4d_trIr5axr6Q32qYc6gLxWVTulg6btW0LdmwMdg1KzCmorxtfiTLlbJ9Vm66MSqP7nhJO9FdrlEDJCyxy0Syo9gvTj1x?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/yJHmhCxZsIdqAe9rcSFq2eShz5tbNYSTL19VX83wnEfp6yx8xkys1zVybuRq539YRwbtgPMFbvBa2yTP36IdvJSRjhoI2CuDUY52Ke6V5r80a2GZVatikbkCSOBl9VdVfP2dZbj1l3xMTr8AOUYoVjvV6hT2kI-kp_1YfBruBmDv04A_al8-y2xVmE3eyOjb?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/F54Ug5P3FKqPpz6f9cWb-GiOY277d402rJ88dV1K6obCiEFlE_XnE2SQNaKd11smIsZdg9bt6qLUlNCYxifBExSBmU4XnsjDIBjeruw3cL-tF2DnaYTHv6-gQIWs5I_L3XcwV-6Jha34Dg5GSDDzOBt0VDgmdhk0T0CMXrnQaZcfJqaT73Y-nB6vQXA-wCOD?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/bbExoEj-VsWUiDwvsIsfVafzvC1z02Cxu0JDL30evRnCSM5h3fMQgkGexEfpmhLPILcp3k0p2Y9GZ53INBHiFe7I9pXHLc8KyXh1DVcBNU_fkHZU4Iqx2-Iw-dgj6mvEwQHSxlzXa_1bOzx-WkmKz_LpXk2LuxGunhBrXg5rtr2sBKt4icDjSIjBMbfbBAA3?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/XC7xTE-Y_a4C9Rv9PgwJFK4AS2IhQInd80bBflEG670emH8ovDRgWuFc80joCwhHezIltWACWMvpmULMrF-Uh3pGKuncDSBZNyBzAyre2CZDv2ft9BZ35o20YDTzRfdVlxRAllwBjH7up5b7ZIV5yQ37PQrl1TmJxCPdttjnT4Je2g74cq430mynrWP5x-U9?purpose=fullsize)

## What is it?

The ST7789 is a colorful LCD display.

Unlike OLED,

it can display:

* Images
* Icons
* Menus
* Animations

Communication:

SPI

Resolution:

240 × 240 pixels

---

### Real-Life Example

Imagine the display of a smartwatch.

It can show colorful graphics and menus.

---

### Common Applications

* Smart Watch
* Dashboard
* User Interface
* IoT Display

---

### Think of it as

📱 A small smartphone screen.

---

# 6. ILI9341 TFT Touch Display

![Image](https://images.openai.com/static-rsc-4/9YjJX2X_xwdK5hUd-aSc0XH2F510oO2ZqrClOydHtRqCdNYosMmVCDeYmTQRvNxtAH6TxVgzXv289Q41cqgF0_71DecHPP4kSEkIXKQVPc_6pmtntNIxO9YkhUBlD-z7Dpz57fdEusNbyLJs8TkU8x2BU0S40SsdtSKv9hIMg7gW_UVEbqDYfelcqdJ34bQ0?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/fjDrKY9I2A8YCV7WBjiMGk3WW-5_QtKs1NVH8lhpbea7R_Hg5AK8oHSWY5b1upugxs7lPneiuuvWutWuciI5pq5IOL-hbF3WX20MdgyTyUYZmfxTd6dXLl_s-Vh6vl-NI_l02EZ90Mw7c2B_6OrHQICq7-0DqkGuVGVarV45ZAaWnAgyGi1GUmak71Am0P_Q?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/46rYG2hbTMnEPEE3STs2-8bKyncHIzDdlf-iYtVtAF0CVmZJTOCWkpqmqOfaGGSgujRVg-KYMTCjm1YySy0qjvmAO4bTjPng3QzR1ujLU2gxxQq8zvKZ3uMREaoDar_RsFZvqqrA4bwGA5hTCuoToZhe1vpcTFPXGPohIT4I-QmSk9SPTSnkAmi7QCgWEmG4?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/2ohqPA4aYV_tLkioavFlUgLUAko6m8VdyBPkq0t1v7RIt-2Y5f4LYtgU1diuzqLwKGa3LEhPMw1sSFAWhqP6Cd3THQGjpDvCWb_cMvtSDR9jxPc6_bil6bnXklRKRjc2YL6ndwBr9GVu40TlxlXI8A-RVJVE2bL8lk4GmcEKXnDWPY05eJvYn-B9wcN-Ur4U?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/KfxsidPDdZiyEjODFnV8sl63_TTupo65lpoxkKdVdPuk9JMV8dDG6r5XcmWciGiSVR7IMmd3tL3TElumtig5Ys5NK1bOfRXDq7XAY8EYXR5E0vIi65Gayk6lCTJ11OWwDyAK7zFTqskrOymhX4ks2Jt5eVP9EujpNy42G2lBnkAqAVLgsy0nAEcT0xX-oce_?purpose=fullsize)

## What is it?

This is a larger color display with **touch capability**.

It includes:

* TFT LCD Display
* XPT2046 Touch Controller

Communication:

SPI

Typical size:

2.4"–2.8"

Resolution:

320 × 240 pixels

---

### Real-Life Example

Think of an ATM screen.

You can:

* Touch buttons
* Navigate menus
* Enter data

Similarly, the ILI9341 display lets users interact with embedded devices.

---

### Common Applications

* Home Automation Panel
* Industrial HMI
* Medical Equipment
* Digital Dashboard

---

### Think of it as

📱 A small touch-screen tablet.

---

# I²C vs SPI (Simple Explanation)

| I²C                                         | SPI                                                                       |
| ------------------------------------------- | ------------------------------------------------------------------------- |
| Uses 2 communication wires                  | Uses 4 or more communication wires                                        |
| Slower                                      | Faster                                                                    |
| Good for sensors                            | Good for displays                                                         |
| Can connect many devices using the same bus | Very fast communication, each device usually has its own chip-select line |

---

# Summary Table

| Sensor / Peripheral       | What It Does                                  | Communication                 | Real-Life Example          | Think of It As          |
| ------------------------- | --------------------------------------------- | ----------------------------- | -------------------------- | ----------------------- |
| **DHT22**                 | Measures temperature & humidity               | Single-wire digital interface | Weather station            | 🌡 Digital Thermometer  |
| **BME280**                | Measures temperature, humidity & air pressure | I²C / SPI                     | Weather forecasting        | 🌤 Mini Weather Station |
| **MPU6050**               | Detects movement, tilt & rotation             | I²C                           | Smartphone screen rotation | 👂 Balance Sensor       |
| **SSD1306 OLED**          | Displays text and graphics                    | I²C                           | Fitness band display       | 📺 Tiny TV              |
| **ST7789 IPS LCD**        | Displays colorful graphics                    | SPI                           | Smartwatch display         | 📱 Smartphone Screen    |
| **ILI9341 TFT + XPT2046** | Color display with touch input                | SPI                           | ATM touch screen           | 📱 Touch Tablet         |

---

# Easy Way to Remember

| Device                    | Remember It As                      |
| ------------------------- | ----------------------------------- |
| **DHT22**                 | 🌡 Measures heat and humidity       |
| **BME280**                | 🌦 Measures weather conditions      |
| **MPU6050**               | 🧭 Detects movement and rotation    |
| **SSD1306 OLED**          | 📺 Shows simple text and graphics   |
| **ST7789 LCD**            | �� Shows colorful images and menus  |
| **ILI9341 Touch Display** | 👆 Shows graphics and detects touch |

### How They Work Together

Imagine you're building a **smart weather station**:

* 🌡 **DHT22/BME280** measures the weather.
* 🧭 **MPU6050** detects if the device is moved or tilted.
* 📺 **SSD1306** or 🎨 **ST7789** displays the readings.
* 👆 **ILI9341 Touch Display** lets the user change settings by touching the screen.

Together with a microcontroller like the **ESP32** or **STM32, these components form a complete embedded system that can sense the environment, process information, and interact with the user.
