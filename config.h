#pragma once

#include <stdint.h>
#include <Wire.h>
#include "I2Cdev.h"     
#include "MPU6050.h"   

#include  "BluetoothSerial.h"
BluetoothSerial SerialBT;

// PIN NUMBERS
// SDA 21
// SCL 22
#define BUTTON1 34
#define BUTTON2 35
#define BUTTON3 32
#define BUTTON4 33
#define LED1 25
#define LED2 26
#define LED3 27

// calibration for mpu DONT TOUCH OR CHANGE
#define X_OFFSET 118
#define Y_OFFSET 128
#define Z_OFFSET 258

// other macros
#define MAX_VOLUME 100
#define PRINT_MPU_DATA 0 // see incoming mpu data
#define PRINT_BLUETOOTH_OUT //see data being sent to ap via bluetooth

// MPU thresholds
#define POS_THRESHOLD -75
#define NEG_THRESHOLD 75

// volume control and timing variables
const unsigned long volControlInterval = 250;
unsigned long lastVolChange=0;
unsigned long currentMillis=0;
int volumeChangePercentage=5;

// an enum is used to send codes to app via bluetooth
// the app cannot handle strings so data has to be encoded
typedef enum{
  BUTTON_ONE_ON, // 1
  BUTTON_TWO_ON, // 2
  VOLUME_ENCODING=5 // 5
}InputCodes;

// structs will be used to pass sensor information easily and cleanly to the application


typedef struct{ // this struct holds sensor values detected by the MPU
  int16_t gyroX; // rotation along x axis
  int16_t gyroY; // rotation along y axis
  int16_t gyroZ; // rotation along z axis
}MPUSensorValues;
typedef struct{
  bool one=0;
  bool two=0;
  bool three=0;
  bool four=0;
}Buttons;
typedef struct{
  uint8_t volume=50; // volume can be 0-100
}MusicParameters;

// define structs
MPU6050 mpu; // makes an MPU object to be used durin initialization
MPUSensorValues mpuSensorValues;
MusicParameters musicParameters;
Buttons button;

