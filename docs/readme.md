# Arduino MKR THERM library


The Arduino MKR THERM library allows you to manage a thermocouple attached to the MKR THERM Shield with a type k connector or with screw terminals. This library manages the MAX31855 chip of the MKR THERM Shield.

The functions available in the library are just two. They allows you to read the temperature of the hot junction of the thermocouple (the tip of the thermocouple) and also the temperature of the cold junction (the connection between the wire of the thermocouple and the connector or the screw terminal). The temperature value of the cold junction is used to give a compensated value of the current measured at the hot junction. This current is then converted into a temperature value. 

To use this library:

```
#include <Arduino_MKRTHERM.h>
```