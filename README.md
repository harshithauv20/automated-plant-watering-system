# Automated Plant Watering System

A simple Arduino-based automation project that waters a plant when the soil becomes dry.

## Project Overview

The system uses a soil-moisture sensor to monitor the soil condition. An Arduino Uno reads the sensor value and controls a DC water pump through a relay module.

When the soil becomes dry:

1. The soil-moisture sensor detects the condition.
2. Arduino reads the sensor value.
3. The relay is activated.
4. The water pump turns ON.
5. Water is delivered to the plant.
6. The pump turns OFF once the watering condition is satisfied.

## Hardware Used

* Arduino Uno
* Soil-moisture sensor/module
* 1-channel relay module
* Small DC water pump
* Water container
* Flexible water tubing
* Jumper wires
* USB cable / Arduino power source

## Basic System Flow

Soil
↓
Soil-Moisture Sensor
↓
Arduino Uno
↓
Relay Module
↓
DC Water Pump
↓
Water Tube
↓
Plant

## Software

* Arduino IDE
* Arduino C/C++

## How the Logic Works

The Arduino continuously reads the analog moisture value.

A dry-soil threshold determines when watering should start. A second threshold determines when watering should stop. Using two thresholds provides simple **hysteresis**, which helps prevent the pump from rapidly switching ON and OFF around a single threshold.

The Arduino code is available in:

`src/automated_watering_system.ino`

## Calibration

The original calibration values were not available, so the threshold values in the reconstructed code should be adjusted for the actual sensor.

To calibrate:

1. Upload the program.
2. Open the Arduino IDE Serial Monitor at 9600 baud.
3. Record the reading in dry soil.
4. Record the reading in wet soil.
5. Adjust `DRY_THRESHOLD` and `WET_THRESHOLD`.
6. Test the relay with the pump disconnected before the final water test.

## Wiring

| Component                | Arduino Connection                                            |
| ------------------------ | ------------------------------------------------------------- |
| Soil-moisture sensor AO  | A0                                                            |
| Soil-moisture sensor VCC | 5V                                                            |
| Soil-moisture sensor GND | GND                                                           |
| Relay IN                 | D7                                                            |
| Relay VCC                | 5V                                                            |
| Relay GND                | GND                                                           |
| Pump                     | Connected through relay contacts and suitable external supply |

**Safety:** Do not power a DC pump directly from an Arduino GPIO pin. Use the relay and an appropriate external power supply for the pump.

## Repository Note

The original source code and documentation for this hobby prototype were lost. This repository preserves the project using the available hardware photographs and a reconstructed Arduino implementation.

The reconstructed code is a functional starting point and is **not claimed to be the exact original source code**.

## Future Improvements

* Add an LCD/OLED display for moisture readings
* Add adjustable moisture thresholds
* Use a capacitive soil-moisture sensor
* Add a manual watering button
* Add a water-level sensor
* Add ESP32/ESP8266 connectivity
* Store and display moisture history

## Project Type

**Arduino | Hardware Automation | Sensors | Actuators**
