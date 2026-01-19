# IoT Laboratory Activity 6: Bi-Directional Serial Communication

## 📖 Project Overview
This project implements a **bi-directional serial control loop** between an Arduino microcontroller and a Python script. Unlike simple one-way control, this system functions as a relay: physical button presses on the Arduino are sent to the computer, processed by Python, and returned as commands to toggle LEDs. This enforces a "software-in-the-loop" architecture where the hardware state is managed entirely by the external Python script.

### 🎯 Objectives
* **Serial Fundamentals:** Understand and implement Arduino Serial Connection.
* **Python Integration:** Utilize Python as the primary logic controller for serial communication.
* **Full-Duplex Circuitry:** Create a circuit that simultaneously handles outbound sensor data (buttons) and inbound control signals (LEDs).

---

## ⚙️ System Requirements & Logic
Per the laboratory guide, the system is implemented with the following logic flows:

### 1. Hardware Configuration
* **Components:** Arduino MCU, 3 LEDs (Red, Green, Blue), 3 Push Buttons, Resistors (220Ω for LEDs), Breadboard/Wires.
* **Pin Assignments:**
    * **Red LED:** Pin 7 &nbsp;|&nbsp; **Green LED:** Pin 6 &nbsp;|&nbsp; **Blue LED:** Pin 5
    * **Button 1:** Pin 12 &nbsp;|&nbsp; **Button 2:** Pin 11 &nbsp;|&nbsp; **Button 3:** Pin 10

### 2. Firmware Logic (Arduino)
The Arduino sketch handles two distinct data streams:
* **Outbound (TX):**
    * When **Button 1** is pressed, it prints `'R'` **ONCE**.
    * When **Button 2** is pressed, it prints `'G'` **ONCE**.
    * When **Button 3** is pressed, it prints `'B'` **ONCE**.
    * *Constraint:* Buttons **do not** control LEDs locally. They only transmit data.
* **Inbound (RX):**
    * Receives `'1'` $\rightarrow$ Toggles **Red LED**.
    * Receives `'2'` $\rightarrow$ Toggles **Green LED**.
    * Receives `'3'` $\rightarrow$ Toggles **Blue LED**.
    * *Constraint:* All inputs are case-insensitive.

### 3. Software Logic (Python)
The Python script acts as a non-terminating relay:
* It listens for serial data indefinitely.
* **Logic Loop:**
    * Receives `'R'` (Btn 1) $\rightarrow$ Sends `'1'` back to Arduino.
    * Receives `'G'` (Btn 2) $\rightarrow$ Sends `'2'` back to Arduino.
    * Receives `'B'` (Btn 3) $\rightarrow$ Sends `'3'` back to Arduino.

---

## 📂 Repository Structure

### 📁 `/Arduino_Firmware`
Contains the embedded C++ code responsible for hardware I/O.

* **`laboratory_activity_6.ino`**: The main application loop. It handles signal debouncing for the buttons and parses incoming serial strings to trigger LED functions.
* **`myFunctions.h`**: A header file containing hardware abstraction. It defines the specific pin mappings (7, 6, 5 for LEDs; 12, 11, 10 for Buttons) and state-toggling helper functions.

### 📁 `/Python_Relay`
Contains the host-side automation script.

* **`lab_activity6.py`**: A continuous script that establishes the serial connection. It implements the "Round Trip" logic, ensuring that a physical button press must travel to the computer and back before any visual change (LED) occurs on the board.

---

## 🔌 Wiring Diagram


Please adhere strictly to the pin map below, as it differs from previous activities:

| Component | Arduino Pin | Connection Details |
| :--- | :--- | :--- |
| **Button 1** | **Pin 12** | One leg to Pin 12, other to GND (Internal Pull-up used) |
| **Button 2** | **Pin 11** | One leg to Pin 11, other to GND (Internal Pull-up used) |
| **Button 3** | **Pin 10** | One leg to Pin 10, other to GND (Internal Pull-up used) |
| **Red LED** | **Pin 7** | Anode (+) to Pin 7, Cathode (-) to GND via Resistor |
| **Green LED** | **Pin 6** | Anode (+) to Pin 6, Cathode (-) to GND via Resistor |
| **Blue LED** | **Pin 5** | Anode (+) to Pin 5, Cathode (-) to GND via Resistor |

---

## 🚀 Usage Guide

1.  **Hardware Assembly:** Wire the circuit according to the table above.
2.  **Firmware Upload:**
    * Open `/Arduino_Firmware/laboratory_activity_6.ino` in the Arduino IDE.
    * Select your board and port, then click **Upload**.
3.  **Python Configuration:**
    * Open `/Python_Relay/lab_activity6.py`.
    * Update the `arduino_port` variable (e.g., `"COM3"` or `"/dev/ttyUSB0"`) to match your system.
4.  **Execution:**
    * Run the script: `python lab_activity6.py`.
    * *Console Output:* `Connected to COM3. Listening for Button Presses...`.
5.  **Operation:**
    * Press **Button 1**: The Python console will log the event, and the **Red LED** will toggle.
    * Press **Button 2**: The **Green LED** will toggle.
    * Press **Button 3**: The **Blue LED** will toggle.