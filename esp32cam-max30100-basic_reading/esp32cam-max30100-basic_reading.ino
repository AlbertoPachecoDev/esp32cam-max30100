/*
  MAX30102 Breakout: Output all the raw Red/IR/Green readings
  By: Nathan Seidle @ SparkFun Electronics
  Date: October 2nd, 2016
  https://github.com/sparkfun/MAX30105_Breakout

  Outputs all Red/IR/Green values.

  Hardware Connections (Breakoutboard to Arduino):
  - VCC = 3.3V (Usar de preferencia 3.3v, en vez de 5v) 
  - GND = GND
  - SDA = A4 (or SDA) + 4.7Kohms a Vcc (pull-up)
  - SCL = A5 (or SCL) + 4.7Kohms a Vcc (pull-up)
  - INT = Not connected (TO-DO)

  The MAX30105 Breakout can handle 5V or 3.3V I2C logic. We recommend powering the board with 5V
  but it will also run at 3.3V.

  This code is released under the [MIT License](http://opensource.org/licenses/MIT).
*/

// #include <Wire.h> // No es necesario, la librería del sensor lo incluye  
#include "MAX30105.h"

MAX30105 particleSensor;

void setup()
{
  Serial.begin(115200);
  Serial.println("MAX30102 Basic Readings Example");
  
  Wire.begin(14,15); // BUG
  // Initialize sensor
  if (particleSensor.begin(Wire) == false) {
    Serial.println("MAX30102 was not found. Please check wiring/power.");
    return; // while(1);
  }
  particleSensor.setup(); // Configure sensor: investigar los parámetros posibles
}

void loop() {
  Serial.print(" R[");
  Serial.print(particleSensor.getRed());
  Serial.print("] IR[");
  Serial.print(particleSensor.getIR());
  // EL SENSOR MAX30102 NO TIENEN LED GREEN Serial.print("] G[");
  // EL SENSOR MAX30102 NO TIENEN LED GREEN Serial.print(particleSensor.getGreen());
  Serial.print("]");
  Serial.println();
  delay(2000);
}
