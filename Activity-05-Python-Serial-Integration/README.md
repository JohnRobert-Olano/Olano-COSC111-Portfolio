# IoT Laboratory Activity 5: Arduino Serial Control with Python

## 📖 Project Overview
This project explores the integration of Python and Arduino to create a hardware-software interface. The goal is to control a simple LED circuit using a Python script running on a laptop, which communicates with the Arduino via a Serial connection.

### Objectives
* **Serial Communication:** Understand and implement Arduino Serial Connection.
* **Python Integration:** Utilize Python as a tool for implementing serial connections.
* **Circuit Control:** Create a simple circuit controlled via Serial connection using Arduino and Python.

---

## 📂 Repository Structure & Activity Descriptions

### 1. `/Arduino_Firmware`
This folder contains the embedded code (sketch and header files) required to run the microcontroller.

**Activity Description:**
The firmware is designed to listen for specific character inputs over the Serial port and manipulate the hardware accordingly. It implements the following logic as required by the laboratory guide:
* **Pin Configuration:** The code initializes the digital pins **8 (Red)**, **9 (Green)**, and **10 (Blue)** as outputs.
* **Input Logic:** The sketch processes single-character commands (case-insensitive) to perform the following actions:
    * **R/r:** Toggles the Red LED state.
    * **G/g:** Toggles the Green LED state.
    * **B/b:** Toggles the Blue LED state.
    * **A/a:** Turns **ALL** LEDs ON.
    * **O/o:** Turns **ALL** LEDs OFF.
    * **V/v:** (Bonus Feature) Toggles Red and Blue LEDs simultaneously (Violet).
* **Error Handling:** Any input not matching the defined keys triggers an error message via the Serial monitor.

### 2. `/Python_Controller`
This folder contains the client-side Python script (`serial_controller.py`) that acts as the user interface.

**Activity Description:**
This script fulfills the requirement to create a non-terminating application that sends commands to the Arduino.
* **User Interface:** Displays a menu with options `[R]`, `[G]`, `[B]`, `[A]`, `[O]`, and `[X]`.
* **Logic Implementation:**
    * **Non-Terminating Loop:** The script runs continuously inside a `while True` loop, allowing for repeated commands without restarting.
    * **Case Insensitivity:** All user inputs are converted to lowercase before processing, ensuring commands like 'r' and 'R' are treated identically.
    * **Exit Condition:** When **X/x** is input, the loop breaks, and the application terminates safely.

---

## 🛠️ Hardware Requirements
To replicate the circuit used in this code, the following components are required:
* Arduino MCU (Uno, Mega, or compatible)
* 3 LEDs (Red, Green, Blue recommended)
* 3 Resistors (220Ω - 330Ω)
* Breadboard and Jumper Wires
* Laptop with Python and `pyserial` installed

### 🔌 Wiring Diagram

Ensure your connections match the pin definitions in `ArduinoFromPythonHeader.h`:

| Component | Arduino Pin | Note |
| :--- | :--- | :--- |
| **Red LED** | Pin 8 | Connect Anode (+) to Pin 8, Cathode (-) to GND via Resistor |
| **Green LED** | Pin 9 | Connect Anode (+) to Pin 9, Cathode (-) to GND via Resistor |
| **Blue LED** | Pin 10 | Connect Anode (+) to Pin 10, Cathode (-) to GND via Resistor |

---

## 🚀 How to Run

1.  **Hardware Setup:** Assemble the circuit as described in the Wiring Diagram section.
2.  **Arduino:**
    * Open `/Arduino_Firmware/Arduino_Firmware.ino`.
    * Upload the sketch to your board.
    * Note the COM port (e.g., COM3, /dev/ttyUSB0).
3.  **Python:**
    * Open `/Python_Controller/serial_controller.py`.
    * Edit the `arduino_port` variable to match your specific COM port.
    * Run the script: `python serial_controller.py`.