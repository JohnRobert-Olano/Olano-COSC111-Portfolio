# ⚡ COSC 111: Internet of Things Portfolio

**Student:** John Robert Olaño  
**Subject:** CS Elective 3 (Internet of Things)  
**Institution:** Cavite State University Imus  

---

## 📖 About This Repository
This portfolio documents my coursework and laboratory activities for **COSC 111**. It showcases a progression of skills in embedded systems, starting from basic Arduino circuitry and C++ programming, moving through Serial communication, and culminating in full-stack IoT implementations using Python, FastAPI, and Web Interfaces.

## 🛠️ Tech Stack & Tools

| Category | Tools & Components |
| :--- | :--- |
| **Hardware** | Arduino Uno, ESP8266/32, Sensors (Thermistor, Photoresistor), Actuators (LEDs, Buzzers) |
| **Firmware** | C++ (Arduino IDE), Serial Communication (UART) |
| **Backend** | Python 3, PySerial, FastAPI, Uvicorn |
| **Frontend** | HTML5, JavaScript (Fetch API) |
| **Protocols** | HTTP, REST API, Serial (9600 Baud) |

---

## 📂 Project Index

### 🟢 Part 1: Fundamentals of Embedded Systems
*Basic circuit logic, digital I/O, and analog sensors.*

| Activity | Project Name | Description | Key Concepts |
| :--- | :--- | :--- | :--- |
| **Lab 1** | **[Running Light Sequence](./Lab_Activity_1)** | A sequential LED lighting circuit that demonstrates digital output control and timing loops. | `digitalWrite`, `delay`, Loops |
| **Lab 3** | **[Fire Sensor Simulation](./Lab_Activity_3)** | An automated alarm system that triggers a buzzer/LED when heat and light thresholds are exceeded. | `analogRead`, `if/else`, Thermistor/LDR |
| **Lab 4** | **[Latching Serial Alarm](./Lab_Activity_4)** | A security system logic where an alarm "latches" (stays on) after a trigger until manually reset via Serial command. | State Flags, Boolean Logic, Serial Monitor |

### 🟡 Part 2: Advanced Logic & State Machines
*Complex control flows and user-configurable systems.*

| Activity | Project Name | Description | Key Concepts |
| :--- | :--- | :--- | :--- |
| **Midterm** | **[Light Intensity Meter](./Midterm_Exam)** | A smart metering system with two modes: **Automatic** (fixed thresholds) and **Manual** (user-defined thresholds via CLI). | State Machines, String Parsing, EEPROM (Conceptual) |

### 🔴 Part 3: Python Integration & Full-Stack IoT
*Bridging hardware with software using Python and Web Technologies.*

| Activity | Project Name | Description | Key Concepts |
| :--- | :--- | :--- | :--- |
| **Lab 5** | **[Python Serial Controller](./Lab_Activity_5)** | A Python script that acts as a remote control for the Arduino, allowing LED manipulation via keyboard commands. | `PySerial`, Python Scripting, Remote Control |
| **Lab 6** | **[Bi-Directional Relay](./Lab_Activity_6)** | A "Software-in-the-Loop" system where Arduino buttons send data to Python, which processes logic and sends commands back to LEDs. | Full-Duplex, Loopback Logic, Latency Management |
| **Lab 7** | **[HTTP Web Control](./Lab_Activity_7)** | A modern IoT architecture using a **Web Browser** to control hardware. Uses **FastAPI** to bridge HTTP requests to Serial commands. | **FastAPI**, REST, JavaScript Fetch, CORS |
| **Final** | **[Physical-to-Cloud API Bridge](./Final_Exam)** | The capstone project: A physical button press on Arduino triggers a remote network API call via a Python gateway. | LAN Networking, HTTP Requests, Middleware |

---

## 🚀 How to Run These Projects

Most projects in this portfolio require a split setup between the Hardware (Arduino) and the Software (Computer).

1. **Upload Firmware:** Open the `.ino` file in the `Arduino_Firmware` folder of the specific activity and upload it to your board.
2. **Close Serial Monitor:** If using a Python script, you must close the Arduino IDE Serial Monitor to free up the port.
3. **Run Python:** Navigate to the `Python_Backend` or `Python_Controller` folder and run:
    ```bash
    pip install -r requirements.txt  # If applicable, or install pyserial/fastapi manually
    python main.py
    ```

---

# 📘 Technical Guide & Codebase Architecture

This section provides a detailed breakdown of the logic, algorithms, and hardware integration used throughout the portfolio. It explains how the firmware (Arduino) interacts with the software (Python/Web) and the physical hardware.

## 🟢 Part 1: Embedded Logic & Sensors

