#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
#define REPORTING_PERIOD_MS 1000

// Temperature sensor setup
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature tempSensor(&oneWire);

// MAX30100 setup
PulseOximeter pox;
uint32_t tsLastReport = 0;

void onBeatDetected() {
  Serial.println("Beat detected!");
}

void setup() {
  Serial.begin(9600);

  // Initialize temperature sensor
  tempSensor.begin();

  // Initialize MAX30100
  Serial.println("Initializing MAX30100...");
  if (!pox.begin()) {
    Serial.println("FAILED to initialize MAX30100");
    for (;;);
  } else {
    Serial.println("MAX30100 initialized");
  }

  pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {
  // Update MAX30100 readings
  pox.update();

  // Read temperature
  tempSensor.requestTemperatures();
  float tempC = tempSensor.getTempCByIndex(0);

  // Every 1 second, print all sensor values
  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
    float bpm = pox.getHeartRate();
    float spo2 = pox.getSpO2();

    Serial.print("BPM: ");
    Serial.print(bpm);
    Serial.print(" | SpO2: ");
    Serial.print(spo2);
    Serial.print(" | Temp(C): ");
    Serial.println(tempC);

    tsLastReport = millis();
  }
}
