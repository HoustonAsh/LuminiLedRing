/*
  Created on Thu May 25 2023

  The MIT License (MIT)
  Copyright (c) 2023 HoustonAsh
  See the LICENSE file in this project for the full license terms.
*/

#include "Animations/LoadLedRingAnimation.h"

void LoadLedRingAnimation::setup(uint32_t rgb, int32_t duration, uint8_t taleScale) {
  LedRingAnimation::setup();
  this->color = rgb;
  this->durationStep = duration / ringSize;
  this->taleScale = taleScale;
}

void LoadLedRingAnimation::process() {
  long int now = millis();
  if (now - startAnimation < durationStep) return;
  startAnimation = now;
  ring[it] = color;
  if (++it == ringSize) it = 0;

  for (size_t i = 0; i < ringSize; ++i)
    ring[i].fadeToBlackBy(taleScale);

  Serial.println(it);

  // FastLED.show();
}