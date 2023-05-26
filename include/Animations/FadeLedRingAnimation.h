/*
  Created on Thu May 25 2023

  The MIT License (MIT)
  Copyright (c) 2023 HoustonAsh
  See the LICENSE file in this project for the full license terms.
*/

#ifndef FADE_LED_RING_ANIMATION
#define FADE_LED_RING_ANIMATION

#include "LedRingAnimation.h"

class FadeLedRingAnimation : public LedRingAnimation {
  uint8_t brightness;
  int32_t updateInterval;
  int32_t lastUpdateTime;
public:
  FadeLedRingAnimation() = default;
  FadeLedRingAnimation(String a) { name = a; }
  void setup(uint8_t brightness, int32_t duration);
  void process();
};

#endif