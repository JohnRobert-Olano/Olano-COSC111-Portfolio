import serial
import time
import os

# Change this to your COM port (ex: COM3, COM4, /dev/ttyUSB0)
arduino_port = "COM7"

arduino = serial.Serial(arduino_port, 9600)
time.sleep(2)  # Allow Arduino to initialize

def clear_screen():
    os.system("cls" if os.name == "nt" else "clear")

def print_menu():
    print("[R] Red ON/OFF")
    print("[G] Green ON/OFF")
    print("[B] Blue ON/OFF")
    print("[V] Blue & Red ON/OFF")
    print("[A] All ON")
    print("[O] All OFF")
    print("[X] Exit")

while True:
    clear_screen()
    print_menu()

    user_choice = input("\nEnter your command: ").strip().lower()

    if user_choice == "x":
        print("Exiting program...")
        break

    if user_choice in ["r", "g", "b", "a", "o", "v"]:
        arduino.write((user_choice + '\n').encode())