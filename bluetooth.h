#pragma once 

#include "config.h"

void sendDataToApp(MPUSensorValues mpuSensorValues, MusicParameters musicParameters, Buttons button){
  uint8_t encodedVolume= musicParameters.volume+VOLUME_ENCODING;

    if (button.one) { 
      SerialBT.println(BUTTON_ONE_ON);
      Serial.println("BUTTON ONE IS ON");
      } else { 
        SerialBT.println(BUTTON_ONE_OFF);
        Serial.println("BUTTON ONE IS OFF");
      }

    if (button.two) { 
      SerialBT.println(BUTTON_TWO_ON); 
      Serial.println("BUTTON TWO IS ON");
      }
    else {
      SerialBT.println(BUTTON_TWO_OFF);
      Serial.println("BUTTON TWO IS OFF");
    }    

  // the volume plus 10 is sent over bluetooth
  // this prevents the esp32 from sending the same thing at the ssame time if the volume is equal to the code for a button 
  // eg volume=0 and button one is on (which will also send a 0)

  SerialBT.println(encodedVolume); // in the code for the app, 10 will be taken away from what is sent to get the actual volume
  Serial.print("ENCODED VOLUME: "); Serial.println(encodedVolume);
  Serial.print("TRUE VOLUME: "); Serial.println(musicParameters.volume);
}