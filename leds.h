#pragma once

// control leds etc

#include "config.h"

void toggleLEDs(Buttons button){ // controls state of leds ( will add led light patterns later)
  if (button.three) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    Serial.println("BUTTON TWO PRESSED");
  } else if (button.four) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    Serial.println("BUTTON ONE PRESSED");
  }
}


