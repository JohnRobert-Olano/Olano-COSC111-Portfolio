#ifndef ARDUINO_FROM_PYTHON_HEADER_H
#define ARDUINO_FROM_PYTHON_HEADER_H

// === Pin Assignments ===
#define RED_LED 8
#define GREEN_LED 9
#define BLUE_LED 10

// === LED States ===
bool redState = false;
bool greenState = false;
bool blueState = false;

// === All OFF ===
void allOff() {
  redState = greenState = blueState = false;
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
}

// === Setup Function for LEDs ===
void setupLEDs() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  allOff();  // Start with all LEDs off
}

// === Toggle Functions ===
void toggleRed() {
  redState = !redState;
  digitalWrite(RED_LED, redState);
}

void toggleViolet() {
  redState = !redState;
  blueState = !blueState;
  digitalWrite(RED_LED, redState);
  digitalWrite(BLUE_LED, blueState);
}

void toggleGreen() {
  greenState = !greenState;
  digitalWrite(GREEN_LED, greenState);
}

void toggleBlue() {
  blueState = !blueState;
  digitalWrite(BLUE_LED, blueState);
}

// === All ON ===
void allOn() {
  redState = greenState = blueState = true;
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, HIGH);
}



#endif