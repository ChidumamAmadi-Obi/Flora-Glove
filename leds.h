#pragma once

// control leds etc

#include "config.h"

void toggleLEDs(Buttons button){ // controls state of leds ( will add led light patterns later)
  if (digitalRead(BUTTON3)) {
    ledstatus++;
    Serial.println("BUTTON THREE PRESSED"); 
  }
  if(ledstatus==0){
    digitalWrite(LED1, LOW);
  }
  else if (ledstatus==1){
    digitalWrite(LED1, HIGH);
  }
  else{
    ledstatus==0;
  }
digitalWrite(LED1,ledstatus);
  
}


