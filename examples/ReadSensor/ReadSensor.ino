/*
  MKR ENV Shield - Read Sensors

  This example reads the sensor connected to the MKR Therm shield
  and prints them to the Serial Monitor once a second.

  The circuit:
  - Arduino MKR board
  - Arduino MKR Therm Shield attached
  - A Thermocouple temperature sensor connected to the shield
 
  This example code is in the public domain.
*/

#include <MKRTherm.h>

void setup() {

  Serial.begin(9600);

  while (!Serial);

  THERM.begin();
}

void loop() {

  Serial.print("ref ");
  Serial.print(THERM.readRefTemperature());
  Serial.println(" °C");

  Serial.print("celcius ");
  Serial.print(THERM.readCelsiusTemperature());
  Serial.println(" °C");

  Serial.println();

  delay(1000);
}