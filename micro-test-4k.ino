#include "Keyboard.h"

// INPUTS
const int BTN1 = 2;
const int BTN2 = 3;
const int BTN3 = 4;
const int BTN4 = 5;

// KEY MAPPING
const int BTN1_KEY = 97;   // 'a'
const int BTN2_KEY = 98;   // 'b'
const int BTN3_KEY = 99;   // 'c'
const int BTN4_KEY = 100;  // 'd'

// LOOP EVERY DELAY MS
const int DELAY = 20;

void setup() {
  // SET PINS AS INPUT
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(BTN3, INPUT);
  pinMode(BTN4, INPUT);

  // KEYBOARD INIT
  Keyboard.begin();
}

void loop() {
  if (digitalRead(BTN1) == HIGH){
    Keyboard.write(BTN1_KEY);
  }

  if (digitalRead(BTN2) == HIGH){
    Keyboard.write(BTN2_KEY);
  }

  if (digitalRead(BTN3) == HIGH){
    Keyboard.write(BTN3_KEY);
  }

  if (digitalRead(BTN4) == HIGH){
    Keyboard.write(BTN4_KEY);
  }

  delay(DELAY);
}
