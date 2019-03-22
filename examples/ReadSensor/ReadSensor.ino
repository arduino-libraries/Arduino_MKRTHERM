/*
  MKR THERM Shield - Read Sensors

  This example reads the sensor connected to the MKR THERM shield
  and prints them to the Serial Monitor once a second.

  The circuit:
  - Arduino MKR board
  - Arduino MKR THERM Shield attached
  - A thermocouple temperature sensor connected to the shield
 
  This example code is in the public domain.
*/

#include <Arduino_MKRTHERM.h>

void setup() {

  Serial.begin(9600);

  while (!Serial);

  if (!THERM.begin()) {
    Serial.println("Failed to initialize MKR THERM shield!");
    while (1);
  }
}

void loop() {

  Serial.print("Internal temperature ");
  Serial.print(THERM.readInternalTemperature());
  Serial.println(" °C");

  Serial.print("External temperature ");
  Serial.print(THERM.readTemperature());
  Serial.println(" °C");

  Serial.println();

  delay(1000);
}
