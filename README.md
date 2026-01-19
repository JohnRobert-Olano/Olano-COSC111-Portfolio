# Laboratory Activity 2: Analog Output & PWM Control

### 📌 Overview
This project explores the concept of **Analog Signal generation** using Pulse Width Modulation (PWM). Unlike the first activity which used purely digital signals (ON/OFF), this activity uses `analogWrite()` to create a "breathing" or fading effect on the LEDs.

This demonstrates how a microcontroller can simulate analog voltages to control the brightness of an LED or the speed of a motor.

---

### 🎯 Objectives
* Understand the difference between Digital (`HIGH`/`LOW`) and Analog (`0-255`) output.
* Implement **PWM (Pulse Width Modulation)** to control LED brightness.
* Optimize code using **Arrays** and **While Loops** instead of writing repetitive lines.

---

### 🛠️ Hardware & Components
* **Microcontroller:** Arduino Uno
* **Actuators:** 5x LEDs (Green, Yellow, Orange, Blue, Red)
* **Passive Components:** 5x Resistors (220Ω), Breadboard, Jumper Wires

### 🔌 Circuit Wiring (PWM Pins)
**Crucial Note:** To achieve the fading effect, we moved the LEDs to **PWM-enabled pins** (denoted by the `~` symbol on the Arduino). Standard digital pins (like 8 and 12) cannot fade.

| LED Position | Variable Name | Actual Arduino Pin |
| :--- | :--- | :--- |
| **LED 1** | `p12` | **Pin 6 (PWM)** |
| **LED 2** | `11` | **Pin 11 (PWM)** |
| **LED 3** | `10` | **Pin 10 (PWM)** |
| **LED 4** | `9` | **Pin 9 (PWM)** |
| **LED 5** | `p8` | **Pin 5 (PWM)** |

![Bitanga_Olano_Paciente_LAB_ACT_2_Working_with_Analog_Signals](https://github.com/user-attachments/assets/90d4d443-38c4-4cff-8a8d-56da4da35b5f)

---

### 💻 Code Explanation
The firmware introduces advanced programming concepts to handle the logic more efficiently.

#### 1. Arrays & Setup
Instead of declaring 5 separate variables, we use an array `LedPINS[]`. This allows us to iterate through pins using a loop.
```cpp
int p8=5;  // Mapped to PWM Pin 5
int p12=6; // Mapped to PWM Pin 6
int LedPINS[] = {p12, 11, 10, 9, p8}; // Array of PWM pins

void setup() {
  int i = 0;
  while (i < 5) {
    pinMode(LedPINS[i], OUTPUT); // Sets all pins in the array to OUTPUT
    i++;
  }
}