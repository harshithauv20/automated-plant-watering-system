/*
  Automated Plant Watering System
  Reconstructed project version from the original hardware photos.

  Hardware:
  - Arduino Uno
  - Soil moisture sensor module
  - 1-channel relay module
  - Small DC water pump
  - Water container + tubing

  IMPORTANT:
  The original source code was lost, so pin numbers and threshold values
  below are a reconstructed starting point. Test and adjust them for your
  exact wiring before operating the pump.
*/

const int SOIL_SENSOR_PIN = A0;
const int RELAY_PIN = 7;

// Many relay modules are active LOW.
// Change these two values if your relay behaves in the opposite way.
const int RELAY_ON = LOW;
const int RELAY_OFF = HIGH;

// Moisture reading depends on the sensor and soil.
// For a typical resistive sensor, higher readings often mean drier soil.
// Adjust after observing Serial Monitor values.
const int DRY_THRESHOLD = 600;
const int WET_THRESHOLD = 450;

void setup() {
  Serial.begin(9600);

  pinMode(SOIL_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  // Keep the pump OFF at startup.
  digitalWrite(RELAY_PIN, RELAY_OFF);

  Serial.println("Automated Watering System Started");
}

void loop() {
  int moisture = analogRead(SOIL_SENSOR_PIN);

  Serial.print("Soil moisture reading: ");
  Serial.println(moisture);

  // If the soil is dry, switch the pump ON.
  if (moisture >= DRY_THRESHOLD) {
    digitalWrite(RELAY_PIN, RELAY_ON);
    Serial.println("Soil is dry -> Pump ON");

    // Water for a short interval.
    delay(3000);

    // Turn the pump off and allow water to soak into the soil.
    digitalWrite(RELAY_PIN, RELAY_OFF);
    Serial.println("Pump OFF -> Waiting for moisture to settle");

    delay(5000);
  }

  // If the soil is sufficiently wet, keep the pump OFF.
  else if (moisture <= WET_THRESHOLD) {
    digitalWrite(RELAY_PIN, RELAY_OFF);
    Serial.println("Soil is wet -> Pump OFF");
  }

  delay(1000);
}
