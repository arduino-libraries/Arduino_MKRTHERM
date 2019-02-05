/*
  This file is part of the MKRTherm library.
  Copyright (c) 2018 Arduino SA. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "MKRTherm.h"

#include "SPI.h"

THERMClass::THERMClass(int cs) : _cs(cs)
{
}

int THERMClass::begin()
{
  pinMode(_cs, OUTPUT);
  digitalWrite(_cs, HIGH);
  SPI.begin();

  return 1;
}

void THERMClass::end()
{
  SPI.end();
}

uint32_t THERMClass::readSensor()
{
  uint32_t read;

  digitalWrite(_cs, LOW);
  delay(1);

  SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));

  read = SPI.transfer(0);
  read <<= 8;
  read |= SPI.transfer(0);
  read <<= 8;
  read |= SPI.transfer(0);
  read <<= 8;
  read |= SPI.transfer(0);

  SPI.endTransaction();

  digitalWrite(_cs, HIGH);
  delay(1);
  return read;
}


double THERMClass::readCelsiusTemperature()
{
  uint32_t rawword;
  double celsius;

  rawword = readSensor();

  // Check for reading error
  if (rawword & 0x7) {
    return NAN; 
  }
  // The temperature is stored in the last 14 word's bits 
  // sendend by the Thermocouple-to-Digital Converter
  if (rawword & 0x80000000) {
    // Negative value, drop the lower 18 bits and explicitly extend sign bits.
    rawword = 0xFFFFC000 | ((rawword >> 18) & 0x00003FFFF);
  } else {
    // Positive value, just drop the lower 18 bits.
    rawword >>= 18;
  }
  // multiply for the LSB value
  celsius = rawword*0.25f;

  return celsius;
}



double THERMClass::readRefTemperature()
{
  uint32_t rawword;
  double ref;

  rawword = readSensor();

  // ignore first 4 FAULT bits
  rawword >>= 4;

  // The cold junction reference temperature is stored in the first 11 word's bits
  // sendend by the Thermocouple-to-Digital Converter
  rawword = rawword & 0x7FF;
  // check sign bit  and convert to negative value.
  if (rawword & 0x800) {
    ref = (0xF800 | (rawword & 0x7FF))*0.0625;
  } else {
      // multiply for the LSB value
      ref = rawword * 0.0625f;
  }

  return ref;
}

THERMClass THERM;
