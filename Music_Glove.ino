#include "config.h"
#include "sensor_input.h"
#include "bluetooth.h"

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10); // wait until serial com has been initialized

  Wire.begin(); // init i2c communication with mpu
  mpu.initialize(); // init mpu

  SerialBT.begin("MusicGlove");

  if (SerialBT.available()) Serial.println("BLUETOOTH CONNECTED");
  else Serial.println("BLUETOOTH NOT CONNECTED");

  pinMode(LED1, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  delay(100);
}

void loop() {
  mpuSensorValues = scanMPU(); // monitor and record MPU sensor data
  controlTouchSensors(); // monitor touch sensors (includes LED control)
  controlVolume(mpuSensorValues,&musicParameters);

  sendDataToApp(mpuSensorValues,musicParameters,button); // sends all data to app via bluetooth

  delay(100);
}
