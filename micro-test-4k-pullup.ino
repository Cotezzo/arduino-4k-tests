#include <Keyboard.h>

// Buttons Pinout
const byte BT_A = 2;
const byte BT_B = 3;
const byte BT_C = 4;
const byte BT_D = 5;

// LED Pinout
const byte BT_A_LED = 10;
const byte BT_B_LED = 16;
const byte BT_C_LED = 14;
const byte BT_D_LED = 15;

// Buttons Keybinds
const char BIND_A = 'd';
const char BIND_B = 'f';
const char BIND_C = 'j';
const char BIND_D = 'k';

const int DELAY = 10;

byte buttonPins[] = { BT_A, BT_B, BT_C, BT_D };
byte bindKeys[] = { BIND_A, BIND_B, BIND_C, BIND_D };
byte ledPins[] = { BT_A_LED, BT_B_LED, BT_C_LED, BT_D_LED };

byte buttonCount = 4;

void setup() {
  // Setup I/O for pins
  byte i = 0;
  while (i < buttonCount) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
    i++;
  }
  Keyboard.begin();
}

void loop() {
  // Read the buttons, if it's low, output a keyboard press
  byte i = 0;
  while(i < buttonCount){
    if (digitalRead(buttonPins[i]) == LOW){
      Keyboard.press(bindKeys[i]);
      digitalWrite(ledPins[i], HIGH);
    } else {
      Keyboard.release(bindKeys[i]);
      digitalWrite(ledPins[i], LOW);
    }
    i++;
  }
  delay(DELAY);
}
