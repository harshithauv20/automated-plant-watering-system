# Wiring Reference

This document is a reconstructed wiring reference because the original circuit notes were lost.

## Sensor

Typical soil moisture sensor module:

- VCC → Arduino 5V
- GND → Arduino GND
- AO → Arduino A0

The digital output (DO) is not required by the reconstructed program.

## Relay

Typical 1-channel relay module:

- VCC → Arduino 5V
- GND → Arduino GND
- IN → Arduino digital pin 7

The reconstructed program assumes an **active-LOW** relay.

If the relay turns ON when the program expects it to be OFF, change:

```cpp
const int RELAY_ON = LOW;
const int RELAY_OFF = HIGH;
```

to the opposite logic.

## Pump

The pump should be powered from a suitable external supply. The relay acts as the switching element.

Do not connect a pump directly to an Arduino digital pin.

For the exact pump supply and relay terminal wiring, verify the voltage/current ratings printed on the actual components.
