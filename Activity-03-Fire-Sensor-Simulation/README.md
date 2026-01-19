# Laboratory Activity 3: Fire Sensor Simulation

### 📌 Overview
This project demonstrates the integration of analog input sensors into an IoT system. The goal was to build a functional **Fire Sensor Simulation** that simultaneously monitors environmental temperature and light levels.

When both the heat and light intensity exceed specific safety thresholds (indicating a potential fire), the system triggers an audiovisual alarm using an LED and a Buzzer.

---

### 🎯 Objectives
* Familiarize with basic IoT sensor components (Thermistor & Photoresistor).
* Integrate analog sensors into an Arduino circuit.
* Implement conditional logic to create a simple fire detection implementation.

---

### 🛠️ Hardware & Components
* **Microcontroller:** Arduino Uno
* **Sensors:**
    * **Thermistor:** Measures temperature changes.
    * **Photoresistor (LDR):** Measures light intensity.
* **Actuators:**
    * **Red LED:** Visual alarm.
    * **Piezo Buzzer:** Audio alarm.
* **Passive Components:** Resistors (10kΩ), Breadboard, Jumper Wires.

### 🔌 Circuit Wiring
The circuit uses two analog input pins for the sensors and one digital output pin for the combined alarm system.

| Component | Pin Type | Arduino Pin | Description |
| :--- | :--- | :--- | :--- |
| **Thermistor** | Analog Input | **A0** | Reads temperature data. |
| **Photoresistor** | Analog Input | **A2** | Reads light brightness. |
| **LED + Buzzer** | Digital Output | **Pin 12** | Triggers the alarm signal. |

![Diagram for Lab Act #3 - Bitanga, Olaño, Paciente](https://github.com/user-attachments/assets/184852f4-cc00-4786-8968-07b949219f07)

---

### 💻 Code Explanation
The firmware is designed with modular functions and uses `const` and `#define` for easy calibration.

#### 1. Constants & Thresholds
We define specific values that determine when the fire alarm should trigger.
```cpp
#define THERMISTOR A0
#define PHOTORESISTOR A2
#define ALERT 12   

const int TEMP_THRESHOLD = 50;    // Trigger if temp is >= 50°C
const int BRIGHT_THRESHOLD = 220; // Trigger if brightness >= 220