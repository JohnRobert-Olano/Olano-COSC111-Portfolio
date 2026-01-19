# Final Lab Exam: Serial API Bridge (Group 3)

## 📖 Project Overview
This project serves as the final examination submission for **Group 3**. It implements a complete IoT control loop that triggers a remote API endpoint based on a physical hardware interaction.

The system uses a "Software-in-the-Loop" architecture:
1.  **Hardware:** A push button on the Arduino acts as the physical trigger.
2.  **Middleware:** A Python script bridges the USB Serial connection to the Local Area Network (LAN).
3.  **Cloud/Server:** An HTTP API receives the request to toggle a remote LED.

---

## 📂 Repository Structure & Activity Descriptions

### 1. `/Arduino_Client`
This folder contains the firmware **`LabExamFinal.ino`**.

**Activity Description:**
* **Hardware Abstraction:** The code configures **Pin 4** as an input using the internal pull-up resistor (`INPUT_PULLUP`), eliminating the need for external resistors.
* **Signal Processing:** It implements a software debouncing algorithm with a **50ms** delay to ensure clean button press detection.
* **Serial Communication:** When a valid button press is detected (logic LOW), the system prints the Group ID (**3**) to the serial monitor at 9600 baud.

### 2. `/Python_Gateway`
This folder contains the bridge script **`main.py`**.

**Activity Description:**
* **Serial Listener:** The script continuously monitors the specified serial port (e.g., `COM7`) for incoming data.
* **Dynamic API Request:** Upon receiving the Group ID (`3`), it constructs a specific URL: `http://172.20.10.3:8000/led/group/3/toggle`.
* **Network Interaction:** It sends a `GET` request to the server and logs the response ("SUCCESS" or "ERROR") to the console for real-time feedback.

---

## 🛠️ Hardware Setup

### Wiring Diagram


**Connection Guide:**
The code relies on the internal pull-up resistor, so the wiring is minimal:

| Component | Arduino Pin | Connection Details |
| :--- | :--- | :--- |
| **Push Button (Leg 1)** | **Pin 4** | Connect directly to Pin 4 |
| **Push Button (Leg 2)** | **GND** | Connect directly to Ground |

---

## 🚀 How to Run

### 1. Arduino Setup
1.  Open `/Arduino_Client/LabExamFinal.ino`.
2.  Ensure the correct group ID is set: `const int groupNumber = 3;`.
3.  Upload the sketch to your board.
4.  **Close the Arduino Serial Monitor** (Required for Python to connect).

### 2. Python Setup
1.  Open `/Python_Gateway/main.py`.
2.  Update `SERIAL_PORT` to match your device (e.g., `COM3`, `/dev/ttyUSB0`).
3.  Install dependencies:
    ```bash
    pip install pyserial requests
    ```
4.  Run the gateway:
    ```bash
    python main.py
    ```

### 3. Verification
* Press the button on the Arduino.
* The Python terminal should display:
    ```text
    Group Received: 3
    Calling Endpoint: ...
    API Response: SUCCESS
    ```