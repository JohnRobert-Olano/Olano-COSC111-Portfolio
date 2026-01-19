# Midterm Laboratory Exam: Light Intensity Meter

### 📌 Overview
This project represents the Midterm Examination for the IoT course. It is a comprehensive **Light Intensity Meter** that categorizes environmental brightness into three levels (Low, Medium, High) using a traffic-light LED system.

The system features two distinct operational modes controlled via Serial Communication:
1.  **Automatic Mode:** Uses pre-programmed thresholds to classify the environment (e.g., "Cloudy", "Clear").
2.  **Manual Mode:** Allows the user to dynamically configure the sensitivity thresholds using specific commands.

---

### 🎯 Objectives
* Implement a dual-mode system (Automatic vs. Manual) using state flags.
* Perform advanced String parsing to handle complex commands with arguments (e.g., `SET LOW 30`).
* Map analog sensor data (0-1023) to a readable percentage format (0-100%).

---

### 🛠️ Hardware & Components
* **Microcontroller:** Arduino Uno
* **Sensors:** Photoresistor (LDR)
* **Actuators:**
    * **Green LED:** Indicates Low light intensity.
    * **Yellow LED:** Indicates Medium light intensity.
    * **Red LED:** Indicates High light intensity.
* **Passive Components:** Resistors (10kΩ for LDR, 220Ω for LEDs), Breadboard.

### 🔌 Circuit Wiring
| Component | Pin Type | Arduino Pin | Description |
| :--- | :--- | :--- | :--- |
| **Photoresistor** | Analog Input | **A0** | Reads raw light values. |
| **Green LED** | Digital Output | **Pin 11** | Active when light is Low. |
| **Yellow LED** | Digital Output | **Pin 12** | Active when light is Medium. |
| **Red LED** | Digital Output | **Pin 13** | Active when light is High. |

---

### 💻 Command Guide
The system listens for specific text commands in the Serial Monitor.

| Command | Description | Example |
| :--- | :--- | :--- |
| `MODE AUTO` | Switches system to Automatic logic (Fixed thresholds: 40% / 70%). | `MODE AUTO` |
| `MODE MANUAL` | Switches system to Manual logic (User-defined thresholds). | `MODE MANUAL` |
| `SET LOW <val>` | Sets the upper limit for the Green LED (Only works in Manual Mode). | `SET LOW 30` |
| `SET HIGH <val>` | Sets the upper limit for the Yellow LED (Only works in Manual Mode). | `SET HIGH 80` |

---

### 🧠 Code Logic & Structure
The firmware uses a main loop to read sensors and a separate function to process serial input.

#### 1. Automatic Logic
In this mode, the thresholds are hardcoded:
* **0% - 40%:** Green LED ("Cloudy").
* **41% - 70%:** Yellow LED ("Clear").
* **> 70%:** Red LED ("Clear"/Bright).

#### 2. Manual Logic
In this mode, the system compares the light percentage against variables `lowThreshold` and `highThreshold`, which can be changed by the user at runtime.

#### 3. Command Parsing
The `processCommand()` function handles input validation:
* It checks if the command starts with specific keywords (`startsWith`).
* It converts the numerical part of the string (substring) into an integer using `.toInt()`.
* It prevents setting invalid thresholds (e.g., setting High lower than Low).

---

### 📂 File Structure
* `MidtermLabExam.ino`: The complete source code with state machine logic.