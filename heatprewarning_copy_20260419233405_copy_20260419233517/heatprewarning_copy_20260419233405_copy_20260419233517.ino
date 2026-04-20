#include <Arduino_RouterBridge.h>
#include <Wire.h>
#include <Modulino.h>

ModulinoThermo thermo;

const int buzzerPin = 11;
#define ALERT_TEMP_F 60.0

void setup() {
  Monitor.begin(115200);
  delay(3000);
  Monitor.println("Step 1: Serial OK");
  Wire.begin();
  Monitor.println("Step 2: Wire OK");
  Monitor.println("Step 3: Initializing Thermo...");
  Modulino.begin();
  thermo.begin();
  Monitor.println("Step 4: Thermo done");
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  float tempC = thermo.getTemperature();
  float tempF = (tempC * 9.0 / 5.0) + 32.0;

  Monitor.print("Temp: ");
  Monitor.print(tempC);
  Monitor.print(" C / ");
  Monitor.print(tempF);
  Monitor.println(" F");

  if (tempF >= ALERT_TEMP_F) {
    Monitor.println("ALERT: Temperature at or above 60F!");
    tone(buzzerPin, 1000);
    delay(200);
    noTone(buzzerPin);
    delay(200);
  } else {
    noTone(buzzerPin);
  }

  delay(2000);
}