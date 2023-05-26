/*
  Created on Thu May 25 2023

  The MIT License (MIT)
  Copyright (c) 2023 HoustonAsh
  See the LICENSE file in this project for the full license terms.
*/

#ifndef BLINK_LED_RING_ANIMATION_H
#define BLINK_LED_RING_ANIMATION_H

#include "LedRingAnimation.h"

class BlinkLedRingAnimation : public LedRingAnimation {
  int blinkCnt;
  uint8_t brightness;
public:
  void setup(uint8_t brightness, int32_t duration, int32_t updateInterval, int blinkCnt);
  void process();
};

#endif