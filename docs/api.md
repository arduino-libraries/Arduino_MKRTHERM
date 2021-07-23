# Arduino MKR THERM library

## Methods

### `begin()`

Initialize the sensor connected to the shield. 

#### Syntax 

```
THERM.begin()
```

#### Parameters

None.

#### Returns

1 on success, 0 on failure.

#### Example

```
if (!THERM.begin()) {
    Serial.println("Failed to initialize MKR THERM shield!");
    while (1);
}
```

#### See also

* [end()](#end)
* [readTemperature()](#readtemperature)
* [readReferenceTemperature()](#readreferencetemperature)

### `end()`

De-initialize the sensor connected to the shield. 

#### Syntax 

```
THERM.end()
```

#### Parameters

None.

#### Returns

None.

#### Example

```
THERM.end();
```

#### See also

* [begin()](#begin)
* [readTemperature()](#readtemperature)
* [readReferenceTemperature()](#readreferencetemperature)

### `readTemperature()`

Read the thermocouple’s hot junction (its tip) temperature value. 

#### Syntax 

```
THERM.readTemperature() 
```

#### Parameters

None.

#### Returns

The thermocouple’s hot junction temperature value in degrees Celsius. 

#### Example

```
Serial.print("Temperature = ");
Serial.print(THERM.readTemperature());
Serial.println(" °C");
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [readReferenceTemperature()](#readreferencetemperature)

### `readReferenceTemperature()`

Read the thermocouple’s cold junction (the connection between the wire of the thermocouple and the connector or the screw terminal) temperature value. This value is used to compensate the temperature reading of the themocouple's hot junction. 

#### Syntax 

```
THERM.readReferenceTemperature()
```

#### Parameters

None.

#### Returns

The thermocouple’s cold junction temperature value in degrees Celsius. 

#### Example

```
Serial.print("Reference temperature = ");
Serial.print(THERM.readReferenceTemperature());
Serial.println(" °C");
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [readTemperature()](#readtemperature)