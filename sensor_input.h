#pragma once

#include "config.h"
#include "leds.h"

MPUSensorValues scanMPU(){
  static MPUSensorValues mpuSensorValues; // make struct to store and return all mpu values

  // store raw mpu values
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); // get raw mpu data

  // convert raw mpu data to degrees
  mpuSensorValues.gyroX = map(ax, -17000, 17000, 0, 255)-X_OFFSET;  // X axis data
  mpuSensorValues.gyroY = map(ay, -17000, 17000, 0, 255)-Y_OFFSET;  // Y axis data
  mpuSensorValues.gyroZ = map(az, -17000, 17000, 0, 255)-Z_OFFSET;  // Z axis data

  if (PRINT_MPU_DATA){ // print if needed
    Serial.print("Axis X = ");
    Serial.print(mpuSensorValues.gyroX);
    Serial.print("  ");
    Serial.print("Axis Y = ");
    Serial.print(mpuSensorValues.gyroY);
    Serial.print("  ");
    Serial.print("Axis Z = ");
    Serial.println(mpuSensorValues.gyroZ);    
  }

  return mpuSensorValues;
}

void controlVolume(MPUSensorValues mpuSensorValues, MusicParameters *musicParameters){
  currentMillis = millis();
  if ((currentMillis - lastVolChange >= volControlInterval)) { // only update volume every 250 milliseconds
    lastVolChange = currentMillis;

    if ((mpuSensorValues.gyroX < POS_THRESHOLD)){ // if mpu gets under -75 degrees decrease volume level
      Serial.println("Decreaseing..."); 
      if (!(musicParameters->volume >= MAX_VOLUME)) { 
        musicParameters->volume -= volumeChangePercentage; 
      }

    } else if ((mpuSensorValues.gyroX > NEG_THRESHOLD)){ // if mpu gets over 75 degrees increase volume level
      Serial.println("Increasing..."); 
      if (!(musicParameters->volume <= 0)) { 
        musicParameters->volume += volumeChangePercentage; 
      }
      
    } 
  }
  Serial.println(musicParameters->volume);
}

void controlTouchSensors(){ // keep track of button states to send to app via bluetooth
  if (digitalRead(BUTTON1)) {
    button.one=true;
  } else {
    button.one=false;
  }

  if (digitalRead(BUTTON2)) {
    button.two=true;
  } else {
    button.two=false;
  }

  if (digitalRead(BUTTON3)) {
    button.three=true;
  } else {
    button.three=false;
  }

  if (digitalRead(BUTTON4)) {
    button.four=true;
  } else {
    button.four=false;
  }

  toggleLEDs(button); // handle led flashing 
}

