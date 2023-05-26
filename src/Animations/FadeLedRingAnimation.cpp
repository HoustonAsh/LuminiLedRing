/*
  Created on Thu May 25 2023

  The MIT License (MIT)
  Copyright (c) 2023 HoustonAsh
  See the LICENSE file in this project for the full license terms.
*/

#include "Animations/FadeLedRingAnimation.h"

void FadeLedRingAnimation::setup(uint8_t brightness, int32_t duration) {
  LedRingAnimation::setup();
  this->finished = false;
  this->brightness = brightness;
  this->updateInterval = duration / brightness / 2;
}

void FadeLedRingAnimation::process() {
  long int now = millis();
  if (now - lastUpdateTime < updateInterval) return;
  lastUpdateTime = now;

  long int t = (now - startAnimation) / updateInterval;

  uint8_t currentB = abs(brightness - t) % (brightness + 1);
  if (currentB == brightness && t > brightness)
    startAnimation = now;

  FastLED.setBrightness(currentB);
  FastLED.show();
}