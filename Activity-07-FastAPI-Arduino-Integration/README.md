# IoT Laboratory Activity 7: HTTP-Based Arduino Control with FastAPI

## 📖 Project Overview
This project demonstrates a full-stack IoT solution. Unlike previous activities that used a command-line interface, this system uses a **Web Browser** as the controller.
1.  **Frontend:** A graphical web page (`web.html`) sends HTTP requests.
2.  **Backend:** A Python **FastAPI** server receives these requests and translates them into Serial commands.
3.  **Hardware:** The Arduino receives the Serial commands and toggles the physical LEDs.

### 🎯 Objectives
* **Modern IoT Architecture:** Implement a client-server model using HTTP protocols.
* **FastAPI Integration:** Use Python's FastAPI library to create a bridge between the web and the Serial port.
* **Remote Control:** Control hardware states (LEDs) via a user-friendly web interface.

---

## 📂 Repository Structure & Activity Descriptions

### 1. `/Arduino_Firmware`
This folder contains the low-level code running on the microcontroller.

* **`Lab_Act7.h`**: A header file acting as a hardware driver.
    * Defines pins: Red (7), Green (6), Blue (5).
    * Contains the `initSystem()` function to configure all pins as OUTPUT/INPUT in one line.
    * Includes a helper function `toggleLED(int pin)` to simplify state changes.
* **`LabAct7.ino`**: The main firmware logic.
    * Listens for specific single-character commands over Serial:
        * `'1'`, `'2'`, `'3'`: Toggle Red, Green, or Blue LEDs respectively.
        * `'9'`: Turns **ALL** LEDs ON (Global On).
        * `'0'`: Turns **ALL** LEDs OFF (Global Off).

### 2. `/Python_Backend`
This folder contains the **FastAPI** server script (`main.py`).

* **Server Lifecycle:** On startup, it automatically establishes a serial connection to the Arduino (e.g., `COM7`).
* **API Endpoints:**
    * `GET /led/{color}`: Accepts "red", "green", or "blue". Sends `'1'`, `'2'`, or `'3'` to the Arduino.
    * `GET /led/on`: Sends `'9'` to turn all LEDs on.
    * `GET /led/off`: Sends `'0'` to turn all LEDs off.
* **CORS Middleware:** Enabled to allow the web page (which runs in the browser) to talk to the local Python server without security blocking.

### 3. `/Web_Client`
This folder contains the user interface (`web.html`).

* **Design:** A responsive "Control Center" card with colored buttons for Red, Green, and Blue, plus master On/Off controls.
* **JavaScript Logic:** Uses the `fetch()` API to send asynchronous HTTP requests to `http://127.0.0.1:8000`. It updates the status text dynamically based on the server's response (Success vs. Connection Failed).

---

## 🛠️ Hardware Setup

### Wiring Diagram

**⚠️ Pin Assignments:**
Ensure your wiring matches `Lab_Act7.h`:

| Component | Arduino Pin | Connection |
| :--- | :--- | :--- |
| **Red LED** | Pin 7 | Anode (+) to Pin 7, Cathode (-) to GND |
| **Green LED** | Pin 6 | Anode (+) to Pin 6, Cathode (-) to GND |
| **Blue LED** | Pin 5 | Anode (+) to Pin 5, Cathode (-) to GND |
| **Buttons** | 12, 11, 10 | (Included in header definitions) |

---

## 🚀 How to Run

### Step 1: Hardware & Firmware
1.  Connect your Arduino and build the circuit.
2.  Open `/Arduino_Firmware/LabAct7.ino`.
3.  Upload the code to your board.
4.  **Close the Arduino IDE Serial Monitor** (This is critical; otherwise, Python cannot connect).

### Step 2: Python Server
1.  Open `/Python_Backend/main.py`.
2.  Update the `SERIAL_PORT` variable (line 11) to match your Arduino (e.g., `COM3`, `COM7`).
3.  Install dependencies:
    ```bash
    pip install fastapi uvicorn pyserial
    ```
4.  Start the server:
    ```bash
    uvicorn Python_Backend.main:app --reload
    ```
    *You should see:* `Connected to Arduino on COM...`

### Step 3: Web Control
1.  Go to the `/Web_Client` folder.
2.  Double-click `web.html` to open it in your browser.
3.  Click the buttons to control your LEDs!

---

## 🔧 Troubleshooting
* **"Connection Failed" in Browser:** Ensure the Python server is running in the terminal.
* **"Access Denied" in Terminal:** The Arduino IDE Serial Monitor is likely open. Close it and restart the Python server.
* **LEDs not responding:** Check if the `baud_rate` in Python (9600) matches the Arduino sketch (9600).