### 1. Sequential Control (Lab 1)
**Project:** Running Light Circuit
* **The Problem:** Controlling multiple outputs with precise timing using digital signals.
* **Code Logic:**
    * **Pin Initialization:** Inside `setup()`, pins 8 through 12 are configured as **OUTPUT**s to send voltage to the LEDs.
    * **Sequential Loop:** The `loop()` writes a `HIGH` signal to the first LED (Green/Pin 12), waits for 1000ms using `delay()`, and proceeds to the next.
    * **State Reset:** After the "Turn ON" sequence, the code executes a "Turn OFF" sequence in the same order.

### 2. Multi-Sensor Conditional Logic (Lab 3)
**Project:** Fire Sensor Simulation
* **The Problem:** Reading analog environmental data and making decisions based on multiple variables simultaneously.
* **Code Logic:**
    * **Threshold Definition:** The system uses `const` integers (`TEMP_THRESHOLD = 50`, `BRIGHT_THRESHOLD = 220`) for easy calibration.
    * **Compound Conditionals:** The alarm triggers only when **BOTH** heat and light intensity exceed their safety thresholds.
    * **Input Types:** Reads from `A0` (Thermistor) and `A2` (Photoresistor) using analog input pins.

### 3. State-Latching Logic (Lab 4)
**Project:** Serial Alarm System
* **The Problem:** Creating an alarm that stays "latched" (active) even if the sensor value returns to normal.
* **Code Logic:**
    * **State Variable:** A boolean variable `isBlinking` tracks the system state.
    * **The Latch:** Once the brightness exceeds the threshold, `isBlinking` becomes `true` and the LED continues to blink indefinitely.
    * **Reset:** The only way to stop the alarm is by manually typing a command in the Serial Monitor.

---

## 🟡 Part 2: Advanced Control Systems

### 4. Dual-Mode State Machine (Midterm Exam)
**Project:** Light Intensity Meter
* **The Problem:** Building a system that can switch behaviors (Auto vs. Manual) at runtime.
* **Code Logic:**
    * **Mode Switching:** The system supports `MODE AUTO` (fixed thresholds) and `MODE MANUAL` (user-defined thresholds).
    * **Dynamic Thresholds:** In Manual mode, the system compares light percentage against variables that can be changed via the CLI.
    * **Command Parsing:** The firmware handles complex commands (e.g., `SET LOW 30`) by parsing the string and converting substrings to integers using `.toInt()`.

---

## 🔴 Part 3: Python & Full-Stack Integration

### 5. Uni-Directional Serial Control (Lab 5)
**Project:** Python LED Controller
* **The Problem:** Controlling hardware from a desktop application via Serial connection.
* **Code Logic:**
    * **Python Logic:** A script runs a non-terminating `while True` loop to allow repeated commands without restarting. It converts inputs to lowercase to ensure case-insensitivity (e.g., 'r' and 'R' are treated identically).
    * **Arduino Logic:** The firmware listens for specific single-character commands to toggle Red (8), Green (9), or Blue (10) LEDs.

### 6. "Software-in-the-Loop" Relay (Lab 6)
**Project:** Bi-Directional Communication
* **The Problem:** Implementing a full-duplex control loop where hardware inputs are processed by external software.
* **Data Flow:**
    1. **Hardware:** Button press sends a character (e.g., `'R'`) to the computer.
    2. **Software (Python):** Receives the character, processes the logic, and sends a command back (e.g., `'1'`).
    3. **Hardware:** Arduino receives the command and toggles the LED.
* **Constraint:** Buttons do not control LEDs locally; the signal must travel to the Python script and back.

### 7. HTTP-to-Serial Bridge (Lab 7)
**Project:** Web-Controlled IoT
* **The Problem:** Controlling hardware via a Web Browser using HTTP protocols.
* **Full Stack Logic:**
    * **Frontend:** `web.html` uses the JavaScript `fetch()` API to send asynchronous HTTP requests.
    * **Middleware:** A **FastAPI** server receives the requests (e.g., `GET /led/on`) and translates them into Serial commands.
    * **Backend:** The Arduino receives the translated command and toggles the physical LEDs.

### 8. Physical-to-Cloud Trigger (Final Exam)
**Project:** Serial API Bridge
* **The Problem:** Triggering a remote network API endpoint from a physical button.
* **Code Logic:**
    * **Hardware Debounce:** The Arduino implements a software debouncing algorithm with a 50ms delay to ensure clean detection.
    * **Python Gateway:** The script continuously monitors the serial port. Upon receiving a specific Group ID (`3`), it constructs a dynamic API request to a specific URL.

---

## 📬 Contact
**John Robert Olaño** *Student, Cavite State University Imus* [GitHub Profile](https://github.com/JohnRobert-Olano)
