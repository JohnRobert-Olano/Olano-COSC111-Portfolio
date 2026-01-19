# Laboratory Activity 4: Arduino Serial Connection

### 📌 Overview
This project focuses on **Serial Communication (UART)**, allowing two-way interaction between the computer and the Arduino. Unlike previous activities where the Arduino acted autonomously, this system accepts user commands via the Serial Monitor.

The system uses a **Photoresistor** to monitor light levels. If the light exceeds a specific threshold, an LED enters a "latched" blinking state that persists even if the light level drops. The only way to stop the alarm is by manually typing a command in the Serial Monitor.

---

### 🎯 Objectives
* Understand and implement Arduino Serial Connection functions.
* Create a simple circuit that can be controlled via user input from the Serial Monitor.
* Implement string manipulation (trimming, case conversion) to handle user commands.

---

### 🛠️ Hardware & Components
* **Microcontroller:** Arduino Uno
* **Sensors:** Photoresistor (LDR)
* **Actuators:** LED (Pin 8)
* **Passive Components:** Resistors (10kΩ for LDR, Current limiting for LED), Breadboard, Jumper Wires.

### 🔌 Circuit Wiring
| Component | Pin Type | Arduino Pin | Description |
| :--- | :--- | :--- | :--- |
| **Photoresistor** | Analog Input | **A0** | Monitors environmental brightness. |
| **LED** | Digital Output | **Pin 8** | Blinks when threshold is met. |

![Diagram of LAB_ACT_4_Arduino_Serial_Connection](https://github.com/user-attachments/assets/e09e173a-f32f-4886-bb0a-23250b7b3096)

---

### 💻 Code Explanation
This firmware introduces **state management** and **String processing**.

#### 1. Latching Logic (State Variable)
We use a boolean variable `isBlinking` to track the system's state.
* If the `brightness` exceeds the threshold (220), `isBlinking` becomes `true`.
* **Crucial Behavior:** Once `true`, the LED continues to blink *even if the sensor reading drops below the threshold*. This mimics a security alarm that requires manual reset.

```cpp
if (brightness >= BRIGHT_THRESHOLD && !isBlinking) {
    isBlinking = true; // Alarm is now active indefinitely
    Serial.println("Threshold reached! LED will start blinking.");
}