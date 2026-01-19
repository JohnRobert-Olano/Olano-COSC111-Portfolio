#include "ArduinoFromPythonHeader.h"

void setup() {
  Serial.begin(9600);
  setupLEDs();
  Serial.println("Arduino LED Serial Controller Ready...");
}

void loop() {
  if (Serial.available() > 0) {
    
    String inputString = Serial.readStringUntil('\n');

    inputString.trim();

    if (inputString.length() == 0) {
      return;
    }

    if (inputString.length() > 1) {
      Serial.println("Error: Please input only one character.");
      return; 
    }

    char input = tolower(inputString.charAt(0));

    switch (input) {
      case 'v':
        toggleViolet();
        Serial.println("Red & Blue LED toggled.");
        break;

      case 'r':
        toggleRed();
        Serial.println("Red LED toggled.");
        break;

      case 'g':
        toggleGreen();
        Serial.println("Green LED toggled.");
        break;

      case 'b':
        toggleBlue();
        Serial.println("Blue LED toggled.");
        break;

      case 'a':
        allOn();
        Serial.println("All LEDs ON.");
        break;

      case 'o':
        allOff();
        Serial.println("All LEDs OFF.");
        break;

      default:
        Serial.print("Error: Invalid input '");
        Serial.print(input);
        Serial.println("'");
        break;
    }
  }
}