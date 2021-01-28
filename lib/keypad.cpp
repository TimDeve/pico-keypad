#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pico/stdlib.h"
#include "pico_rgb_keypad.hpp"

#include "keypad.h"

using namespace pimoroni;

const int PicoKeypad__PadsNumber = PicoRGBKeypad::NUM_PADS;

PicoRGBKeypad pico_keypad;

void PicoKeypad__init() {
  pico_keypad.init();
}

void PicoKeypad__set_brightness(float brightness) {
  pico_keypad.set_brightness(brightness);
}

void PicoKeypad__illuminate(int i, unsigned char r, unsigned char g, unsigned char b) {
  pico_keypad.illuminate(i, r, g, b);
}

void PicoKeypad__update() {
  pico_keypad.update();
}

uint16_t PicoKeypad__get_button_states() {
  return pico_keypad.get_button_states();
}
