# Laboratory Activity 1: Digital Output & Sequential Control

### 📌 Overview
This project demonstrates the basics of **digital output signals** in an IoT system. The goal was to create a "running light" circuit where five LEDs turn on and off in a specific sequence using an Arduino microcontroller. This activity reinforces the understanding of pin configuration, voltage levels (HIGH/LOW), and timing delays.

---

### 🎯 Objectives
* Review Arduino board architecture for IoT implementation.
* Understand the application of digital signals (`HIGH` vs `LOW`).
* Write firmware to control multiple output devices sequentially.

---

### 🛠️ Hardware & Components
* **Microcontroller:** Arduino Uno
* **Actuators:** 5x LEDs (Green, Yellow, Orange, Blue, Red)
* **Passive Components:** 5x Resistors (Current limiting), Breadboard, Jumper Wires

### 🔌 Circuit Wiring
The LEDs are connected to the digital pins of the Arduino as follows:
| LED Color | Arduino Pin |
| :--- | :--- |
| **Green** | Pin 12 |
| **Yellow** | Pin 11 |
| **Orange** | Pin 10 |
| **Blue** | Pin 9 |
| **Red** | Pin 8 |

> **Note:** All LEDs are connected in series with a resistor to the ground (GND) rail of the breadboard to prevent burning out the components.

![Bitanga_Olano_Paciente_Breadboard_diagram](https://github.com/user-attachments/assets/fadaed9f-2c4a-4ffb-bbb9-4726fa6e4a3c)

---

### 💻 Code Explanation
The firmware is written in C++ (Arduino Sketch). Here is how the logic functions:

#### 1. Setup Phase
[cite_start]Inside the `setup()` function, we configure the specific digital pins (8 through 12) to behave as **OUTPUT**s[cite: 2, 3]. This allows the Arduino to send voltage to the LEDs.

#### 2. The Main Loop
The `loop()` function executes the following sequence indefinitely:
* [cite_start]**Turn ON Sequence:** The code sets the `Green` LED (Pin 12) to `HIGH` (5V), waits for 1000 milliseconds (1 second), and then proceeds to the next LED (`Yellow`, `Orange`, etc.) until all lights are illuminated[cite: 4, 5].
* [cite_start]**Turn OFF Sequence:** Once all LEDs are lit, the code begins turning them off in the same order (starting from Green/Pin 12) with a 1-second delay between each step[cite: 6, 7].

```cpp
// Snippet of the control logic
digitalWrite(Green, HIGH); // Turns on Green LED
delay(1000);               // Waits 1 second
digitalWrite(Yellow, HIGH);// Turns on Yellow LED