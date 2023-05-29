// #define CARD_READER_HARDWARE_SERIAL Serial2
#define LUMINI_CLK_PIN 2
#define LUMINI_DATA_PIN 1

#include <Arduino.h>
#include "LuminiLedRingContext.h"
#include "LuminiLedRing.h"

LuminiLedRingContext context;
LuminiLedRing luminiLedRing;

void setup() {
  Serial.begin(115200);
  Serial.println("READY!");
  luminiLedRing.setup(&context);

  // luminiLedRing.load(CRGB::HTMLColorCode::Aquamarine, 7000, 5);
}

void loop() {
  int lSt = millis();
  int lEnd = millis();
  if (lEnd - lSt > 2) {
    Serial.println((String)"SLOW FRAME: " + (lEnd - lSt));
  }
  // context.loop();
}