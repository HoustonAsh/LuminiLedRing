/*
  Created on Thu May 25 2023

  The MIT License (MIT)
  Copyright (c) 2023 HoustonAsh
  See the LICENSE file in this project for the full license terms.
*/

#include "LuminiLedRing.h"
#include "Arduino.h"
#include "FastLED.h"


BlinkLedRingAnimation blinkLedRingAnimation;
LoadLedRingAnimation loadLedRingAnimation;
FadeLedRingAnimation fadeLedRingAnimation("Fading");

void LuminiLedRing::setup(LuminiLedRingContext* ctx) {
  FastLED.addLeds<APA102, LUMINI_DATA_PIN, LUMINI_CLK_PIN, BGR>(ring, NUM_LEDS);
  FastLED.setBrightness(DEFAULT_BRIGHTNESS);
  context = ctx;

  loadLedRingAnimation.setLed(ring, NUM_LEDS);
}

/// @brief Turn on given percentage of lights
/// @param rgb 
/// @param percentage 
void LuminiLedRing::progress(uint32_t rgb, uint8_t percentage) {
  percentage = map(percentage, 0, 100, 0, NUM_LEDS);
  for (int i = 0; i < percentage; ++i) ring[i] = rgb;
  for (int i = percentage; i < NUM_LEDS; ++i)
    ring[i] = CRGB::HTMLColorCode::Black;
  FastLED.show();
}

/// @brief Turn on all lights
/// @param rgb color
void LuminiLedRing::enable(uint32_t rgb) {
  for (int i = 0; i < NUM_LEDS; ++i) ring[i] = rgb;
  FastLED.show();
}

/// @brief Start blink animation.
/// @param duration duration time
/// @param interval blink time
/// @param count number of blinks
void LuminiLedRing::blink(int32_t duration, int32_t interval, int count) {
  context->setAnimation((LedRingAnimation*)&blinkLedRingAnimation);
  blinkLedRingAnimation.setup(DEFAULT_BRIGHTNESS, duration, interval, count);
}

/// @brief Start load animation
/// @param rgb color
/// @param duration time of full rotation
void LuminiLedRing::load(uint32_t rgb, uint32_t duration, uint8_t taleScale) {
  context->setAnimation((LedRingAnimation*)&loadLedRingAnimation);
  loadLedRingAnimation.setup(rgb, duration, taleScale);
}

/// @brief Start fade animation
/// @param duration duration time
void LuminiLedRing::fade(uint32_t duration) {
  context->setAnimation((LedRingAnimation*)&fadeLedRingAnimation);
  fadeLedRingAnimation.setup(DEFAULT_BRIGHTNESS, duration);

  Serial.println((long int)(LedRingAnimation*)&fadeLedRingAnimation, HEX);
  Serial.println((long int)context->getAnimation(), HEX);
  if (context->getAnimation() != nullptr)
    Serial.println(context->getAnimation()->name);
}