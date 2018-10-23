/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB https://goo.gl/jtiYJy
*/

#include <Wire.h>
#include "MAX30100_PulseOximeter.h" //https://github.com/oxullo/Arduino-MAX30100

uint32_t intervalT = 1000;
uint32_t previousMillisT = 0;
String resultSerialT;

PulseOximeter maxSensorT;

void setup() {
  Serial.begin(115200);
  Serial.print("Inicializando el sensor: ");
  if (!maxSensorT.begin()) {
    Serial.println("Fallido");
    for (;;);
  } else
    Serial.println("Completado");
  previousMillisT = millis();
}

void loop() {
  maxSensorT.update();
  uint32_t currentMillisT = millis();
  if ((unsigned long)(currentMillisT - previousMillisT) >= intervalT) {
    resultSerialT = "Pulso Cardiaco: " + String(maxSensorT.getHeartRate()) + "BPS | ";
    resultSerialT += "Saturación de Oxígeno:" + String(maxSensorT.getSpO2()) + "%";
    Serial.println(resultSerialT);
    previousMillisT = millis();
  }
}
